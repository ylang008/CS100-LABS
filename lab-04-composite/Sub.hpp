#ifndef __SUB_HPP__
#define __SUB_HPP__
#include "base.hpp"
#include "Operator.hpp"

class Sub : public Operator {
      
    public:
        Sub(Base* left, Base* right){this->left = left; this->right = right; }
        virtual double evaluate() {return left->evaluate()-right->evaluate(); }
        virtual std::string stringify(){return left->stringify() + " - " + right->stringify();} 
};


class TwoSubMock : public Base {
        public:
                TwoSubMock() {};
                virtual double evaluate() { return 2.5 ;}
                virtual std::string stringify() { return "2.5";}
};
class NegSixSubMock : public Base {
        public:
                NegSixSubMock() {};
                virtual double evaluate() { return -6.0; }
                virtual std::string stringify() { return "-6.0"; }
};

class ZeroSubMock : public Base {
        public:
                ZeroSubMock() {};
                virtual double evaluate() { return 0; }
                virtual std::string stringify() { return "0" ;}
};
#endif //__SUB_HPP__A
