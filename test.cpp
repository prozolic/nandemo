
#ifndef TEST_NAMDEMO
#define TEST_NAMDEMO

#include "nandemo.h"

#define CATCH_CONFIG_MAIN 
#include "catch.hpp"


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


#endif // TEST_NAMDEMO
