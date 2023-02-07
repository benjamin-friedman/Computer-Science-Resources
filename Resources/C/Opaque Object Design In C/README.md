# Opaque Object Design In C

This folder contains information regarding the opaque object design in C. C is not an object oriented language and the opaque object design emulates object oriented programming to some extent. Read the PDF for an in depth explanation of the opaque object design and then review the code files which demonstrate the basics of the opaque object design using a simple date object.

The basics of the opaque object design:
- Put the opaque object handle and function declarations in the header file.
- Put the structure definition and function definitions in the implementation file.

The types of functions created for any opaque object:
- Create initializer functions - this includes default and customer initializers as necessary to set a newly instantiated object to some default or custom state. For the date object this would be some default date or a specific date when provided the day, month, and year.
- Create setter functions with error checking which set data in the object - for the date object this would be to set the day, month, and year. There are a limited amount of days, months, and years, and only certain days are valid in certain months.
- Create getter functions to get data in the object- for the date object this would be to get the day, month, and year.
- Create other useful functions for the object as necessary - for the date object this would be something like a function to print out the date.
- Create a destroyer function to free up the memory for the object to avoid memory leaks - for the date object this would be freeing up the date structure but more complicated objects could have data within the object that was also allocated on the heap in which case it would need to be freed as well.
