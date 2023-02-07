# Performance of malloc, calloc, and realloc

- The malloc function allocates memory on the heap leaving it uninitialized. For example, it could allocate an array of 10 integers and all would be uninitialized.
- The calloc function allocates memory on the heap and initializes it by zeroing it out. For example, it could allocate an array of 10 integers and all would be set to 0.
- The realloc function reallocates an existing piece of memory on the heap either to increase or decrease its size. It will attempt to do this resize operation using the existing piece of memory instead of creating a whole new copy of it though this is not guaranteed to happen. If the size is increased then the new resized portion is uninitialized. For example, if it resized an array of 10 integers by doubling the size, the new array would either be the existing 10 integers plus another 10 integers uninitialized, or it would be a copy of the 10 integers plus another 10 integers uninitialized.

This program demonstrates the performance differences of malloc, calloc, and realloc in the following situations:
- Zeroing out a new array using malloc vs. calloc
- Resizing an existing array using malloc vs. realloc

The program demonstrates that on average it is more efficient to zero out a new array with calloc and resize an existing array with realloc. The results of running the program an array size of 100 thousand, 1 million, 10 million, and 100 million can be seen in results.txt.

It is intuitive that it would on average be faster to resize an array with realloc because it always attempts to take the existing array and add on extra memory to it instead of creating a copy like malloc always does. It is not intuitive that it would be faster to zero out a new array with calloc. The reasons for this would get into the underlying implementation of calloc.
