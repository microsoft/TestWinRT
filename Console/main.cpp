#include "pch.h"
#include "..\Tests.h"

using namespace winrt;
using namespace TestComponent;

int main()
{
    try
    {
        TestRunner::TestCallee(make<Tests>());

        uint32_t percentage = TestRunner::TestCaller([](ITests const& tests)
            {
                RunTests(tests);
            });

        printf("Test passed: %d%%\n", percentage);

        percentage = TestRunner::TestCaller([](auto&&){});
        assert(percentage == 0);

        percentage = TestRunner::TestCaller([](ITests const& tests)
            {
                tests.T1_Simple();
            });

        assert(percentage > 0 && percentage < 100);
    }
    catch (hresult_error const& e)
    {
        printf("Test failed: %ls\n", e.message().c_str());
    }
}
