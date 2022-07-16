#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "mult.hpp"
#include "op.hpp"

SevenOpMock* sevenhalf = new SevenOpMock();
NegativeSevenOpMock* negseven = new NegativeSevenOpMock();
ZeroOpMock* zero = new ZeroOpMock();

TEST(MultTest, MultEvaluateNonZero) {
    Mult* test = new Mult(sevenhalf, sevenhalf);
    EXPECT_EQ(test->evaluate(), 56.25);
}

TEST(MultTest, MultEvaluateNonZero2) {
    Mult* test = new Mult(negseven, negseven);
    EXPECT_EQ(test->evaluate(), 56.25);
}

TEST(MultTest, MultEvaluateNegative) {
    Mult* test = new Mult(sevenhalf, negseven);
    EXPECT_EQ(test->evaluate(), -56.25);
}

TEST(MultTest, MultEvaluateZero) {
    Mult* test = new Mult(sevenhalf, zero);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultStringifyNonZero) {
    Mult* test = new Mult(sevenhalf, sevenhalf);
    EXPECT_EQ(test->stringify(), "7.5 * 7.5");
}

TEST(MultTest, MultStringifyNegative) {
    Mult* test = new Mult(sevenhalf, negseven);
    EXPECT_EQ(test->stringify(), "7.5 * -7.5");
}

TEST(MultTest, MultStringifyZero) {
    Mult* test = new Mult(sevenhalf, zero);
    EXPECT_EQ(test->stringify(), "7.5 * 0");
}



#endif //__MULT_TEST_HPP__
