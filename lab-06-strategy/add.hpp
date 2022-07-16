#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "operator.hpp"
#include "op.hpp" // t include all the mocks

class Add : public Operator {
        public:
                Add(Base* left, Base* right) {this->left = left; this->right = right; }
                virtual double evaluate() { return left->evaluate() + right->evaluate(); }
                virtual std::string stringify() { return left->stringify() + " + " + right->stringify(); }
};


#endif

