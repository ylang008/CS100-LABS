#include <iostream>
#include "../header/rectangle.hpp"

int main(int argc,char** argv) {
	Rectangle rect;
	if (argc == 3) {
		rect.set_width(std::stoi(argv[1]));
		rect.set_height(std::stoi(argv[2]));
		std::cout << rect.area();
	} 
	else {
		std::cout << 0;
	}	
	return 0;
}

