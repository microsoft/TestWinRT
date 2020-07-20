#include "pch.h"
#include "BenchmarkComponent.h"
#include "ClassWithMultipleInterfaces.g.cpp"
#include "ClassWithMarshalingRoutines.g.cpp"
#include "WrappedClass.g.cpp"

using namespace winrt::Windows::Foundation;

namespace winrt::BenchmarkComponent::implementation
{
    ClassWithMultipleInterfaces::ClassWithMultipleInterfaces()
    {
    }

    int32_t ClassWithMultipleInterfaces::IntProperty()
    {
        return 1;
    }

    void ClassWithMultipleInterfaces::IntProperty(int32_t val)
    {
    }

    bool ClassWithMultipleInterfaces::BoolProperty()
    {
        return true;
    }

    void ClassWithMultipleInterfaces::BoolProperty(bool val)
    {
    }

    double ClassWithMultipleInterfaces::DoubleProperty()
    {
        return 1;
    }

    void ClassWithMultipleInterfaces::DoubleProperty(double val)
    {
    }

    int32_t ClassWithMultipleInterfaces::DefaultIntProperty()
    {
        return 1;
    }

    bool ClassWithMultipleInterfaces::DefaultBoolProperty()
    {
        return false;
    }

    double ClassWithMultipleInterfaces::DefaultDoubleProperty()
    {
        return 1;
    }

    void ClassWithMultipleInterfaces::DefaultIntProperty(int32_t val)
    {
    }

    void ClassWithMultipleInterfaces::DefaultBoolProperty(bool val)
    {
    }

    void ClassWithMultipleInterfaces::DefaultDoubleProperty(double val)
    {
    }

    ClassWithMarshalingRoutines::ClassWithMarshalingRoutines()
    {
    }

    hstring ClassWithMarshalingRoutines::DefaultStringProperty()
    {
        return hstring();
    }

    void ClassWithMarshalingRoutines::DefaultStringProperty(hstring val)
    {
    }
    
    Windows::Foundation::IInspectable ClassWithMarshalingRoutines::DefaultKeyValuePairProperty()
    {
        Windows::Foundation::Collections::ValueSet valueSet;
        valueSet.Insert(hstring(L"key"), PropertyValue::CreateString(L"value"));
        return valueSet.First().Current();
    }

    void ClassWithMarshalingRoutines::DefaultKeyValuePairProperty(Windows::Foundation::IInspectable val)
    {
    }

    Windows::Foundation::IInspectable ClassWithMarshalingRoutines::DefaultNullableProperty()
    {
        return IReference<INT32>(123);
    }

    void ClassWithMarshalingRoutines::DefaultNullableProperty(Windows::Foundation::IInspectable val)
    {
    }

    Windows::Foundation::IInspectable ClassWithMarshalingRoutines::DefaultArrayProperty()
    {
        int values[]{ 0, 42, 1729, -1 };
        auto propertyValue = PropertyValue::CreateInt32Array(values).as<IPropertyValue>();
        auto referenceArray = propertyValue.as<IReferenceArray<int>>();
        return referenceArray;
    }

    void ClassWithMarshalingRoutines::DefaultArrayProperty(Windows::Foundation::IInspectable val)
    {
    }
    
    WrappedClass::WrappedClass()
    {
    }

    int32_t WrappedClass::DefaultIntProperty()
    {
        return int32_t();
    }

    void WrappedClass::DefaultIntProperty(int32_t val)
    {
    }

}