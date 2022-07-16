#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "pow.hpp"

ThreePowMock* three_pow = new ThreePowMock();
NegFivePowMock* negfive_pow  = new NegFivePowMock();
ZeroPowMock* zero_pow  = new ZeroPowMock();

TEST(Powtest, PowEvaluatePositive){
    Pow* test = new Pow( three_pow , three_pow  );
    EXPECT_EQ(test->evaluate(), 27); 
}

TEST(Powtest, PowEvaluateNegative){
    Pow* test = new Pow(  negfive_pow ,  three_pow );
    EXPECT_EQ(test->evaluate(),-125 );
}

TEST(Powtest, PowEvaluateZero){
    Pow* test = new Pow(  three_pow ,  zero_pow );
    EXPECT_EQ(test->evaluate(), 1);
}

TEST(Powtest, PowstringifyPosituve){
    Pow* test = new Pow( three_pow  ,three_pow );
    EXPECT_EQ(test->stringify(), "3.0 ** 3.0");
}


TEST(Powtest, PowstringifyNegative){
   Pow* test = new Pow(  negfive_pow  ,  negfive_pow  );
   EXPECT_EQ(test->stringify(),"-5.0 ** -5.0" );
}

TEST(Powtest, PowstringifyZero){
   Pow* test = new Pow(  three_pow  ,  zero_pow );
   EXPECT_EQ(test->stringify(), "3.0 ** 0");
}



#endif//__POW_TEST_HPP__

