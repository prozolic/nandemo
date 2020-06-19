
#include <iostream>
#include <vector>
#include "nandemo.h"

class test_obj
{
public:
    std::string to_string() const
    {
        return "this is TEST_OBJ!!";
    }
};

class test_obj2
{};

class test_obj3
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
        test_obj test;
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        test_obj2 test;
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        test_obj3 test;
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }

    {
        std::vector<std::string> test;
        std::string result = nandemo::to_string(test);
        std::cout << result << std::endl;
    }


    return 0;
}