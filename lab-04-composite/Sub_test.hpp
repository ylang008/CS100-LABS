#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include "Sub.hpp"

TwoSubMock* twohalf = new TwoSubMock();
NegSixSubMock* negsix = new NegSixSubMock();
ZeroSubMock* zero_ = new ZeroSubMock();

TEST(Subtest, SubEvaluatePositive){
    Sub* test = new Sub(twohalf , twohalf);
    EXPECT_EQ(test->evaluate(), 0); 
}

TEST(Subtest, SubEvaluateNegative){
    Sub* test = new Sub(  negsix,  negsix);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(Subtest, SubEvaluateZero){
    Sub* test = new Sub(  zero_,  twohalf);
    EXPECT_EQ(test->evaluate(), -2.5);
}

TEST(Subtest, SubstringifyPosituve){
    Sub* test = new Sub( twohalf, twohalf);
    EXPECT_EQ(test->stringify(), "2.5 - 2.5");
}


TEST(Subtest, SubstringifyNegative){
   Sub* test = new Sub(  negsix,  negsix);
   EXPECT_EQ(test->stringify(),"-6.0 - -6.0" );
}

TEST(Subtest, SubstringifyZero){
   Sub* test = new Sub(  zero_,  twohalf);
   EXPECT_EQ(test->stringify(), "0 - 2.5");
}



#endif//__SUB_TEST_HPP__
