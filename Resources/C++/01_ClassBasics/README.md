# Class Basics
An example C++ class demonstrating some of the basics of C++ classes
  
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

Static member variables
    - A static member variable is a variable that is shared amgonst all objects of a given class.
      In other words, the member variable x is not static, which means that every object in
      "ExampleClass" has it's own unique copy of x. The member variable y is static which means
      that there is one variable y that is shared amongst all the objects.
