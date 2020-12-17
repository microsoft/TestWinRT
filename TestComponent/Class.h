#pragma once
#include "Class.g.h"

namespace winrt::TestComponent::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        int32_t One();
    };
}

namespace winrt::TestComponent::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
