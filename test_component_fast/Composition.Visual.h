#pragma once
#include "Composition.Visual.g.h"
#include "Composition.CompositionObject.h"

namespace winrt::test_component_fast::Composition::implementation
{
    struct Visual : VisualT<Visual, implementation::CompositionObject>
    {
        Visual(Composition::Compositor const& compositor);

        int32_t Offset();
        void Offset(int32_t value);
        void ParentForTransform(Composition::Visual const& value);
        int32_t Pad();
        winrt::hstring Serialize(int32_t number);

    private:
        int32_t m_offset{};
    protected:
        int32_t m_pad = 10;
    };
}
