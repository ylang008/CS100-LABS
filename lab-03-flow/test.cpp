#include "c-echo.h"
#include "c-count.h"

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

TEST(CountTest, HelloWorld) {
	std::string test_str = "hello world";
	EXPECT_EQ(2, count(test_str));
}

TEST(CountTest, EmptyString) {
        std::string test_str = "";
        EXPECT_EQ(0, count(test_str));
}

TEST(CountTest, ManySpaces) {
        std::string test_str = "   this   string has     weird   spacing";
        EXPECT_EQ(5, count(test_str));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
