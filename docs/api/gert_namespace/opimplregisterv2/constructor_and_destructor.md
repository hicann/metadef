# 构造和析构函数

## 函数功能

OpImplRegisterV2类作为注册接口类，提供了一系列算子原型注册接口，供用户注册指定算子类型的Tiling函数、Infershape函数、私有属性等信息。

## 函数原型

- 指定算子类型为op\_type，构造一个用于算子注册的OpImplRegisterV2对象，并对其注册数据进行默认初始化。

    ```cpp
    explicit OpImplRegisterV2(const ge::char_t *op_type)
    ```

- 移动构造和拷贝构造函数，二者功能均能将另一个OpImplRegisterV2对象register\_data的OpImplFunctions数据注册到OpImplRegistry单例所管理的map中，并且生成一个新的默认初始化的OpImplRegisterV2对象。

    ```cpp
    OpImplRegisterV2(OpImplRegisterV2 &&register_data) noexcept
    OpImplRegisterV2(const OpImplRegisterV2 &register_data)
    OpImplRegisterV2 &operator=(const OpImplRegisterV2 &) = delete
    OpImplRegisterV2 &operator=(OpImplRegisterV2 &&) = delete
    ```

- 析构函数

    ```cpp
    ~OpImplRegisterV2()
    ```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|op_type|输入|指定的算子类型。|
|register_data|输入|另一个注册对象，类型为OpImplRegisterV2的引用。|

## 返回值说明

一个用于算子注册的OpImplRegisterV2对象。

## 约束说明

无。
