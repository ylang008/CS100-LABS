#ifndef __OPERATOR_HPP__
#define __OPERATOR_HPP__
 
#include "base.hpp"
 
  class Operator : public Base {
      protected:
          Base* left;
          Base* right;
      public:
          virtual double evaluate() = 0;
          virtual std::string stringify() = 0;
 };
#endif //__Operator___HPP

