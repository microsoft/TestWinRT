#pragma once

#include "ClassWithMultipleInterfaces.g.h"
#include "ClassWithMarshalingRoutines.g.h"
#include "ClassWithFastAbi.g.h"
#include "ClassWithFastAbiDerived.g.h"
#include "NonAgileClassWithMultipleInterfaces.g.h"
#include "WrappedClass.g.h"
#include "EventOperations.g.h"
#include "ClassWithAsync.g.h"
#include "Composable.g.h"

namespace winrt::BenchmarkComponent::implementation
{
    struct ClassWithMultipleInterfaces : ClassWithMultipleInterfacesT<ClassWithMultipleInterfaces>
    {
        ClassWithMultipleInterfaces();
        ClassWithMultipleInterfaces(int32_t value);

        int32_t IntProperty();
        void IntProperty(int32_t val);
        void VoidMethod();
        int32_t IntMethod(int32_t value);

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
        Windows::Foundation::IInspectable DefaultObjectProperty() const;
        void DefaultObjectProperty(Windows::Foundation::IInspectable const& value);
        hstring DefaultStringProperty() const;
        void DefaultStringProperty(hstring const& value);
        void DefaultVoidMethod();
        int32_t DefaultIntMethod(int32_t value);
        hstring DefaultStringMethod(hstring const& input);
        void AcceptStringArray(array_view<hstring const> values);
        void ThrowInvalidArgument();

        Windows::Foundation::IInspectable NewObject() const;

        void QueryBoolInterface(IIntProperties properties);
    private:
        Windows::Foundation::IInspectable m_object;
        hstring m_string;
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
        Windows::Foundation::Collections::IMap<hstring, BenchmarkComponent::WrappedClass> dictionary;
        Windows::Foundation::Collections::IVector<winrt::hstring> list;
        BenchmarkComponent::WrappedClass existingWrappedClass;
        BenchmarkComponent::ClassWithFastAbi existingUnsealedObject;

        Windows::Foundation::Collections::IKeyValuePair<hstring, IInspectable> createKeyValuePairObject();
        Windows::Foundation::IReference<INT32> createNullableObject();
        Windows::Foundation::IReferenceArray<int> createArrayObject();
        Windows::Foundation::Collections::IMap<hstring, BenchmarkComponent::WrappedClass> createDictionary();

        int32_t _int = 0;
        BenchmarkComponent::NonBlittable _nonBlittable;
        winrt::event<Windows::Foundation::EventHandler<int32_t>> _intChanged;
        winrt::event<Windows::Foundation::EventHandler<double_t>> _doubleChanged;
        BenchmarkComponent::ProvideInt _handler;
        BenchmarkComponent::ProvideInt _existingHandler = [] { return 4; };
        Windows::Foundation::Uri _uri;
        Windows::UI::Xaml::Interop::TypeName _type;
    public:
        ClassWithMarshalingRoutines();
        ClassWithMarshalingRoutines(hstring const& value);

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

        Windows::Foundation::Uri NewUri();
        void NewUri(Windows::Foundation::Uri val);
        Windows::Foundation::Uri ExistingUri();
        void ExistingUri(Windows::Foundation::Uri val);

        Windows::UI::Xaml::Interop::TypeName NewType();
        void NewType(Windows::UI::Xaml::Interop::TypeName val);
        Windows::UI::Xaml::Interop::TypeName ExistingType();
        void ExistingType(Windows::UI::Xaml::Interop::TypeName val);

        Windows::Foundation::Collections::IVector<winrt::hstring> NewList();

        int32_t IntProperty();
        void IntProperty(int32_t value);
        winrt::event_token IntPropertyChanged(Windows::Foundation::EventHandler<int32_t> const& handler);
        void IntPropertyChanged(winrt::event_token const& token) noexcept;
        void RaiseIntChanged();
        void CallForInt(BenchmarkComponent::ProvideInt const& provideInt);

        winrt::event_token DoublePropertyChanged(Windows::Foundation::EventHandler<double_t> const& handler);
        void DoublePropertyChanged(winrt::event_token const& token) noexcept;
        void RaiseDoubleChanged();

        Windows::Foundation::Collections::IMap<winrt::hstring, BenchmarkComponent::WrappedClass> ExistingDictionary();

        Windows::Foundation::Collections::IVector<int32_t> Items(uint32_t count);
        Windows::Foundation::Collections::IVectorView<int32_t> ItemsView(uint32_t count);
        Windows::Foundation::Collections::IMap<hstring, int32_t> StringMap(uint32_t count);
        Windows::Foundation::Collections::IMapView<int32_t, int32_t> MapView(uint32_t count);

        Windows::Foundation::Collections::IVector<BenchmarkComponent::WrappedClass> ObjectItems(uint32_t count);
        Windows::Foundation::Collections::IVectorView<BenchmarkComponent::WrappedClass> ObjectItemsView(uint32_t count);
        Windows::Foundation::Collections::IMap<hstring, BenchmarkComponent::WrappedClass> ObjectMap(uint32_t count);
        Windows::Foundation::Collections::IMapView<hstring, BenchmarkComponent::WrappedClass> ObjectMapView(uint32_t count);

        Windows::Foundation::IReference<int32_t> NullableInt();
        void NullableInt(Windows::Foundation::IReference<int32_t> const& value);
        Windows::Foundation::IReference<BenchmarkComponent::BlittableStruct> NullableBlittableStruct();
        void NullableBlittableStruct(Windows::Foundation::IReference<BenchmarkComponent::BlittableStruct> const& value);
        Windows::Foundation::IReference<BenchmarkComponent::NonBlittable> NullableNonBlittableStruct();
        void NullableNonBlittableStruct(Windows::Foundation::IReference<BenchmarkComponent::NonBlittable> const& value);
        Windows::Foundation::IReference<Windows::Foundation::TimeSpan> NullableTimeSpan();
        void NullableTimeSpan(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> const& value);
        Windows::Foundation::IInspectable BoxedDelegate();
        void BoxedDelegate(Windows::Foundation::IInspectable const& value);

        BenchmarkComponent::ProvideInt NewIntDelegate();
        BenchmarkComponent::ProvideInt ExistingIntDelegate();
        BenchmarkComponent::WrappedClass GetNewSealedObject();
        BenchmarkComponent::WrappedClass GetExistingSealedObject();
        BenchmarkComponent::ClassWithFastAbi GetNewUnsealedObject();
        BenchmarkComponent::ClassWithFastAbi GetExistingUnsealedObject();
        BenchmarkComponent::ClassWithFastAbi GetNewDerivedAsBase();

        void GetWeakReference(Windows::Foundation::IInspectable obj);
        Windows::Foundation::IInspectable GetAndResolveWeakReference(Windows::Foundation::IInspectable obj);
    };

    struct EventOperations : EventOperationsT<EventOperations>
    {
    private:
        BenchmarkComponent::IEvents events;
        int32_t intVal;
        double_t doubleVal;
        winrt::event_token intEventToken;
        winrt::event_token doubleEventToken;

    public:
        EventOperations() = default;

        EventOperations(BenchmarkComponent::IEvents const& instance);
        void AddIntEvent();
        void AddDoubleEvent();
        void RemoveIntEvent();
        void RemoveDoubleEvent();
        void FireIntEvent();
        void FireDoubleEvent();
    };

    struct ClassWithAsync : ClassWithAsyncT<ClassWithAsync>
    {
    public:
        ClassWithAsync() = default;

        Windows::Foundation::IAsyncAction Complete();
        Windows::Foundation::IAsyncAction YieldComplete();
        Windows::Foundation::IAsyncOperation<int32_t> Return(int32_t value);
        Windows::Foundation::IAsyncOperation<int32_t> YieldReturn(int32_t value);
    };

    struct Composable : ComposableT<Composable>
    {
        Composable() = default;

        bool BoolProperty();
        void BoolProperty(bool val);
    };

    struct ClassWithFastAbi : ClassWithFastAbiT<ClassWithFastAbi>
    {
        ClassWithFastAbi() = default;
        ClassWithFastAbi(int32_t value);
        int32_t DefaultIntProperty();
        int32_t NonDefaultIntProperty();
        void DefaultVoidMethod();
        int32_t DefaultIntMethod(int32_t value);
        void NonDefaultVoidMethod();
        int32_t NonDefaultIntMethod(int32_t value);
    };

    struct ClassWithFastAbiDerived : ClassWithFastAbiDerivedT<ClassWithFastAbiDerived, implementation::ClassWithFastAbi>
    {
        ClassWithFastAbiDerived();
        ClassWithFastAbiDerived(int32_t value);
        int32_t DerivedDefaultIntProperty();
        int32_t DerivedNonDefaultIntProperty();
        void DerivedDefaultVoidMethod();
        int32_t DerivedDefaultIntMethod(int32_t value);
        void DerivedNonDefaultVoidMethod();
        int32_t DerivedNonDefaultIntMethod(int32_t value);
    };

    struct NonAgileClassWithMultipleInterfaces : NonAgileClassWithMultipleInterfacesT<NonAgileClassWithMultipleInterfaces, winrt::non_agile>
    {
        NonAgileClassWithMultipleInterfaces() = default;

        int32_t IntProperty();
        void IntProperty(int32_t value);
        void VoidMethod();
        int32_t IntMethod(int32_t value);
        bool BoolProperty();
        void BoolProperty(bool value);
        double DoubleProperty();
        void DoubleProperty(double value);
        int32_t DefaultIntProperty();
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

    struct EventOperations : EventOperationsT<EventOperations, implementation::EventOperations>
    {
    };

    struct Composable : ComposableT<Composable, implementation::Composable>
    {
    };

    struct ClassWithFastAbi : ClassWithFastAbiT<ClassWithFastAbi, implementation::ClassWithFastAbi>
    {
    };

    struct ClassWithFastAbiDerived : ClassWithFastAbiDerivedT<ClassWithFastAbiDerived, implementation::ClassWithFastAbiDerived>
    {
    };

    struct NonAgileClassWithMultipleInterfaces : NonAgileClassWithMultipleInterfacesT<NonAgileClassWithMultipleInterfaces, implementation::NonAgileClassWithMultipleInterfaces>
    {
    };

    struct ClassWithAsync : ClassWithAsyncT<ClassWithAsync, implementation::ClassWithAsync>
    {
    };
}
