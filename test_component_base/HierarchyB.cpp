#include "pch.h"
#include "HierarchyB.h"
#include "HierarchyB.g.cpp"

namespace winrt::test_component_base::implementation
{
    HierarchyB::HierarchyB(hstring const& name)
    {
        throw hresult_not_implemented();
    }
    winrt::hstring HierarchyB::HierarchyA_Method()
    {
        return L"HierarchyB.HierarchyA_Method";
    }
    winrt::hstring HierarchyB::HierarchyB_Method()
    {
        return L"HierarchyB.HierarchyB_Method";
    }
}
