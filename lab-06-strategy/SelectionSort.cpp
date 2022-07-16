#include "SelectionSort.hpp"

SelectionSort::SelectionSort() : Sort() {}
void SelectionSort :: sort(Container* container) {
  
        int i , j , min;
        int size = container->size();
        for ( i = 0 ; i < size-1 ; i++)
        { 
          min = i;
          for (j = i+1 ; j < size ; j++)
          {
             if (container->at(j)->evaluate() < container->at(min)->evaluate()){
                min = j;
	     }
	  }
             container->swap(i,min);

 
        }
}

