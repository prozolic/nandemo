
#ifndef TEST_NAMDEMO
#define TEST_NAMDEMO

#include "nandemo.h"

#define CATCH_CONFIG_MAIN 
#include "catch.hpp"

class test_class{};
struct test_struct{};

namespace nandemo_test
{
    class test_class{};

    class test_class2
    {
    public:
        std::string to_string() const
        {
            return "this is test_class2!!";
        }
    };

    class test_class3
    {
    public:
        void to_string() const{}
    };

    struct test_struct{};

    struct test_struct2
    {
    public:
        std::string to_string() const
        {
            return "this is test_struct2!!";
        } 
    };

    class test_struct3
    {
    public:
        void to_string() const{}
    };

}

TEST_CASE("sample test","[sample test]")
{
    {
        // integer type
        int value{999};
        auto result = nandemo::to_string(value); // "999"
        REQUIRE(result == "999");
    }
    {
        // float point type
        float f_value{1.0f};
        auto result = nandemo::to_string(f_value); // "1.000000"
        REQUIRE(result == "1.000000");
    }
    {
        // bool type
        bool b_value{true};
        auto result = nandemo::to_string(b_value); // "true"
        REQUIRE(result == "true");
    }
    {
        // char type
        char c_value{'n'};
        auto result = nandemo::to_string(c_value); // "n"
        REQUIRE(result == "n");
    }
    {
        // string type
        std::string s_value{"this is string"};
        auto result = nandemo::to_string(s_value); // "this is string"
        REQUIRE(result == "this is string");
    }
    {
        // string_view type
        std::string_view sv_value{"this is string_view"};
        auto result = nandemo::to_string(sv_value); // "this is string_view"
        REQUIRE(result == "this is string_view");
    }
}

TEST_CASE("positive std::int32_t test1","[Numeric type test]")
{
    nandemo::int32 test_value{0};
    {
        auto result = nandemo::to_string(test_value);
        CHECK("0" == result);
    }
    {
        test_value = 1;
        auto result = nandemo::to_string(test_value);
        CHECK("1" == result);
    }
    
    {
        test_value = 2;
        auto result = nandemo::to_string(test_value);
        CHECK("2" == result);
    }

    {
        test_value = 4;
        auto result = nandemo::to_string(test_value);
        CHECK("4" == result);
    }

    {
        test_value = 8;
        auto result = nandemo::to_string(test_value);
        CHECK("8" == result);
    }

    {
        test_value = 16;
        auto result = nandemo::to_string(test_value);
        CHECK("16" == result);
    }

    {
        test_value = 32;
        auto result = nandemo::to_string(test_value);
        CHECK("32" == result);
    }

    {
        test_value = 64;
        auto result = nandemo::to_string(test_value);
        CHECK("64" == result);
    }
    {
        test_value = 128;
        auto result = nandemo::to_string(test_value);
        CHECK("128" == result); 
    }

    {
        test_value = 256;
        auto result = nandemo::to_string(test_value);
        CHECK("256" == result); 
    }

    {
        test_value = 512;
        auto result = nandemo::to_string(test_value);
        CHECK("512" == result); 
    }

    {
        test_value = 1024;
        auto result = nandemo::to_string(test_value);
        CHECK("1024" == result); 
    }

    {
        test_value = 2048;
        auto result = nandemo::to_string(test_value);
        CHECK("2048" == result); 
    }

    {
        test_value = 4096;
        auto result = nandemo::to_string(test_value);
        CHECK("4096" == result); 
    }

    {
        //Max
        test_value = 2147483647;
        auto result = nandemo::to_string(test_value);
        CHECK("2147483647" == result);
    }
}

TEST_CASE("positive std::size_t test","[Numeric type test]")
{
    nandemo::usize test_value{0};
    {
        auto result = nandemo::to_string(test_value);
        CHECK("0" == result);
    }
    {
        test_value = 1;
        auto result = nandemo::to_string(test_value);
        CHECK("1" == result);
    }
    
    {
        test_value = 2;
        auto result = nandemo::to_string(test_value);
        CHECK("2" == result);
    }

    {
        test_value = 4;
        auto result = nandemo::to_string(test_value);
        CHECK("4" == result);
    }

    {
        test_value = 8;
        auto result = nandemo::to_string(test_value);
        CHECK("8" == result);
    }

    {
        test_value = 16;
        auto result = nandemo::to_string(test_value);
        CHECK("16" == result);
    }

    {
        test_value = 32;
        auto result = nandemo::to_string(test_value);
        CHECK("32" == result);
    }

    {
        test_value = 64;
        auto result = nandemo::to_string(test_value);
        CHECK("64" == result);
    }

    {
        test_value = 128;
        auto result = nandemo::to_string(test_value);
        CHECK("128" == result); 
    }

    {
        test_value = 256;
        auto result = nandemo::to_string(test_value);
        CHECK("256" == result); 
    }

    {
        test_value = 512;
        auto result = nandemo::to_string(test_value);
        CHECK("512" == result); 
    }

    {
        test_value = 1024;
        auto result = nandemo::to_string(test_value);
        CHECK("1024" == result); 
    }

    {
        test_value = 2048;
        auto result = nandemo::to_string(test_value);
        CHECK("2048" == result); 
    }

    {
        test_value = 4096;
        auto result = nandemo::to_string(test_value);
        CHECK("4096" == result); 
    }
}

TEST_CASE("negative std::int32_t test","[Numeric type test]")
{
    nandemo::int32 test_value{0};
    {
        auto result = nandemo::to_string(test_value);
        CHECK("0" == result);
    }
    {
        test_value = -1;
        auto result = nandemo::to_string(test_value);
        CHECK("-1" == result);
    }
    
    {
        test_value = -2;
        auto result = nandemo::to_string(test_value);
        CHECK("-2" == result);
    }

    {
        test_value = -4;
        auto result = nandemo::to_string(test_value);
        CHECK("-4" == result);
    }

    {
        test_value = -8;
        auto result = nandemo::to_string(test_value);
        CHECK("-8" == result);
    }

    {
        test_value = -16;
        auto result = nandemo::to_string(test_value);
        CHECK("-16" == result);
    }

    {
        test_value = -32;
        auto result = nandemo::to_string(test_value);
        CHECK("-32" == result);
    }

    {
        test_value = -64;
        auto result = nandemo::to_string(test_value);
        CHECK("-64" == result);
    }
    {
        test_value = -128;
        auto result = nandemo::to_string(test_value);
        CHECK("-128" == result); 
    }

    {
        test_value = -256;
        auto result = nandemo::to_string(test_value);
        CHECK("-256" == result); 
    }

    {
        test_value = -512;
        auto result = nandemo::to_string(test_value);
        CHECK("-512" == result); 
    }

    {
        test_value = -1024;
        auto result = nandemo::to_string(test_value);
        CHECK("-1024" == result); 
    }

    {
        test_value = -2048;
        auto result = nandemo::to_string(test_value);
        CHECK("-2048" == result); 
    }

    {
        test_value = -4096;
        auto result = nandemo::to_string(test_value);
        CHECK("-4096" == result); 
    }

    {
        //Min
        test_value = -2147483647;
        auto result = nandemo::to_string(test_value);
        CHECK("-2147483647" == result);
    }
}

TEST_CASE("positive floating point test1","[Floating point type test]")
{
    float test_value{0.f};
    {
        auto result = nandemo::to_string(test_value);
        CHECK("0.000000" == result);
    }
    {
        test_value = 1.f;
        auto result = nandemo::to_string(test_value);
        CHECK("1.000000" == result);
    }
    
    {
        test_value = 2.f;
        auto result = nandemo::to_string(test_value);
        CHECK("2.000000" == result);
    }

    {
        test_value = 4.f;
        auto result = nandemo::to_string(test_value);
        CHECK("4.000000" == result);
    }

    {
        test_value = 8.f;
        auto result = nandemo::to_string(test_value);
        CHECK("8.000000" == result);
    }

    {
        test_value = 16.f;
        auto result = nandemo::to_string(test_value);
        CHECK("16.000000" == result);
    }

    {
        test_value = 32.f;
        auto result = nandemo::to_string(test_value);
        CHECK("32.000000" == result);
    }

    {
        test_value = 64.f;
        auto result = nandemo::to_string(test_value);
        CHECK("64.000000" == result);
    }
    
    {
        test_value = 128.f;
        auto result = nandemo::to_string(test_value);
        CHECK("128.000000" == result); 
    }

    {
        test_value = 256.f;
        auto result = nandemo::to_string(test_value);
        CHECK("256.000000" == result); 
    }

    {
        test_value = 512.f;
        auto result = nandemo::to_string(test_value);
        CHECK("512.000000" == result); 
    }

    {
        test_value = 1024.f;
        auto result = nandemo::to_string(test_value);
        CHECK("1024.000000" == result); 
    }

    {
        test_value = 2048.f;
        auto result = nandemo::to_string(test_value);
        CHECK("2048.000000" == result); 
    }

    {
        test_value = 4096.f;
        auto result = nandemo::to_string(test_value);
        CHECK("4096.000000" == result); 
    }
}

TEST_CASE("positive floating point test2","[Floating point type test]")
{
    float test_value;
    {
        test_value = 0.000001f;
        auto result = nandemo::to_string(test_value);
        CHECK("0.000001" == result);
    }

    {
        test_value = 0.00001f;
        auto result = nandemo::to_string(test_value);
        CHECK("0.000010" == result);
    }

    {
        test_value = 0.0001f;
        auto result = nandemo::to_string(test_value);
        CHECK("0.000100" == result);
    }

    {
        test_value = 0.001f;
        auto result = nandemo::to_string(test_value);
        CHECK("0.001000" == result);
    }

    {
        test_value = 0.01f;
        auto result = nandemo::to_string(test_value);
        CHECK("0.010000" == result);
    }

    {
        test_value = 0.1f;
        auto result = nandemo::to_string(test_value);
        CHECK("0.100000" == result);
    }

    {
        test_value = 0.12f;
        auto result = nandemo::to_string(test_value);
        CHECK("0.120000" == result);
    }

    {
        test_value = 0.123f;
        auto result = nandemo::to_string(test_value);
        CHECK("0.123000" == result);
    }

    {
        test_value = 0.1234f;
        auto result = nandemo::to_string(test_value);
        CHECK("0.123400" == result);
    }

    {
        test_value = 0.12345f;
        auto result = nandemo::to_string(test_value);
        CHECK("0.123450" == result);
    }

    {
        test_value = 0.123456f;
        auto result = nandemo::to_string(test_value);
        CHECK("0.123456" == result);
    }

}

TEST_CASE("negative floating point test1","[Floating point type test]")
{
    float test_value{-0.f};
    {
        auto result = nandemo::to_string(test_value);
        CHECK("-0.000000" == result);
    }
    {
        test_value = -1.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-1.000000" == result);
    }
    
    {
        test_value = -2.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-2.000000" == result);
    }

    {
        test_value = -4.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-4.000000" == result);
    }

    {
        test_value = -8.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-8.000000" == result);
    }

    {
        test_value = -16.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-16.000000" == result);
    }

    {
        test_value = -32.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-32.000000" == result);
    }

    {
        test_value = -64.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-64.000000" == result);
    }
    
    {
        test_value = -128.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-128.000000" == result); 
    }

    {
        test_value = -256.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-256.000000" == result); 
    }

    {
        test_value = -512.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-512.000000" == result); 
    }

    {
        test_value = -1024.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-1024.000000" == result); 
    }

    {
        test_value = -2048.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-2048.000000" == result); 
    }

    {
        test_value = -4096.f;
        auto result = nandemo::to_string(test_value);
        CHECK("-4096.000000" == result); 
    }
}

TEST_CASE("negative floating point test2","[Floating point type test]")
{
    float test_value;
    {
        test_value = -0.000001f;
        auto result = nandemo::to_string(test_value);
        CHECK("-0.000001" == result);
    }

    {
        test_value = -0.00001f;
        auto result = nandemo::to_string(test_value);
        CHECK("-0.000010" == result);
    }

    {
        test_value = -0.0001f;
        auto result = nandemo::to_string(test_value);
        CHECK("-0.000100" == result);
    }

    {
        test_value = -0.001f;
        auto result = nandemo::to_string(test_value);
        CHECK("-0.001000" == result);
    }

    {
        test_value = -0.01f;
        auto result = nandemo::to_string(test_value);
        CHECK("-0.010000" == result);
    }

    {
        test_value = -0.1f;
        auto result = nandemo::to_string(test_value);
        CHECK("-0.100000" == result);
    }

    {
        test_value = -0.12f;
        auto result = nandemo::to_string(test_value);
        CHECK("-0.120000" == result);
    }

    {
        test_value = -0.123f;
        auto result = nandemo::to_string(test_value);
        CHECK("-0.123000" == result);
    }

    {
        test_value = -0.1234f;
        auto result = nandemo::to_string(test_value);
        CHECK("-0.123400" == result);
    }

    {
        test_value = -0.12345f;
        auto result = nandemo::to_string(test_value);
        CHECK("-0.123450" == result);
    }

    {
        test_value = -0.123456f;
        auto result = nandemo::to_string(test_value);
        CHECK("-0.123456" == result);
    }

}

TEST_CASE("base number test1","[base number test]")
{
    constexpr nandemo::int32 value{123};
    {
        auto result = nandemo::to_string_numeric<nandemo::base::decimal>(value); // 123
        CHECK(result == "123");
    }

    {
        auto result = nandemo::to_string_decimal(value); // 123
        CHECK(result == "123");
    }

    {
        auto result = nandemo::to_string_numeric<nandemo::base::binary>(value); // 00000000000000000000000001111011
        CHECK(result == "00000000000000000000000001111011");
    }

    {
        auto result = nandemo::to_string_binary(value); // 00000000000000000000000001111011
        CHECK(result == "00000000000000000000000001111011");
    }
    {
        auto result = nandemo::to_string_numeric<nandemo::base::hex>(value); // 7b
        CHECK(result == "7b");
    }

    {
        auto result = nandemo::to_string_hex(value); // 7b
        CHECK(result == "7b");
    }
}

TEST_CASE("base number zero padding test","[base number test]")
{
    constexpr nandemo::int32 pading{5};
    constexpr nandemo::int32 value{123};
    {
        auto result = nandemo::to_string_numeric<nandemo::base::decimal,pading>(value); // 00123
        CHECK(result == "00123");
    }

    {
        auto result = nandemo::to_string_decimal<pading>(value); // 00123
        CHECK(result == "00123");
    }

    {
        auto result = nandemo::to_string_numeric<nandemo::base::hex,pading>(value); // 7b
        CHECK(result == "0007b");
    }

    {
        auto result = nandemo::to_string_hex<pading>(value); // 7b
        CHECK(result == "0007b");
    }
}

TEST_CASE("bool test1","[bool test]")
{
    {
        CHECK("true" == nandemo::to_string(true));
        CHECK("false" == nandemo::to_string(false));
    }
    {
        auto true_value{true};
        auto false_value{false};
        CHECK("true" == nandemo::to_string(true_value));
        CHECK("false" == nandemo::to_string(false_value));
    }
}

TEST_CASE("class test1","[class test]")
{
    {
        test_class c_value;
        std::string result = nandemo::to_string(c_value); // "test_class"
        CHECK(result == "test_class");

    }
    {
        // with namespace
        nandemo_test::test_class c_value;
        auto result = nandemo::to_string(c_value); // "nandemo_test::test_class"
        CHECK(result == "nandemo_test::test_class");
    }
}

TEST_CASE("class to_string test","[class test]")
{
    {
        // with namespace
        nandemo_test::test_class2 c_value;
        auto result = nandemo::to_string(c_value); // "this is test_class2!!"
        CHECK(result == "this is test_class2!!");
    }
}

TEST_CASE("class to_string test2","[class test]")
{
    {
        // with namespace
        nandemo_test::test_class3 c_value;
        auto result = nandemo::to_string(c_value); // "nandemo_test::test_class"
        CHECK(result == "nandemo_test::test_class3");
    }
}

TEST_CASE("struct test","[struct test]")
{
    {
        test_struct s_value;
        std::string result = nandemo::to_string(s_value); // "test_struct"
        CHECK(result == "test_struct");
    }
    {
        // with namespace
        nandemo_test::test_struct s_value;
        auto result = nandemo::to_string(s_value); // "nandemo_test::test_struct"
        CHECK(result == "nandemo_test::test_struct");
    }
}

TEST_CASE("struct to_string test","[struct test]")
{
    {
        // with namespace
        nandemo_test::test_struct2 s_value;
        auto result = nandemo::to_string(s_value); // "this is test_struct2!!"
        CHECK(result == "this is test_struct2!!");
    }
}

TEST_CASE("struct to_string test2","[struct test]")
{
    {
        // with namespace
        nandemo_test::test_struct3 s_value;
        auto result = nandemo::to_string(s_value); // "nandemo_test::test_struct3"
        CHECK(result == "nandemo_test::test_struct3");
    }
}

TEST_CASE("string type test1","[string type test]")
{
    {
        // char
        auto result = nandemo::to_string('a');
        CHECK(result == "a");
    }
    {
        // const char[]
        auto result = nandemo::to_string("hello world");
        CHECK(result == "hello world");
    }
    {
        // std::string
        std::string test_value{"hello world"};
        CHECK(test_value == "hello world");
    }
    {
        // std::string_view
        std::string_view test_value{"hello world"};
        CHECK(test_value == "hello world");
    }
}


#endif // TEST_NAMDEMO
