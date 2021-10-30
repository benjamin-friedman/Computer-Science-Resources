/*
   This program demonstrates the basics of C++ copy and move semantics:
	- copy assignment/copy constructor
	- move assignment/move constructor
	- the "std::move()" function - converts an lvalue to an rvalue, used in move semantics
	- lvalues vs. rvalues (brief description below)


   Though lvalues and rvalues have official definitions, the best way to think of them in general is that an lvalue is
   something that you can reference by a name, and an rvalue is something that you cannot reference by a name.
	- lvalues take the form of things like variables and objects
	- rvalues take the form of things like hardcoded numbers and temporary objects
   Meaning, in "int x = 3;", x is an lvalue since it's a variable with a name, whereas 3 is an rvalue since it's just
   the number 3. It is not a variable but rather a temporary value loaded somewhere in the computers memory for the purposes
   of executing that one line of code.
   A common misconception about lvalues and rvalues is that the l and r stand for "left" and "right" meaning lvalues go on the
   left side of the "=" operator, and r values go on the right side. As you will see in the examples below, this is not the case.

	int x = 3;				x is an lvalue, 3 is an rvalue
	int y = x;				x and y are both lvalues
	string s = "Liebestraum";		s is an lvalue, "Liebestraum" is an rvalue
	string s2 = s;				s2 and s are both lvalues

   Can an rvalue go on the left of the "=" operator? Yes.
	s + s = s;				s + s is an rvalue, s is an lvalue
   Though this statement has zero utility, it is still valid C++ code.

   There ARE cases where you can refer to an rvalue by a name. This is when you use && to denote something as an rvalue.
   This is most commonly seen in a formal parameter to a function such as in move semantics as seen below.
*/

#include <iostream>

using namespace std;

class MyClass {
public:
	// Default Constructor
	MyClass();
	// 1-Parameter Constructor
	explicit MyClass(int _x);

	// Copy Constructor
	MyClass(const MyClass& myClass);

	// Move Constructor: notice how it's not "const" because it will be changed
	MyClass(MyClass&& myClass) noexcept; 			// "noexcept" means it will not throw exceptions
								// move constructors should have to have this keyword

	// Copy assignment
	MyClass& operator=(const MyClass& myClass);

	// Move assignment: notice how it's not "const" because it will be changed
	MyClass& operator=(MyClass&& myClass) noexcept; 	// once again, will not throw exceptions
								// move assignment operators should have this keyword

	~MyClass() { delete[] a; }

private:
	int x;
	int* a;
};

int main() {

	// CONSTRUCTOR
	MyClass mc1;
	MyClass mc2(mc1);		// copy constructor called. mc1 is an lvalue
	MyClass mc22 = mc1;
	cout << endl << endl;

	MyClass mc3;
	MyClass mc4(move(mc3)); 	// move constructor called. move() converts the lvalue mc3 to an rvalue

	cout << endl << endl;

	// ASSIGNMENT OPERATOR
	MyClass mc6;
	MyClass mc7;
	mc7 = mc6; 			// copy assignment called. mc6 is an lvalue

	cout << endl << endl;

	MyClass mc8;
	MyClass mc9;
	mc9 = move(mc8); 		// move assignment called. move() converts the lvalue mc8 to an ravlue
	cout << endl;
	MyClass mc10;
	cout << endl;
	mc10 = MyClass(); 		// move assignment called. MyClass() is an rvalue
	cout << endl;

	return 0;
}


MyClass::MyClass() : x(10) {
	a = new int[x];
	for (int i = 0; i < x; i++)
		a[i] = i;
}

explicit MyClass::MyClass(int _x) : x(_x) {
	a = new int[x];
	for (int i = 0; i < x; i++)
		a[i] = i;
}


/* A complete and independent copy of myClass will be made
   and stored in the newly constructed object. */
MyClass::MyClass(const MyClass& myClass) {
	cout << "copy constructor\n";

	x = myClass.x;
	a = new int[x];
	for (int i = 0; i < x; i++)
		a[i] = myClass.a[i];
}

/* The newly constructed object takes myClass's already
   allocated array and uses it as it's own. myClass's
   array is set to the nullptr because it no longer has
   ownership of it. No new memory allocation happens. */
MyClass::MyClass(MyClass&& myClass) noexcept {
	cout << "move constructor\n";

	x = myClass.x;
	a = myClass.a;
	myClass.a = nullptr;
}

/* A complete and independent copy of myClass is made and
   returned to the object it's being assigned to. */
MyClass& MyClass::operator=(const MyClass& myClass) {
	cout << "copy assignment\n";

	if (this == &myClass)
		return *this;

	x = myClass.x;
	if (a != nullptr)
		delete[] a;
	a = new int[x];
	for (int i = 0; i < x; i++)
		a[i] = myClass.a[i];

	return *this;
}

/* The object getting assigned to takes myClass's already
   allocated array and uses it as it's own. myClass's array
   is set to the nullptr because it no longer has ownership
   of it. No new memory allocation happens. */
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
