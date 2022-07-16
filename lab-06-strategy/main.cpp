#include "base.hpp"
#include "op.hpp"
#include "operator.hpp"
#include "rand.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "add.hpp"
#include "sub.hpp"

#include "listContainer.hpp"
#include "VectorContainer.hpp"
#include "bubbleSort.hpp"
#include "SelectionSort.hpp"

#include <iostream>

int main() {
	Op* one = new Op(1);
	Op* two = new Op(2);
	Op* three = new Op(3);
	Op* four = new Op(4);
	Op* five = new Op(5);
	Op* six = new Op(6);
	Op* seven = new Op(7);
	Op* eight = new Op(8);


	std::cout << "Demo using VectorContainer:" << std::endl;
        VectorContainer v(new SelectionSort());
	Mult* subtreeC_treeC = new Mult(two,three);	
	Div* subtreeD_treeD = new Div(six, three);
	Add* treeC = new Add(subtreeC_treeC, subtreeD_treeD);

	v.add_element(treeC);
	std::cout << "Added a tree: " << std::endl;
	v.print();
	std::cout << std::endl;
	v.add_element(subtreeC_treeC);
	std::cout << "Added a tree: " << std::endl;
	v.print();
	std::cout << std::endl;
	v.add_element(subtreeD_treeD);
	std::cout << "Added a tree: " << std::endl;
	v.print();
	std::cout << std::endl;

	std::cout << "Sorting with selection sort: " << std::endl;
	v.sort();
	v.print();
	std::cout << std::endl;	

	v.swap(0, 2);
	std::cout << "Swapping Locations 0 and 2" << std::endl;
	v.print();
	std::cout << std::endl;

	v.set_sort_function(new BubbleSort());
	std::cout << "sorting function set to bubble sort" << std::endl;
	 std::cout << "Sorting with bubble sort: " << std::endl;
	v.sort();	
	v.print();
	std::cout << std::endl;

	std::cout << "evaluated last tree: ";	
	std::cout << v.at(2)->evaluate()<<std::endl;

	
	std::cout << "Demo using ListContainer:" << std::endl;
        ListContainer l(new BubbleSort());
	Mult* subtreeA_treeA = new Mult(two, three);	
	Div* subtreeB_treeB = new Div(six, three);
	Add* treeA = new Add(subtreeA_treeA, subtreeB_treeB);
	
	l.add_element(treeA);
	std::cout << "Added a tree: " << std::endl;
	l.print();
	std::cout << std::endl;
	l.add_element(subtreeA_treeA);
	std::cout << "Added a tree: " << std::endl;
	l.print();
	std::cout << std::endl;
	l.add_element(subtreeB_treeB);
	std::cout << "Added a tree: " << std::endl;
	l.print();
	std::cout << std::endl;
	
	std::cout << "Sorting with bubble sort: " << std::endl;
	l.sort();
	l.print();
	std::cout << std::endl;	

	l.swap(0, 2);
	std::cout << "Swapping Locations 0 and 2" << std::endl;
	l.print();
	std::cout << std::endl;

	l.set_sort_function(new SelectionSort());
	std::cout << "sorting function set to selection sort" << std::endl;
	 std::cout << "Sorting with selection sort: " << std::endl;
	l.sort();	
	l.print();
	std::cout << std::endl;

	std::cout << "evaluated last tree: ";	
	std::cout << l.at(2)->evaluate()<<std::endl;

	return 0;
}
