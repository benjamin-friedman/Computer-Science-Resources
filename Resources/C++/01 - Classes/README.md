# Class Basics
An example C++ class demonstrating some of the basics of C++ classes



**Class Setup** - The basic setup of a class is described below (using ExampleClass as an example). Note the naming conventions.
    Header file:
        - This can be a ".h" or ".hpp" file. The difference is that ".h" files can be used for C or C++,
          and ".hpp" files are exclusively for C++.
        - The header file is named "ExampleClass.h".
        - Header guards with a macro named EXAMPLE_CLASS_H.
        - Within the header file is the class definition which contains member variables and member function declarations.
          Function declarations can be omitted and the function definitions can be directly written inside of the class. These
          are called **inline functions**.
        - Everything in the class is made either **public** or **private**. If those keywords are not used, then everything is
          public by default. The basic, general conventions are described below:
              - **private**: Member variables and any helper functions used exclusively within the function definitions of the class.
                By making the member variables private, they are protected from being modified directly in a program. Instead,
                member variables are modified by using functions, and the functions are written in such a way that the the member variables
                can never be modified to an invalid state, such as setting the size of a vector to a negative number. The helper functions
                are private because they never need to be used outside of the class, so there's no point in making them public.
              - **public**: Member functions and any member variables that don't need to be private. The member functions are public because
                they are what need to be used in the main function. Typical examples of member variables that don't need to be private are
                constants such as mathematical constants like PI.
    Implementation File:
        - This is the ".cpp" file named "ExampleClass.cpp". It contains the function definitions for any non-inline functions.
    Main File:
        - This is the "main.cpp" file where the main function is. This not actually part of the class interface, but a main function
          is required for any C++ program. It is where the program runs, and where objects of the class are instantiated and used.

  
**Constructor** - a function that gets called when an object is instantiated.
    Default Constructor
        - Sets all the member variables to valid but default values.
    3 Arg Constructor
        - A constructor that takes 3 arguments. Some member variables get set to the arguments passed
          to it, and some member variables get set to default values. A constructor can take any amount
          of arguments. Whether a 1 arg, 2 arg, 3 arg etc. constructor is used just depends on its utility.
    Copy Constructors
        - Creates a new object that is a complete and independent copy of an already existing object.

**Get / Getter Functions**
    - These are functions that "get" the data in the object. These are used for private
      member variables because private member variables cannot be accessed directly outside of a class.
      The "const" keyword means the function will not modify any private member variables.

**Set / Setter / Mutator Functions**
    - These are functions that "set" the data in the object to new values. They do not have the "const"
      keyword since they are modifying the member variables.
  
**Other**
    - Any function that does not fall under the hiearchy of constructors, getters, setters, or
      the destructor.

**Destructor**
    - A destructor gets called by default when an object goes out of scope. A destructor only needs
      to be created if the class contains variables that are dynamically allocated aka use the "new"
      keyword. Any variable dynamically allocated must be freed up with the "delete" keyword. Note
      that new and delete are to malloc and free in the C programming language. If a class does not
      have any variables that are dynamically allocated, a destructor does not need to be created.

**Static member variables**
    - A static member variable is a variable that is shared amgonst all objects of a given class.
      In other words, the member variable x is not static, which means that every object in
      "ExampleClass" has it's own unique copy of x. The member variable y is static which means
      that there is one variable y that is shared amongst all the objects.
