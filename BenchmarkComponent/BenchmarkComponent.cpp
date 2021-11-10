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

    Windows::Foundation::IInspectable ClassWithMultipleInterfaces::NewObject() const
    {
        return make<ClassWithMarshalingRoutines>();
    }

    Windows::Foundation::IInspectable ClassWithMultipleInterfaces::DefaultObjectProperty() const
    {
        return m_object;
    }

    void ClassWithMultipleInterfaces::DefaultObjectProperty(Windows::Foundation::IInspectable const& value)
    {
        m_object = value;
    }

    hstring ClassWithMultipleInterfaces::DefaultStringProperty() const
    {
        return m_string;
    }
    void ClassWithMultipleInterfaces::DefaultStringProperty(hstring const& value)
    {
        m_string = value;
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
        keyValuePairObject = createKeyValuePairObject();
        arrayObject = createArrayObject();
        nullableObject = createNullableObject();
        dictionary = createDictionary();
    }

    hstring ClassWithMarshalingRoutines::DefaultStringProperty()
    {
        return hstring();
    }

    void ClassWithMarshalingRoutines::DefaultStringProperty(hstring val)
    {
    }

    Windows::Foundation::Collections::IKeyValuePair<hstring, IInspectable> ClassWithMarshalingRoutines::createKeyValuePairObject()
    {
        Windows::Foundation::Collections::ValueSet valueSet;
        valueSet.Insert(hstring(L"key"), PropertyValue::CreateInt32(27861));
        return valueSet.First().Current();
    }

    Windows::Foundation::IReference<INT32> ClassWithMarshalingRoutines::createNullableObject()
    {
        return IReference<INT32>(123);
    }

    Windows::Foundation::IReferenceArray<int> ClassWithMarshalingRoutines::createArrayObject()
    {
        int values[]{ 0, 42, 1729, -1 };
        auto propertyValue = PropertyValue::CreateInt32Array(values).as<IPropertyValue>();
        return propertyValue.as<IReferenceArray<int>>();
    }

    Windows::Foundation::Collections::IMap<hstring, BenchmarkComponent::WrappedClass> ClassWithMarshalingRoutines::createDictionary()
    {
        std::map<hstring, BenchmarkComponent::WrappedClass> dict;
        dict[L"a"] = winrt::make<WrappedClass>();
        return winrt::single_threaded_map(std::move(dict));
    }

    Windows::Foundation::Collections::IMap<winrt::hstring, BenchmarkComponent::WrappedClass> ClassWithMarshalingRoutines::ExistingDictionary()
    {
        return dictionary;
    }
    
    Windows::Foundation::IInspectable ClassWithMarshalingRoutines::NewTypeErasedKeyValuePairObject()
    {
        return createKeyValuePairObject();
    }

    void ClassWithMarshalingRoutines::NewTypeErasedKeyValuePairObject(Windows::Foundation::IInspectable val)
    {
    }

    Windows::Foundation::IInspectable ClassWithMarshalingRoutines::NewTypeErasedNullableObject()
    {
        return createNullableObject();
    }

    void ClassWithMarshalingRoutines::NewTypeErasedNullableObject(Windows::Foundation::IInspectable val)
    {
    }

    Windows::Foundation::IInspectable ClassWithMarshalingRoutines::NewTypeErasedArrayObject()
    {
        return createArrayObject();
    }

    void ClassWithMarshalingRoutines::NewTypeErasedArrayObject(Windows::Foundation::IInspectable val)
    {
    }

    Windows::Foundation::IInspectable ClassWithMarshalingRoutines::ExistingTypeErasedKeyValuePairObject()
    {
        return keyValuePairObject;
    }

    void ClassWithMarshalingRoutines::ExistingTypeErasedKeyValuePairObject(Windows::Foundation::IInspectable val)
    {
    }

    Windows::Foundation::IInspectable ClassWithMarshalingRoutines::ExistingTypeErasedNullableObject()
    {
        return nullableObject;
    }

    void ClassWithMarshalingRoutines::ExistingTypeErasedNullableObject(Windows::Foundation::IInspectable val)
    {
    }

    Windows::Foundation::IInspectable ClassWithMarshalingRoutines::ExistingTypeErasedArrayObject()
    {
        return arrayObject;
    }

    void ClassWithMarshalingRoutines::ExistingTypeErasedArrayObject(Windows::Foundation::IInspectable val)
    {
    }

    BenchmarkComponent::WrappedClass ClassWithMarshalingRoutines::NewWrappedClassObject()
    {
        return make<WrappedClass>();
    }

    void ClassWithMarshalingRoutines::NewWrappedClassObject(BenchmarkComponent::WrappedClass val)
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

    int32_t ClassWithMarshalingRoutines::IntProperty()
    {
        return _int;
    }
    void ClassWithMarshalingRoutines::IntProperty(int32_t value)
    {
        _int = value;
        _intChanged(*this, _int);
    }
    winrt::event_token ClassWithMarshalingRoutines::IntPropertyChanged(EventHandler<int32_t> const& handler)
    {
        return _intChanged.add(handler);
    }
    void ClassWithMarshalingRoutines::IntPropertyChanged(winrt::event_token const& token) noexcept
    {
        _intChanged.remove(token);
    }
    void ClassWithMarshalingRoutines::RaiseIntChanged()
    {
        _intChanged(*this, _int);
    }
    void ClassWithMarshalingRoutines::CallForInt(BenchmarkComponent::ProvideInt const& provideInt)
    {
        _int = provideInt();
    }

    winrt::event_token ClassWithMarshalingRoutines::DoublePropertyChanged(EventHandler<double_t> const& handler)
    {
        return _doubleChanged.add(handler);
    }
    void ClassWithMarshalingRoutines::DoublePropertyChanged(winrt::event_token const& token) noexcept
    {
        _doubleChanged.remove(token);
    }
    void ClassWithMarshalingRoutines::RaiseDoubleChanged()
    {
        _doubleChanged(*this, _int);
    }
}