#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "MathLib.hpp"

TEST(max_Two_Arguments, TestCase_1_Passed)
{
    EXPECT_EQ(5, Lib::max(5,1));
    EXPECT_EQ(0, Lib::max(0,-1));
    EXPECT_EQ(100, Lib::max(100,99.9));
    EXPECT_EQ(-1, Lib::max(-1,-5));
}
TEST(max_Two_Arguments, TestCase_2_FAILED)
{
    EXPECT_NE(10, Lib::max(10,20));
    EXPECT_NE(1, Lib::max(1,1.2));
    EXPECT_NE(10, Lib::max(10,20));
    EXPECT_NE(-1, Lib::max(-1,0));
}

TEST(max_One_Arguments, TestCase_3_Passed)
{
    EXPECT_EQ(5, Lib::max(5));
    EXPECT_EQ(0, Lib::max(0));
    EXPECT_EQ(100, Lib::max(100));
    EXPECT_EQ(-1, Lib::max(-1));
}

TEST(max_Three_Arguments, TestCase_4_Passed)
{
    EXPECT_EQ(15, Lib::max(5,1,15));
    EXPECT_EQ(0, Lib::max(0,-1,-6));
    EXPECT_EQ(1010, Lib::max(100,99.9,1010));
    EXPECT_EQ(0, Lib::max(-1,-5,0));
}
TEST(max_Three_Arguments, TestCase_5_FAILED)
{
    EXPECT_NE(15, Lib::max(20,1,15));
    EXPECT_NE(0, Lib::max(10,-1,-6));
    EXPECT_NE(100, Lib::max(100,99.9,1010));
    EXPECT_NE(-1, Lib::max(-1,-5,0));
}

TEST(min_Two_Arguments, TestCase_1_Passed)
{
    EXPECT_EQ(5, Lib::max(5,1));
    EXPECT_EQ(0, Lib::max(0,-1));
    EXPECT_EQ(100, Lib::max(100,99.9));
    EXPECT_EQ(-1, Lib::max(-1,-5));
}
TEST(min_Two_Arguments, TestCase_2_FAILED)
{
    EXPECT_NE(10, Lib::max(10,20));
    EXPECT_NE(1, Lib::max(1,1.2));
    EXPECT_NE(10, Lib::max(10,20));
    EXPECT_NE(-1, Lib::max(-1,0));
}

TEST(min_One_Arguments, TestCase_3_Passed)
{
    EXPECT_EQ(5, Lib::max(5));
    EXPECT_EQ(0, Lib::max(0));
    EXPECT_EQ(100, Lib::max(100));
    EXPECT_EQ(-1, Lib::max(-1));
}

TEST(min_Three_Arguments, TestCase_4_Passed)
{
    EXPECT_EQ(15, Lib::max(5,1,15));
    EXPECT_EQ(0, Lib::max(0,-1,-6));
    EXPECT_EQ(1010, Lib::max(100,99.9,1010));
    EXPECT_EQ(0, Lib::max(-1,-5,0));
}
TEST(min_Three_Arguments, TestCase_5_FAILED)
{
    EXPECT_NE(15, Lib::max(20,1,15));
    EXPECT_NE(0, Lib::max(10,-1,-6));
    EXPECT_NE(100, Lib::max(100,99.9,1010));
    EXPECT_NE(-1, Lib::max(-1,-5,0));
}
TEST(min_ZERO_Arguments, TestCase_6_PASSED)
{
    EXPECT_EQ(0, Lib::min());
}
TEST(max_ZERO_Arguments, TestCase_6_PASSED)
{
    EXPECT_EQ(0, Lib::max());
}
int main(void){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
