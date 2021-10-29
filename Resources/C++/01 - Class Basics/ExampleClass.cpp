#include "ExampleClass.h"
#include <iostream>

/***** Static Variables *****/
int ExampleClass::y = 10;
const double ExampleClass::PI = 3.14159;

/***** Constructors ******/
/* Default Constructor - will initialize all of the member variables to default values.
   Can be initialized in the body, or using the special notation after the colon. */
ExampleClass::ExampleClass() : str("Ballad 1 in G Minor"), x(1849) {
	size = 0;
	capacity = 10;
	vec = new int[capacity];
}


/* 1 parameter constructor, should use explicit */
ExampleClass::ExampleClass(int _capacity) : str("Ballad 1 in G Minor"), x(1849),
capacity(_capacity)
{
	vec = new int[capacity];
	size = 0;
}


/* 3 arg constructor - will initialize all of the member variables to either one of the 3 arguemnts
   provided or default values. */
ExampleClass::ExampleClass(string _str, double _x, int _capacity) : str(_str), x(_x), size(0) {
	capacity = (_capacity);
	vec = new int[capacity];
}


/* Copy Constructor - constructs a new object that is a complete and independent copy of "ec". */
ExampleClass::ExampleClass(const ExampleClass& ec) {
	str = ec.str;
	x = ec.x;
	size = ec.size;
	capacity = ec.capacity;
	vec = new int[capacity];
	for (int i = 0; i < size; i++)
		vec[i] = ec.vec[i];
}




/***** Destructor *****/
ExampleClass::~ExampleClass() {
	delete[] vec;		// vec was allocated on the heap with "new"
}




/* Copy Assignment Operator */
ExampleClass& ExampleClass::operator=(const ExampleClass& ec) {
	if (this == &ec)		// prevent from copying to self
		return *this;

	str = ec.str;
	x = ec.x;
	size = ec.size;
	capacity = ec.capacity;

	if (vec != nullptr)			// free up the current array before creating the new array
		delete[] vec;			// not doing this would cause a memory leak
	vec = new int[capacity];
	for (int i = 0; i < size; i++)
		vec[i] = ec.vec[i];

	return *this;
}




/***** Get/Getter Functions *****/
double ExampleClass::getX() const {
	return x;
}


int ExampleClass::getSize() const {
	return size;
}


int ExampleClass::getCapacity() const {
	return capacity;
}


int ExampleClass::getIntegerAtIndex(int index) const {
	if (index > 0 && index < size)
		return vec[index];
	else {
		cout << "Cannot retrieve integer at index " << index << " - it is an invalid index." << endl << endl;
		return -9090;
	}
}




/* Set/Setter/Mutator functions */
void ExampleClass::ExampleClass::setStr(string newStr) {
	str = newStr;
}


void ExampleClass::ExampleClass::setX(double newX) {
	x = newX;
}


void ExampleClass::ExampleClass::pushBack(int newItem) {
	if (size == capacity) {
		int* newVec = new int[capacity * 2];
		for (int i = 0; i < capacity; i++)
			newVec[i] = vec[i];
		delete[] vec;
		vec = newVec;
		capacity *= 2;
	}
	vec[size++] = newItem;
}


void ExampleClass::pop() {
	if (size > 0)
		size--;
	else
		cout << "Cannot pop the vector because it is empty." << endl << endl;
}


void ExampleClass::modifyIntegerAtIndex(int index, int newItem) {
	if (index >= 0 && index < size)
		vec[index] = newItem;
	else
		cout << "Cannot modify the integer at index " << index << " - it is an invalid index." << endl << endl;
}




/***** Other Functions*****/
void ExampleClass::printVec() const {
	if (size == 0)
		cout << "The vector is empty.\n\n";
	else {
		cout << "The items in the vector are:\n";
		for (int i = 0; i < size; i++) {
			cout << vec[i];
			if (i < size - 1)
				cout << ' ';
			else
				cout << endl << endl;
		}
	}
}




/* Friend Function Definition */
void printStr(const ExampleClass& ec) {
	cout << ec.str;
}




/***** Static Functions *****/
void ExampleClass::printPI() {
	cout << "The value of the mathematical constant pi is " << PI << endl << endl;
}
