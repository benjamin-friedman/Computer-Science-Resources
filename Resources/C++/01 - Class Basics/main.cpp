/*
  ExampleClass.cpp - Main program for demonstrating ExampleClass
	- Include directives for any built-in C++ libraries
	- Include directives for any user-defined classes
	- The main function.
*/

#include <iostream>
#include "ExampleClass.h"

/* Using namespace std is not a good convention - it is being used here
   for the purposes of demonstration to make the code easier to read. */
using namespace std;

int main(int argc, char* argv[]) {

	/* Constructors and copy assignment operator */
	cout << "CALLING CONSTRUCTORS AND COPY ASSIGNMENT OPERATOR\n";
	ExampleClass ec;							// Default Constructor
	ExampleClass ec1(3);							// 1-parameter Constructor
	ExampleClass ec2("Ballad 1 in G Minor", 1849, 3);			// 3-parameter Constructor
	ExampleClass ec3(ec2);							// Copy Constructor
	ec = ec1;								// Copy Assignment Operator
	cout << endl << endl;


	/* pushback */
	cout << "PUSHBACK\n";
	for (int i = 0; i < 5; i++) {
		cout << "pushing back " << i + 1 << " into the array\n";
		ec1.pushBack(i + 1);
	}
	cout << endl << endl;


	/* Get Functions */
	cout << "GET FUNCTIONS\n";
	cout << "The word in ec1 is " << ec1.getStr() << endl;
	cout << "The size of ec1 is " << ec1.getSize() << endl;
	cout << "The capacity of ec1 is " << ec1.getCapacity() << endl;
	for (int i = 0; i < ec1.getSize(); i++) {
		cout << "The integer at index " << i << " is " << ec1.getIntegerAtIndex(i) << endl;
	}
	cout << endl << endl;


	/* Set Functions */
	cout << "SET AND OTHER FUNCTIONS\n";
	ec1.setX(1810);
	cout << "After setting x to a new value, x = " << ec1.getX() << endl;

	ec1.setStr("Nocturne in B Flat Minor");
	cout << "After setting str to a new value, str = " << ec1.getStr() << endl;

	ec1.printArray();
	ec1.pop();
	ec1.modifyIntegerAtIndex(0, 52);
	cout << "After popping the vector once, and modifying the value at index 0\n";
	ec1.printArray();

	cout << "Using the friend function to print the string, str = ";
	printStr(ec1);
	cout << endl << endl << endl;


	/* Static Members */
	cout << "STATIC MEMBERS\n";
	// printPI can be be called with or without the instantiation of an object
	cout << "Calling printPI() without an object\n";
	ExampleClass::printPI();
	cout << "Calling printPI() with an object\n";
	ec.printPI();

	// y can be accessed directly with or without an the instantiation of an object
	cout << "Getting the original value of y without an object: " << ExampleClass::y << endl;
	cout << "Getting the original value of y with an object: " << ec1.y << endl;

	// setY and getY can be called with or without the instantiation of an object
	ExampleClass::setY(44);
	cout << "Calling setY() and getY() without an object, y is now " << ExampleClass::getY() << endl;
	ec.setY(50);
	cout << "Calling setY() and getY() without an object, y is now " << ec.getY() << endl;

	return 0;
}
