#include "BaseFactory.hpp"
#include <iostream>
#include <string>
#include "base.hpp"
using namespace std;
int main(int argc, char** argv){
BaseFactory bs;

cout << bs.parse(argv, argc)->evaluate()<< endl;
cout <<bs.parse(argv, argc)->stringify()<< endl;

return 0;
}
