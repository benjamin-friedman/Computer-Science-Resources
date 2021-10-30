/*
  InheritanceBascisPart1.cpp - Part 1 for discussing the basics of inheritance with a simple Base and Derived class example.
  The most important concept it demonstrates is how to properly implement constructors, copy assignment operators,
  and destructors in inheritance. Additionally, in the main program you can see the order in which the constructors
  and destructors get called based on the programs output.

  The fundamentals seen here can be extrapolated to any class you create.

  Always make base class destructors virtual, here's why - https://www.geeksforgeeks.org/virtual-destructor/
*/


#include <iostream>
using namespace std;

// Base class
class Base {
public:
	/* Default Constructor
	   Initialize size to 0, capacity to 10, create the array */
	Base() : size(0), capacity(10) {
		a = new int[capacity];
		cout << "Base constructor called\n";
	}

	/* 1 Arg Constructor
	   Same as default except with a custom capacity */
	Base(int _capacity) : size(0), capacity(_capacity) {
		a = new int[capacity];
		cout << "Base 1 arg constructor called\n";
	}

	/* Copy Constructor
	   Make a new object that is a copy of another object, in this case "base" */
	Base(const Base& base) : size(base.size), capacity(base.capacity) {
		a = new int[capacity];
		for (int i = 0; i < size; i++)
			a[i] = base.a[i];
		cout << "Base copy constructor called\n";
	}

	/* Copy assignment Operator
	   Make a copy of another object, in this case "base". This is different from the copy constructor in that
	   the copy constructor is called when an object is first made. This copy assignment operator is called when
	   you have an already existing object, and you want to store the contents of another object in it. */
	Base& operator=(const Base& base) {
		// check if you're setting an object equal to itself
		if (this == &base)
			return *this;

		// free up memory of current object - not doing this would cause a memory leak
		if (a != nullptr)
			delete[] a;

		size = base.size;
		capacity = base.capacity;
		a = new int[capacity];
		for (int i = 0; i < size; i++)
			a[i] = base.a[i];

		cout << "Base copy assignment operator called\n";

		return *this;
	}

	// destructor - note that it's "virtual".
	virtual ~Base() {
		delete[] a;	// free up any dynamically allocated memory
		cout << "Base destructor called\n";
	}

private:
	int size;
	int capacity;
	int* a;
};

// Derived class that inherits from Base
class Derived : public Base {
public:
	/* Derived Class Constructor:
	   The default constructor for the Base class is called unless
	   specified otherwise */
	Derived() : y(1) {
		cout << "Derived default constructor called\n";
	}

	/* Derived 1 Arg Constructor:
	   The Base class 1 arg constructor is explicitly called. If it
	   weren't, the default constructor would be called */
	Derived(int _y, int _capacity) : y(_y), Base(_capacity) {
		cout << "Derived 2 arg constructor called\n";
	}

	/* Derived Class Copy Constructor:
	   Call the Base class copy constructor to copy over
	   the inherited data in "derived" */
	Derived(const Derived& derived) : Base(derived) {
		y = derived.y;
		cout << "Derived copy constructor called\n";
	}

	/* Derived Copy Assignment Operator:
	   Call the Base class copy assignment operator to copy
	   over the inherited data in "derived" */
	Derived& operator=(const Derived& derived) {
		Base::operator=(derived);
		y = derived.y;
		cout << "Derived copy assignment operator called\n";
	}

	// destructor
	~Derived() {
		cout << "Derived destructor called\n";
	}

private:
	double y;
};


int main(int argc, char* argv[]) {

	// Comment/ucomment the following options accordingly to see different demonstrations

	/* Option 1: Default derived constructor */
	Derived d;
	cout << endl;

	/* Option 2: 2 arg derived constructor */
	/*Derived d(3, 10);
	cout << endl;*/

	/* Option 3: copy constructor */
	/*Derived d(3, 10);
	cout << endl;
	Derived dCopy(d);
	cout << endl;*/

	/* Option 4: copy assignment operator */
	/*Derived d(3, 10);
	cout << endl;
	Derived dCopy;
	cout << endl;
	dCopy = d;
	cout << endl;*/

	return 0;
}
