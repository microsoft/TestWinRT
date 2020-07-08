#pragma once
#include "Composable.g.h"

namespace winrt::TestComponent::implementation
{
    struct Composable : ComposableT<Composable>
    {
        Composable() = default;

        Composable(int32_t init);
        int32_t Value();

        int32_t m_value{};
    };
}

namespace winrt::TestComponent::factory_implementation
{
    struct Composable : ComposableT<Composable, implementation::Composable>
    {
    };
}
