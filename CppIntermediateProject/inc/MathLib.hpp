#pragma once
#ifndef _MATHLIB_HPP_
#define _MATHLIB_HPP_



namespace Lib
{
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
    T min(const T & Arg1)
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
    template<typename T, typename U, typename ... Ts >
    auto min(const T & Arg1, const U & Arg2, const Ts & ... Va_list)
    {
        static_assert((std::is_arithmetic_v<T> && std::is_arithmetic_v<U> ), "This Function Works Only for Athimetic data types");
        // tail recursion Method
        if constexpr (sizeof ... (Va_list) > 0)
        {
            auto l_result = ((Arg1<Arg2) ? Arg1 : Arg2);
            return min(l_result, Va_list ...);
        }
        else
        {
            return ((Arg1<Arg2) ? Arg1 : Arg2);
        }
    }
    /**
     * @brief Function overloading of the min template Function to get the max of No parameters are passed
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
    T max(const T & Arg1)
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
    template<typename T, typename U, typename ... Ts >
    auto max(const T & Arg1, const U & Arg2, const Ts & ... Va_list)
    {
        static_assert((std::is_arithmetic_v<T> && std::is_arithmetic_v<U> ), "This Function Works Only for Athimetic data types");
        // tail recursion Method
        if constexpr (sizeof ... (Va_list) > 0)
        {
            auto l_result = ((Arg1>Arg2) ? Arg1 : Arg2);
            return max(l_result, Va_list ...);
        }
        else{
            return ((Arg1>Arg2) ? Arg1 : Arg2);
        }        
    }
}

#endif
