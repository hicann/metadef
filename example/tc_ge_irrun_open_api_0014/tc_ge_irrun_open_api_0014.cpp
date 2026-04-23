/**
* Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <map>

#include "graph.h"
#include "types.h"
#include "tensor.h"
#include "ge_error_codes.h"
#include "ge_api_types.h"
#include "ge_api.h"
#include "nonlinear_fuc_ops.h"
#include "nn_calculation_ops.h"
#include "array_ops.h"
#include "ge_ir_build.h"
#include "ascend_string.h"
#include "acl.h"
#include "acl_rt.h"
#include "acl_op_compiler.h"

#define FAILED -1
#define SUCCESS 0

using namespace ge;
using std::vector;
using std::map;
using std::string;

string GetTime()
{
    time_t timep;
    time (&timep);
    char tmp[64];
    struct tm result;
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S,000", localtime_r(&timep, &result));
    return tmp;
}

uint32_t GetDataTypeSize(DataType dt)
{
    uint32_t dilation =1;
    if(dt == ge::DT_FLOAT)
        dilation = 4;
    else if(dt == ge::DT_FLOAT16)
        dilation = 2;
    else if(dt == ge::DT_INT16)
        dilation = 2;
    else if(dt == ge::DT_UINT16)
        dilation = 2;
    else if(dt == ge::DT_INT32)
        dilation = 4;
    else if(dt == ge::DT_UINT32)
        dilation = 4;
    else if(dt == ge::DT_INT64)
        dilation = 8;
    else if(dt == ge::DT_UINT64)
        dilation = 8;
    else if(dt == ge::DT_INT8)
        dilation = 1;
    return dilation;
}

int32_t GenOnesData(vector<int64_t> shapes, Tensor &input_tensor, TensorDesc &input_tensor_desc, DataType data_type, int value) {
    input_tensor_desc.SetRealDimCnt(shapes.size());
    size_t size = 1;
    for (uint32_t i = 0; i < shapes.size(); i++) {
        size *= shapes[i];
    }
    uint32_t data_len = size * GetDataTypeSize(data_type);
    char* pData = new(std::nothrow) char[data_len];
    for (uint32_t i = 0; i < size; ++i) {
        *(pData + i) = value;
    }
    input_tensor = Tensor(input_tensor_desc, reinterpret_cast<uint8_t*>(pData), data_len);
    return SUCCESS;
}

int32_t WriteDataToFile(string bin_file, uint64_t data_size, uint8_t* inputData) {
    FILE *fp;
    fp = fopen(bin_file.c_str(), "w");
    fwrite(inputData, sizeof(uint8_t), data_size, fp);
    fclose(fp);
    return SUCCESS;
}

int32_t LoadDataFromFile(string bin_file, vector<int64_t> shapes, Tensor &input_tensor, TensorDesc &input_tensor_desc, DataType data_type) {
    size_t size = 1;
    for (uint32_t i = 0; i < shapes.size(); i++) {
        size *= shapes[i];
    }
    uint32_t data_size = size * GetDataTypeSize(data_type);
    FILE *fp;
    fp = fopen(bin_file.c_str(), "r");
    uint32_t* memory = (uint32_t*)malloc(data_size * sizeof(uint32_t));
    fread(memory, sizeof(uint32_t), data_size, fp);
    fclose(fp);
    uint8_t* inputData = (uint8_t*)memory;
    input_tensor_desc.SetRealDimCnt(shapes.size());
    input_tensor = Tensor(input_tensor_desc, inputData, data_size);
    return SUCCESS;
}

int32_t GenOnesDataInt64(vector<int64_t> shapes, Tensor &input_tensor, TensorDesc &input_tensor_desc, int64_t value) {
    input_tensor_desc.SetRealDimCnt(shapes.size());
    size_t size = 1;
    for (uint32_t i = 0; i < shapes.size(); i++) {
        size *= shapes[i];
    }
    uint32_t data_len = size * 8;
    int64_t * pData = nullptr;
    pData = new int64_t[size];
    for(int i=0; i<size; ++i) {
        *(pData+i) = value;
    }
    input_tensor = Tensor(input_tensor_desc, (uint8_t*)pData, data_len);
    return SUCCESS;
}

int32_t GenOnesDataUint64(vector<int64_t> shapes, Tensor &input_tensor, TensorDesc &input_tensor_desc, uint64_t value) {
    input_tensor_desc.SetRealDimCnt(shapes.size());
    size_t size = 1;
    for (uint32_t i = 0; i < shapes.size(); i++) {
        size *= shapes[i];
    }
    uint32_t data_len = size * 8;
    uint64_t * pData = nullptr;
    pData = new uint64_t[size];
    for(int i=0; i<size; ++i) {
        *(pData+i) = value;
    }
    input_tensor = Tensor(input_tensor_desc, (uint8_t*)pData, data_len);
    return SUCCESS;
}

int32_t GenOnesDataInt32(vector<int64_t> shapes, Tensor &input_tensor, TensorDesc &input_tensor_desc, int32_t value) {
     input_tensor_desc.SetRealDimCnt(shapes.size());
     size_t size = 1;
     for (uint32_t i = 0; i < shapes.size(); i++) {
         size *= shapes[i];
     }
     uint32_t data_len = size * 4;
     int32_t* pData = new(std::nothrow) int32_t[size];
     for (uint32_t i = 0; i < size; ++i) {
         *(pData + i) = value;
     }
     input_tensor = Tensor(input_tensor_desc, reinterpret_cast<uint8_t*>(pData), data_len);
     return SUCCESS;
 }
 
 int32_t GenOnesDataInt8(vector<int64_t> shapes, Tensor &input_tensor, TensorDesc &input_tensor_desc, int8_t value) {
    input_tensor_desc.SetRealDimCnt(shapes.size());
    size_t size = 1;
    for (uint32_t i = 0; i < shapes.size(); i++) {
        size *= shapes[i];
    }
    uint32_t data_len = size * 1;
    int8_t* pData = new(std::nothrow) int8_t[data_len];
    for (uint32_t i = 0; i < size; ++i) {
        *(pData + i) = value;
    }
    input_tensor = Tensor(input_tensor_desc, reinterpret_cast<uint8_t*>(pData), data_len);
    return SUCCESS;
}

int32_t GenOnesDataFloat32(vector<int64_t> shapes, Tensor &input_tensor, TensorDesc &input_tensor_desc, float value) {
    input_tensor_desc.SetRealDimCnt(shapes.size());
    size_t size = 1;
    for (uint32_t i = 0; i < shapes.size(); i++) {
        size *= shapes[i];
    }
    uint32_t data_len = size * 4;
    float * pData = nullptr;
    pData = new float[size];
    for(int i=0; i<size; ++i) {
        *(pData+i) = value;
    }
    input_tensor = Tensor(input_tensor_desc, (uint8_t*)pData, data_len);
    return SUCCESS;
}    
//this for function op gragh

static Status InitGE()
{
    printf("[IR run log] - INFO - [XIR]: Start to initialize ge using ge global options\n");
    std::map<AscendString, AscendString> global_options = {
        {"ge.exec.deviceId", R"(0)"},
        {"ge.deterministic", R"(1)"}
    };

    Status ret = ge::GEInitialize(global_options);
    if (ret != SUCCESS) {
        printf("[IR run log] - INFO - [XIR]: Initialize ge using ge global options failed\n");
        return FAILED;
    }
    printf("[IR run log] - INFO - [XIR]: Initialize ge using ge global options success\n");
    return SUCCESS;
}

static Status BuildReluGraph(Graph& graph, std::vector<ge::Tensor>& input)
{
    vector<int64_t> placeholder_01_shape = {1, 3, 32, 32};
    auto placeholder_01 = op::Data("placeholder_01")
            .set_attr_index(0);
    TensorDesc placeholder_01_desc = TensorDesc(ge::Shape(placeholder_01_shape), FORMAT_NHWC, DT_FLOAT16);
    placeholder_01_desc.SetPlacement(ge::kPlacementHost);
    placeholder_01_desc.SetFormat(FORMAT_NHWC);
    Tensor tensor_placeholder_01;

    Status ret = GenOnesData(placeholder_01_shape, tensor_placeholder_01, placeholder_01_desc, DT_FLOAT16, 1);
    if (ret != SUCCESS) {
        printf("%s - ERROR - [XIR]: Generate input data failed\n", GetTime().c_str());
        return FAILED;
    }

    placeholder_01.update_input_desc_x(placeholder_01_desc);
    placeholder_01.update_output_desc_y(placeholder_01_desc);
    input.push_back(tensor_placeholder_01);
    graph.AddOp(placeholder_01);

    auto relu_01 = op::Relu("relu_01")
            .set_input_x(placeholder_01, 0);

    relu_01.SetAttr("pattern", "ElemWise");
    TensorDesc tensor_desc_relu_01_x = relu_01.GetInputDescByName("x");
    TensorDesc tensor_desc_relu_01_y = relu_01.GetOutputDescByName("y");

    tensor_desc_relu_01_x.SetOriginFormat(FORMAT_NHWC);
    tensor_desc_relu_01_y.SetOriginFormat(FORMAT_NHWC);

    tensor_desc_relu_01_x.SetFormat(FORMAT_NHWC);
    tensor_desc_relu_01_y.SetFormat(FORMAT_NHWC);

    relu_01.UpdateInputDesc("x", tensor_desc_relu_01_x);
    relu_01.UpdateOutputDesc("y", tensor_desc_relu_01_y);
    graph.AddOp(relu_01);
    printf("%s - INFO - [XIR]: Add relu op into ir compute graph finished\n", GetTime().c_str());

    std::vector<Operator> inputs{placeholder_01};
    std::vector<Operator> outputs{relu_01};
    graph.SetInputs(inputs).SetOutputs(outputs);

    return SUCCESS;
}

static Status CreateAndAddGraphToSession(Graph& graph, ge::Session*& session)
{
    printf("[IR run log] - INFO - [XIR]: Start to initialize ge using ge session options\n");
    std::map<AscendString, AscendString> session_options = {};

    printf("[IR run log] - INFO - [XIR]: Start to initialize ge using ge graph options\n");
    std::map<AscendString, AscendString> graph_options = {};

    ge::Session sess = Session(session_options);
    session = &sess;
    if (session == nullptr) {
        printf("[IR run log] - ERROR - [XIR]: Create ir session using build options failed\n");
        return FAILED;
    }
    printf("[IR run log] - INFO - [XIR]: Create ir session using build options success\n");

    printf("[IR run log] - INFO - [XIR]: Start to add compute graph to ir session\n");
    uint32_t graph_id = 9;
    Status ret = session->AddGraph(graph_id, graph, graph_options);
    if (ret != SUCCESS) {
        printf("[IR run log] - INFO - [XIR]: Add graph failed\n");
        return FAILED;
    }
    printf("[IR run log] - INFO - [XIR]: Session add ir compute graph to ir session success\n");

    printf("[IR run log] - INFO - [XIR]: Start to compile graph to ir session\n");
    ret = session->CompileGraph(graph_id);
    if (ret != SUCCESS) {
        printf("[IR run log] - INFO - [XIR]: compile graph failed, pls check");
        return FAILED;
    }
    printf("[IR run log] - INFO - [XIR]: Session run ir compile graph success\n");

    return SUCCESS;
}

static Status InitACL(aclrtStream& stream)
{
    const char* aclConfigPath = "";
    aclError retInit = aclInit(aclConfigPath);
    if (retInit != ACL_ERROR_NONE) {
        printf("[ACL run log] - INFO - [XIR]: acl init failed.\n");
        return FAILED;
    }
    printf("[ACL run log] - INFO - [XIR]: acl init success\n");

    int32_t deviceId = 0;
    retInit = aclrtSetDevice(deviceId);
    if (retInit != ACL_ERROR_NONE) {
        printf("[ACL run log] - INFO - [XIR]: acl set deviceid failed\n");
        return FAILED;
    }
    printf("[ACL run log] - INFO - [XIR]: acl set deviceid success\n");

    aclError aclRet = aclrtCreateStream(&stream);
    if (aclRet != ACL_ERROR_NONE) {
        printf("[ACL run log] - INFO - [XIR]: acl creat stream failed\n");
        return FAILED;
    }
    printf("[ACL run log] - INFO - [XIR]: acl creat stream success\n");

    return SUCCESS;
}

static Status PrepareInputTensors(const std::vector<ge::Tensor>& input,
                                  std::vector<gert::Tensor>& input_device,
                                  aclrtStream stream)
{
    input_device.resize(input.size());
    for (size_t i = 0; i < input.size(); i++) {
        auto input_size = input[i].GetSize();
        auto input_desc = input[i].GetTensorDesc();
        gert::StorageShape storage_shape({4, 50, 50, 3}, {4, 50, 50, 3});
        auto input_format = input_desc.GetFormat();
        gert::StorageFormat storage_format(input_format, input_format, {});
        auto input_dtype = input_desc.GetDataType();
        uint8_t* input_buffer = input[i].GetData();
        void* inputdevBuffer = nullptr;
        aclError aclRet = aclrtMalloc(&inputdevBuffer, input_size, ACL_MEM_MALLOC_NORMAL_ONLY);
        if (aclRet != ACL_ERROR_NONE) {
            printf("[ACL run log] - INFO - [XIR]: malloc input dev buffer fail\n");
            return FAILED;
        }
        aclRet = aclrtMemcpy(inputdevBuffer, input_size, input_buffer, input_size, ACL_MEMCPY_HOST_TO_DEVICE);
        if (aclRet != ACL_ERROR_NONE) {
            printf("[ACL run log] - INFO - [XIR]: acl memcpy input to dev failed\n");
            return FAILED;
        }
        printf("[ACL run log] - INFO - [XIR]: acl memcpy input host to device success\n");
        input_device[i] = {storage_shape, storage_format, gert::kOnDeviceHbm, input_dtype, inputdevBuffer};
    }
    return SUCCESS;
}

static Status ExecuteGraphAndSaveOutput(ge::Session& sess, uint32_t graph_id,
                                        aclrtStream stream,
                                        std::vector<gert::Tensor>& input_device,
                                        std::vector<gert::Tensor>& output)
{
    std::map<AscendString, AscendString> load_graph_options = {};
    Status ret = GeSessionLoadGraph(sess, graph_id, load_graph_options, stream);
    if (ret != SUCCESS) {
        printf("[IR run log] - INFO - [XIR]: GeSessionLoadGraph failed\n");
        return FAILED;
    }
    printf("[IR run log] - INFO - [XIR]: GeSessionLoadGraph success\n");

    ret = PrepareInputTensors(input, input_device, stream);
    if (ret != SUCCESS) {
        return FAILED;
    }

    size_t output_size = 4 * 48 * 48 * 3;
    void* outputdevBuffer = nullptr;
    aclrtMalloc(&outputdevBuffer, output_size, ACL_MEM_MALLOC_NORMAL_ONLY);
    output.resize(1);
    output[0] = {{{4, 48, 48, 3}, {4, 48, 48, 3}}, {}, gert::kOnDeviceHbm, {}, outputdevBuffer};

    printf("[IR run log] - INFO - [XIR]: Start to run ir compute graph the second time\n");
    ret = GeSessionExecuteGraphWithStreamAsync(sess, graph_id, stream, input_device, output);
    if (ret != SUCCESS) {
        printf("[IR run log] - INFO - [XIR]: GeSessionExecuteGraphWithStreamAsync failed\n");
        return FAILED;
    }
    printf("[IR run log] - INFO - [XIR]: GeSessionExecuteGraphWithStreamAsync success\n");

    aclError aclRet = aclrtSynchronizeStream(stream);
    if (aclRet != ACL_ERROR_NONE) {
        printf("[ACL run log] - INFO - [XIR]: sync stream failed\n");
        return FAILED;
    }
    printf("[ACL run log] - INFO - [XIR]: stream sync success\n");

    string output_file = "./tc_ge_irrun_open_api_0014/tc_ge_irrun_open_api_0014_npu_output_";
    for (size_t i = 0; i < output.size(); i++) {
        string output1_file = output_file + std::to_string(i) + ".bin";
        auto output1_addr = output[i].GetData<uint8_t>();
        auto output_size1 = output[i].GetSize();
        void* output1_hostBuffer = nullptr;
        aclRet = aclrtMallocHost(&output1_hostBuffer, output_size1);
        aclrtMemcpy(output1_hostBuffer, output_size1, output1_addr, output_size1, ACL_MEMCPY_DEVICE_TO_HOST);
        WriteDataToFile((const char*)output1_file.c_str(), output_size1, (uint8_t*)output1_hostBuffer);
        aclrtFreeHost(output1_hostBuffer);
    }

    return SUCCESS;
}

static Status Cleanup()
{
    printf("[IR run log] - INFO - [XIR]: Start to finalize ir graph session\n");
    Status ret = ge::GEFinalize();
    if (ret != SUCCESS) {
        printf("[IR run log] - INFO - [XIR]: Finalize ir graph session failed\n");
        return FAILED;
    }
    printf("[IR run log] - INFO - [XIR]: Finalize ir graph session success\n");

    printf("[IR run log] - INFO - [XIR]: Start to finalize acl\n");
    ret = aclFinalize();
    if (ret != SUCCESS) {
        printf("[IR run log] - INFO - [XIR]: Finalize acl failed\n");
        return FAILED;
    }
    printf("[IR run log] - INFO - [XIR]: Finalize acl success\n");

    return SUCCESS;
}

int main(int argc, char* argv[])
{
    const char* graph_name = "tc_ge_irrun_open_api_0014";
    Graph graph(graph_name);
    std::vector<ge::Tensor> input;
    ge::Session* session = nullptr;
    aclrtStream stream = nullptr;
    std::vector<gert::Tensor> input_device;
    std::vector<gert::Tensor> output;

    Status ret = InitGE();
    if (ret != SUCCESS) {
        return FAILED;
    }

    ret = BuildReluGraph(graph, input);
    if (ret != SUCCESS) {
        Cleanup();
        return FAILED;
    }

    ret = CreateAndAddGraphToSession(graph, session);
    if (ret != SUCCESS) {
        Cleanup();
        return FAILED;
    }

    ret = InitACL(stream);
    if (ret != SUCCESS) {
        Cleanup();
        return FAILED;
    }

    ret = ExecuteGraphAndSaveOutput(*session, 9, stream, input_device, output);
    if (ret != SUCCESS) {
        Cleanup();
        return FAILED;
    }

    ret = Cleanup();
    if (ret != SUCCESS) {
        return FAILED;
    }

    return SUCCESS;
}
