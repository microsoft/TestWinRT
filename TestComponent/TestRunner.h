#pragma once
#include "TestRunner.g.h"

namespace winrt::TestComponent::implementation
{
    struct TestRunner
    {
        TestRunner() = default;

        static void TestProducer(ITests const& callee);
        static uint32_t TestConsumer(TestHandler const& caller);
        static void TestSelf();
        static ITests MakeTests();
    };
}

namespace winrt::TestComponent::factory_implementation
{
    struct TestRunner : TestRunnerT<TestRunner, implementation::TestRunner>
    {
    };
}
