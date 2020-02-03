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

        auto Params_Bool(bool a, bool& b)
        {
            b = a;
            return a;
        }
        void Call_Params_Bool(Delegate_Params_Bool const& handler)
        {
            bool const a = true;
            bool b;
            bool c = handler(true, b);
            TEST_REQUIRE(L"Params_Bool", b && c);
        }

        auto Params_UInt8(uint8_t a, uint8_t& b)
        {
            b = a;
            return a;
        }
        auto Params_UInt16(uint16_t a, uint16_t& b)
        {
            b = a;
            return a;
        }
        auto Params_UInt32(uint32_t a, uint32_t& b)
        {
            b = a;
            return a;
        }
        auto Params_UInt64(uint64_t a, uint64_t& b)
        {
            b = a;
            return a;
        }
        auto Params_Int16(int16_t a, int16_t& b)
        {
            b = a;
            return a;
        }
        auto Params_Int32(int32_t a, int32_t& b)
        {
            b = a;
            return a;
        }
        auto Params_Int64(int64_t a, int64_t& b)
        {
            b = a;
            return a;
        }
        auto Params_Single(float a, float& b)
        {
            b = a;
            return a;
        }
        auto Params_Double(double a, double& b)
        {
            b = a;
            return a;
        }
        auto Params_Char(char16_t a, char16_t& b)
        {
            b = a;
            return a;
        }
        auto Params_String(hstring const& a, hstring& b)
        {
            TEST_REQUIRE(L"Params_String", b.empty());
            b = a;
            return a;
        }

        auto Params_Struct_Blittable(Struct_Blittable const& a, Struct_Blittable& b)
        {
            b = a;
            return a;
        }

        auto Params_Struct_NonBlittable(Struct_NonBlittable const& a, Struct_NonBlittable& b)
        {
            TEST_REQUIRE(L"Params_Struct_NonBlittable", b == Struct_NonBlittable{});
            b = a;
            return a;
        }

        auto Params_Struct_Nested(Struct_Nested const& a, Struct_Nested& b)
        {
            TEST_REQUIRE(L"Params_Struct_Nested", b == Struct_Nested{});
            b = a;
            return a;
        }

        auto ArrayParams_Bool(array_view<bool const> a, array_view<bool> b, com_array<bool>& c)
        {
            TEST_REQUIRE(L"ArrayParams_Bool", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_Bool", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<bool>(a.begin(), a.end());
            return com_array<bool>(a.begin(), a.end());
        }

        auto ArrayParams_UInt8(array_view<uint8_t const> a, array_view<uint8_t> b, com_array<uint8_t>& c)
        {
            TEST_REQUIRE(L"ArrayParams_UInt8", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_UInt8", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<uint8_t>(a.begin(), a.end());
            return com_array<uint8_t>(a.begin(), a.end());
        }
        auto ArrayParams_UInt16(array_view<uint16_t const> a, array_view<uint16_t> b, com_array<uint16_t>& c)
        {
            TEST_REQUIRE(L"ArrayParams_UInt16", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_UInt16", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<uint16_t>(a.begin(), a.end());
            return com_array<uint16_t>(a.begin(), a.end());
        }
        auto ArrayParams_UInt32(array_view<uint32_t const> a, array_view<uint32_t> b, com_array<uint32_t>& c)
        {
            TEST_REQUIRE(L"ArrayParams_UInt32", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_UInt32", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<uint32_t>(a.begin(), a.end());
            return com_array<uint32_t>(a.begin(), a.end());
        }
        auto ArrayParams_UInt64(array_view<uint64_t const> a, array_view<uint64_t> b, com_array<uint64_t>& c)
        {
            TEST_REQUIRE(L"ArrayParams_UInt64", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_UInt64", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<uint64_t>(a.begin(), a.end());
            return com_array<uint64_t>(a.begin(), a.end());
        }
        auto ArrayParams_Int16(array_view<int16_t const> a, array_view<int16_t> b, com_array<int16_t>& c)
        {
            TEST_REQUIRE(L"ArrayParams_Int16", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_Int16", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<int16_t>(a.begin(), a.end());
            return com_array<int16_t>(a.begin(), a.end());
        }
        auto ArrayParams_Int32(array_view<int32_t const> a, array_view<int32_t> b, com_array<int32_t>& c)
        {
            TEST_REQUIRE(L"ArrayParams_Int32", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_Int32", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<int32_t>(a.begin(), a.end());
            return com_array<int32_t>(a.begin(), a.end());
        }
        auto ArrayParams_Int64(array_view<int64_t const> a, array_view<int64_t> b, com_array<int64_t>& c)
        {
            TEST_REQUIRE(L"ArrayParams_Int64", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_Int64", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<int64_t>(a.begin(), a.end());
            return com_array<int64_t>(a.begin(), a.end());
        }
        auto ArrayParams_Single(array_view<float const> a, array_view<float> b, com_array<float>& c)
        {
            TEST_REQUIRE(L"ArrayParams_Single", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_Single", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<float>(a.begin(), a.end());
            return com_array<float>(a.begin(), a.end());
        }
        auto ArrayParams_Double(array_view<double const> a, array_view<double> b, com_array<double>& c)
        {
            TEST_REQUIRE(L"ArrayParams_Double", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_Double", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<double>(a.begin(), a.end());
            return com_array<double>(a.begin(), a.end());
        }
        auto ArrayParams_Char(array_view<char16_t const> a, array_view<char16_t> b, com_array<char16_t>& c)
        {
            TEST_REQUIRE(L"ArrayParams_Char", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_Char", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<char16_t>(a.begin(), a.end());
            return com_array<char16_t>(a.begin(), a.end());
        }
        auto ArrayParams_String(array_view<hstring const> a, array_view<hstring> b, com_array<hstring>& c)
        {
            TEST_REQUIRE(L"ArrayParams_String", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_String", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<hstring>(a.begin(), a.end());
            return com_array<hstring>(a.begin(), a.end());
        }

        auto CollectionParams_Iterable(IIterable<hstring> const& a, IIterable<hstring>& b)
        {
            b = single_threaded_vector(std::vector<hstring>{ begin(a), end(a) });
            return b;
        }
        auto CollectionParams_IterablePair(IIterable<IKeyValuePair<hstring, hstring>> const& a, IIterable<IKeyValuePair<hstring, hstring>>& b)
        {
            std::map<hstring, hstring> copy;

            for (auto&& pair : a)
            {
                copy[pair.Key()] = pair.Value();
            }

            b = single_threaded_map(std::move(copy));
            return b;
        }
        auto CollectionParams_Map(IMap<hstring, hstring> const& a, IMap<hstring, hstring>& b)
        {
            std::map<hstring, hstring> copy;

            for (auto&& pair : a)
            {
                copy[pair.Key()] = pair.Value();
            }

            b = single_threaded_map(std::move(copy));
            return b;
        }
        auto CollectionParams_MapView(IMapView<hstring, hstring> const& a, IMapView<hstring, hstring>& b)
        {
            std::map<hstring, hstring> copy;

            for (auto&& pair : a)
            {
                copy[pair.Key()] = pair.Value();
            }

            b = single_threaded_map(std::move(copy)).GetView();
            return b;
        }
        auto CollectionParams_Vector(IVector<hstring> const& a, IVector<hstring>& b)
        {
            b = single_threaded_vector(std::vector<hstring>{ begin(a), end(a) });
            return b;
        }

        auto CollectionParams_VectorView(IVectorView<hstring> const& a, IVectorView<hstring>& b)
        {
            b = single_threaded_vector(std::vector<hstring>{ begin(a), end(a) }).GetView();
            return b;
        }

        IAsyncAction Async_Action(IAsyncAction suspend, bool fail)
        {
            co_await suspend;

            if (fail)
            {
                throw hresult_invalid_argument(L"test");
            }
        }
        IAsyncActionWithProgress<int32_t> Async_ActionWithProgress(IAsyncAction suspend, bool fail, int32_t progress)
        {
            co_await suspend;
            auto callback = co_await get_progress_token();
            callback(progress);

            if (fail)
            {
                throw hresult_invalid_argument(L"test");
            }
        }
        IAsyncOperation<int32_t> Async_Operation(IAsyncAction suspend, bool fail, int32_t result)
        {
            co_await suspend;

            if (fail)
            {
                throw hresult_invalid_argument(L"test");
            }

            co_return result;
        }
        IAsyncOperationWithProgress<int32_t, int32_t> Async_OperationWithProgress(IAsyncAction suspend, bool fail, int32_t result, int32_t progress)
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
            tests.Call_Params_Bool([&](bool a, bool& b)
                {
                    return tests.Params_Bool(a, b);
                });
        }
        {
            uint8_t a = 123;
            uint8_t b;
            uint8_t c = tests.Params_UInt8(a, b);
            TEST_REQUIRE(L"Params_UInt8", a == b && a == c);
        }
        {
            uint16_t a = 123;
            uint16_t b;
            uint16_t c = tests.Params_UInt16(a, b);
            TEST_REQUIRE(L"Params_UInt16", a == b && a == c);
        }
        {
            uint32_t a = 123;
            uint32_t b;
            uint32_t c = tests.Params_UInt32(a, b);
            TEST_REQUIRE(L"Params_UInt32", a == b && a == c);
        }
        {
            uint64_t a = 123;
            uint64_t b;
            uint64_t c = tests.Params_UInt64(a, b);
            TEST_REQUIRE(L"Params_UInt64", a == b && a == c);
        }
        {
            int16_t a = 123;
            int16_t b;
            int16_t c = tests.Params_Int16(a, b);
            TEST_REQUIRE(L"Params_Int16", a == b && a == c);
        }
        {
            int32_t a = 123;
            int32_t b;
            int32_t c = tests.Params_Int32(a, b);
            TEST_REQUIRE(L"Params_Int32", a == b && a == c);
        }
        {
            int64_t a = 123;
            int64_t b;
            int64_t c = tests.Params_Int64(a, b);
            TEST_REQUIRE(L"Params_Int64", a == b && a == c);
        }
        {
            float a = 12.3f;
            float b;
            float c = tests.Params_Single(a, b);
            TEST_REQUIRE(L"Params_Single", a == b && a == c);
        }
        {
            double a = 12.3;
            double b;
            double c = tests.Params_Double(a, b);
            TEST_REQUIRE(L"Params_Double", a == b && a == c);
        }
        {
            char16_t a = L'W';
            char16_t b;
            char16_t c = tests.Params_Char(a, b);
            TEST_REQUIRE(L"Params_Char", a == b && a == c);
        }
        {
            hstring a = L"WinRT";
            hstring b;
            hstring c = tests.Params_String(a, b);
            TEST_REQUIRE(L"Params_String", a == b && a == c);
        }
        {
            Struct_Blittable a{ false, 1, 2, 3, 4, -5, -6, -7, 8.0f, 9.0, L'X', guid_of<ITests>() };
            Struct_Blittable b;
            Struct_Blittable c = tests.Params_Struct_Blittable(a, b);
            TEST_REQUIRE(L"Params_Struct_Blittable", a == b && a == c);
        }
        {
            Struct_NonBlittable a{ L"WinRT", 1234 };
            Struct_NonBlittable b;
            Struct_NonBlittable c = tests.Params_Struct_NonBlittable(a, b);
            TEST_REQUIRE(L"Params_Struct_NonBlittable", a == b && a == c);
        }
        {
            Struct_Nested a{ { false, 1, 2, 3, 4, -5, -6, -7, 8.0f, 9.0, L'X', guid_of<ITests>() }, { L"WinRT", 1234 } };
            Struct_Nested b;
            Struct_Nested c = tests.Params_Struct_Nested(a, b);
            TEST_REQUIRE(L"Params_Struct_Nested", a == b && a == c);
        }

        {
            std::array<bool, 3> a{ true,false,true };
            std::array<bool, 3> b;
            com_array<bool> c;
            com_array<bool> d = tests.ArrayParams_Bool(a, b, c);
            TEST_REQUIRE(L"ArrayParams_Bool", a == b && a == c && c == d);
        }
        {
            std::array<uint8_t, 3> a{ 1,2,3 };
            std::array<uint8_t, 3> b;
            com_array<uint8_t> c;
            com_array<uint8_t> d = tests.ArrayParams_UInt8(a, b, c);
            TEST_REQUIRE(L"ArrayParams_UInt8", a == b && a == c && c == d);
        }
        {
            std::array<uint16_t, 3> a{ 1,2,3 };
            std::array<uint16_t, 3> b;
            com_array<uint16_t> c;
            com_array<uint16_t> d = tests.ArrayParams_UInt16(a, b, c);
            TEST_REQUIRE(L"ArrayParams_UInt16", a == b && a == c && c == d);
        }
        {
            std::array<uint32_t, 3> a{ 1,2,3 };
            std::array<uint32_t, 3> b;
            com_array<uint32_t> c;
            com_array<uint32_t> d = tests.ArrayParams_UInt32(a, b, c);
            TEST_REQUIRE(L"ArrayParams_UInt32", a == b && a == c && c == d);
        }
        {
            std::array<uint64_t, 3> a{ 1,2,3 };
            std::array<uint64_t, 3> b;
            com_array<uint64_t> c;
            com_array<uint64_t> d = tests.ArrayParams_UInt64(a, b, c);
            TEST_REQUIRE(L"ArrayParams_UInt64", a == b && a == c && c == d);
        }
        {
            std::array<int16_t, 3> a{ 1,2,3 };
            std::array<int16_t, 3> b;
            com_array<int16_t> c;
            com_array<int16_t> d = tests.ArrayParams_Int16(a, b, c);
            TEST_REQUIRE(L"ArrayParams_Int16", a == b && a == c && c == d);
        }
        {
            std::array<int32_t, 3> a{ 1,2,3 };
            std::array<int32_t, 3> b;
            com_array<int32_t> c;
            com_array<int32_t> d = tests.ArrayParams_Int32(a, b, c);
            TEST_REQUIRE(L"ArrayParams_Int32", a == b && a == c && c == d);
        }
        {
            std::array<int64_t, 3> a{ 1,2,3 };
            std::array<int64_t, 3> b;
            com_array<int64_t> c;
            com_array<int64_t> d = tests.ArrayParams_Int64(a, b, c);
            TEST_REQUIRE(L"ArrayParams_Int64", a == b && a == c && c == d);
        }
        {
            std::array<float, 3> a{ 1.0f,2.0f,3.0f };
            std::array<float, 3> b;
            com_array<float> c;
            com_array<float> d = tests.ArrayParams_Single(a, b, c);
            TEST_REQUIRE(L"ArrayParams_Single", a == b && a == c && c == d);
        }
        {
            std::array<double, 3> a{ 1.0,2.0,3.0 };
            std::array<double, 3> b;
            com_array<double> c;
            com_array<double> d = tests.ArrayParams_Double(a, b, c);
            TEST_REQUIRE(L"ArrayParams_Double", a == b && a == c && c == d);
        }
        {
            std::array<char16_t, 3> a{ L'a',L'b',L'c' };
            std::array<char16_t, 3> b;
            com_array<char16_t> c;
            com_array<char16_t> d = tests.ArrayParams_Char(a, b, c);
            TEST_REQUIRE(L"ArrayParams_Char", a == b && a == c && c == d);
        }
        {
            std::array<hstring, 3> a{ L"apples",L"oranges",L"pears" };
            std::array<hstring, 3> b;
            com_array<hstring> c;
            com_array<hstring> d = tests.ArrayParams_String(a, b, c);
            TEST_REQUIRE(L"ArrayParams_String", a == b && a == c && c == d);
        }

        {
            IIterable<hstring> a = single_threaded_vector<hstring>({ L"apples",L"oranges",L"pears" });
            IIterable<hstring> b;
            IIterable<hstring> c = tests.CollectionParams_Iterable(a, b);
            TEST_REQUIRE(L"CollectionParams_Iterable", a != b && a != c);
            TEST_REQUIRE(L"CollectionParams_Iterable", std::equal(begin(a), end(a), begin(b), end(b)));
            TEST_REQUIRE(L"CollectionParams_Iterable", std::equal(begin(a), end(a), begin(c), end(c)));
        }
        {
            IIterable<IKeyValuePair<hstring, hstring>> a = single_threaded_map<hstring, hstring>(std::map<hstring,hstring>{ {L"apples", L"1"},{L"oranges",L"2"},{L"pears",L"3"} });
            IIterable<IKeyValuePair<hstring, hstring>> b;
            IIterable<IKeyValuePair<hstring, hstring>> c = tests.CollectionParams_IterablePair(a, b);
            TEST_REQUIRE(L"CollectionParams_IterablePair", a != b && a != c);
            TEST_REQUIRE(L"CollectionParams_IterablePair", std::equal(begin(a), end(a), begin(b), end(b), pair_equal));
            TEST_REQUIRE(L"CollectionParams_IterablePair", std::equal(begin(a), end(a), begin(c), end(c), pair_equal));
        }
        {
            IMap<hstring, hstring> a = single_threaded_map<hstring, hstring>(std::map<hstring, hstring>{ {L"apples", L"1"}, { L"oranges",L"2" }, { L"pears",L"3" } });
            IMap<hstring, hstring> b;
            IMap<hstring, hstring> c = tests.CollectionParams_Map(a, b);
            TEST_REQUIRE(L"CollectionParams_Map", a != b && a != c);
            TEST_REQUIRE(L"CollectionParams_Map", std::equal(begin(a), end(a), begin(b), end(b), pair_equal));
            TEST_REQUIRE(L"CollectionParams_Map", std::equal(begin(a), end(a), begin(c), end(c), pair_equal));
        }
        {
            IMapView<hstring, hstring> a = single_threaded_map<hstring, hstring>(std::map<hstring, hstring>{ {L"apples", L"1"}, { L"oranges",L"2" }, { L"pears",L"3" } }).GetView();
            IMapView<hstring, hstring> b;
            IMapView<hstring, hstring> c = tests.CollectionParams_MapView(a, b);
            TEST_REQUIRE(L"CollectionParams_MapView", a != b && a != c);
            TEST_REQUIRE(L"CollectionParams_MapView", std::equal(begin(a), end(a), begin(b), end(b), pair_equal));
            TEST_REQUIRE(L"CollectionParams_MapView", std::equal(begin(a), end(a), begin(c), end(c), pair_equal));
        }
        {
            IVector<hstring> a = single_threaded_vector<hstring>({ L"apples",L"oranges",L"pears" });
            IVector<hstring> b;
            IVector<hstring> c = tests.CollectionParams_Vector(a, b);
            TEST_REQUIRE(L"CollectionParams_Vector", a != b && a != c);
            TEST_REQUIRE(L"CollectionParams_Vector", std::equal(begin(a), end(a), begin(b), end(b)));
            TEST_REQUIRE(L"CollectionParams_Vector", std::equal(begin(a), end(a), begin(c), end(c)));
        }

        {
            IVectorView<hstring> a = single_threaded_vector<hstring>({ L"apples",L"oranges",L"pears" }).GetView();
            IVectorView<hstring> b;
            IVectorView<hstring> c = tests.CollectionParams_VectorView(a, b);
            TEST_REQUIRE(L"CollectionParams_VectorView", a != b && a != c);
            TEST_REQUIRE(L"CollectionParams_VectorView", std::equal(begin(a), end(a), begin(b), end(b)));
            TEST_REQUIRE(L"CollectionParams_VectorView", std::equal(begin(a), end(a), begin(c), end(c)));
        }

        {
            TEST_REQUIRE(L"Async_Action", tests.Async_Action(NoAsync(), false).Status() == AsyncStatus::Completed);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async_Action(SignalAsync(signal.get()), false);
            TEST_REQUIRE(L"Async_Action", async.Status() == AsyncStatus::Started);
            SetEvent(signal.get());
            async.get();
        }
        {
            auto signal = auto_event();
            auto async = tests.Async_Action(SignalAsync(signal.get()), true);
            TEST_REQUIRE(L"Async_Action", async.Status() == AsyncStatus::Started);
            SetEvent(signal.get());
            try
            {
                async.get();
                TEST_REQUIRE(L"Async_Action", false);
            }
            catch (hresult_invalid_argument const& e)
            {
                TEST_REQUIRE(L"Async_Action", e.message() == L"test");
            }
        }

        {
            TEST_REQUIRE(L"Async_ActionWithProgress", tests.Async_ActionWithProgress(NoAsync(), false, 321).Status() == AsyncStatus::Completed);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async_ActionWithProgress(SignalAsync(signal.get()), false, 321);
            TEST_REQUIRE(L"Async_ActionWithProgress", async.Status() == AsyncStatus::Started);
            int32_t progress{};
            async.Progress([&](auto&&, int32_t args)
                {
                    progress = args;
                });
            SetEvent(signal.get());
            async.get();
            TEST_REQUIRE(L"Async_ActionWithProgress", progress == 321);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async_ActionWithProgress(SignalAsync(signal.get()), true, 321);
            TEST_REQUIRE(L"Async_ActionWithProgress", async.Status() == AsyncStatus::Started);
            int32_t progress{};
            async.Progress([&](auto&&, int32_t args)
                {
                    progress = args;
                });
            SetEvent(signal.get());
            try
            {
                async.get();
                TEST_REQUIRE(L"Async_ActionWithProgress", false);
            }
            catch (hresult_invalid_argument const& e)
            {
                TEST_REQUIRE(L"Async_ActionWithProgress", e.message() == L"test");
            }
            TEST_REQUIRE(L"Async_ActionWithProgress", progress == 321);
        }

        {
            auto async = tests.Async_Operation(NoAsync(), false, 123);
            TEST_REQUIRE(L"Async_Operation", async.Status() == AsyncStatus::Completed);
            TEST_REQUIRE(L"Async_Operation", async.get() == 123);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async_Operation(SignalAsync(signal.get()), false, 123);
            TEST_REQUIRE(L"Async_Operation", async.Status() == AsyncStatus::Started);
            SetEvent(signal.get());
            TEST_REQUIRE(L"Async_Operation", async.get() == 123);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async_Operation(SignalAsync(signal.get()), true, 123);
            TEST_REQUIRE(L"Async_Operation", async.Status() == AsyncStatus::Started);
            SetEvent(signal.get());
            try
            {
                async.get();
                TEST_REQUIRE(L"Async_Operation", false);
            }
            catch (hresult_invalid_argument const& e)
            {
                TEST_REQUIRE(L"Async_Operation", e.message() == L"test");
            }
        }

        {
            auto async = tests.Async_OperationWithProgress(NoAsync(), false, 123, 321);
            TEST_REQUIRE(L"Async_OperationWithProgress", async.Status() == AsyncStatus::Completed);
            TEST_REQUIRE(L"Async_OperationWithProgress", async.get() == 123);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async_OperationWithProgress(SignalAsync(signal.get()), false, 123, 321);
            TEST_REQUIRE(L"Async_OperationWithProgress", async.Status() == AsyncStatus::Started);
            int32_t progress{};
            async.Progress([&](auto&&, int32_t args)
                {
                    progress = args;
                });
            SetEvent(signal.get());
            TEST_REQUIRE(L"Async_OperationWithProgress", async.get() == 123);
            TEST_REQUIRE(L"Async_OperationWithProgress", progress == 321);
        }
        {
            auto signal = auto_event();
            auto async = tests.Async_OperationWithProgress(SignalAsync(signal.get()), true, 123, 321);
            TEST_REQUIRE(L"Async_OperationWithProgress", async.Status() == AsyncStatus::Started);
            int32_t progress{};
            async.Progress([&](auto&&, int32_t args)
                {
                    progress = args;
                });
            SetEvent(signal.get());
            try
            {
                async.get();
                TEST_REQUIRE(L"Async_OperationWithProgress", false);
            }
            catch (hresult_invalid_argument const& e)
            {
                TEST_REQUIRE(L"Async_OperationWithProgress", e.message() == L"test");
            }
            TEST_REQUIRE(L"Async_OperationWithProgress", progress == 321);
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
