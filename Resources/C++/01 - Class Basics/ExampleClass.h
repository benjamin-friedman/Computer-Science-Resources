#ifndef EXAMPLE_CLASS_H
#define EXAMPLE_CLASS_H

#include <iostream>
#include <string>

using namespace std;


class ExampleClass {
public:
    /* Constructors */
    ExampleClass();                                         // default constructor
    explicit ExampleClass(int _capacity);                   // 1 parameter constructor, should use explicit
    ExampleClass(string _str, double _x, int _capacity);   // 3 parameter constructor
    ExampleClass(const ExampleClass& ec);                   // copy constructor

    /* Destructor */
    ~ExampleClass();

    /* Copy assignment operator */
    ExampleClass& operator=(const ExampleClass& ec);

    /* Get/Getter functions */
    string getStr() const {                                // inline function example
        return str;
    }

    double getX() const;                                    // returns x
    int getSize() const;                                    // returns the size
    int getCapacity() const;                                // returns the capacity
    int getIntegerAtIndex(int index) const;                 // returns the number at a given index in the array


    /* Set/Setter/Mutator functions */
    void setStr(string newStr);                           // sets word to the new word
    void setX(double newX);                                 // sets x to the new x-value
    void pushBack(int newItem);                             // pushes back a new integer into the array
    void pop();                                             // pops an item off the array
    void modifyIntegerAtIndex(int index, int newItem);      // sets the integer at "index" to "newItem"

    /* Other */
    void printVec() const;                                  // prints out all the integers in the vector

    /* Friend Function */
    friend void printStr(const ExampleClass& ec);           // prints out str

    /* Static Functions */
    static void printPI();                                  // prints out PI
    static int getY() {                                     // inline function returning the value in y
        return y;
    }

    static void setY(int newY) {                            // inline function setting y to newY
        y = newY;
    }

    /* Static member variables */
    const static int daysInAWeek = 7;
    const static double PI;
    static int y;

private:
    // Two sets of data types - built-in C++ class and a primitive type
    string str;
    double x;

    // a vector of integers, use in place of the C++ vector class
    int* vec;
    int size;
    int capacity;
};


#endif
