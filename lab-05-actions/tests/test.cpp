#include "gtest/gtest.h"
#include "../header/rectangle.hpp"

TEST(PerimeterTest,NormalInput) {
    Rectangle rect;
    rect.set_width(3);
    rect.set_height(5);
    EXPECT_EQ(16,rect.perimeter());
}

TEST(PerimeterTest,ZeroInputs) {
    Rectangle rect;
    rect.set_width(0);
    rect.set_height(0);
    EXPECT_EQ(0,rect.perimeter());
}

TEST(PerimeterTest,NegativeInputs) {
    Rectangle rect;
    rect.set_width(-2);
    rect.set_height(4);
    EXPECT_EQ(4,rect.perimeter());
}

TEST(AreaTest,PositiveInputs) {
    Rectangle rect;
    rect.set_width(3);
    rect.set_height(5);
    EXPECT_EQ(15,rect.area());
}

TEST(AreaTest,ZeroInputs) {
    Rectangle rect;
    rect.set_width(0);
    rect.set_height(0);
    EXPECT_EQ(0,rect.area());
}

TEST(AreaTest,NegativeInputs) {
    Rectangle rect;
    rect.set_width(-2);
    rect.set_height(4);
    EXPECT_EQ(-8,rect.area());
}

TEST(RectangleConstructorTest, DefaultConstructor) {
	Rectangle r;
	EXPECT_EQ(r.get_width(), 0);
	EXPECT_EQ(r.get_height(), 0);
}

TEST(RectangleConstructorTest, NonZeroConstructor) {
        Rectangle r(2,4);
        EXPECT_EQ(r.get_width(), 2);
        EXPECT_EQ(r.get_height(), 4);
}

TEST(RectangleConstructorTest, ZeroConstructor) {
        Rectangle r(0,2);
        EXPECT_EQ(r.get_width(), 0);
        EXPECT_EQ(r.get_height(), 2);
}

TEST(RectangleConstructorTest, NegativeConstructor) {
        Rectangle r(-2,-4);
        EXPECT_EQ(r.get_width(), -2);
        EXPECT_EQ(r.get_height(), -4);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
