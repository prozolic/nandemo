//--------------------------------------------------------------------------------
//  MIT License
//  
//  Copyright (c) 2020 prozolic
//  
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//  
//--------------------------------------------------------------------------------



#ifndef NANDEMO_H
#define NANDEMO_H

#include <algorithm>
#include <charconv>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <typeinfo>
#include <type_traits>

#if defined(__GNUC__)
#include <cxxabi.h>
#endif


namespace nandemo
{
    using int32 = std::int32_t;
    using int64 = std::int64_t;
    using usize = std::size_t;
    using nandemo_nullptr = std::nullptr_t;
}

namespace nandemo::math
{
    template<class type>
    struct zero
    {
        constexpr static type value = static_cast<type>(0);
    };

    template<class type>
    inline constexpr type zero_v = zero<type>::value;

    template<class type>
    inline constexpr bool is_numerical_v = std::is_floating_point_v<type> || std::is_integral_v<type>;

    template<class type, typename std::enable_if_t<is_numerical_v<type> ,nandemo_nullptr> = nullptr>
    inline constexpr type abs(type value)
    {
        return (value < zero_v<type>) ? -value : value; 
    }

    template<class type, typename std::enable_if_t<is_numerical_v<type> ,nandemo_nullptr> = nullptr>
    inline constexpr bool sign(type value)
    {
        return (value < zero_v<type>);
    }

    template<class type, typename std::enable_if_t<std::is_integral_v<type>,nandemo_nullptr> = nullptr>
    inline constexpr usize digits_unroll4(type value)
    {
        usize number{1};

        for(;;)
        {
            if(value < 10) return number;
            if(value < 100) return number + 1;
            if(value < 1000) return number + 2;
            if(value < 10000) return number + 3;
            value /= static_cast<type>(10000);
            number += 4;
        }
    }

}


namespace nandemo::detail
{
    
    template<class type>
    struct has_to_string
    {
    private:
        template<class other_type>
        static auto check(other_type o) -> decltype(o.to_string(),std::true_type());
        static std::false_type check(...);

    public:
        constexpr static bool value = decltype(check(std::declval<type>()))::value; 
    };

    template<class type>
    inline constexpr bool has_to_string_v = has_to_string<type>::value;

    template<class type, class return_type>
    struct is_to_string_return_type
    {
        struct dummy_to_string_functor
        {
            template<class real_type>
            inline auto operator()(const real_type& value) const
            {
                return value.to_string();
            }
        };

        constexpr static bool value = 
            std::is_same_v<return_type,  std::invoke_result_t<dummy_to_string_functor,type>>;
    };

    template<class type, class return_type>
    constexpr bool is_to_string_return_type_v = is_to_string_return_type<type, return_type>::value;

    template<class type>
    struct convert_to_stdstring_type : std::false_type{};

    template<>
    struct convert_to_stdstring_type<char> : std::true_type{};

    template<>
    struct convert_to_stdstring_type<char*> : std::true_type{};

    template<>
    struct convert_to_stdstring_type<char const*> : std::true_type{};

    template<>
    struct convert_to_stdstring_type<std::string> : std::true_type{};

    template<>
    struct convert_to_stdstring_type<std::string_view> : std::true_type{};

    template<class type>
    inline constexpr bool convert_to_stdstring_type_v = convert_to_stdstring_type<std::decay_t<type>>::value;

    template<class type>
    struct is_numeric_type
    {
        static constexpr bool value = 
            !convert_to_stdstring_type_v<type> && math::is_numerical_v<type>;
    };

    template<class type>
    inline constexpr bool is_numeric_type_v = is_numeric_type<type>::value;

    template<class type>
    struct is_bool : std::false_type{};

    template<>
    struct is_bool<bool> : std::true_type{};

    template<class type>
    inline constexpr bool is_bool_v = is_bool<type>::value;


    struct string_type
    {
        template<class type>
        inline std::string operator()(const type& value) const
        {
            return std::string{value};
        }
    };

    struct integral_type
    {
        template<class type>
        inline std::string operator()(type value) const
        {
            const auto abs_value = math::abs(value);
            const usize offset = math::sign(value) ? 1 : 0;
            const usize str_length = math::digits_unroll4(abs_value);

            std::string result(str_length + offset, '\0');
            char* result_p = &result[0];

            if (math::sign(value))
            {
                *result_p++ = '-';
            }

            to_digit10(abs_value, result_p, str_length);

            return result;
        }

        template<class type>
        inline void to_digit10(type value, char* first, usize length) const noexcept
        {
            static constexpr char digits[] = 
	        "0001020304050607080910111213141516171819"
	        "2021222324252627282930313233343536373839"
	        "4041424344454647484950515253545556575859"
	        "6061626364656667686970717273747576777879"
	        "8081828384858687888990919293949596979899";

            char* chars = first;
            usize position = length - 1;
            while(value >= 100)
            {
                const usize index = (value % 100) << 1;
                value /= 100;
                chars[position - 1] = digits[index];
                chars[position] = digits[index + 1];

                position -= 2;
            }
            if (value < 10)
            {
                chars[position] = '0' + static_cast<usize>(value);
                return ;
            }

            const usize index = value << 1;
            chars[position - 1] = digits[index];
            chars[position] = digits[index + 1];
            return;
        }

        
    };

    struct float_type
    {
        template<class type>
        inline std::string operator()(type value) const
        {
            return std::to_string(value);
        }
    };


    struct class_type
    {   
        struct ptr_deleter
        {
            template<class type>
            void operator()(type* ptr) const noexcept
            {
                std::free(ptr);
            }
        };

#if defined(__GNUC__)
        inline auto to_string_type_name(const std::type_info& info) const
        {
            int32 status{0};
            std::unique_ptr<char, ptr_deleter> ptr( abi::__cxa_demangle(info.name(), nullptr, nullptr,&status)); 

            return std::string{ptr.get()}; 
        }
#else
        inline auto to_string_type_name(const std::type_info& info) const
        {
            return std::string{info.name()};   
        }      
#endif

        template<class type>
        inline std::string operator()(const type& value) const
        {
            return to_string_type_name(typeid(value));
        }
        
    };

    struct bool_type
    {
        inline std::string operator()(bool value) const
        {
            return value ? "true" : "false";
        }
    };


    template<class type>
    inline auto to_string_from_numerical(type value)
    {
        if constexpr (std::is_floating_point_v<type>)
        {
            return float_type()(value);
        }
        else
        {
            return integral_type()(value);
        }
    }

    template<class type>
    inline auto to_string_from_bool(type value)
    {
        return bool_type()(value);
    }   

    template<class type>
    inline auto to_string_from_class(const type& value)
    {
        return class_type()(value);
    }

    template<class type>
    inline auto to_string_core(const type& value)
    {
        if constexpr (convert_to_stdstring_type_v<type>)
        {
            return string_type()(value);
        }
        else if constexpr (is_numeric_type_v<type> && !is_bool_v<type>)
        {
            return to_string_from_numerical(value);
        }
        else if constexpr (is_numeric_type_v<type> && is_bool_v<type>)
        {
            return to_string_from_bool(value);
        }
        else
        {
            return to_string_from_class(value);   
        }
    }

    struct has_to_string_function_type
    {
        template<class type>
        inline std::string operator()(const type& value) const
        {
            return value.to_string();
        }
    };

    template<class type>
    inline auto to_string(const type& value) -> std::string
    {
        if constexpr (has_to_string_v<type>)
        {
            if constexpr (is_to_string_return_type_v<type, std::string>)
            {
                return has_to_string_function_type()(value);
            }
            else
            {
                return to_string_core(value);
            }
        }
        else
        {
            return to_string_core(value);
        }
    }

}

namespace nandemo
{
    template<class type>
    inline auto to_string(const type& value)
    {
        return detail::to_string(value);
    }

    template<class type, class deleter_type>
    inline auto to_string(const std::unique_ptr<type, deleter_type>& unique)
    {
        return to_string(*unique);
    }

    template<class type>
    inline auto to_string(const std::shared_ptr<type>& shared)
    {
        return to_string(*shared);
    }   

}



#endif //NANDEMO_H