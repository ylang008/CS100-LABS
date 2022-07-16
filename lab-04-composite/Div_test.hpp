#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"
#include "Div.hpp"

SevenDivMock* sevenhalf_div = new SevenDivMock();
NegEightDivMock* negeight_div  = new NegEightDivMock();
ZeroDivMock* zero_div  = new ZeroDivMock();

TEST(Divtest, DivEvaluatePositive){
    Div* test = new Div( sevenhalf_div , sevenhalf_div );
    EXPECT_EQ(test->evaluate(), 1); 
}

TEST(Divtest, DivEvaluateNegative){
    Div* test = new Div(  negeight_div ,  negeight_div );
    EXPECT_EQ(test->evaluate(), 1);
}

TEST(Divtest, DivEvaluateZero){
    Div* test = new Div(  zero_div ,  sevenhalf_div );
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(Divtest, DivstringifyPosituve){
    Div* test = new Div( sevenhalf_div , sevenhalf_div );
    EXPECT_EQ(test->stringify(), "7.5 / 7.5");
}


TEST(Divtest, DivstringifyNegative){
   Div* test = new Div(  negeight_div ,  negeight_div );
   EXPECT_EQ(test->stringify(),"-8.0 / -8.0" );
}

TEST(Divtest, DivstringifyZero){
   Div* test = new Div(  zero_div ,  sevenhalf_div );
   EXPECT_EQ(test->stringify(), "0 / 7.5");
}



#endif//__DIV_TEST_HPP__

