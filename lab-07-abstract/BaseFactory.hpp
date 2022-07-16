#ifndef __BASEFACTORY_HPP__
#define __BASEFACTORY_HPP__

#include "op.hpp"
#include "Rand.hpp"
#include "Operator.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Mult.hpp"
#include "Pow.hpp"
#include "Div.hpp"
#include <string>

using namespace std;

class BaseFactory {
	private:
		Base* root;
	public:
		BaseFactory();
		Base* parse(char** input, int length);
		Base* getBase(string input);
		Base* getBase(string input, int value);
		Base* getBase(string input, Base* left, Base* right);
};

#endif
