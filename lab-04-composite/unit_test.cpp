#include "gtest/gtest.h"

#include "op_test.hpp"
#include "Mult_test.hpp"
#include "Rand_test.hpp"
#include "Div_test.hpp"
#include "Pow_test.hpp"
#include "Add_test.hpp"
#include "Sub_test.hpp"



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
