#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {

    private:
    double value;
    public:
        Rand() : Base() {value = rand() % 100; }
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


//Mock classes
class SevenRandMock: public Base {
    public:
        SevenRandMock() { };

        virtual double evaluate() { return 7.5; }
        virtual std::string stringify() { return "7.5"; }
};


class ZeroRandMock: public Base {
    public:
        ZeroRandMock() { };

        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "0"; }
};


class NegativeSevenRandMock: public Base {
    public:
        NegativeSevenRandMock() { };

        virtual double evaluate() { return -7.5; }
        virtual std::string stringify() { return "-7.5"; }
};

#endif //__RAND_HPP__

