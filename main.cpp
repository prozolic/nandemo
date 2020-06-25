
#include <iostream>
#include <vector>
#include "nandemo.h"

class test_class{};

class test_class2
{
public:
    std::string to_string() const
    {
        return "this is TEST_CLASS2!!";
    }
};

struct test_struct{};

class test_class3
{
public:
    void to_string() const{}    
};

int main()
{
    std::cout << "nandemo test" << std::endl;


    {
        nandemo::int32 test{9};
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        std::size_t test{123456789};
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;        
    }

    {
        std::size_t test{12301089};
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;        
    }

    {
        nandemo::int32 test{-7};
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;        
    }

    {
        nandemo::int32 test{-75926};
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;        
    }

    {
        float test{9.03f};
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        double test{9.03};
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        bool test{true};
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        bool test{false};
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        char test{'n'};
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        auto test = "const char* = test";
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        char test[] = "char [5] = test";
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        const char test[] = "const char [5] = test";
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        std::string test{"std::string = test"};
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        std::string_view test{"std::string_view = test"};
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        test_class test;
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        test_class2 test;
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        test_class3 test;
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        test_struct test;
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        std::vector<std::string> test;
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        test_class2 test;
        std::string result = nandemo::to_string<nandemo::level::class_name>(test);
        std::cout << result << std::endl;
    }

    {
        test_class2 test;
        std::string result = nandemo::to_string<nandemo::level::normal>(test);
        std::cout << result << std::endl;
    }

    {
        std::size_t test{123456789};
        std::string result = nandemo::to_string<nandemo::level::class_name>(test);
        std::cout << result << std::endl;
    }
    {
        nandemo::int32 test{347};
        std::string result = nandemo::to_string<nandemo::level::formatting, nandemo::base::decimal, 12>(test);
        std::cout << result << std::endl;        
    }
    {
        nandemo::int32 test{348};
        std::string result = nandemo::to_string_numeric<nandemo::base::decimal, 9>(test);
        std::cout << result << std::endl;        
    }
    {
        nandemo::int32 test{349};
        std::string result = nandemo::to_string_decimal<4>(test);
        std::cout << result << std::endl;        
    }
    {
        nandemo::int32 test{349};
        std::string result = nandemo::to_string_decimal(test);
        std::cout << result << std::endl;        
    }
    {
        nandemo::int32 test{1034547};
        std::string result = nandemo::to_string<nandemo::level::formatting,nandemo::base::binary>(test);
        std::cout << result << std::endl;        
    }
    {
        nandemo::int32 test{1034547};
        std::string result = nandemo::to_string<nandemo::level::formatting,nandemo::base::decimal, 6>(test);
        std::cout << result << std::endl;        
    }
    {
        nandemo::int32 test{-4535};
        std::string result = nandemo::to_string<nandemo::level::formatting,nandemo::base::hex>(test);
        std::cout << result << std::endl;        
    }
    {
        nandemo::int32 test{-4535};
        std::string result = nandemo::to_string_binary(test);
        std::cout << result << std::endl;        
    }
    {
        nandemo::int32 test{27};
        std::string result = nandemo::to_string_numeric<nandemo::base::binary>(test);
        std::cout << result << std::endl;          
    }
    {
        nandemo::int32 test{27};
        std::string result = nandemo::to_string_numeric<nandemo::base::hex, 10>(test);
        std::cout << result << std::endl;          
    }
    {
        nandemo::int32 test{123};
        std::string result = nandemo::to_string_numeric<nandemo::base::decimal>(test);
        std::cout << result << std::endl;          
    }
    {
        nandemo::int32 test{123};
        std::string result = nandemo::to_string_numeric<nandemo::base::binary>(test);
        std::cout << result << std::endl;          
    }
    {
        nandemo::int32 test{123};
        std::string result = nandemo::to_string_numeric<nandemo::base::hex>(test);
        std::cout << result << std::endl;          
    }
    {
        nandemo::int32 test{123};
        std::string result = nandemo::to_string_numeric<nandemo::base::decimal, 5>(test);
        std::cout << result << std::endl;          
    }
    {
        nandemo::int32 test{123};
        std::string result = nandemo::to_string_numeric<nandemo::base::binary, 5>(test);
        std::cout << result << std::endl;          
    }
    {
        nandemo::int32 test{123};
        std::string result = nandemo::to_string_numeric<nandemo::base::hex, 5>(test);
        std::cout << result << std::endl;          
    }
    {
        nandemo::int32 test{-27};
        std::string result = nandemo::to_string_numeric<nandemo::base::binary, 10>(test);
        std::cout << result << std::endl;          
    }
    {
        nandemo::int32 test{-27};
        std::string result = nandemo::to_string_hex(test);
        std::cout << result << std::endl;
    }

    return 0;
}