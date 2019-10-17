#pragma once
#include "TestRunner.g.h"

namespace winrt::TestComponent::implementation
{
    struct TestRunner
    {
        TestRunner() = default;

        static void TestCallee(ITests const& callee);
        static uint32_t TestCaller(TestHandler const& caller);
    };
}

namespace winrt::TestComponent::factory_implementation
{
    struct TestRunner : TestRunnerT<TestRunner, implementation::TestRunner>
    {
    };
}
