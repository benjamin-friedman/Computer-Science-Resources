/*
   This program shows an example of C++ operator overloading using a Money class example. The fundamentals shown
   here can be extrapolated to do operator overloading for any class you create, and any operator not used in this
   example. Operator overloading can be done for any operator, and whether or not you overload an operator for a class
   just depends on the utility of the operator for the given class.

   Operator overloading can be done using both friend and non-friend functions, so an example with a friend function is shown.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


class Money
{
public:
	// constructors
	Money(void);
	Money(double amount);
	Money(int _dollars, int _cents);
	Money(int _dollars);

	// mutators
	void input(void);						// reads the dollar sign as well as the amount number
	void setDollars(int _dollars);
	void setCents(int _cents);

	//accessor
	double getAmount(void) const;
	int getDollars(void) const;
	int getCents(void) const;
	void output(void) const;

	// operator overloaders
	friend const Money operator +(const Money& amount1, const Money& amount2);

private:
	int dollars, cents;						// a negative amount is represented as negative dollars AND negative cents
											// i.e. $-4.50 is -4 dollars and -50 cents
	int dollarsPart(double amount) const;	// helper functions
	int centsPart(double amount) const;
};


const Money operator -(const Money& amount1, const Money& amount2);
bool operator ==(const Money& amount1, const Money& amount2);
const Money operator -(const Money& amount);	// unary minus operator, not subtraction

ostream& operator <<(ostream& outStream, const Money& m);
istream& operator >>(istream& inStream, Money &m);

const Money operator++(Money& m);				// prefix increment operator
const Money operator++(Money& m, int n);		// postfix increment operator


int main(void) {
	Money m1(5);
	Money m2(7.50);

	// equivalency and insertion operators
	if (m1 == m2) cout << m1 << " is the same as " << m2 << endl << endl;
	else cout << m1 << " is not the same as " << m2 << endl << endl;

	// addition operator
	Money m3;
	m3 = m1 + m2;
	cout << m3 << " equals " << m1 << " + " << m2 << endl << endl;

	// subtraction operator
	Money m4;
	m4 = m1 - m2;
	cout << m4 << " equals " << m1 << " - " << m2 << endl << endl;

	// unary minus operator
	Money m5(10);
	cout << "negative " << m5 << " equals " << -m5 << endl << endl;

	// post/prefix increment operators
	Money m6(10);
	cout << m6++ << " wil be " << m6 + 1 << " after this statement" << endl;
	cout << "after: " << m6 << endl;
	cout << "it incrememented to " << ++m6 << " during the execution of this statement" << endl << endl;

	// extraction operator
	Money m7;
	cout << "enter a new money value like $4 or $4.53: " << endl;
	cin >> m7;
	cout << "you entered: " << m7;

	
	return 0;
}






/***** Money Class *****/
// Constructors
Money::Money(void) : dollars(0), cents(0) {}

Money::Money(double amount) : dollars(dollarsPart(amount)), cents(centsPart(amount)) {}

Money::Money(int _dollars) : dollars(_dollars), cents(0) {}

Money::Money(int _dollars, int _cents) {
	if ((_dollars < 0 && _cents > 0) || (_dollars > 0 && _cents < 0)) {
		cout << "Inconsistent money data.\n";
		exit(1);
	}
	dollars = _dollars;
	cents = _cents;
}

// mutators
void Money::setDollars(int _dollars) {
	dollars = _dollars;
}

void Money::setCents(int _cents) {
	cents = _cents;
}

// accessors
double Money::getAmount(void) const {
	return dollars + cents * 0.01;
}

int Money::getDollars(void) const {
	return dollars;
}

int Money::getCents(void) const {
	return cents;
}


void Money::output(void) const {
	int absDollars = abs(dollars);
	int absCents = abs(cents);
	cout << "$";
	if (dollars < 0 || cents < 0)
		cout << "-";
	cout << absDollars;
	cout << '.';
	if (absCents >= 10) 
		cout << absCents;
	else cout << '0' << absCents;
}

void Money::input(void) {
	char dollarSign;
	cin >> dollarSign;
	if (dollarSign != '$') {
		cout << "No dollar sign in Money input.\n";
		exit(1);
	}
	double amountAsDouble;
	cin >> amountAsDouble;
	dollars = dollarsPart(amountAsDouble);
	cents = centsPart(amountAsDouble);
}


// private functions
int Money::dollarsPart(double amount) const {
	return static_cast<int>(amount);
}

int Money::centsPart(double amount) const {
	int iCents = (amount - static_cast<int>(amount)) * 100;
	return iCents;

}


// Operators overloading
// Friend function, can access "cents" and "dollars" directly
const Money operator+(const Money& amount1, const Money& amount2) {
	int allCents1 = amount1.cents + amount1.dollars * 100,
		allCents2 = amount2.cents + amount2.dollars * 100;
	int sumAllCents = allCents1 + allCents2;
	int absAllCents = abs(sumAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;
	if (sumAllCents < 0) {
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}
	return Money(finalDollars, finalCents);
}

// Non-friend function, cannot access "cents" and "dollars" directly.
const Money operator-(const Money& amount1, const Money& amount2) {
	int allCents1 = amount1.getCents() + amount1.getDollars() * 100,
		allCents2 = amount2.getCents() + amount2.getDollars() * 100;
	int diffAllCents = allCents1 - allCents2;
	int absAllCents = abs(diffAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;
	if (diffAllCents < 0) {
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}
	return Money(finalDollars, finalCents);
}

bool operator==(const Money& amount1, const Money& amount2) {
	return ((amount1.getDollars() == amount2.getDollars()) &&
		(amount1.getCents() == amount2.getCents()));
}
 
const Money operator-(const Money& amount) {
	return Money(-amount.getDollars(), -amount.getCents());
}


ostream& operator<<(ostream& outStream, const Money& m) {
	int absDollars = abs(m.getDollars());
	int absCents = abs(m.getCents());
	outStream << "$";
	if (m.getDollars() < 0 || m.getCents() < 0) 
		outStream << "-";
	outStream << absDollars;
	outStream << '.';
	if (absCents >= 10) 
		outStream << absCents;
	else outStream << '0' << absCents;
	return outStream;
}

istream& operator >>(istream& inStream, Money &m) {
	//get dollar sign
	char dollarSign;
	inStream >> dollarSign;
	if (dollarSign != '$') {
		cout << "wrong format, must start with $" << endl;
		exit(1);
	}

	//get money values
	double totalAmount;
	inStream >> totalAmount;
	int dollars = static_cast<int>(totalAmount);
	int cents = (totalAmount - dollars) * 100;
	if (totalAmount != dollars)
		cents++;	// floating point number issue - 8.51 gets stored as 8.509999 so cents would be 50 not 51

	//update object
	m = Money(dollars, cents);
	return inStream;
}

//prefix ++m
const Money operator++(Money& m) {
	m.setDollars(m.getDollars() + 1);
	return m;
}

//postfix m++
const Money operator++(Money& m, int n) {
	int dollars = m.getDollars();
	m.setDollars(dollars + 1);
	return Money(dollars);
}
