#pragma once

#include "ClassWithMultipleInterfaces.g.h"
#include "ClassWithMarshalingRoutines.g.h"
#include "WrappedClass.g.h"

namespace winrt::BenchmarkComponent::implementation
{
    struct ClassWithMultipleInterfaces : ClassWithMultipleInterfacesT<ClassWithMultipleInterfaces>
    {
        ClassWithMultipleInterfaces();

        int32_t IntProperty();
        void IntProperty(int32_t val);

        bool BoolProperty();
        void BoolProperty(bool val);

        double DoubleProperty();
        void DoubleProperty(double val);

        int32_t DefaultIntProperty();
        bool DefaultBoolProperty();
        double DefaultDoubleProperty();
        void DefaultIntProperty(int32_t val);
        void DefaultBoolProperty(bool val);
        void DefaultDoubleProperty(double val);
    };

    struct WrappedClass : WrappedClassT<WrappedClass>
    {
        WrappedClass();

        int32_t DefaultIntProperty();
        void DefaultIntProperty(int32_t val);
    };

    struct ClassWithMarshalingRoutines : ClassWithMarshalingRoutinesT<ClassWithMarshalingRoutines>
    {
    private:
        Windows::Foundation::Collections::IKeyValuePair<hstring, IInspectable> keyValuePairObject;
        Windows::Foundation::IReference<INT32> nullableObject;
        Windows::Foundation::IReferenceArray<int> arrayObject;

        Windows::Foundation::Collections::IKeyValuePair<hstring, IInspectable> createKeyValuePairObject();
        Windows::Foundation::IReference<INT32> createNullableObject();
        Windows::Foundation::IReferenceArray<int> createArrayObject();

    public:
        ClassWithMarshalingRoutines();

        hstring DefaultStringProperty();
        void DefaultStringProperty(hstring val);

        Windows::Foundation::IInspectable NewTypeErasedKeyValuePairObject();
        void NewTypeErasedKeyValuePairObject(Windows::Foundation::IInspectable val);

        Windows::Foundation::IInspectable NewTypeErasedNullableObject();
        void NewTypeErasedNullableObject(Windows::Foundation::IInspectable val);

        Windows::Foundation::IInspectable NewTypeErasedArrayObject();
        void NewTypeErasedArrayObject(Windows::Foundation::IInspectable val);

        Windows::Foundation::IInspectable ExistingTypeErasedKeyValuePairObject();
        void ExistingTypeErasedKeyValuePairObject(Windows::Foundation::IInspectable val);

        Windows::Foundation::IInspectable ExistingTypeErasedNullableObject();
        void ExistingTypeErasedNullableObject(Windows::Foundation::IInspectable val);

        Windows::Foundation::IInspectable ExistingTypeErasedArrayObject();
        void ExistingTypeErasedArrayObject(Windows::Foundation::IInspectable val);

        BenchmarkComponent::WrappedClass NewWrappedClassObject();
        void NewWrappedClassObject(BenchmarkComponent::WrappedClass val);
    };
}

namespace winrt::BenchmarkComponent::factory_implementation
{
    struct ClassWithMultipleInterfaces : ClassWithMultipleInterfacesT<ClassWithMultipleInterfaces, implementation::ClassWithMultipleInterfaces>
    {
    };

    struct ClassWithMarshalingRoutines : ClassWithMarshalingRoutinesT<ClassWithMarshalingRoutines, implementation::ClassWithMarshalingRoutines>
    {
    };

    struct WrappedClass : WrappedClassT<WrappedClass, implementation::WrappedClass>
    {
    };
}
