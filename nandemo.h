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
#include <cmath>
#include <climits>
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
    using uint8 = std::uint8_t;
    using usize = std::size_t;
    using nandemo_nullptr = std::nullptr_t;

    inline constexpr usize BIT_LENGTH = CHAR_BIT;
    inline constexpr usize BINARY_LENGTH = 2;
    inline constexpr usize DECIMAL_LENGTH = 10;
    inline constexpr usize HEX_LENGTH = 16;
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

    template<class type, typename std::enable_if_t<std::is_integral_v<type>,nandemo_nullptr> = nullptr>
    inline constexpr usize digits_hex_unroll4(type value)
    {
        usize number{1};

        for(;;)
        {
            if(value < 16) return number;
            if(value < 256) return number + 1;
            if(value < 4096) return number + 2;
            if(value < 65536) return number + 3;
            value /= static_cast<type>(65536);
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


    template<class type>
    struct string_type
    {
        inline std::string operator()(const type& value) const
        {
            return std::string{value};
        }
    };

    template<class type, usize digits_type = 10>
    struct to_digits
    {
        inline void operator()(char* first, usize length, type value) const
        {
            if constexpr (digits_type == BINARY_LENGTH)
            {
                to_binary(first, length ,value);
            }
            else if constexpr (digits_type == DECIMAL_LENGTH)
            {
                to_decimal(first, length, value);
            }   
            else if constexpr (digits_type == HEX_LENGTH)
            {
                to_hex(first, length, value);
            }
        }

        void to_binary(char* first, usize length, type value) const
        {
            static constexpr char digits[] = "01";

            char* ch = first;
            usize bit_index{0};
            const usize position{length - 1};
            
            while(bit_index <= position)
            {
                ch[bit_index] = digits[(value >> (position - bit_index)) & 1]; 
                bit_index++;
            }
        }

        void to_decimal(char* first, usize length, type value) const
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
        }

        void to_hex(char* first, usize length, type value) const
        {
            static constexpr char digits[] = 
	        "000102030405060708090a0b0c0d0e0f"
            "101112131415161718191a1b1c1d1e1f"
	        "202122232425262728292a2b2c2d2e2f"
            "303132333435363738393a3b3c3d3e3f"
	        "404142434445464748494a4b4c4d4e4f"
            "505152535455565758595a5b5c5d5e5f"
	        "606162636465666768696a6b6c6d6e6f"
            "707172737475767778797a7b7c7d7e7f"
	        "808182838485868788898a8b8c8d8e8f"
            "909192939495969798999a9b9c9d9e9f"
	        "a0a1a2a3a4a5a6a7a8a9aaabacadaeaf"
            "b0b1b2b3b4b5b6b7b8b9babbbcbdbebf"
	        "c0c1c2c3c4c5c6c7c8c9cacbcccdcecf"
            "d0d1d2d3d4d5d6d7d8d9dadbdcdddedf"
	        "e0e1e2e3e4e5e6e7e8e9eaebecedeeef"
            "f0f1f2f3f4f5f6f7f8f9fafbfcfdfeff";

            char* ch = first;
            usize position = length - 1;
            while(value >= 256)
            {
                const usize index = (value % 256) << 1;
                value /= 256;
                ch[position - 1] = digits[index];
                ch[position] = digits[index + 1];
                position -= 2;
            }
            if (value < 16)
            {
                constexpr static char hex[] = "0123456789abcdef";
                ch[position] = hex[value];
                return;
            }

            const usize index = value << 1;
            ch[position - 1] = digits[index];
            ch[position] = digits[index + 1];
        }
    };
    

    template<class type, usize base_type = DECIMAL_LENGTH>
    struct integral_type
    {
        inline std::string operator()(type value) const
        {
            if constexpr (base_type == BINARY_LENGTH)
            {
                return convert_binary(value);
            }
            else if constexpr (base_type == DECIMAL_LENGTH)
            {
                return convert_decimal(value);
            }   
            else if constexpr (base_type == HEX_LENGTH)
            {
                return convert_hex(value);
            }
        }

        inline std::string convert_binary(type value) const
        {
            constexpr usize bits = BIT_LENGTH * sizeof(type);

            std::string result(bits, '0');
            to_digits<type, BINARY_LENGTH>()(&result[0], bits, value);
            return result;            
        }

        inline std::string convert_decimal(type value) const
        {
            const auto abs_value = math::abs(value);
            const usize offset = math::sign(value) ? 1 : 0;
            const usize str_length = math::digits_unroll4(abs_value);

            std::string result(str_length + offset, '0');
            char* result_p = &result[0];

            if (math::sign(value))
            {
                *result_p++ = '-';
            }

            to_digits<type, DECIMAL_LENGTH>()(result_p, str_length, abs_value);

            return result;
        }

        inline std::string convert_hex(type value) const
        {
            const auto signed_value = static_cast<std::make_unsigned_t<type>>(value);
            const usize length = math::digits_hex_unroll4(signed_value);
            std::string result(length, '0');
            char* result_p = &result[0];

            to_digits<std::make_unsigned_t<type>, HEX_LENGTH>()(result_p, length, signed_value);
            return result;            
        }
        
    };

    template<class type, usize base_type, usize padding>
    struct integral_type_zero_padding
    {
        inline std::string operator()(type value) const
        {
            if constexpr (base_type == BINARY_LENGTH)
            {
                return convert_binary(value);
            }
            else if constexpr (base_type == DECIMAL_LENGTH)
            {
                return convert_decimal(value);
            }   
            else if constexpr (base_type == HEX_LENGTH)
            {
                return convert_hex(value);
            }
        }

        inline std::string convert_binary(type value) const
        {
            return integral_type<type, BINARY_LENGTH>()(value);
        }

        inline std::string convert_decimal(type value) const
        {
            const auto abs_value = math::abs(value);

            if (const usize length = math::digits_unroll4(abs_value); padding > length)
            {
                const usize offset = math::sign(value) ? 1 : 0;
                std::string result(padding + offset, '0');
                char* result_p = &result[0];
                if (math::sign(value))
                {
                    *result_p = '-';
                }

                to_digits<type, DECIMAL_LENGTH>()(&result[padding - length + offset], length, abs_value);
                return result;
            }
            else
            {
                return integral_type<type, DECIMAL_LENGTH>()(value);
            }            
        }

        inline std::string convert_hex(type value) const
        {
            const auto signed_value = static_cast<std::make_unsigned_t<type>>(value);

            if (const usize length = math::digits_hex_unroll4(signed_value); padding > length)
            {
                std::string result(padding, '0');
                to_digits<std::make_unsigned_t<type>, HEX_LENGTH>()(&result[padding - length], length, signed_value);
                return result;
            }
            else
            {
                return integral_type<type, HEX_LENGTH>()(value);
            }
        }

    };

    template<class type>
    struct float_type
    {
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
            return float_type<type>()(value);
        }
        else
        {
            return integral_type<type, 10>()(value);
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
            return string_type<type>()(value);
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

    template<class type, usize base, usize padding>
    inline auto to_string_formatting(type value)
    {
        if constexpr (std::is_floating_point_v<type>)
        {
            return float_type<type>()(value);
        }
        else
        {
            return integral_type_zero_padding<type, base, padding>()(value);
        }        
    }

}

namespace nandemo
{
    enum class level : uint8
    {
        normal = 0,
        class_name = 1,
        formatting = 2,
    };

    enum class base : uint8
    {
        binary = BINARY_LENGTH,
        decimal = DECIMAL_LENGTH,
        hex = HEX_LENGTH
    };

    template<base base_n = base::decimal, usize padding = 1, class type>
    inline auto to_string_numeric(const type& value)
    {
        return detail::to_string_formatting<type, static_cast<usize>(base_n), padding>(value);
    }

    template<usize padding = 1, class type>
    inline auto to_string_binary(const type& value)
    {
        return to_string_numeric<base::binary, padding>(value);
    }

    template<usize padding = 1, class type>
    inline auto to_string_decimal(const type& value)
    {
        return to_string_numeric<base::decimal, padding>(value);
    }

    template<usize padding = 1, class type>
    inline auto to_string_hex(const type& value)
    {
        return to_string_numeric<base::hex, padding>(value);
    }

    template<level lv = level::normal, base base_n = base::decimal, usize padding = 1, class type>
    inline auto to_string(const type& value)
    {
        if constexpr (lv == level::normal)
        {
            return detail::to_string(value);
        }
        else if constexpr (lv == level::class_name)
        {
            return detail::to_string_from_class(value);
        }
        else if constexpr (lv == level::formatting)
        {
            return to_string_numeric<base_n, padding>(value);
        }
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