#ifndef __LISTCONTAINER_HPP__
#define __LISTCONTAINER_HPP__

#include "sort.hpp"
#include "base.hpp"
#include "container.hpp"

#include <list>
#include <iterator>

class ListContainer : public Container {
	protected:
		std::list<Base*> baseList;
	public:
		ListContainer();
		ListContainer(Sort* function);
		void set_sort_function(Sort* sort_function);
		void add_element(Base* element);
		void print();
		void sort();
		void swap(int i, int j);
		Base* at(int i);
		int size();
};

#endif
