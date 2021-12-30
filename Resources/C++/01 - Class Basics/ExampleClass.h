/*
  ExampleClass.h - Header file for ExampleClass
    - Header guards
    - Include directives for C++ built-in libraries and user-defined libraries.
          - Hypothetically, if ExampleClass used another class, like ExampleClass2,
            then
                #include "ExampleClass2.h"
            would be present as well.
    - Class declaration with declarations for member variables/functions and
      any inline function definitions.
*/

#ifndef EXAMPLE_CLASS_H     // header guards
#define EXAMPLE_CLASS_H

#include <iostream>
#include <string>

/* Using namespace std is not a good convention - it is being used here
   for the purposes of demonstration to make the code easier to read. */
using namespace std;


class ExampleClass {
public:
    /* Constructors */
    ExampleClass();                                         // default constructor
    explicit ExampleClass(int _capacity);                   // 1 parameter constructor, should use explicit
    ExampleClass(string _str, double _x, int _capacity);    // 3 parameter constructor

    /* Destructor */
    ~ExampleClass();

    /* Get functions */
    string getStr() const {                                // inline function example
        return str;
    }

    double getX() const;                                    // returns x
    int getSize() const;                                    // returns the size
    int getCapacity() const;                                // returns the capacity
    int getIntegerAtIndex(int index) const;                 // returns the number at a given index in the array


    /* Set/Setter/Mutator functions */
    void setStr(string newStr);                             // sets word to the new word
    void setX(double newX);                                 // sets x to the new x-value
    void pushBack(int newItem);                             // pushes back a new integer into the array
    void pop();                                             // pops an item off the array
    void modifyIntegerAtIndex(int index, int newItem);      // sets the integer at "index" to "newItem"

    /* Other */
    void printArray() const;                                // prints out all the integers in the vector

    /* Friend Function */
    friend void printStr(const ExampleClass& ec);           // prints out str

    /* Static Functions */
    static void printPI();                                  // prints out PI
    static int getY();                                      // returns y
    static void setY(int newY);                             // sets y to a new value
   

    /* Static member variables */
    const static double PI;
    static int y;

private:
    // Two sets of data types - built-in C++ class and a primitive type
    string str;
    double x;

    // A vector of integers, used in place of the C++ vector class
    int* a;
    int size;
    int capacity;

    // helper function to resize a
    void resizeArray();
};


#endif
