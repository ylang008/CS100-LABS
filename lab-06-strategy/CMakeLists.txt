CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE-CXX-STANDARD 11)

ADD_EXECUTABLE(test
	unit_test.cpp
        VectorContainer.cpp
        listContainer.cpp
        SelectionSort.cpp
	bubbleSort.cpp

)



ADD_EXECUTABLE(demo
        main.cpp
        VectorContainer.cpp
        listContainer.cpp
        SelectionSort.cpp
        bubbleSort.cpp
 
  )


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
