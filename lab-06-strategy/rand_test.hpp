#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"
#include "rand.hpp"

TEST(RandTest, RandEvaluatePositive) {
    SevenRandMock* test = new SevenRandMock();
    EXPECT_EQ(test->evaluate(), 7.5);
}

TEST(RandTest, RandEvaluateZero) {
    ZeroRandMock* test = new ZeroRandMock();
    EXPECT_EQ(test->evaluate(), 0);
}


TEST(RandTest, RandEvaluateNegative) {
    NegativeSevenRandMock* test = new NegativeSevenRandMock();
    EXPECT_EQ(test->evaluate(), -7.5);
}

TEST(RandMockTest, RandMockStringifyNonZero) {
    SevenRandMock* test = new SevenRandMock();
    ASSERT_EQ(test->stringify(), "7.5");
}

TEST(RandMockTest, RandMockStringifyZero) {
    ZeroRandMock* test = new ZeroRandMock();
    ASSERT_EQ(test->stringify(), "0");
}

TEST(RandMockTest, RandMockStringifyNegative) {
    NegativeSevenRandMock* test = new NegativeSevenRandMock();
    ASSERT_EQ(test->stringify(), "-7.5");
}

TEST(RandTest, RandGenerateRandomly) {
    Rand* r1 = new Rand();
    Rand* r2 = new Rand();

    EXPECT_NE(r1->evaluate(), r2->evaluate());
}

TEST(RandTest, RandLessThanNithyNine) {
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(),99);
}

TEST(RandTest, RandGreaterThanZero) {
    Rand* test = new Rand();
    EXPECT_GT(test->evaluate(), 0);
}

TEST(RandTest, RandStringifyGenerateRandomly) {
    Rand* r1 = new Rand();
    Rand* r2 = new Rand();
    EXPECT_NE(r1->stringify(), r2->stringify());
}





#endif //__RAND_TEST_HPP__

