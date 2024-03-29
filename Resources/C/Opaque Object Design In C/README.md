# Opaque Object Design In C

This folder contains information regarding the opaque object design in C. C is not an object-oriented programming language and the opaque object design is an attempt to emulate object oriented-programming in C to some extent. However, it is not possible to have all the features of object-oriented programming and for the features it can emulate there is a lot of extra manual work that has to be done. Learning the opaque object design in C teaches you the history of why object-oriented programming was developed to begin with and gives you an appreciation for object-oriented programming since all of the features that the opaque object design tries to implement are automatically built into object-oriented languages with something called classes. This is not at all to say that C is inherently an inferior language to object-oriented languages. C is a great language that is the language of choice or at a minimum has its place in many areas of software engineering such as embedded systems to give one example. However, there are advantages to using object-oriented programming in many contexts and in that sense C is lacking. This ultimately just illustrates the bigger picture of programming languages which is that in general any given programming language isn't inherently worse or better than other languages. Rather, different programming languages are used for different areas of software engineering. Each programming languages has different features, advantages, disadvantages, and its utility is situation dependent. For example, you could use C, not JavaScript, for embedded systems and on the contrary you could use JavaScript, not C, for web applications. This is equivalent to how any given tool in a toolbox is not better or worse than the other tools but rather different tools are used for different tasks.

Read the PDF for an in depth explanation of the opaque object design and then review the code files which demonstrate the basics of the opaque object design using a simple date object.


The basics of the opaque object design:
- Put the opaque object handle and function declarations in the header file.
- Put the structure definition and function definitions in the implementation file.

The types of functions created for any opaque object:
- Create initializer functions - this includes default and customer initializers as necessary to set a newly instantiated object to some default or custom state. For the date object this would be some default date or a specific date when provided the day, month, and year.
- Create setter functions with error checking which set data in the object - for the date object this would be to set the day, month, and year. There are a limited amount of days, months, and years, and only certain days are valid in certain months.
- Create getter functions to get data in the object- for the date object this would be to get the day, month, and year.
- Create other useful functions for the object as necessary - for the date object this would be something like a function to print out the date.
- Create a destroyer function to free up the memory for the object to avoid memory leaks - for the date object this would be freeing up the date structure but more complicated objects could have data within the object that was also allocated on the heap in which case it would need to be freed as well.
