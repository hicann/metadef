# TensorDesc

TensorDesc的拷贝构造和赋值操作均为值拷贝，不共享TensorDesc信息。

TensorDesc的Move构造和Move赋值，会将原有TensorDesc信息移动到新的TensorDesc对象中。

- [TensorDesc构造函数和析构函数](tensordesc_constructor_and_destructor.md)

- [GetConstData](GetConstData.md)

- [GetDataType](GetDataType.md)

- [GetExpandDimsRule](GetExpandDimsRule.md)

- [GetFormat](GetFormat.md)

- [GetName](GetName.md)

- [GetOriginFormat](GetOriginFormat.md)

- [GetOriginShape](GetOriginShape.md)

- [GetPlacement](GetPlacement.md)

- [GetRealDimCnt](GetRealDimCnt.md)

- [GetShape](GetShape.md)

- [GetShapeRange](GetShapeRange.md)

- [GetSize](GetSize.md)

- [SetConstData](SetConstData.md)

- [SetDataType](SetDataType.md)

- [SetExpandDimsRule](SetExpandDimsRule.md)

- [SetFormat](SetFormat.md)

- [SetName](SetName.md)

- [SetOriginFormat](SetOriginFormat.md)

- [SetOriginShape](SetOriginShape.md)

- [SetPlacement](SetPlacement.md)

- [SetRealDimCnt](SetRealDimCnt.md)

- [SetSize](SetSize.md)

- [SetShape](SetShape.md)

- [SetShapeRange](SetShapeRange.md)

- [SetUnknownDimNumShape](SetUnknownDimNumShape.md)

- [SetReuseInputIndex](SetReuseInputIndex.md)

- [Update](Update.md)
