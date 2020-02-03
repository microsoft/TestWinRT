#include "pch.h"
#include "TestRunner.h"
#include "TestRunner.g.cpp"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

#define TEST_REQUIRE_N(type, number, expression) { if (!(expression)) throw hresult_invalid_argument(type + to_hstring(number)); }

#define TEST_REQUIRE(expression, message) { if (!(expression)) throw hresult_invalid_argument(message); }

bool pair_equal(IKeyValuePair<hstring, hstring> const& left, IKeyValuePair<hstring, hstring> const& right)
{
    return left.Key() == right.Key() && left.Value() == right.Value();
}

namespace winrt::TestComponent::implementation
{
    struct Tests : implements<Tests, ITests>
    {
    private:

        uint32_t m_counter{};
        const uint32_t m_total{ 47 };

    public:

        void abi_enter()
        {
            ++m_counter;
        }

        uint32_t Percentage() const
        {
            return m_counter * 100 / m_total;
        }

        void Simple()
        {
        }

#define TEST_GEN(number, type) \
    auto Param ## number(type const& a, type & b) \
    { \
        b = a; \
        return a; \
    }

        TEST_GEN(1, bool);
        TEST_GEN(2, uint8_t);
        TEST_GEN(3, uint16_t);
        TEST_GEN(4, uint32_t);
        TEST_GEN(5, uint64_t);
        TEST_GEN(6, int16_t);
        TEST_GEN(7, int32_t);
        TEST_GEN(8, int64_t);
        TEST_GEN(9, float);
        TEST_GEN(10, double);
        TEST_GEN(11, char16_t);
        TEST_GEN(13, Blittable);

#undef TEST_GEN

        // These are non-blittable, so we additionally validate that the out params (b) have default (zeroed) values.

        auto Param12(hstring const& a, hstring& b)
        {
            TEST_REQUIRE_N(L"Param", 12, b.empty());
            b = a;
            return a;
        }
        auto Param14(NonBlittable const& a, NonBlittable& b)
        {
            TEST_REQUIRE_N(L"Param", 14, b == NonBlittable{});
            b = a;
            return a;
        }
        auto Param15(Nested const& a, Nested& b)
        {
            TEST_REQUIRE_N(L"Param", 15, b == Nested{});
            b = a;
            return a;
        }

#define TEST_GEN(number, type, value) \
    void Param ## number ## Call(Param ## number ## Handler const& handler) \
    { \
        type const a = value; \
        type b; \
        type c = handler(a, b); \
        TEST_REQUIRE_N(L"Param", number, a == b && a == c); \
    }

        TEST_GEN(1, bool, true);
        TEST_GEN(2, uint8_t, 1);
        TEST_GEN(3, uint16_t, 2);
        TEST_GEN(4, uint32_t, 3);
        TEST_GEN(5, uint64_t, 4);
        TEST_GEN(6, int16_t, 5);
        TEST_GEN(7, int32_t, 6);
        TEST_GEN(8, int64_t, 7);
        TEST_GEN(9, float, 8.1f);
        TEST_GEN(10, double, 9.1);
        TEST_GEN(11, char16_t, L'W');
        // TODO: do these also need non-blittable out param testing?
        TEST_GEN(12, hstring, L"WinRT");
        TEST_GEN(13, Blittable, (Blittable{ false, 1, 2, 3, 4, -5, -6, -7, 8.0f, 9.0, L'X', guid_of<ITests>() }));
        TEST_GEN(14, NonBlittable, (NonBlittable{ L"WinRT", 1234 }));
        TEST_GEN(15, Nested, (Nested{ { false, 1, 2, 3, 4, -5, -6, -7, 8.0f, 9.0, L'X', guid_of<ITests>() }, { L"WinRT", 1234 } }));

#undef TEST_GEN

#define TEST_GEN(number, type) \
auto Array ## number(array_view<type const> a, array_view<type> b, com_array<type>& c) \
{ \
    TEST_REQUIRE_N(L"Array", number, a.size() == b.size()); \
    TEST_REQUIRE_N(L"Array", number, c.size() == 0); \
    std::copy(a.begin(), a.end(), b.begin()); \
    c = com_array<type>(a.begin(), a.end()); \
    return com_array<type>(a.begin(), a.end()); \
}

        TEST_GEN(1, bool);
        TEST_GEN(2, uint8_t);
        TEST_GEN(3, uint16_t);
        TEST_GEN(4, uint32_t);
        TEST_GEN(5, uint64_t);
        TEST_GEN(6, int16_t);
        TEST_GEN(7, int32_t);
        TEST_GEN(8, int64_t);
        TEST_GEN(9, float);
        TEST_GEN(10, double);
        TEST_GEN(11, char16_t);
        TEST_GEN(12, hstring);
        TEST_GEN(13, Blittable);
        TEST_GEN(14, NonBlittable);
        TEST_GEN(15, Nested);

#undef TEST_GEN

#define TEST_GEN(number, type, value) \
    void Array ## number ## Call(Array ## number ## Handler const& handler) \
    { \
        std::array<type, 3> a value; \
        std::array<type, 3> b; \
        com_array<type> c; \
        com_array<type> d = handler(a, b, c); \
        TEST_REQUIRE_N(L"Array", number, std::equal(a.begin(), a.end(), b.begin(), b.end())); \
        TEST_REQUIRE_N(L"Array", number, std::equal(a.begin(), a.end(), c.begin(), c.end())); \
        TEST_REQUIRE_N(L"Array", number, std::equal(a.begin(), a.end(), d.begin(), d.end())); \
    }

        TEST_GEN(1, bool, ({ true, false, true }));
        TEST_GEN(2, uint8_t, ({ 1, 2, 3 }));
        TEST_GEN(3, uint16_t, ({ 4, 5, 7 }));
        TEST_GEN(4, uint32_t, ({ 7, 8, 9 }));
        TEST_GEN(5, uint64_t, ({ 1, 2, 3 }));
        TEST_GEN(6, int16_t, ({ 4, 5, 7 }));
        TEST_GEN(7, int32_t, ({ 7, 8, 9 }));
        TEST_GEN(8, int64_t, ({ 1, 2, 3 }));
        TEST_GEN(9, float, ({ 1.0f, 2.0f, 3.0f }));
        TEST_GEN(10, double, ({ 4.0f, 5.0f, 6.0f }));
        TEST_GEN(11, char16_t, ({ L'W', L'i', L'n' }));
        TEST_GEN(12, hstring, ({ L"C++", L"C#", L"Rust" }));
        TEST_GEN(13, Blittable, ({ Blittable{ false, 1, 2, 3, 4, -5, -6, -7, 8.0f, 9.0, L'X', guid_of<ITests>() }, Blittable{ true, 10, 20, 30, 40, -50, -60, -70, 80.0f, 90.0, L'Y', guid_of<IStringable>() }, Blittable{ false, 1, 2, 3, 4, -5, -6, -7, 8.0f, 9.0, L'Z', guid_of<IInspectable>() } }));
        TEST_GEN(14, NonBlittable, ({ NonBlittable{ L"First", 123 }, NonBlittable{ L"Second", 456 }, NonBlittable{ L"Third", 789 } }));
        TEST_GEN(15, Nested, ({ Nested{ { false, 1, 2, 3, 4, -5, -6, -7, 8.0f, 9.0, L'X', guid_of<ITests>() }, { L"First", 123 } }, Nested{ { true, 10, 20, 30, 40, -50, -60, -70, 80.0f, 90.0, L'Y', guid_of<IStringable>() }, { L"Second", 456 } }, Nested{ { false, 1, 2, 3, 4, -5, -6, -7, 8.0f, 9.0, L'Z', guid_of<IInspectable>() }, { L"Third", 789 } } }));

#undef TEST_GEN

        auto Collection1(IIterable<hstring> const& a, IIterable<hstring>& b)
        {
            b = single_threaded_vector(std::vector<hstring>{ begin(a), end(a) });
            return b;
        }
        auto Collection2(IIterable<IKeyValuePair<hstring, hstring>> const& a, IIterable<IKeyValuePair<hstring, hstring>>& b)
        {
            std::map<hstring, hstring> copy;

            for (auto&& pair : a)
            {
                copy[pair.Key()] = pair.Value();
            }

            b = single_threaded_map(std::move(copy));
            return b;
        }
        auto Collection3(IMap<hstring, hstring> const& a, IMap<hstring, hstring>& b)
        {
            std::map<hstring, hstring> copy;

            for (auto&& pair : a)
            {
                copy[pair.Key()] = pair.Value();
            }

            b = single_threaded_map(std::move(copy));
            return b;
        }
        auto Collection4(IMapView<hstring, hstring> const& a, IMapView<hstring, hstring>& b)
        {
            std::map<hstring, hstring> copy;

            for (auto&& pair : a)
            {
                copy[pair.Key()] = pair.Value();
            }

            b = single_threaded_map(std::move(copy)).GetView();
            return b;
        }
        auto Collection5(IVector<hstring> const& a, IVector<hstring>& b)
        {
            b = single_threaded_vector(std::vector<hstring>{ begin(a), end(a) });
            return b;
        }

        auto Collection6(IVectorView<hstring> const& a, IVectorView<hstring>& b)
        {
            b = single_threaded_vector(std::vector<hstring>{ begin(a), end(a) }).GetView();
            return b;
        }

        IAsyncAction Async1(IAsyncAction suspend, bool fail)
        {
            co_await suspend;

            if (fail)
            {
                throw hresult_invalid_argument(L"test");
            }
        }
        IAsyncActionWithProgress<int32_t> Async2(IAsyncAction suspend, bool fail, int32_t progress)
        {
            co_await suspend;
            auto callback = co_await get_progress_token();
            callback(progress);

            if (fail)
            {
                throw hresult_invalid_argument(L"test");
            }
        }
        IAsyncOperation<int32_t> Async3(IAsyncAction suspend, bool fail, int32_t result)
        {
            co_await suspend;

            if (fail)
            {
                throw hresult_invalid_argument(L"test");
            }

            co_return result;
        }
        IAsyncOperationWithProgress<int32_t, int32_t> Async4(IAsyncAction suspend, bool fail, int32_t result, int32_t progress)
        {
            co_await suspend;
            auto callback = co_await get_progress_token();
            callback(progress);

            if (fail)
            {
                throw hresult_invalid_argument(L"test");
            }

            co_return result;
        }
    };

    IAsyncAction SignalAsync(HANDLE event)
    {
        co_await resume_on_signal(event);
    }

    IAsyncAction NoAsync()
    {
        co_return;
    }

    auto auto_event()
    {
        return handle{ CreateEvent(nullptr, false, false, nullptr) };
    }

    void RunTests(ITests const& tests)
    {
        tests.Simple();

#define TEST_GEN(number, type) \
    tests.Param ## number ## Call([&](type const& a, type& b) { return tests.Param ## number(a, b); });

        TEST_GEN(1, bool);
        TEST_GEN(2, uint8_t);
        TEST_GEN(3, uint16_t);
        TEST_GEN(4, uint32_t);
        TEST_GEN(5, uint64_t);
        TEST_GEN(6, int16_t);
        TEST_GEN(7, int32_t);
        TEST_GEN(8, int64_t);
        TEST_GEN(9, float);
        TEST_GEN(10, double);
        TEST_GEN(11, char16_t);
        TEST_GEN(12, hstring);
        TEST_GEN(13, Blittable);
        TEST_GEN(14, NonBlittable);
        TEST_GEN(15, Nested);

#undef TEST_GEN

        //{
        //    IIterable<hstring> a = single_threaded_vector<hstring>({ L"apples",L"oranges",L"pears" });
        //    IIterable<hstring> b;
        //    IIterable<hstring> c = tests.Collection1(a, b);
        //    TEST_REQUIRE(L"Collection1", a != b && a != c);
        //    TEST_REQUIRE(L"Collection1", std::equal(begin(a), end(a), begin(b), end(b)));
        //    TEST_REQUIRE(L"Collection1", std::equal(begin(a), end(a), begin(c), end(c)));
        //}
        //{
        //    IIterable<IKeyValuePair<hstring, hstring>> a = single_threaded_map<hstring, hstring>(std::map<hstring,hstring>{ {L"apples", L"1"},{L"oranges",L"2"},{L"pears",L"3"} });
        //    IIterable<IKeyValuePair<hstring, hstring>> b;
        //    IIterable<IKeyValuePair<hstring, hstring>> c = tests.Collection2(a, b);
        //    TEST_REQUIRE(L"Collection2", a != b && a != c);
        //    TEST_REQUIRE(L"Collection2", std::equal(begin(a), end(a), begin(b), end(b), pair_equal));
        //    TEST_REQUIRE(L"Collection2", std::equal(begin(a), end(a), begin(c), end(c), pair_equal));
        //}
        //{
        //    IMap<hstring, hstring> a = single_threaded_map<hstring, hstring>(std::map<hstring, hstring>{ {L"apples", L"1"}, { L"oranges",L"2" }, { L"pears",L"3" } });
        //    IMap<hstring, hstring> b;
        //    IMap<hstring, hstring> c = tests.Collection3(a, b);
        //    TEST_REQUIRE(L"Collection3", a != b && a != c);
        //    TEST_REQUIRE(L"Collection3", std::equal(begin(a), end(a), begin(b), end(b), pair_equal));
        //    TEST_REQUIRE(L"Collection3", std::equal(begin(a), end(a), begin(c), end(c), pair_equal));
        //}
        //{
        //    IMapView<hstring, hstring> a = single_threaded_map<hstring, hstring>(std::map<hstring, hstring>{ {L"apples", L"1"}, { L"oranges",L"2" }, { L"pears",L"3" } }).GetView();
        //    IMapView<hstring, hstring> b;
        //    IMapView<hstring, hstring> c = tests.Collection4(a, b);
        //    TEST_REQUIRE(L"Collection4", a != b && a != c);
        //    TEST_REQUIRE(L"Collection4", std::equal(begin(a), end(a), begin(b), end(b), pair_equal));
        //    TEST_REQUIRE(L"Collection4", std::equal(begin(a), end(a), begin(c), end(c), pair_equal));
        //}
        //{
        //    IVector<hstring> a = single_threaded_vector<hstring>({ L"apples",L"oranges",L"pears" });
        //    IVector<hstring> b;
        //    IVector<hstring> c = tests.Collection5(a, b);
        //    TEST_REQUIRE(L"Collection5", a != b && a != c);
        //    TEST_REQUIRE(L"Collection5", std::equal(begin(a), end(a), begin(b), end(b)));
        //    TEST_REQUIRE(L"Collection5", std::equal(begin(a), end(a), begin(c), end(c)));
        //}

        //{
        //    IVectorView<hstring> a = single_threaded_vector<hstring>({ L"apples",L"oranges",L"pears" }).GetView();
        //    IVectorView<hstring> b;
        //    IVectorView<hstring> c = tests.Collection6(a, b);
        //    TEST_REQUIRE(L"Collection6", a != b && a != c);
        //    TEST_REQUIRE(L"Collection6", std::equal(begin(a), end(a), begin(b), end(b)));
        //    TEST_REQUIRE(L"Collection6", std::equal(begin(a), end(a), begin(c), end(c)));
        //}

        //{
        //    TEST_REQUIRE(L"Async1", tests.Async1(NoAsync(), false).Status() == AsyncStatus::Completed);
        //}
        //{
        //    auto signal = auto_event();
        //    auto async = tests.Async1(SignalAsync(signal.get()), false);
        //    TEST_REQUIRE(L"Async1", async.Status() == AsyncStatus::Started);
        //    SetEvent(signal.get());
        //    async.get();
        //}
        //{
        //    auto signal = auto_event();
        //    auto async = tests.Async1(SignalAsync(signal.get()), true);
        //    TEST_REQUIRE(L"Async1", async.Status() == AsyncStatus::Started);
        //    SetEvent(signal.get());
        //    try
        //    {
        //        async.get();
        //        TEST_REQUIRE(L"Async1", false);
        //    }
        //    catch (hresult_invalid_argument const& e)
        //    {
        //        TEST_REQUIRE(L"Async1", e.message() == L"test");
        //    }
        //}

        //{
        //    TEST_REQUIRE(L"Async2", tests.Async2(NoAsync(), false, 321).Status() == AsyncStatus::Completed);
        //}
        //{
        //    auto signal = auto_event();
        //    auto async = tests.Async2(SignalAsync(signal.get()), false, 321);
        //    TEST_REQUIRE(L"Async2", async.Status() == AsyncStatus::Started);
        //    int32_t progress{};
        //    async.Progress([&](auto&&, int32_t args)
        //        {
        //            progress = args;
        //        });
        //    SetEvent(signal.get());
        //    async.get();
        //    TEST_REQUIRE(L"Async2", progress == 321);
        //}
        //{
        //    auto signal = auto_event();
        //    auto async = tests.Async2(SignalAsync(signal.get()), true, 321);
        //    TEST_REQUIRE(L"Async2", async.Status() == AsyncStatus::Started);
        //    int32_t progress{};
        //    async.Progress([&](auto&&, int32_t args)
        //        {
        //            progress = args;
        //        });
        //    SetEvent(signal.get());
        //    try
        //    {
        //        async.get();
        //        TEST_REQUIRE(L"Async2", false);
        //    }
        //    catch (hresult_invalid_argument const& e)
        //    {
        //        TEST_REQUIRE(L"Async2", e.message() == L"test");
        //    }
        //    TEST_REQUIRE(L"Async2", progress == 321);
        //}

        //{
        //    auto async = tests.Async3(NoAsync(), false, 123);
        //    TEST_REQUIRE(L"Async3", async.Status() == AsyncStatus::Completed);
        //    TEST_REQUIRE(L"Async3", async.get() == 123);
        //}
        //{
        //    auto signal = auto_event();
        //    auto async = tests.Async3(SignalAsync(signal.get()), false, 123);
        //    TEST_REQUIRE(L"Async3", async.Status() == AsyncStatus::Started);
        //    SetEvent(signal.get());
        //    TEST_REQUIRE(L"Async3", async.get() == 123);
        //}
        //{
        //    auto signal = auto_event();
        //    auto async = tests.Async3(SignalAsync(signal.get()), true, 123);
        //    TEST_REQUIRE(L"Async3", async.Status() == AsyncStatus::Started);
        //    SetEvent(signal.get());
        //    try
        //    {
        //        async.get();
        //        TEST_REQUIRE(L"Async3", false);
        //    }
        //    catch (hresult_invalid_argument const& e)
        //    {
        //        TEST_REQUIRE(L"Async3", e.message() == L"test");
        //    }
        //}

        //{
        //    auto async = tests.Async4(NoAsync(), false, 123, 321);
        //    TEST_REQUIRE(L"Async4", async.Status() == AsyncStatus::Completed);
        //    TEST_REQUIRE(L"Async4", async.get() == 123);
        //}
        //{
        //    auto signal = auto_event();
        //    auto async = tests.Async4(SignalAsync(signal.get()), false, 123, 321);
        //    TEST_REQUIRE(L"Async4", async.Status() == AsyncStatus::Started);
        //    int32_t progress{};
        //    async.Progress([&](auto&&, int32_t args)
        //        {
        //            progress = args;
        //        });
        //    SetEvent(signal.get());
        //    TEST_REQUIRE(L"Async4", async.get() == 123);
        //    TEST_REQUIRE(L"Async4", progress == 321);
        //}
        //{
        //    auto signal = auto_event();
        //    auto async = tests.Async4(SignalAsync(signal.get()), true, 123, 321);
        //    TEST_REQUIRE(L"Async4", async.Status() == AsyncStatus::Started);
        //    int32_t progress{};
        //    async.Progress([&](auto&&, int32_t args)
        //        {
        //            progress = args;
        //        });
        //    SetEvent(signal.get());
        //    try
        //    {
        //        async.get();
        //        TEST_REQUIRE(L"Async4", false);
        //    }
        //    catch (hresult_invalid_argument const& e)
        //    {
        //        TEST_REQUIRE(L"Async4", e.message() == L"test");
        //    }
        //    TEST_REQUIRE(L"Async4", progress == 321);
        //}
    }

    void TestRunner::TestProducer(ITests const& tests)
    {
        RunTests(tests);
    }

    uint32_t TestRunner::TestConsumer(TestHandler const& caller)
    {
        auto tests = make_self<Tests>();
        caller(*tests);
        return tests->Percentage();
    }

    void TestRunner::TestSelf()
    {
        TestRunner::TestProducer(make<Tests>());

        uint32_t percentage = TestRunner::TestConsumer([](ITests const& tests)
            {
                RunTests(tests);
            });

        TEST_REQUIRE(percentage == 100, L"Test cover is " + to_hstring(percentage) + L"%");
        percentage = TestRunner::TestConsumer([](auto&&) {});
        TEST_REQUIRE(percentage == 0, L"TestSelf");

        percentage = TestRunner::TestConsumer([](ITests const& tests)
            {
                tests.Simple();
            });

        TEST_REQUIRE(percentage > 0 && percentage < 100, L"TestSelf");
    }
}
