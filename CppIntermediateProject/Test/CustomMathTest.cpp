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
TEST(sub_One_Arguments, TestCase_2_PASSED)
{
    EXPECT_EQ(5, Lib::sub(5));
}
TEST(sub_One_Arguments, TestCase_3_PASSED)
{
    Lib::Custom custom("I");
    EXPECT_EQ(custom.getCustomValue().c_str(), Lib::sub(custom).getCustomValue());
}
TEST(sub_Two_Arguments, TestCase_4_PASSED)
{
    EXPECT_EQ(-2, Lib::sub(0,2));
    EXPECT_EQ(2, Lib::sub(0,-2));
    EXPECT_EQ(2.6, Lib::sub(0.0,-2.6));
    EXPECT_EQ(2.6f, Lib::sub(0.0,-2.6f));
}
TEST(sub_Three_Arguments, TestCase_4_PASSED)
{
    EXPECT_EQ(-12, Lib::sub(4,6,10));
    EXPECT_EQ(-3, Lib::sub(0,-2,5));
    EXPECT_EQ(-1.4, Lib::sub(0.0,-2.6,4));
    EXPECT_EQ(-8.0f, Lib::sub(0.0f,-2.6f,10.6f));
}
TEST(sub_Two_Arguments_Custom, TestCase_5_PASSED)
{
    Lib::Custom custom1("Ibraheeim");
    Lib::Custom custom2("ee");
    EXPECT_STREQ("Ibrahim", Lib::sub<Lib::Custom>(custom1, custom2).getCustomValue().c_str());
}
TEST(sub_Three_Arguments_Custom, TestCase_6_PASSED)
{
    Lib::Custom custom1("Ibraheeim Sabiiiiier");
    Lib::Custom custom2("ee");
    Lib::Custom custom3("iiiii");
    EXPECT_STREQ("Ibrahim Saber", Lib::sub<Lib::Custom>(custom1,custom2,custom3).getCustomValue().c_str());
}
int main(void){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
