/*
  ExampleClass.cpp - Implementation file for ExampleClass
	- The include directive for the header file must always be included
	- Any other necessary include directives - note that any include directives
	  already in the header file do not need to be written again here. By including
	  the header file, those include directives are already included here.
	- Static member variable initializations
	- Function definitions for any non-inline member functions
*/

#include "ExampleClass.h"

/***** Static Variables *****/
int ExampleClass::y = 10;
const double ExampleClass::PI = 3.14159;

/***** Constructors ******/
/* Default Constructor - will initialize all of the member variables to default values.
   Can be initialized in the body, or using the member initializer list. */
ExampleClass::ExampleClass() : str("Ballad 1 in G Minor"), x(1849), size(0), capacity(3) {
	a = new int[capacity];
	cout << "Default constructor called for object at address " << this << endl;
}


/* 1 parameter constructor, should use explicit */
ExampleClass::ExampleClass(int _capacity) : str("Ballad 1 in G Minor"), x(1849), size(0), capacity(_capacity) {
	a = new int[capacity];
	cout << "1-Parameter constructor called for the object at address " << this << endl;
}


/* 3 arg constructor - will initialize all of the member variables to either one of the 3 arguemnts
   provided or default values. */
ExampleClass::ExampleClass(string _str, double _x, int _capacity) : str(_str), x(_x), size(0), capacity(_capacity) {
	a = new int[capacity];
	cout << "3-Parameter constructor called for the object at address " << this << endl;
}


/* Copy Constructor - constructs a new object that is a complete and independent copy of "ec". */
ExampleClass::ExampleClass(const ExampleClass& ec) : str(ec.str), x(ec.x), size(ec.size), capacity(ec.capacity) {
	a = new int[capacity];
	for (int i = 0; i < size; i++)
		a[i] = ec.a[i];
	cout << "Copy constructor called for the object at address " << this << endl;
}




/***** Destructor *****/
ExampleClass::~ExampleClass() {
	delete[] a;		// vec was allocated on the heap with "new"
	cout << "Destructor called for object at address " << this << endl;
}




/* Copy Assignment Operator */
ExampleClass& ExampleClass::operator=(const ExampleClass& ec) {
	if (this == &ec)			// prevent from copying to self
		return *this;

	/* Copy the values from ec to the calling object */
	str = ec.str;
	x = ec.x;
	size = ec.size;
	capacity = ec.capacity;
			
	/* Make a deep copy of the array in ec, and store it in the calling object. Simply
	   writing the line
	        a = ec.a
	   would mean "a" and "ec.a" share the same array instead of "a" having a copy of the array. */
	delete[] a;					
	a = new int[capacity];
	for (int i = 0; i < size; i++)
		a[i] = ec.a[i];

	cout << "Copy assignment operator called for object at address " << this;
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
	if (index >= 0 && index < size)
		return a[index];
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
		resizeArray();		// call the helper function to resize the array.
	}
	a[size++] = newItem;
}


void ExampleClass::pop() {
	if (size > 0)
		size--;
	else
		cout << "Cannot pop the vector because it is empty." << endl << endl;
}


void ExampleClass::modifyIntegerAtIndex(int index, int newItem) {
	if (index >= 0 && index < size)
		a[index] = newItem;
	else
		cout << "Cannot modify the integer at index " << index << " - it is an invalid index." << endl << endl;
}




/***** Other Functions*****/
void ExampleClass::printArray() const {
	if (size == 0)
		cout << "The vector is empty.\n\n";
	else {
		cout << "The items in the vector are:\n";
		for (int i = 0; i < size; i++) {
			cout << a[i];
			if (i < size - 1)
				cout << ' ';
			else
				cout << endl;
		}
	}
}




/* Friend Function Definition */
void printStr(const ExampleClass& ec) {
	cout << ec.str;
}




/***** Static Functions *****/
void ExampleClass::printPI() {
	cout << "The value of the mathematical constant pi is " << PI << endl;
}


int ExampleClass::getY() {
	return y;
}


void ExampleClass::setY(int newY) {
	y = newY;
}



/***** Helper Functions *****/
void ExampleClass::resizeArray() {
	cout << "The array is being resized\n";

	/* The array can be resized to any new capacity. A common convention
	   is to double the capacity. This avoids having to constantly do resize
	   operations every time a new item is added. */
	int* newArray = new int[capacity * 2];
	for (int i = 0; i < capacity; i++)
		newArray[i] = a[i];
	
	delete[] a;
	a = newArray;
	capacity *= 2;
}
