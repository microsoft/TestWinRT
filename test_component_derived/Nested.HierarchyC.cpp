#include "pch.h"
#include "Nested.HierarchyC.h"
#include "Nested.HierarchyE.h"
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
        return winrt::test_component_derived::Nested::HierarchyD();
    }

    Windows::Foundation::IInspectable HierarchyC::CreateDerivedHierarchyDAsObject()
    {
        return winrt::test_component_derived::Nested::HierarchyD();
    }

    winrt::test_component_base::HierarchyB HierarchyC::CreateNonProjectedDerivedHierarchyEAsHierarchyB()
    {
        return make<test_component_derived::Nested::implementation::HierarchyE>();
    }

    winrt::test_component_derived::Nested::HierarchyC HierarchyC::CreateNonProjectedDerivedHierarchyEAsHierarchyC()
    {
        return make<test_component_derived::Nested::implementation::HierarchyE>();
    }

    Windows::Foundation::Collections::IVector<winrt::test_component_derived::Nested::HierarchyC> HierarchyC::CreateDerivedHierarchyDList()
    {
        Windows::Foundation::Collections::IVector<winrt::test_component_derived::Nested::HierarchyC> list = 
            single_threaded_vector<winrt::test_component_derived::Nested::HierarchyC>({ 
                winrt::test_component_derived::Nested::HierarchyD(),
                winrt::test_component_derived::Nested::HierarchyD(),
                winrt::test_component_derived::Nested::HierarchyD()
            });
        return list;
    }

    Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> HierarchyC::CreateDerivedHierarchyDAsObjectList()
    {
        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> list =
            single_threaded_vector<Windows::Foundation::IInspectable>({ 
                winrt::test_component_derived::Nested::HierarchyD(),
                winrt::test_component_derived::Nested::HierarchyD(),
                winrt::test_component_derived::Nested::HierarchyD() 
            });
        return list;
    }
}
