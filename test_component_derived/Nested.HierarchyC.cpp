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
}
