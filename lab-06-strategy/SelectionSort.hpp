#ifndef __SELECTIONSORT_HPP__
#define __SELECTIONSORT_HPP__

#include "sort.hpp"
#include "container.hpp"
#include "base.hpp"

class SelectionSort : public Sort {
        public:
          SelectionSort();
          void sort (Container* container);

};







#endif//__SELECTIONSORT_HPP__

