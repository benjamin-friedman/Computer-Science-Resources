#include <iostream>

using namespace std;

class MyClass {
public:
	// Default Constructor
	MyClass();

	// Copy Constructor
	MyClass(const MyClass& myClass);

	// Move Constructor: notice how it's not "const" because it will be changed
	MyClass(MyClass&& myClass) noexcept; // "noexcept" just means it may not throw exceptions
										 // move constructors should have to have this keyword
										 
	// Copy assignment
	MyClass& operator=(const MyClass& myClass);

	// Move assignment: notice how it's not "const" because it will be changed
	MyClass& operator=(MyClass&& myClass) noexcept; // once again, should not throw exceptions
													// move assignment operators should have this keyword

	~MyClass() { delete[] a; }

private:
	int x;
	int* a;
};

int main() {

	// CONSTRUCTOR
	MyClass mc1;
	MyClass mc2(mc1);	// copy constructor called. mc1 is an lvalue

	cout << endl << endl;

	MyClass mc3;
	MyClass mc4(move(mc3)); // move constructor called. move() converts the lvalue mc3 to an rvalue

	cout << endl << endl;

	// ASSIGNMENT OPERATOR
	MyClass mc6;
	MyClass mc7;
	mc7 = mc6; // copy assignment called. mc6 is an lvalue

	cout << endl << endl;

	MyClass mc8;
	MyClass mc9;
	mc9 = move(mc8); // move assignment called. move() converts the lvalue mc8 to an ravlue
	cout << endl;
	MyClass mc10;
	cout << endl;
	mc10 = MyClass(); // move assignment called. MyClass() is an rvalue
	cout << endl;

	return 0;
}


MyClass::MyClass() {
	x = 3;
	a = new int[10];
}

/* A complete and independent copy of myClass will be made
   and stored in the newly constructed object */
MyClass::MyClass(const MyClass& myClass) {
	cout << "copy constructor\n";

	x = myClass.x;
	a = new int[10];
	for (int i = 0; i < 10; i++)
		a[i] = myClass.a[i];
}

/* The newly constructed object takes myClass's already
   allocated array and uses it as it's own. myClass's
   array is set to the nullptr because it no longer has
   ownership of it. No new memory allocation happens */
MyClass::MyClass(MyClass&& myClass) noexcept {
	cout << "move constructor\n";

	x = myClass.x;
	a = myClass.a;
	myClass.a = nullptr;
}

/* A complete and independent copy of myClass is made and
   returned to the object it's being assigned to */
MyClass& MyClass::operator=(const MyClass& myClass) {
	cout << "copy assignment\n";

	if (this == &myClass)
		return *this;

	x = myClass.x;
	if (a != nullptr)
		delete[] a;
	a = new int[10];
	for (int i = 0; i < 10; i++)
		a[i] = myClass.a[i];

	return *this;
}

/* The object getting assigned to takes myClass's already
   allocated array and uses it as it's own. myClass's array
   is set to the nullptr because it no longer has ownership
   of it. No new memory allocation happens */
MyClass& MyClass::operator=(MyClass&& myClass) noexcept {
	cout << "move assignment";

	if (this == &myClass)
		return *this;

	x = myClass.x;
	if (a != nullptr)
		delete[] a;
	a = myClass.a;
	myClass.a = nullptr;

	return *this;
}