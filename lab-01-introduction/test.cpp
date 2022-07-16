#include "c-echo.h"
#include "header/rectangle.hpp"
#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
	EXPECT_EQ("hello world", echo(3, test_val));
}

TEST(EchoTest, EmptyString) {
	char* test_val[1]; test_val[0] = "./c-echo";
	EXPECT_EQ("", echo(1, test_val));
}

TEST(EchoTest, NumberString) {
	char* test_val[2]; test_val[0] = "./c-echo"; test_val[1] = "\t";
	EXPECT_EQ("\t", echo(2, test_val)); 
}

TEST(EchoTest, SingleCharacters) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "h"; test_val[2] = "i";
	EXPECT_EQ("h i", echo(3, test_val));
}

TEST(EchoTest, Combination) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "h"; test_val[2] = "2";
	EXPECT_EQ("h 2", echo(3, test_val));
}

TEST(RectangleTest, BasicArea) {
	char* test_val[3]; test_val[0] = "./rect_area_test"; test_val[1] = "3"; test_val[2] = "4";
	Rectangle rect;
	rect.set_width(3);
	rect.set_height(4);
	EXPECT_EQ(12, rect.area());
}

TEST(RectangleTest, NegativeNumber) {
	char* test_val[3]; test_val[0] = "./rect_area_test"; test_val[1] = "-1"; test_val[2] = "3";
	Rectangle rect;
	rect.set_width(-1);
	rect.set_height(3);	
	EXPECT_EQ(-3, rect.area());
}

TEST(RectangleTest, ZeroLength) {
	char* test_val[3]; test_val[0] = "./rect_area_test"; test_val[1] = "0"; test_val[2] = "2";
	Rectangle rect;
	rect.set_width(0);
	rect.set_height(2);
	EXPECT_EQ(0, rect.area());
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
