#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"

TEST(OpMockTest, OpMockEvaluateNonZero) {
    SevenOpMock* test = new SevenOpMock();
    ASSERT_EQ(test->evaluate(), 7.5);
}

TEST(OpMockTest, OpMockEvaluateZero) {
    ZeroOpMock* test = new ZeroOpMock();
    ASSERT_EQ(test->evaluate(), 0);
}

TEST(OpMockTest, OpMockEvaluateNegative) {
    NegativeSevenOpMock* test = new NegativeSevenOpMock();
    ASSERT_EQ(test->evaluate(), -7.5);
}

TEST(OpMockTest, OpMockStringifyNonZero) {
    SevenOpMock* test = new SevenOpMock();
    ASSERT_EQ(test->stringify(), "7.5");
}

TEST(OpMockTest, OpMockStringifyZero) {
    ZeroOpMock* test = new ZeroOpMock();
    ASSERT_EQ(test->stringify(), "0");
}

TEST(OpMockTest, OpMockStringifyNegative) {
    NegativeSevenOpMock* test = new NegativeSevenOpMock();
    ASSERT_EQ(test->stringify(), "-7.5");
}

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0.0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpEvaluateNegative) {
    Op* test = new Op(-8.5);
    EXPECT_EQ(test->evaluate(), -8.5);
}

TEST(OpTest, OpStringifyNonZero) {
    Op* test = new Op(8.10);
    EXPECT_EQ(test->stringify(), "8.1");
}

TEST(OpTest, OpStringifyNonZero2) {
    Op* test = new Op(8.0);
    EXPECT_EQ(test->stringify(), "8");
}

TEST(OpTest, OpStringifyZero) {
    Op* test = new Op(0.0);
    EXPECT_EQ(test->stringify(), "0");
}

TEST(OpTest, OpStringifyNegative) {
    Op* test = new Op(-8.0);
    EXPECT_EQ(test->stringify(), "-8");
}

#endif //__OP_TEST_HPP__
