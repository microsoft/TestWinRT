#include "pch.h"
#include "TestRunner.h"
#include "TestRunner.g.cpp"

#define TEST_REQUIRE(test, expression) { if (!(expression)) throw winrt::hresult_invalid_argument(test); }

namespace winrt::TestComponent::implementation
{
    using namespace Windows::Foundation;
    using namespace Windows::Foundation::Collections;

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

        auto Param1(bool a, bool& b)
        {
            b = a;
            return a;
        }
        void Param1Call(Param1Handler const& handler)
        {
            bool const a = true;
            bool b;
            bool c = handler(a, b);
            TEST_REQUIRE(L"Param1", b && c);
        }

        auto Param2(uint8_t a, uint8_t& b)
        {
            b = a;
            return a;
        }
        auto Param3(uint16_t a, uint16_t& b)
        {
            b = a;
            return a;
        }
        auto Param4(uint32_t a, uint32_t& b)
        {
            b = a;
            return a;
        }
        auto Param5(uint64_t a, uint64_t& b)
        {
            b = a;
            return a;
        }
        auto Param6(int16_t a, int16_t& b)
        {
            b = a;
            return a;
        }
        auto Param7(int32_t a, int32_t& b)
        {
            b = a;
            return a;
        }
        auto Param8(int64_t a, int64_t& b)
        {
            b = a;
            return a;
        }
        auto Param9(float a, float& b)
        {
            b = a;
            return a;
        }
        auto Param10(double a, double& b)
        {
            b = a;
            return a;
        }
        auto Param11(char16_t a, char16_t& b)
        {
            b = a;
            return a;
        }
        auto Param12(hstring const& a, hstring& b)
        {
            TEST_REQUIRE(L"Param12", b.empty());
            b = a;
            return a;
        }

        auto Param13(Blittable const& a, Blittable& b)
        {
            b = a;
            return a;
        }

        auto Param14(NonBlittable const& a, NonBlittable& b)
        {
            TEST_REQUIRE(L"Param14", b == NonBlittable{});
            b = a;
            return a;
        }

        auto Param15(Nested const& a, Nested& b)
        {
            TEST_REQUIRE(L"Param15", b == Nested{});
            b = a;
            return a;
        }

        auto Array1(array_view<bool const> a, array_view<bool> b, com_array<bool>& c)
        {
            TEST_REQUIRE(L"Array1", a.size() == b.size());
            TEST_REQUIRE(L"Array1", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<bool>(a.begin(), a.end());
            return com_array<bool>(a.begin(), a.end());
        }

        auto Array2(array_view<uint8_t const> a, array_view<uint8_t> b, com_array<uint8_t>& c)
        {
            TEST_REQUIRE(L"Array2", a.size() == b.size());
            TEST_REQUIRE(L"Array2", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<uint8_t>(a.begin(), a.end());
            return com_array<uint8_t>(a.begin(), a.end());
        }
        auto Array3(array_view<uint16_t const> a, array_view<uint16_t> b, com_array<uint16_t>& c)
        {
            TEST_REQUIRE(L"Array3", a.size() == b.size());
            TEST_REQUIRE(L"Array3", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<uint16_t>(a.begin(), a.end());
            return com_array<uint16_t>(a.begin(), a.end());
        }
        auto Array4(array_view<uint32_t const> a, array_view<uint32_t> b, com_array<uint32_t>& c)
        {
            TEST_REQUIRE(L"Array4", a.size() == b.size());
            TEST_REQUIRE(L"Array4", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<uint32_t>(a.begin(), a.end());
            return com_array<uint32_t>(a.begin(), a.end());
        }
        auto Array5(array_view<uint64_t const> a, array_view<uint64_t> b, com_array<uint64_t>& c)
        {
            TEST_REQUIRE(L"Array5", a.size() == b.size());
            TEST_REQUIRE(L"Array5", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<uint64_t>(a.begin(), a.end());
            return com_array<uint64_t>(a.begin(), a.end());
        }
        auto Array6(array_view<int16_t const> a, array_view<int16_t> b, com_array<int16_t>& c)
        {
            TEST_REQUIRE(L"Array6", a.size() == b.size());
            TEST_REQUIRE(L"Array6", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<int16_t>(a.begin(), a.end());
            return com_array<int16_t>(a.begin(), a.end());
        }
        auto Array7(array_view<int32_t const> a, array_view<int32_t> b, com_array<int32_t>& c)
        {
            TEST_REQUIRE(L"Array7", a.size() == b.size());
            TEST_REQUIRE(L"Array7", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<int32_t>(a.begin(), a.end());
            return com_array<int32_t>(a.begin(), a.end());
        }
        auto Array8(array_view<int64_t const> a, array_view<int64_t> b, com_array<int64_t>& c)
        {
            TEST_REQUIRE(L"Array8", a.size() == b.size());
            TEST_REQUIRE(L"Array8", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<int64_t>(a.begin(), a.end());
            return com_array<int64_t>(a.begin(), a.end());
        }
        auto Array9(array_view<float const> a, array_view<float> b, com_array<float>& c)
        {
            TEST_REQUIRE(L"Array9", a.size() == b.size());
            TEST_REQUIRE(L"Array9", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<float>(a.begin(), a.end());
            return com_array<float>(a.begin(), a.end());
        }
        auto Array10(array_view<double const> a, array_view<double> b, com_array<double>& c)
        {
            TEST_REQUIRE(L"Array10", a.size() == b.size());
            TEST_REQUIRE(L"Array10", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<double>(a.begin(), a.end());
            return com_array<double>(a.begin(), a.end());
        }
        auto Array11(array_view<char16_t const> a, array_view<char16_t> b, com_array<char16_t>& c)
        {
            TEST_REQUIRE(L"Array11", a.size() == b.size());
            TEST_REQUIRE(L"Array11", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<char16_t>(a.begin(), a.end());
            return com_array<char16_t>(a.begin(), a.end());
        }
        auto Array12(array_view<hstring const> a, array_view<hstring> b, com_array<hstring>& c)
        {
            TEST_REQUIRE(L"Array12", a.size() == b.size());
            TEST_REQUIRE(L"Array12", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<hstring>(a.begin(), a.end());
            return com_array<hstring>(a.begin(), a.end());
        }
        auto Array13(array_view<Blittable const> a, array_view<Blittable> b, com_array<Blittable>& c)
        {
            TEST_REQUIRE(L"Array13", a.size() == b.size());
            TEST_REQUIRE(L"Array13", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<Blittable>(a.begin(), a.end());
            return com_array<Blittable>(a.begin(), a.end());
        }
        auto Array14(array_view<NonBlittable const> a, array_view<NonBlittable> b, com_array<NonBlittable>& c)
        {
            TEST_REQUIRE(L"Array14", a.size() == b.size());
            TEST_REQUIRE(L"Array14", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<NonBlittable>(a.begin(), a.end());
            return com_array<NonBlittable>(a.begin(), a.end());
        }
        auto Array15(array_view<Nested const> a, array_view<Nested> b, com_array<Nested>& c)
        {
            TEST_REQUIRE(L"Array15", a.size() == b.size());
            TEST_REQUIRE(L"Array15", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<Nested>(a.begin(), a.end());
            return com_array<Nested>(a.begin(), a.end());
        }

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

    template <typename T>
    bool operator==(std::array<T, 3> const& left, com_array<T> const& right)
    {
        return std::equal(left.begin(), left.end(), right.begin(), right.end());
    }

    bool pair_equal(IKeyValuePair<hstring, hstring> const& left, IKeyValuePair<hstring, hstring> const& right)
    {
        return left.Key() == right.Key() && left.Value() == right.Value();
    }

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

        {
            tests.Param1Call([&](bool a, bool& b)
                {
                    return tests.Param1(a, b);
                });
        }
        {
            uint8_t a = 123;
            uint8_t b;
            uint8_t c = tests.Param2(a, b);
            TEST_REQUIRE(L"Param2", a == b && a == c);
        }
        {
            uint16_t a = 123;
            uint16_t b;
            uint16_t c = tests.Param3(a, b);
            TEST_REQUIRE(L"Param3", a == b && a == c);
        }
        {
            uint32_t a = 123;
            uint32_t b;
            uint32_t c = tests.Param4(a, b);
            TEST_REQUIRE(L"Param4", a == b && a == c);
        }
        {
            uint64_t a = 123;
            uint64_t b;
            uint64_t c = tests.Param5(a, b);
            TEST_REQUIRE(L"Param5", a == b && a == c);
        }
        {
            int16_t a = 123;
            int16_t b;
            int16_t c = tests.Param6(a, b);
            TEST_REQUIRE(L"Param6", a == b && a == c);
        }
        {
            int32_t a = 123;
            int32_t b;
            int32_t c = tests.Param7(a, b);
            TEST_REQUIRE(L"Param7", a == b && a == c);
        }
        {
            int64_t a = 123;
            int64_t b;
            int64_t c = tests.Param8(a, b);
            TEST_REQUIRE(L"Param8", a == b && a == c);
        }
        {
            float a = 12.3f;
            float b;
            float c = tests.Param9(a, b);
            TEST_REQUIRE(L"Param9", a == b && a == c);
        }
        {
            double a = 12.3;
            double b;
            double c = tests.Param10(a, b);
            TEST_REQUIRE(L"Param10", a == b && a == c);
        }
        {
            char16_t a = L'W';
            char16_t b;
            char16_t c = tests.Param11(a, b);
            TEST_REQUIRE(L"Param11", a == b && a == c);
        }
        {
            hstring a = L"WinRT";
            hstring b;
            hstring c = tests.Param12(a, b);
            TEST_REQUIRE(L"Param12", a == b && a == c);
        }
        {
            Blittable a{ false, 1, 2, 3, 4, -5, -6, -7, 8.0f, 9.0, L'X', guid_of<ITests>() };
            Blittable b;
            Blittable c = tests.Param13(a, b);
            TEST_REQUIRE(L"Param13", a == b && a == c);
        }
        {
            NonBlittable a{ L"WinRT", 1234 };
            NonBlittable b;
            NonBlittable c = tests.Param14(a, b);
            TEST_REQUIRE(L"Param14", a == b && a == c);
        }
        {
            Nested a{ { false, 1, 2, 3, 4, -5, -6, -7, 8.0f, 9.0, L'X', guid_of<ITests>() }, { L"WinRT", 1234 } };
            Nested b;
            Nested c = tests.Param15(a, b);
            TEST_REQUIRE(L"Param15", a == b && a == c);
        }

        {
            std::array<bool, 3> a{ true,false,true };
            std::array<bool, 3> b;
            com_array<bool> c;
            com_array<bool> d = tests.Array1(a, b, c);
            TEST_REQUIRE(L"Array1", a == b && a == c && c == d);
        }
        {
            std::array<uint8_t, 3> a{ 1,2,3 };
            std::array<uint8_t, 3> b;
            com_array<uint8_t> c;
            com_array<uint8_t> d = tests.Array2(a, b, c);
            TEST_REQUIRE(L"Array2", a == b && a == c && c == d);
        }
        {
            std::array<uint16_t, 3> a{ 1,2,3 };
            std::array<uint16_t, 3> b;
            com_array<uint16_t> c;
            com_array<uint16_t> d = tests.Array3(a, b, c);
            TEST_REQUIRE(L"Array3", a == b && a == c && c == d);
        }
        {
            std::array<uint32_t, 3> a{ 1,2,3 };
            std::array<uint32_t, 3> b;
            com_array<uint32_t> c;
            com_array<uint32_t> d = tests.Array4(a, b, c);
            TEST_REQUIRE(L"Array4", a == b && a == c && c == d);
        }
        {
            std::array<uint64_t, 3> a{ 1,2,3 };
            std::array<uint64_t, 3> b;
            com_array<uint64_t> c;
            com_array<uint64_t> d = tests.Array5(a, b, c);
            TEST_REQUIRE(L"Array5", a == b && a == c && c == d);
        }
        {
            std::array<int16_t, 3> a{ 1,2,3 };
            std::array<int16_t, 3> b;
            com_array<int16_t> c;
            com_array<int16_t> d = tests.Array6(a, b, c);
            TEST_REQUIRE(L"Array6", a == b && a == c && c == d);
        }
        {
            std::array<int32_t, 3> a{ 1,2,3 };
            std::array<int32_t, 3> b;
            com_array<int32_t> c;
            com_array<int32_t> d = tests.Array7(a, b, c);
            TEST_REQUIRE(L"Array7", a == b && a == c && c == d);
        }
        {
            std::array<int64_t, 3> a{ 1,2,3 };
            std::array<int64_t, 3> b;
            com_array<int64_t> c;
            com_array<int64_t> d = tests.Array8(a, b, c);
            TEST_REQUIRE(L"Array8", a == b && a == c && c == d);
        }
        {
            std::array<float, 3> a{ 1.0f,2.0f,3.0f };
            std::array<float, 3> b;
            com_array<float> c;
            com_array<float> d = tests.Array9(a, b, c);
            TEST_REQUIRE(L"Array9", a == b && a == c && c == d);
        }
        {
            std::array<double, 3> a{ 1.0,2.0,3.0 };
            std::array<double, 3> b;
            com_array<double> c;
            com_array<double> d = tests.Array10(a, b, c);
            TEST_REQUIRE(L"Array10", a == b && a == c && c == d);
        }
        {
            std::array<char16_t, 3> a{ L'a',L'b',L'c' };
            std::array<char16_t, 3> b;
            com_array<char16_t> c;
            com_array<char16_t> d = tests.Array11(a, b, c);
            TEST_REQUIRE(L"Array11", a == b && a == c && c == d);
        }
        {
            std::array<hstring, 3> a{ L"apples",L"oranges",L"pears" };
            std::array<hstring, 3> b;
            com_array<hstring> c;
            com_array<hstring> d = tests.Array12(a, b, c);
            TEST_REQUIRE(L"Array12", a == b && a == c && c == d);
        }

        {
            IIterable<hstring> a = single_threaded_vector<hstring>({ L"apples",L"oranges",L"pears" });
            IIterable<hstring> b;
            IIterable<hstring> c = tests.Collection1(a, b);
            TEST_REQUIRE(L"Collection1", a != b && a != c);
            TEST_REQUIRE(L"Collection1", std::equal(begin(a), end(a), begin(b), end(b)));
            TEST_REQUIRE(L"Collection1", std::equal(begin(a), end(a), begin(c), end(c)));
        }
        {
            IIterable<IKeyValuePair<hstring, hstring>> a = single_threaded_map<hstring, hstring>(std::map<hstring,hstring>{ {L"apples", L"1"},{L"oranges",L"2"},{L"pears",L"3"} });
            IIterable<IKeyValuePair<hstring, hstring>> b;
            IIterable<IKeyValuePair<hstring, hstring>> c = tests.Collection2(a, b);
            TEST_REQUIRE(L"Collection2", a != b && a != c);
            TEST_REQUIRE(L"Collection2", std::equal(begin(a), end(a), begin(b), end(b), pair_equal));
            TEST_REQUIRE(L"Collection2", std::equal(begin(a), end(a), begin(c), end(c), pair_equal));
        }
        {
            IMap<hstring, hstring> a = single_threaded_map<hstring, hstring>(std::map<hstring, hstring>{ {L"apples", L"1"}, { L"oranges",L"2" }, { L"pears",L"3" } });
            IMap<hstring, hstring> b;
            IMap<hstring, hstring> c = tests.Collection3(a, b);
            TEST_REQUIRE(L"Collection3", a != b && a != c);
            TEST_REQUIRE(L"Collection3", std::equal(begin(a), end(a), begin(b), end(b), pair_equal));
            TEST_REQUIRE(L"Collection3", std::equal(begin(a), end(a), begin(c), end(c), pair_equal));
        }
        {
            IMapView<hstring, hstring> a = single_threaded_map<hstring, hstring>(std::map<hstring, hstring>{ {L"apples", L"1"}, { L"oranges",L"2" }, { L"pears",L"3" } }).GetView();
            IMapView<hstring, hstring> b;
            IMapView<hstring, hstring> c = tests.Collection4(a, b);
            TEST_REQUIRE(L"Collection4", a != b && a != c);
            TEST_REQUIRE(L"Collection4", std::equal(begin(a), end(a), begin(b), end(b), pair_equal));
            TEST_REQUIRE(L"Collection4", std::equal(begin(a), end(a), begin(c), end(c), pair_equal));
        }
        {
            IVector<hstring> a = single_threaded_vector<hstring>({ L"apples",L"oranges",L"pears" });
            IVector<hstring> b;
            IVector<hstring> c = tests.Collection5(a, b);
            TEST_REQUIRE(L"Collection5", a != b && a != c);
            TEST_REQUIRE(L"Collection5", std::equal(begin(a), end(a), begin(b), end(b)));
            TEST_REQUIRE(L"Collection5", std::equal(begin(a), end(a), begin(c), end(c)));
        }

        {
            IVectorView<hstring> a = single_threaded_vector<hstring>({ L"apples",L"oranges",L"pears" }).GetView();
            IVectorView<hstring> b;
            IVectorView<hstring> c = tests.Collection6(a, b);
            TEST_REQUIRE(L"Collection6", a != b && a != c);
            TEST_REQUIRE(L"Collection6", std::equal(begin(a), end(a), begin(b), end(b)));
            TEST_REQUIRE(L"Collection6", std::equal(begin(a), end(a), begin(c), end(c)));
        }

        {
            TEST_REQUIRE(L"Async1", tests.Async1(NoAsync(), false).Status() == AsyncStatus::Completed);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async1(SignalAsync(signal.get()), false);
            TEST_REQUIRE(L"Async1", async.Status() == AsyncStatus::Started);
            SetEvent(signal.get());
            async.get();
        }
        {
            auto signal = auto_event();
            auto async = tests.Async1(SignalAsync(signal.get()), true);
            TEST_REQUIRE(L"Async1", async.Status() == AsyncStatus::Started);
            SetEvent(signal.get());
            try
            {
                async.get();
                TEST_REQUIRE(L"Async1", false);
            }
            catch (hresult_invalid_argument const& e)
            {
                TEST_REQUIRE(L"Async1", e.message() == L"test");
            }
        }

        {
            TEST_REQUIRE(L"Async2", tests.Async2(NoAsync(), false, 321).Status() == AsyncStatus::Completed);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async2(SignalAsync(signal.get()), false, 321);
            TEST_REQUIRE(L"Async2", async.Status() == AsyncStatus::Started);
            int32_t progress{};
            async.Progress([&](auto&&, int32_t args)
                {
                    progress = args;
                });
            SetEvent(signal.get());
            async.get();
            TEST_REQUIRE(L"Async2", progress == 321);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async2(SignalAsync(signal.get()), true, 321);
            TEST_REQUIRE(L"Async2", async.Status() == AsyncStatus::Started);
            int32_t progress{};
            async.Progress([&](auto&&, int32_t args)
                {
                    progress = args;
                });
            SetEvent(signal.get());
            try
            {
                async.get();
                TEST_REQUIRE(L"Async2", false);
            }
            catch (hresult_invalid_argument const& e)
            {
                TEST_REQUIRE(L"Async2", e.message() == L"test");
            }
            TEST_REQUIRE(L"Async2", progress == 321);
        }

        {
            auto async = tests.Async3(NoAsync(), false, 123);
            TEST_REQUIRE(L"Async3", async.Status() == AsyncStatus::Completed);
            TEST_REQUIRE(L"Async3", async.get() == 123);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async3(SignalAsync(signal.get()), false, 123);
            TEST_REQUIRE(L"Async3", async.Status() == AsyncStatus::Started);
            SetEvent(signal.get());
            TEST_REQUIRE(L"Async3", async.get() == 123);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async3(SignalAsync(signal.get()), true, 123);
            TEST_REQUIRE(L"Async3", async.Status() == AsyncStatus::Started);
            SetEvent(signal.get());
            try
            {
                async.get();
                TEST_REQUIRE(L"Async3", false);
            }
            catch (hresult_invalid_argument const& e)
            {
                TEST_REQUIRE(L"Async3", e.message() == L"test");
            }
        }

        {
            auto async = tests.Async4(NoAsync(), false, 123, 321);
            TEST_REQUIRE(L"Async4", async.Status() == AsyncStatus::Completed);
            TEST_REQUIRE(L"Async4", async.get() == 123);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async4(SignalAsync(signal.get()), false, 123, 321);
            TEST_REQUIRE(L"Async4", async.Status() == AsyncStatus::Started);
            int32_t progress{};
            async.Progress([&](auto&&, int32_t args)
                {
                    progress = args;
                });
            SetEvent(signal.get());
            TEST_REQUIRE(L"Async4", async.get() == 123);
            TEST_REQUIRE(L"Async4", progress == 321);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async4(SignalAsync(signal.get()), true, 123, 321);
            TEST_REQUIRE(L"Async4", async.Status() == AsyncStatus::Started);
            int32_t progress{};
            async.Progress([&](auto&&, int32_t args)
                {
                    progress = args;
                });
            SetEvent(signal.get());
            try
            {
                async.get();
                TEST_REQUIRE(L"Async4", false);
            }
            catch (hresult_invalid_argument const& e)
            {
                TEST_REQUIRE(L"Async4", e.message() == L"test");
            }
            TEST_REQUIRE(L"Async4", progress == 321);
        }
    }

    void TestRunner::TestCallee(ITests const& tests)
    {
        RunTests(tests);
    }

    uint32_t TestRunner::TestCaller(TestHandler const& caller)
    {
        auto tests = make_self<Tests>();
        caller(*tests);
        return tests->Percentage();
    }

    void TestRunner::TestSelf()
    {
        TestRunner::TestCallee(make<Tests>());

        uint32_t percentage = TestRunner::TestCaller([](ITests const& tests)
            {
                RunTests(tests);
            });

        TEST_REQUIRE(L"Test cover is " + to_hstring(percentage) + L"%", percentage == 100);
        percentage = TestRunner::TestCaller([](auto&&) {});
        TEST_REQUIRE(L"TestSelf", percentage == 0);

        percentage = TestRunner::TestCaller([](ITests const& tests)
            {
                tests.Simple();
            });

        TEST_REQUIRE(L"TestSelf", percentage > 0 && percentage < 100);
    }
}
