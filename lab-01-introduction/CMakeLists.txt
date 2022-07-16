CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(area_calculator
	src/main1.cpp
	src/rectangle.cpp
)

ADD_EXECUTABLE(c-echo
	main2.cpp
)

ADD_EXECUTABLE(rect_area_test
	src/main3.cpp
	src/rectangle.cpp
)

ADD_EXECUTABLE(test
	test.cpp
	src/rectangle.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
