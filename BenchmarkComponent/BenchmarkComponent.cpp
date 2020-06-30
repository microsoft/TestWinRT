#include "pch.h"
#include "BenchmarkComponent.h"
#include "ClassWithMultipleInterfaces.g.cpp"

namespace winrt::BenchmarkComponent::implementation
{
    ClassWithMultipleInterfaces::ClassWithMultipleInterfaces()
    {
    }

    int32_t ClassWithMultipleInterfaces::IntProperty1()
    {
        return 1;
    }

    void ClassWithMultipleInterfaces::IntProperty1(int32_t val)
    {
    }

    bool ClassWithMultipleInterfaces::BoolProperty1()
    {
        return true;
    }

    void ClassWithMultipleInterfaces::BoolProperty1(bool val)
    {
    }

    double ClassWithMultipleInterfaces::DoubleProperty1()
    {
        return 1;
    }

    void ClassWithMultipleInterfaces::DoubleProperty1(double val)
    {
    }

    int32_t ClassWithMultipleInterfaces::IntProperty()
    {
        return 1;
    }

    bool ClassWithMultipleInterfaces::BoolProperty()
    {
        return false;
    }

    double ClassWithMultipleInterfaces::DoubleProperty()
    {
        return 1;
    }

    void ClassWithMultipleInterfaces::IntProperty(int32_t val)
    {
    }

    void ClassWithMultipleInterfaces::BoolProperty(bool val)
    {
    }

    void ClassWithMultipleInterfaces::DoubleProperty(double val)
    {
    }
}