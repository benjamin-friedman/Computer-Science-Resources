/* Main program demonstrating the ExampleClass. */

#include <iostream>
#include "ExampleClass.h"
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {

	ExampleClass ec;										// Default Constructor
	ExampleClass ec1(10);									// 1-parameter Constructor
	ExampleClass ec2("Ballad 1 in G Minor", 1849, 10);		// 3-parameter Constructor
	ExampleClass ec3(ec2);									// Copy Constructor

	ec = ec1;												// Copy Assignment Operator

	// pushback 5 times into ec1
	for (int i = 0; i < 5; i++)
		ec1.pushBack(i + 1);

	// call all the get functions
	cout << "The word in ec1 is " << ec1.getStr() << endl;
	cout << "The size of ec1 is " << ec1.getSize() << endl;
	cout << "The capacity of ec1 is " << ec1.getCapacity() << endl;
	for (int i = 0; i < ec1.getSize(); i++) {
		cout << "The integer at index " << i << " is " << ec1.getIntegerAtIndex(i) << endl;
	}
	cout << endl;

	// call the set and other functions
	ec1.setX(1810);
	cout << "After setting a new x value, x = " << ec1.getX() << endl << endl;

	ec1.setStr("Nocturne in B Flat Minor");
	cout << "After setting a new str value, str = " << ec1.getStr() << endl << endl;

	ec1.pop();
	ec1.modifyIntegerAtIndex(0, 52);
	cout << "After popping the vector once, and modifying the value at index 0.\n";
	ec1.printVec();
	cout << endl << endl;

	cout << "Using the friend function, the str string in the class is ";
	printStr(ec1);
	cout << endl << endl;

	ExampleClass::printPI();
	cout << endl;

	cout << "The value stored in y is " << ExampleClass::getY() << endl << endl;

	ExampleClass::setY(44);
	cout << "After setting y to a new value, it is now " << ec1.getY() << endl << endl;


	return 0;
}
