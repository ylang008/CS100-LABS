#include "listContainer.hpp"

#include <iostream>
#include <algorithm>

ListContainer::ListContainer() : Container() {};
ListContainer::ListContainer(Sort* function) : Container(function){};

void ListContainer::set_sort_function(Sort* sort_function) {
	this->sort_function = sort_function;
}

void ListContainer::add_element(Base* element) {
	baseList.push_back(element);
}

void ListContainer::print() {
	std::list<Base*>::iterator it;
        for (it = baseList.begin(); it!= baseList.end(); ++it) {
        	std::cout <<(*it)->stringify();
        }
}

void ListContainer::sort() {
        try {
		if(sort_function == nullptr) {
			throw 1;
		}
		sort_function->sort(this);
	} catch (int e) {
		std::cout << "Caught exception";
	}
}

void ListContainer::swap(int i, int j) {
	std::list<Base*>::iterator it1 = baseList.begin();
	std::list<Base*>::iterator it2 = baseList.begin();
	for (int k = 0; k < i; ++k) { it1++; }
	for (int k = 0; k < j; ++k) { it2++; }
	std::iter_swap(it1, it2);	
}

Base* ListContainer::at(int i) {
	std::list<Base*>::iterator it = baseList.begin();
	for (int k = 0; k < i; ++k) { it++; }
	return *it;
}

int ListContainer::size() { return baseList.size(); }
