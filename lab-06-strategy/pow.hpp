#ifndef __POW_HPP__
#define _POW_HPP__
#include "base.hpp"
#include "operator.hpp"
#include "math.h"
class Pow : public Operator {
      
    public:
        Pow(Base* left, Base* right){this->left = left; this->right = right; }
        virtual double evaluate() {return pow( left->evaluate(),right->evaluate()); }
        virtual std::string stringify(){return left->stringify() + " ** " + right->stringify();} 
};


class ThreePowMock : public Base {
        public:
                ThreePowMock() {};
                virtual double evaluate() { return 3.0 ;}
                virtual std::string stringify() { return "3.0";}
};
class NegFivePowMock : public Base {
        public:
                NegFivePowMock() {};
                virtual double evaluate() { return -5.0; }
                virtual std::string stringify() { return "-5.0"; }
};

class ZeroPowMock : public Base {
        public:
                ZeroPowMock() {};
                virtual double evaluate() { return 0; }
                virtual std::string stringify() { return "0" ;}
};
#endif //__POW_HPP__
