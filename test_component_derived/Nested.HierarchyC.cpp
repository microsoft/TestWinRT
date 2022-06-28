#include "pch.h"
#include "Nested.HierarchyC.h"
#include "Nested.HierarchyC.g.cpp"

namespace winrt::test_component_derived::Nested::implementation
{
    HierarchyC::HierarchyC(hstring const& name)
    {
        throw hresult_not_implemented();
    }

    winrt::hstring HierarchyC::HierarchyB_Method()
    {
        return L"HierarchyC.HierarchyB_Method";
    }

    winrt::hstring HierarchyC::HierarchyC_Method()
    {
        return L"HierarchyC.HierarchyC_Method";
    }

    winrt::test_component_derived::Nested::HierarchyC HierarchyC::CreateDerivedHierarchyD()
    {
        return HierarchyD();
    }

    Windows::Foundation::IInspectable HierarchyC::CreateDerivedHierarchyDAsObject()
    {
        return HierarchyD();
    }

    Windows::Foundation::Collections::IVector<winrt::test_component_derived::Nested::HierarchyC> HierarchyC::CreateDerivedHierarchyDList()
    {
        Windows::Foundation::Collections::IVector<winrt::test_component_derived::Nested::HierarchyC> list = 
            single_threaded_vector<winrt::test_component_derived::Nested::HierarchyC>({ HierarchyD(), HierarchyD(), HierarchyD() });
        return list;
    }

    Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> HierarchyC::CreateDerivedHierarchyDAsObjectList()
    {
        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> list =
            single_threaded_vector<Windows::Foundation::IInspectable>({ HierarchyD(), HierarchyD(), HierarchyD() });
        return list;
    }
}
