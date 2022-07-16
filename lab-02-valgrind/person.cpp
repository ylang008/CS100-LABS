#include "person.h"
#include <iostream>
#include <string.h>
#include <array>

using std::cout;
using std::endl;

Person::Person(char *name, Person* father, Person* mother){
    // increase the size of new char[] by 1 because strlen doesn't account for null char created by c-string
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);   
    this->father = father;
    this->mother = mother;
    capacity = 1;
    numChildren = 0;
    children = new Person*[capacity];
}

Person::~Person(){
    // deallocate children array but not the children within, because they are deallocated by PersonList destructor
    delete[] children;
    // deallocate name because a new char array was assigned to it
    delete[] name;
    // set pointers to 0 because they are not longer being used
    father = 0;
    mother = 0;
}

void Person::addChild(Person *newChild){
    if(numChildren == capacity) expand(&children, &capacity);
    children[numChildren++] = newChild;
}

void Person::printAncestors(){
    cout << endl << "Ancestors of " << name << endl;
    printLineage('u', 0);
}

void Person::printDecendents(){
    cout << endl << "Decendents of " << name << endl;
    printLineage('d', 0);
}

void Person::printLineage(char dir, int level){
    char *temp = compute_relation(level);

    if(dir == 'd'){
        for(int i = 0; i < numChildren; i++){
            cout << temp << "child: " << children[i]->getName() << endl;
            children[i]->printLineage(dir, level + 1);
        }
    } else {
        if(mother){
            cout << temp << "mother: " << mother->getName() << endl;
            mother->printLineage(dir, level + 1);
        }
        if(father){
            cout << temp << "father: " << father->getName() << endl;
            father->printLineage(dir, level + 1);
        }
    }
    // delete the temp array which was allocated by compute_relation(level)
    // after it is printed, it is no longer of use
    delete[] temp;
}

/* helper function to compute the lineage
* if level = 0 then returns the empty string
* if level >= 1 then returns ("great ")^(level - 1) + "grand "
*/
char* Person::compute_relation(int level){
    if(level == 0) return strcpy(new char[1], "");

    char *temp = strcpy(new char[strlen("grand ") + 1], "grand ");;
    
    for(int i = 2; i <= level; i++){
        char *temp2 = new char[strlen("great ") + strlen(temp) + 1];
        strcat(strcpy(temp2, "great "), temp);
	// delete original char[] after ruinning strcpy
	// temp will be replaced by temp2, so it is necesary to delete peviously allocated memory
	delete[] temp;

        temp = temp2;
    }
    return temp;
}

/* non-member function which doubles the size of t
 * NOTE: t's type will be a pointer to an array of pointers
 */
void expand(Person ***t, int *MAX){
  Person **temp = new Person*[2 * *MAX];
  memcpy(temp, *t, *MAX * sizeof(**t));
  
  for (int i = 0; i < *MAX; ++i) {
    // delete t->;
  }
  // delete *t which is the array of pointer
  // memcpy allocates new memory to temp, so it is necessary to delete previously allocated medmeory
  delete[] *t;


 *MAX *= 2;
  *t = temp;
}
