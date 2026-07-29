# Stride构造函数

## 函数功能

Stride构造函数。

## 函数原型

下文中的dim\_num\_为维度个数，即有几维；strides\_为具体的步长信息。

- 默认构造一个Stride对象，默认构造的Stride对象中，dim\_num\_长度为0。

    ```cpp
    Stride() : dim_num_(0), strides_{0}
    ```

- 通过strides\_值构造Stride，例如：Stride\(\{18,9,3,1\}\)表示创建一个Stride对象，Stride对象有4个维度，每个维度的步长分别是18,9,3,1。

    ```cpp
    Stride(const std::initializer_list<int64_t> &args) : Stride()
    ```

- 拷贝构造，为了提升性能，strides\_超过源Stride对象dim\_num\_的空间没有拷贝，可能有脏数据。

    ```cpp
    Stride(const Stride &other)
    ```

- 拷贝赋值，为了提升性能，strides\_超过源Stride对象dim\_num\_的空间没有拷贝，可能有脏数据。

    ```cpp
    Stride &operator=(const Stride &other)
    ```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|args|输入|Stride对象的所有步长值。|
|other|输入|源Stride对象。|

## 返回值说明

生成一个初始化的Stride对象。

## 约束说明

无。

## 调用示例

```cpp
Stride stride({3, 256, 256}); // dim_num_=3  strides_描述张量的前三维的步长为3,256,256
```
