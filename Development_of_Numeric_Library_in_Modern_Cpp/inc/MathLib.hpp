#pragma once
#ifndef _MATHLIB_HPP_
#define _MATHLIB_HPP_
#include <string>

namespace Lib
{
    class Custom
    {
    public:
        Custom(std::string b) : m_b{b} {}
        ~Custom() {}
        void print() { std::cout << m_b << "\n"; }
        void setCustomValue(std::string val){m_b = val;}
        std::string getCustomValue(void) const { return this->m_b; }
        Custom friend operator-(const Custom &Obj1, const Custom &Obj2)
        {
            Custom temp(Obj1.m_b);
            std::string::size_type iter = temp.m_b.find(Obj2.m_b);
            if (iter != std::string::npos)
            {
                temp.m_b.erase(iter, Obj2.m_b.length());
            }
            return temp;
        }

    private:
        std::string m_b;
    };

    /// @brief Function overloading of the min template Function to get the min of No parameters are passed
    /// @return [int] 0
    int min()
    {
        return 0;
    }
    /**
     * @brief template overloading of the min template Function to get the min of only one parameter is passed
     *
     * @tparam T
     * @param Arg1
     * @return T
     */
    template <typename T>
    T min(const T &Arg1)
    {
        // static_assert(condition, message);
        // condition is a compile time expression
        // message is a string literal
        // if condition is false, the program is aborted (generate a compiler error)
        // programming by contrcat
        static_assert(std::is_arithmetic_v<T>, "This Function Works Only for Athimetic data types");
        return Arg1;
    }
    /**
     * @brief Template min Function to get the min of two or more parameters
     *
     * @tparam T
     * @tparam U
     * @tparam Ts
     * @param Arg1
     * @param Arg2
     * @param Va_list
     * @return auto
     */
    template <typename T, typename U, typename... Ts>
    auto min(const T &Arg1, const U &Arg2, const Ts &...Va_list)
    {
        static_assert((std::is_arithmetic_v<T> && std::is_arithmetic_v<U>), "This Function Works Only for Athimetic data types");
        // tail recursion Method
        if constexpr (sizeof...(Va_list) > 0)
        {
            auto l_result = ((Arg1 < Arg2) ? Arg1 : Arg2);
            return min(l_result, Va_list...);
        }
        else
        {
            return ((Arg1 < Arg2) ? Arg1 : Arg2);
        }
    }
    /**
     * @brief Function overloading of the max template Function to get the max of No parameters are passed
     * @return [int] 0
     */
    int max()
    {
        return 0;
    }
    /**
     * @brief template overloading of the max template Function to get the max of only one parameter is passed
     *
     * @tparam T
     * @param Arg1
     * @return T
     */
    template <typename T>
    T max(const T &Arg1)
    {
        static_assert(std::is_arithmetic_v<T>, "This Function Works Only for Athimetic data types");
        return Arg1;
    }
    /**
     * @brief Template Max Function to get the max of two or more parameters
     *
     * @tparam T
     * @tparam U
     * @tparam Ts
     * @param Arg1
     * @param Arg2
     * @param Va_list
     * @return auto
     */
    template <typename T, typename U, typename... Ts>
    auto max(const T &Arg1, const U &Arg2, const Ts &...Va_list)
    {
        static_assert((std::is_arithmetic_v<T> && std::is_arithmetic_v<U>), "This Function Works Only for Athimetic data types");
        // tail recursion Method
        if constexpr (sizeof...(Va_list) > 0)
        {
            auto l_result = ((Arg1 > Arg2) ? Arg1 : Arg2);
            return max(l_result, Va_list...);
        }
        else
        {
            return ((Arg1 > Arg2) ? Arg1 : Arg2);
        }
    }

    /**
     * @brief template overloading of the sub template Function to get the sub of only one parameter is passed
     *
     * @tparam T
     * @param Arg1
     * @return T
     */
    template <typename T>
    auto sub(const T &Arg1)
    {
        return Arg1;
    }
    /**
     * @brief Template sub Function to get the sub of two or more parameters
     *
     * @tparam T
     * @tparam U
     * @tparam Ts
     * @param Arg1
     * @param Arg2
     * @param Va_list
     * @return auto
     */
    template <typename T, typename U>
    auto sub(const T &a, const U &b)
    {
        static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, "This Function Works Only for Athimetic data types");
        return (a - b);
    }
    template <>
    auto sub<Custom>(const Custom &a,const Custom &b)
    {
        return a - b;
    }
    template <typename... Ts>
    auto sub(const Ts &...Va_list)
    {
        return (... - Va_list);
    }

}

#endif
