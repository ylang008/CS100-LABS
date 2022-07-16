#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    private:
	double value;
    public:
        Op(double value) : Base() { this->value = value; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() {
	    if (value == 0) {
		return "0";
	    }
	    std::string str = std::to_string((value));
	    char c[] = {'0', '.'}; 
	    str.erase(str.find_last_not_of(c) + 1, std::string::npos);
	    return str;
	}
};

// Mock classes
class SevenOpMock : public Base {
    public:
        SevenOpMock() { };
        virtual double evaluate() { return 7.5; }
        virtual std::string stringify() { return "7.5"; }
};

class ZeroOpMock : public Base {
    public:
        ZeroOpMock() { };
        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "0"; }
};

class NegativeSevenOpMock : public Base {
    public:
        NegativeSevenOpMock() { };
        virtual double evaluate() { return -7.5; }
        virtual std::string stringify() { return "-7.5"; }
};


#endif //__OP_HPP__
