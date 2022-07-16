#ifndef __DIV_HPP__
#define __DIV_HPP__
#include "base.hpp"
#include "Operator.hpp"

class Div : public Operator {
      
    public:
        Div(Base* left, Base* right){this->left = left; this->right = right; }
        virtual double evaluate() {return left->evaluate()/right->evaluate(); }
        virtual std::string stringify(){return left->stringify() + " / " + right->stringify();} 
};


class SevenDivMock : public Base {
        public:
                SevenDivMock() {};
                virtual double evaluate() { return 7.5 ;}
                virtual std::string stringify() { return "7.5";}
};
class NegEightDivMock : public Base {
        public:
                NegEightDivMock() {};
                virtual double evaluate() { return -8.0; }
                virtual std::string stringify() { return "-8.0"; }
};

class ZeroDivMock : public Base {
        public:
                ZeroDivMock() {};
                virtual double evaluate() { return 0; }
                virtual std::string stringify() { return "0" ;}
};
#endif //__DIV_HPP__
