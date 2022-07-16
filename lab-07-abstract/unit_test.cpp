#include "gtest/gtest.h"
#include "BaseFactory.hpp"
#include "op.hpp"
#include "Rand.hpp"
#include "base.hpp"

#include <iostream>
#include <string>

using namespace std;

TEST(BaseFactoryTests, ParseSimpleExpression) {
	char* test_val[4]; test_val[0] = "."; test_val[1] = "8"; test_val[2] = "+"; test_val[3] = "2"; 
	BaseFactory factory;
	Base* tree = factory.parse(test_val, 4);
	EXPECT_EQ(tree->evaluate(), 10);
}

TEST(BaseFactoryTests, ParseSimpleExpression2) {
        char* test_val[4]; test_val[0] = "."; test_val[1] = "3"; test_val[2] = "**"; test_val[3] = "3";
        BaseFactory factory;
        Base* tree = factory.parse(test_val, 4);
        EXPECT_EQ(tree->evaluate(), 27);
}

TEST(BaseFactoryTests, ParseLongerExpression) {
        char* test_val[] = {"./exe","8","+","2","-","5"};
        BaseFactory factory;
        Base* tree = factory.parse(test_val, 6);
        EXPECT_EQ(tree->evaluate(), 5);
}

TEST(BaseFactoryTests, ParseMultipleOps) {
	char* test_val[] = {"./exe","8","+","2","-","4","*","2","/","3"};
        BaseFactory factory;
        Base* tree = factory.parse(test_val, 10);
        EXPECT_EQ(tree->evaluate(), 4);
}

TEST(BaseFactoryTests, ParseSpaceless) {
        char* test_val[] = {"./exe","8+2-5"};
        BaseFactory factory;
        Base* tree = factory.parse(test_val, 2);
        EXPECT_EQ(tree->evaluate(), 5);
}

TEST(BaseFactoryTests, ParseDoubleDigitExpression) {
	char* test_val[] = {"./exe","10","+","2","-","11"};
	BaseFactory factory;
        Base* tree = factory.parse(test_val, 6);
        EXPECT_EQ(tree->evaluate(), 1);
}

TEST(BaseFactoryTests, ParseRandExpression) {
        char* test_val[] = {"./exe","?","+","1"};
        BaseFactory factory;
        Base* tree1 = factory.parse(test_val, 4);
	Base* tree2 = factory.parse(test_val, 4);
        EXPECT_NE(tree1->evaluate(), tree2->evaluate());
}

TEST(BaseFactoryTests, IncorrectSyntaxExpression) {
	char* test_val[] = {"./exe","+","1","-","2"};
        BaseFactory factory;
        Base* tree = factory.parse(test_val, 5);
        EXPECT_EQ(tree, nullptr);
}

TEST(BaseFactoryTests, IncorrectSyntaxExpression2) {
        char* test_val[] = {"./exe","1","-","2","+"};
        BaseFactory factory;
        Base* tree = factory.parse(test_val, 5);
        EXPECT_EQ(tree, nullptr);
}

TEST(BaseFactoryTests, IncorrectSyntaxExpression3) {
        char* test_val[] = {"./exe","1","-","+","2"};
        BaseFactory factory;
        Base* tree = factory.parse(test_val, 5);
        EXPECT_EQ(tree, nullptr);
}

TEST(BaseFactoryTests, IncorrectSyntaxExpression4) {
        char* test_val[] = {"./exe","1","t","+","2"};
        BaseFactory factory;
        Base* tree = factory.parse(test_val, 5);
        EXPECT_EQ(tree, nullptr);
}

ZeroOpMock* zero_o = new ZeroOpMock();
SevenOpMock* seven_o = new SevenOpMock();
FiveOpMock* five_o = new FiveOpMock();
ZeroRandMock* zero_r= new ZeroRandMock();
SevenRandMock* seven_r = new SevenRandMock();
FiveRandMock* five_r = new FiveRandMock();

TEST(getBase_OneParameter_Test, randomlynum) {
 	BaseFactory* bf;
	EXPECT_NE(bf->getBase("rand")->evaluate(),bf->getBase("rand")->evaluate());
	EXPECT_NE(bf->getBase("rand")->stringify(),bf->getBase("rand")->stringify());
}

TEST(getBase_OneParameter_Test, randInvalidInput) {
	BaseFactory* bf;
   	EXPECT_EQ(bf->getBase(""),nullptr);
   	EXPECT_EQ(bf->getBase("hi"),nullptr);
}
 
TEST(getBase_TowParameter_Test, zeroBase) {
  	BaseFactory* bf;
 	EXPECT_EQ(bf->getBase("op",0)->evaluate(),zero_o->evaluate());
  	EXPECT_EQ(bf->getBase("op",0)->stringify(),zero_o->stringify());
}

TEST(getBase_TowParameter_Test,nonZeroBase) {
  	BaseFactory* bf;
  	EXPECT_EQ(bf->getBase("op",7)->evaluate(),seven_o->evaluate());
  	EXPECT_EQ(bf->getBase("op",7)->stringify(),seven_o->stringify());
}

TEST(getBase_TowParameter_Test, invalidInput) {
  	BaseFactory* bf;
  	EXPECT_EQ(bf->getBase("",0),nullptr);
  	EXPECT_EQ(bf->getBase("rand",0),nullptr);
  	EXPECT_EQ(bf->getBase("hi",0),nullptr); 
}

TEST(getBase_ThreeParameter_mult_Test, positiveBase) {
  	BaseFactory* bf;
  	Mult* mult = new Mult(seven_o,five_o); 
  	EXPECT_EQ(bf->getBase("*",seven_o,five_o)->evaluate(),mult->evaluate());
  	EXPECT_EQ(bf->getBase("*",seven_o,five_o)->stringify(),mult->stringify());
}

TEST(getBase_ThreeParameter_div_Test, positiveBase) {
   	BaseFactory* bf;
   	Div* div = new Div(seven_o,five_o);
   	EXPECT_EQ(bf->getBase("/",seven_o,five_o)->evaluate(),div->evaluate());
   	EXPECT_EQ(bf->getBase("/",seven_o,five_o)->stringify(),div->stringify());
}

TEST(getBase_ThreeParameter_add_Test, positiveBase) {
   	BaseFactory* bf;
   	Add* add = new Add(seven_o,five_o);
   	EXPECT_EQ(bf->getBase("+",seven_o,five_o)->evaluate(),add->evaluate());
   	EXPECT_EQ(bf->getBase("+",seven_o,five_o)->stringify(),add->stringify());  }

TEST(getBase_ThreeParameter_sub_Test, positiveBase) {
   	BaseFactory* bf;
   	Sub* sub = new Sub(seven_o,five_o);
   	EXPECT_EQ(bf->getBase("-",seven_o,five_o)->evaluate(),sub->evaluate());
   	EXPECT_EQ(bf->getBase("-",seven_o,five_o)->stringify(),sub->stringify());  }

TEST(getBase_ThreeParameter_pow_Test, positiveBase) {
   	BaseFactory* bf;
   	Pow* pow = new Pow(seven_o,five_o);
   	EXPECT_EQ(bf->getBase("**",seven_o,five_o)->evaluate(),pow->evaluate());
   	EXPECT_EQ(bf->getBase("**",seven_o,five_o)->stringify(),pow->stringify()); 
}

TEST(getBase_ThreeParameter_Test, invalidInput) {
   	BaseFactory* bf;
   	EXPECT_EQ(bf->getBase("",seven_o,five_o),nullptr);
   	EXPECT_EQ(bf->getBase("hi",seven_o,five_o),nullptr); 
}   

int main(int argc, char **argv) {
  	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}
