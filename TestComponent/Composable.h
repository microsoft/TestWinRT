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

        int32_t One();
        int32_t Two();
        int32_t Three();
        int32_t Four();
    };
}

namespace winrt::TestComponent::factory_implementation
{
    struct Composable : ComposableT<Composable, implementation::Composable>
    {
    };
}
