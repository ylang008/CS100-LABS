#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"

SevenOpMock* sevenhalf_add = new SevenOpMock();
NegativeSevenOpMock* negseven_add = new NegativeSevenOpMock();
ZeroOpMock* zero_add = new ZeroOpMock();

TEST(AddTest, AddEvaluateNonZero) {
        Add* test = new Add(sevenhalf_add, sevenhalf_add);
        EXPECT_EQ(test->evaluate(), 15.0);
}

TEST(AddTest, AddEvaluateNegative) {
        Add* test = new Add(negseven_add, negseven_add);
        EXPECT_EQ(test->evaluate(), -15.0);
}

TEST(AddTest, AddEvaluateZero) {
        Add* test= new Add(sevenhalf_add, zero_add);
        EXPECT_EQ(test->evaluate(), 7.5);
}

TEST(AddTest, AddStringifyNonZero) {
        Add* test = new Add(sevenhalf_add, sevenhalf_add);
        EXPECT_EQ(test->stringify(), "7.5 + 7.5");
}

TEST(AddTest, AddStringifyNegative) {
        Add* test = new Add(negseven_add, negseven_add);
        EXPECT_EQ(test->stringify(), "-7.5 + -7.5");
}

TEST(AddTest, AddStringifyZero) {
        Add* test = new Add(negseven_add, zero_add);
        EXPECT_EQ(test->stringify(), "-7.5 + 0");
}

#endif
