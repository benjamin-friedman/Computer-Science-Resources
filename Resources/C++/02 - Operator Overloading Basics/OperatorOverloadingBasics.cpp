/*
  Main.cpp - A class called Point and a main function.

  This file demonstrates the use of operator overloading for a simple
  class storing the x-y coordinate pair for a point on a graph.

  The following operator overloads are covered
      addition, subtraction, and unary -		+, -, and -
	  multiplication and division				* and /
	  equivalent and not equivalent				== and !=
	  pre and postincrement						++ and ++
	  pre and postdecrement						-- and --
	  output stream/insertion					<<, typically cout
	  input stream/extraction					>>, typically cin

  Every single operator can be overloaded for a class, and some of the most common ones
  are in this program. Some always have utility, such as << and >>. For others, it's situationally
  dependent. For examples, it makes more sense/has more utility to overload + and - for a Money
  class but it makes less sense/has less utility to overload * and / for a Money class.
  
  Operator overloads can be done with friend or non-friend functions. One example is shown
  with a friend function (addition) to show the differences.

  The logic seen here can be applied to operator overloading for any C++ class.

*/

#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point {
public:
	// Constructors
	Point() : x(0), y(0) {}
	Point(double _x, double _y) : x(_x), y(_y) {}

	// Getters/Setters
	double getX() const { return x; }
	double getY() const { return y; }
	void setX(double newX) { x = newX; }
	void setY(double newY) { y = newY; }

	// Friend Function example
	friend const Point operator+(const Point& p1, const Point& p2);
private:
	double x, y;
};


/* Operator Overloading Function Declarations */

// Overloads for subtraction, and unary minus operator. Note that
// subtraction is "p1 - p2" and unary minus operator is "-p1"
const Point operator-(const Point& p1, const Point& p2);
const Point operator-(const Point& p);						// unary

// Overloads for multiplication and division
const Point operator*(const Point& p1, const Point& p2);
const Point operator/(const Point& p1, const Point& p2);

// Overloads for comparison operators
bool operator==(const Point& p1, const Point& p2);
bool operator!=(const Point& p1, const Point& p2);

// Overloads for the ++ pre/post increment operators
const Point operator++(Point& p);							// preincrement: ++p
const Point operator++(Point& p, int n);					// postincrement: p++

// Overloads for the -- pre/post decrement operators
const Point operator--(Point& p);							// predecrement: --p
const Point operator--(Point& p, int n);					// postdecrement: p--

// Overloads for the insertion/extraction operator
ostream& operator<<(ostream& out, const Point& p);			// cout << p
istream& operator>>(istream& in, Point& p);					// cin >> p




int main(int argc, char* argv[]) {

	Point p1(3, 4);
	Point p2(-2, 5);

	cout << "ADDITION\n";
	cout << p1 << " + " << p2 << " = " << p1 + p2 << endl << endl;

	cout << "SUBTRACTION\n";
	cout << p1 << " - " << p2 << " = " << p1 - p2 << endl << endl;

	cout << "UNARY MINUS\n";
	cout << "-" << p1 << " = " << -p1 << endl << endl;

	cout << "MULTIPLICATION\n";
	cout << p1 << " * " << p2 << " = " << p1 * p2 << endl << endl;

	cout << "DIVISION\n";
	cout << p1 << " / " << p2 << " = " << p1 / p2 << endl << endl;

	cout << "EQUIVALENT\n";
	cout << p1 << " == " << p2 << ": ";
	if (p1 == p2) cout << "true";
	else cout << "false";
	cout << endl << endl;

	cout << "NOT EQUIVALENT\n";
	cout << p1 << " != " << p2 << ": ";
	if (p1 != p2) cout << "true";
	else cout << "false";
	cout << endl << endl;

	cout << "PRE/POSTINCREMENT\n";
	cout << "The current coordinate is " << p1 << endl;
	cout << "The postincrement operator is being called, so " << p1++ << " does not increment until after" << endl;
	cout << "The coordinate is now " << p1 << endl;
	cout << "The current coordinate is " << p2 << endl;
	cout << "The preincrement operator is being called, so it is incremented to " << ++p2 << " in this statement" << endl;
	cout << endl;

	cout << "PRE/POSTDECREMENT\n";
	cout << "The current coordinate is " << p1 << endl;
	cout << "The postdecrement operator is being called, so " << p1-- << " does not decrement until after" << endl;
	cout << "The coordinate is now " << p1 << endl;
	cout << "The current coordinate is " << p2 << endl;
	cout << "The predecrement operator is being called, so it is decremented to " << --p2 << " in this statement" << endl;
	cout << endl;

	return 0;
}



/* Operator Overloading Function Definitions */

// Addition
const Point operator+(const Point& p1, const Point& p2) {
	return Point(p1.x + p2.x, p1.y + p2.y);
}


// Subtraction
const Point operator-(const Point& p1, const Point& p2) {
	return Point(p1.getX() - p2.getX(), p1.getY() - p2.getY());
}


// Unary minus
const Point operator-(const Point& p) {
	return Point(-p.getX(), -p.getY());
}


// Multiplication
const Point operator*(const Point& p1, const Point& p2) {
	return Point(p1.getX() * p2.getX(), p1.getY() * p2.getY());
}


// Division
const Point operator/(const Point& p1, const Point& p2) {
	return Point(p1.getX() / p2.getX(), p1.getY() / p2.getY());
}


// Equivalent
bool operator==(const Point& p1, const Point& p2) {
	return p1.getX() == p2.getX() && p1.getY() == p2.getY();
}


// Not Equivalent
bool operator!=(const Point& p1, const Point& p2) {
	return p1.getX() != p2.getX() || p1.getY() != p2.getY();
}


// Preincrement
const Point operator++(Point& p) {
	p.setX(p.getX() + 1);
	p.setY(p.getY() + 1);
	return p;
}


// Postincrement
const Point operator++(Point& p, int n) {
	double xBefore = p.getX();
	double yBefore = p.getY();
	p.setX(p.getX() + 1);
	p.setY(p.getY() + 1);
	return Point(xBefore, yBefore);
}


// Predecrement
const Point operator--(Point& p) {
	p.setX(p.getX() - 1);
	p.setY(p.getY() - 1);
	return p;
}


// Postdecrement
const Point operator--(Point& p, int n) {
	double xBefore = p.getX();
	double yBefore = p.getY();
	p.setX(p.getX() - 1);
	p.setY(p.getY() - 1);
	return Point(xBefore, yBefore);
}


// Insertion operator - 
ostream& operator<<(ostream& out, const Point& p) {
	out << "(" << p.getX() << ", " << p.getY() << ")";
	return out;
}


// Extraction operator (cin)
istream& operator>>(istream& in, Point& p) {
	double x, y;
	in >> x >> y;
	p.setX(x);
	p.setY(y);
	return in;
}

#endif
