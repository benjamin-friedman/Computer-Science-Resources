#include <stdio.h>
#include <stdlib.h>

/* A program demonstrating how to properly use malloc. Students are often taught a way that is valid
   but not considered the best practice */


typedef struct s1 {
    int data1;
} S1;

typedef struct s2 {
    int data1;
    int data2;
} S2;


int main(int argc, char* argv[]) {
    /* Not Best Practice
       - typecast the return value of malloc.
       - explicitly write a type inside of sizeof(...) */
    int* a = (int*)malloc(sizeof(int) * 10);
    S1* b = (S1*)malloc(sizeof(S1));

    // You decide to change "a" to an array of 10 doubles, and "b" to an S2 structure...your code becomes invalid.
    double* a = (int*)malloc(sizeof(int) * 10);          // invalid, must manually make additional changes
    S2* b = (S1*)malloc(sizeof(S1));                     // invalid, must manually make additional changes

    double* a = (double*)malloc(sizeof(double) * 10;     // valid after manually making additional changes
    S2 * b = (S2*)malloc(sizeof(S2));                    // valid after manually making additional changes



    /* Best practice
       - get rid of the typecast on the return value of malloc
       - don't explicitly write in a type in sizeof(...) */
    int* a = malloc(sizeof(*a) * 10);
    S1* b = malloc(sizeof(*b));

    // You decid to change "a" to an array of 10 doubles, and "b" to an S2 structure...your code is STILL valid                            
    double* a = malloc(sizeof(*a) * 10);                 // valid, no need to manually make additional changes
    S2* b = malloc(sizeof(*b));                         // valid, no need to manually make additional changes

    return 0;
}
