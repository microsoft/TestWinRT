#include "pch.h"
#include "TestRunner.h"
#include "TestRunner.g.cpp"

#define TEST_REQUIRE(test, expression) { if (!(expression)) throw winrt::hresult_invalid_argument(test); }

namespace winrt::TestComponent::implementation
{
    using namespace Windows::Foundation::Collections;

    struct Tests : implements<Tests, ITests>
    {
    private:

        uint32_t m_counter{};
        const uint32_t m_total{ 31 };

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

    void RunTests(ITests const& tests)
    {
        tests.Simple();
        {
            bool const a = true;
            bool b;
            bool c = tests.Params_Bool(true, b);
            TEST_REQUIRE(L"Params_Bool", b && c);
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
