#pragma once

#include "ClassWithMultipleInterfaces.g.h"

namespace winrt::BenchmarkComponent::implementation
{
    struct ClassWithMultipleInterfaces : ClassWithMultipleInterfacesT<ClassWithMultipleInterfaces>
    {
        ClassWithMultipleInterfaces();

        int32_t IntProperty1();
        void IntProperty1(int32_t val);

        bool BoolProperty1();
        void BoolProperty1(bool val);

        double DoubleProperty1();
        void DoubleProperty1(double val);

        int32_t IntProperty();
        bool BoolProperty();
        double DoubleProperty();
        void IntProperty(int32_t val);
        void BoolProperty(bool val);
        void DoubleProperty(double val);
    };
}

namespace winrt::BenchmarkComponent::factory_implementation
{
    struct ClassWithMultipleInterfaces : ClassWithMultipleInterfacesT<ClassWithMultipleInterfaces, implementation::ClassWithMultipleInterfaces>
    {
    };
}
