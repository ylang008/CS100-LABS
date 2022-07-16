#ifndef __LISTCONTAINER_TEST_HPP__
#define __LISTCONTAINER_TEST_HPP__

#include "gtest/gtest.h"
#include "listContainer.hpp"
#include "bubbleSort.hpp"
#include "SelectionSort.hpp"
#include "base.hpp"

TEST(ContainerList_add_element, simpleOperands) {
	ListContainer l;
	Base* seven = new Op(7);
	Base* three = new Op(3);
	l.add_element(seven);
        l.add_element(three);

	testing::internal::CaptureStdout();
        l.print();
        std::string output = testing::internal::GetCapturedStdout();
	
	EXPECT_EQ(output, "73");
}

TEST(ContainerList_add_element, combinationOps) {
	ListContainer l;
	Base* seven = new Op(7);
	Base* three = new Op(3);
	Base* mult = new Mult(seven, three);
	l.add_element(seven);
	l.add_element(three);
	l.add_element(mult);

	testing::internal::CaptureStdout();
	l.print();
	std::string output = testing::internal::GetCapturedStdout();
	
	EXPECT_EQ(output, "737 * 3");
}

TEST(ContainerList_swap, simpleOperandsMiddle) {
	ListContainer l;
        Base* seven = new Op(7);
        Base* three = new Op(3);

	l.add_element(seven);
        l.add_element(three);
   	l.add_element(seven);
	l.add_element(seven);
	l.swap(1,2);

	testing::internal::CaptureStdout();
        l.print();
        std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(output, "7737");
}

TEST(ContainerList_swap, simpleOperandsEdge) {
        ListContainer l;
        Base* seven = new Op(7);
        Base* three = new Op(3);

        l.add_element(three);
        l.add_element(seven);
        l.add_element(seven);
        l.add_element(seven);
        l.swap(0,3);

        testing::internal::CaptureStdout();
        l.print();
        std::string output = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output, "7773");
}

TEST(ContainerList_at, simpleOperands) {
	ListContainer l;
        Base* seven = new Op(7);
        Base* three = new Op(3);

	l.add_element(seven);
	l.add_element(seven);
	l.add_element(seven);
	l.add_element(three);
	l.add_element(seven);
	
	EXPECT_EQ(l.at(3)->stringify(), "3");
}

TEST(ContainerList_at, opTree) {
        ListContainer l;
        Base* seven = new Op(7);
        Base* three = new Op(3);
	Mult* mult = new Mult(seven, three);
	Div* div = new Div(mult, three);

        l.add_element(mult);
        l.add_element(div);
        l.add_element(mult);

        EXPECT_EQ(l.at(1)->stringify(), "7 * 3 / 3" );
}

TEST(ContainerList_sort, NullPtr) {
	ListContainer l;
	
	testing::internal::CaptureStdout();
        l.sort();
        std::string output = testing::internal::GetCapturedStdout();
	
	EXPECT_EQ(output, "Caught exception");
}

TEST(ContainerList_sort, EmptyBubbleSort) {
        ListContainer l(new BubbleSort());
	l.sort();

	testing::internal::CaptureStdout();
        l.print();
        std::string output = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output, "");
}

TEST(ContainerList_sort, BubbleSort) {
	ListContainer l(new BubbleSort());
 	Base* seven = new Op(7);
        Base* three = new Op(3);
	Base* four = new Op(4);
	l.add_element(seven);
	l.add_element(three);
	l.add_element(four);
 	l.sort();
	
	testing::internal::CaptureStdout();
        l.print();
        std::string output = testing::internal::GetCapturedStdout();
	
	EXPECT_EQ(output, "347");
}

TEST(ContainerList_sort, EmptySelectionSort) {
        ListContainer l(new SelectionSort());
        l.sort();

        testing::internal::CaptureStdout();
        l.print();
        std::string output = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output, "");
}

TEST(ContainerList_sort, SelectionSort) {
        ListContainer l(new SelectionSort());
        Base* seven = new Op(7);
        Base* three = new Op(3);
        Base* four = new Op(4);
        l.add_element(seven);
        l.add_element(three);
        l.add_element(four);
	l.sort();
        testing::internal::CaptureStdout();
        l.print();
        std::string output = testing::internal::GetCapturedStdout();

        EXPECT_EQ(output, "347");
}

TEST(ContainerList_size, Empty) {
        ListContainer l;
        EXPECT_EQ(l.size(), 0);
}

TEST(ContainerList_size, NonEmpty) {
	ListContainer l;
        Base* seven = new Op(7);
	l.add_element(seven);
	l.add_element(seven);
	l.add_element(seven);
	
	EXPECT_EQ(l.size(), 3);	
}

#endif
