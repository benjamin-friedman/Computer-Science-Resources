/*
  File: date.h
  Description: header file for the date object interface

  Notes:
      - Preconditions are things that are assumed to be true before a function is called.
        This means you don't need to check for them not being true. For example, if hDate
        is a handle to a valid Date object, that means it holds the address of a date object
        and is not NULL. Therefore, you don't need to check if it's NULL inside of the function
        defintion.
      - Postconditions are all of the things that happen as a result of the function called.
        They include descriptions about what the function does, how any formal parameters change
        (if at all), and describe what happens with the functions return value.
*/
  

#ifndef DATE_H
#define DATE_H

#include "status.h"

typedef void* DATE;        // opaque object handle


// Initializer
/*
  PRECONDITION:
    - None.
  POSTCONDITION:
    - Creates a new date object and sets the day, month, and year to January 1st, 1970.
    - Returns SUCCESS, else FAILURE for any memory allocation failure.

*/
DATE date_init_default(void);




// "set" or "setter" functions
/* 
  PRECONDITION:
      - hDate is a handle to a valid date object.
      - newDay is the new day of the month to be set.
  POSTCONDITION:
      - If newDay is a valid day, sets the day in the object to newDay and returns SUCCESS.
      - If newDay is not a valid day, it is ignored and returns FAILURE.
*/
Status date_set_day(DATE hDate, int newDay);

/*
  PRECONDITION:
      - hDate is a handle to a valid date object.
      - newMonth is the new month to be set.
  POSTCONDITION:
      - If newMonth is a valid month, sets the month in the object to newMonth and returns SUCCESS.
      - If newMonth is not a valid month, it is ignored and returns FAILURE.
*/
Status date_set_month(DATE hDate, int newMonth);

/*
  PRECONDITION:
      - hDate is a handle to a valid date object.
      - newYear is the new year to be set.
  POSTCONDITION:
      - If newYear is a valid year, sets the year in the object to newYear and returns SUCCESS.
      - If newYear is not a valid year, it is ignored and returns FAILURE.
*/
Status date_set_year(DATE hDate, int newYear);




// "get" or "getter" functions
/*
  PRECONDITION:
      - hDate is a handle to a valid date object.
  POSTCONDITION:
      - Returns the day.
*/

int date_get_day(DATE hDate);

/*
  PRECONDITION:
      - hDate is a handle to a valid date object.
  POSTCONDITION:
      - Returns the month.
*/
int date_get_month(DATE hDate);

/*
  PRECONDITION:
      - hDate is a handle to a valid date object.
  POSTCONDITION:
      - Returns the year.
*/
int date_get_year(DATE hDate);



// other
/*
  PRECONDITION:
      - hDate is a handle to a valid date object.
  POSTCONDITION:
      - Prints the date: MM/DD/YYYY
*/
void date_print(DATE hDate);



// destroyer
/*
  PRECONDITION:
      - phDate is a pointer to a handle to a valid date object.
  POSTCONDITION:
      - Frees all of the memory associated with the date object and sets the handle
        pointed to by phDate to NULL to avoid a dangling pointer.
*/
void date_destroy(DATE* phDate);


#endif
