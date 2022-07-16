#include "BaseFactory.hpp"
#include <cctype>
#include <string>
#include <iostream>

BaseFactory::BaseFactory() : root(nullptr) {};

Base* BaseFactory::parse(char** input, int length) {
	// check for valid command input
	if (length < 2) { return nullptr; }

	// create an expression string
	std::string expression = "";
	for (int i = 1; i < length; ++i) {
		expression += input[i];
	}
	//std::cout << expression << std::endl;
	//std::cout << "Expresion size: " << expression.size() << std::endl;
	// check for valid expression
	if (!std::isdigit(expression[0]) && expression[0] != '?') { return nullptr; }
	if (!std::isdigit(expression.back())) { return nullptr; }
	

	// set initial root to operand or rand
	std::string currentOp = ""; // holds a single operator/operand
	int index = 0; // index for entire expression array
	while (index < expression.size()) {
		if (std::isdigit(expression[index])) {
			currentOp += expression[index];
			//std::cout << currentOp << std::endl;
		}
		else if (expression[index] == '?') {
			currentOp = "?";
		}
		else { 
			break; 
		}
		index++;
		//std::cout << "index: " << index << std::endl;
	}


	if (currentOp == "?") {
		root = getBase("rand");
	}
	else { 	
		root = getBase("op", std::stoi(currentOp));
	}
	
	// construct the rest of the tree
	std::string op = ""; // stores the operator
	while (index < expression.size()) {
		//std::cout << "adding more" << std::endl;
		// take in operator
		currentOp = "";
		while (index < expression.size()) {
			if (!std::isdigit(expression[index])) {
                        	currentOp += expression[index];
				//std::cout << currentOp << std::endl;
                	}
			else {
				break;
			}	
			index++;
			//std::cout << "nested index1: " << index << std::endl;
		}

		// make sure next char is an operator
		op = currentOp;
		if (op!="+" && op!="-" && op!="*" && op!="/" && op!="**") { return nullptr; }
		
		// get next operand
		currentOp = "";
		while (index < expression.size()) {
                	if (std::isdigit(expression[index])) {
                	        currentOp += expression[index];
                		//std::cout << currentOp << std::endl;
			}
                	else if (expression[index] == '?') {
                	        currentOp = "?";
                	}
                	else {
                	        break;
                	}
			index++;
			//std::cout << "nested index2: " << index << std::endl;
        	}
		
		// extend tree
		if (currentOp == "?") {
                	root = getBase(op, root, getBase("rand"));
        	}
        	else {
        	        root = getBase(op, root, getBase("op", std::stoi(currentOp)));
	        }
		//index++;
		//std::cout << "outer index: " << index << std::endl;
		//std::cout << "expression size: " << expression.size() << std::endl;
	}
	return root;			
}

Base* BaseFactory::getBase(string input) {
	if (input == "rand") {
		return new Rand();	
	}
	return nullptr;
}

Base* BaseFactory::getBase(string input, int value) {
	if (input == "op") {
		return new Op(value);
	}
	return nullptr;
}

Base* BaseFactory::getBase(string input, Base* left, Base* right){
        if (input == "+"){
        	return new Add(left,right);        
	}
        else if (input == "-"){
        	return new Sub(left,right);
        }
        else if (input == "*"){
        	return new Mult(left,right);
        }
        else if (input == "/"){
        	return new Div(left,right);
        }
        else if (input == "**"){
        	return new Pow(left,right);
        }
	else {
        	return nullptr;
        }
}
