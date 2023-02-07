/*
  This program demonstrates the performance differences of malloc, calloc, and realloc in the following situations:
	1) Zeroing out a new array using malloc vs. calloc
	2) Resizing an existing array using malloc vs. realloc
  For the purposes of demonstration it is assumed that memory allocation will not fail.

  The program demonstrates that on average it is more efficient to zero out a new array with calloc and resize an existing array with realloc.
  The size of the array has to be fairly large (1 million in this case) to get a noticeable performance increase using clock_t
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ARRAY_SIZE 1000000
#define TRIALS 1000


int main(void) {
	// both cases
	int* a;
	int* temp;


	// malloc vs. calloc zeroing out
	clock_t zeroOutMallocStart, zeroOutMallocEnd;  // malloc times
	long double zeroOutMallocTime;
	clock_t zeroOutCallocStart, zeroOutCallocEnd;  // calloc times
	long double zeroOutCallocTime;
	long double* zeroOutMallocTimes;               // stores malloc times
	int zeroOutMallocWins = 0;                     // # times malloc wins
	long double zeroOutMallocAvgPerfInc = 0;       // average performance increase for malloc
	long double* zeroOutCallocTimes;               // stores calloc times
	int zeroOutCallocWins = 0;                     // # of times calloc wins
	long double zeroOutCallocAvgPerfInc = 0;       // average performance increase for calloc
	int zeroOutTies = 0;                           // # of ties


	// malloc vs. realloc resizing
	clock_t resizeMallocStart, resizeMallocEnd;    // malloc times
	long double resizeMallocTime;
	clock_t resizeReallocStart, resizeReallocEnd;  // realloc times
	long double resizeReallocTime;
	long double* resizeMallocTimes;                // stores malloc times
	int resizeMallocWins = 0;                      // # of times malloc wins
	long double resizeMallocAvgPerfInc = 0;        // average performance increase of malloc
	long double* resizeReallocTimes;               // stores realloc times
	int resizeReallocWins = 0;                     // # of times realloc wins
	long double resizeReallocAvgPerfInc = 0;       // average performance increase of realloc
	int resizeTies = 0;                            // # of ties


	// initialize time arrays
	zeroOutMallocTimes = malloc(sizeof(*zeroOutMallocTimes) * TRIALS);
	zeroOutCallocTimes = malloc(sizeof(*zeroOutCallocTimes) * TRIALS);
	resizeMallocTimes = malloc(sizeof(*resizeMallocTimes) * TRIALS);
	resizeReallocTimes = malloc(sizeof(*resizeReallocTimes) * TRIALS);


	// run the trials
	for (size_t i = 0; i < TRIALS; ++i) {
		// malloc vs. calloc
		// zero out a new array with malloc
		zeroOutMallocStart = clock();
		a = malloc(sizeof(*a) * ARRAY_SIZE);
		for (size_t i = 0; i < ARRAY_SIZE; ++i)
			a[i] = 0;
		zeroOutMallocEnd = clock();
		zeroOutMallocTime = ((long double)(zeroOutMallocEnd - zeroOutMallocStart)) / CLOCKS_PER_SEC;
		free(a);


		// zero out a new array with calloc
		zeroOutCallocStart = clock();
		a = calloc(ARRAY_SIZE, sizeof(*a));
		zeroOutCallocEnd = clock();
		zeroOutCallocTime = ((long double)(zeroOutCallocEnd - zeroOutCallocStart)) / CLOCKS_PER_SEC;
		free(a);


		// store times
		zeroOutMallocTimes[i] = zeroOutMallocTime;
		zeroOutCallocTimes[i] = zeroOutCallocTime;




		// resize an array with malloc
		a = calloc(ARRAY_SIZE, sizeof(*a));
		resizeMallocStart = clock();
		temp = malloc(sizeof(*temp) * ARRAY_SIZE * 2);
		for (size_t i = 0; i < ARRAY_SIZE; ++i)
			temp[i] = a[i];
		free(a);
		a = temp;
		resizeMallocEnd = clock();
		resizeMallocTime = ((long double)(resizeMallocEnd - resizeMallocStart)) / CLOCKS_PER_SEC;
		free(a);


		// resize an array with realloc
		a = calloc(ARRAY_SIZE, sizeof(*a));
		resizeReallocStart = clock();
		temp = realloc(a, ARRAY_SIZE * 2);
		a = temp; // this is redundant if realloc successfuly resized a without having to copy it
		resizeReallocEnd = clock();
		resizeReallocTime = ((long double)(resizeReallocEnd - resizeReallocStart)) / CLOCKS_PER_SEC;
		free(a);


		// store times
		resizeMallocTimes[i] = resizeMallocTime;
		resizeReallocTimes[i] = resizeReallocTime;
	}




	// calculate performance differences
	for (size_t i = 0; i < TRIALS; ++i) {
		// malloc vs. calloc zeroing out
		// calloc performed better than malloc
		if (zeroOutCallocTimes[i] < zeroOutMallocTimes[i]) {
			++zeroOutCallocWins;
			zeroOutCallocAvgPerfInc += zeroOutMallocTimes[i] - zeroOutCallocTimes[i];
		}
		// tie
		else if (zeroOutCallocTimes[i] == zeroOutMallocTimes[i]) {
			++zeroOutTies;
		}
		// malloc performed better than calloc
		else {
			++zeroOutMallocWins;
			zeroOutMallocAvgPerfInc += zeroOutCallocTimes[i] - zeroOutMallocTimes[i];
		}



		
		// malloc vs. realloc resizing
		// realloc performed better than malloc
		if (resizeReallocTimes[i] < resizeMallocTimes[i]) {
			++resizeReallocWins;
			resizeReallocAvgPerfInc += resizeMallocTimes[i] - resizeReallocTimes[i];
		}
		// tie
		else if (resizeReallocTimes[i] == resizeMallocTimes[i]) {
			++resizeTies;
		}
		// malloc performed better than realloc
		else {
			++resizeMallocWins;
			resizeMallocAvgPerfInc += resizeReallocTimes[i] - resizeMallocTimes[i];
		}
	}




	// calculate averages
	zeroOutCallocAvgPerfInc /= zeroOutCallocWins;
	zeroOutMallocAvgPerfInc /= zeroOutMallocWins;
	resizeReallocAvgPerfInc /= resizeReallocWins;
	resizeMallocAvgPerfInc /= resizeMallocWins;




	// display results
	printf("---------- RESULTS ----------\nTrials: %d\nArray Size: %d\n\n\n", TRIALS, ARRAY_SIZE);
	printf("ZEROING OUT - malloc vs. calloc\n");
	printf("%-43s%-7d", "Number of times calloc performed better:", zeroOutCallocWins);
	if (zeroOutCallocWins > 0)
		printf("%-35s%g seconds", "Average performance increase:", zeroOutCallocAvgPerfInc);
	printf("\n");
	printf("%-43s%-7d", "Number of times malloc performed better:", zeroOutMallocWins);
	if (zeroOutMallocWins > 0)
		printf("%-35s%g seconds", "Average performance increase:", zeroOutMallocAvgPerfInc);
	printf("\n");
	printf("%-43s%-7d", "Number of ties", zeroOutTies);
	printf("\n\n\n");
	printf("RESIZING - malloc vs. realloc\n");
	printf("%-43s%-7d", "Number of times realloc performed better:", resizeReallocWins);
	if (resizeReallocWins > 0)
		printf("%-35s%g seconds", "Average performance increase:", resizeReallocAvgPerfInc);
	printf("\n");
	printf("%-43s%-7d", "Number of times malloc performed better:", resizeMallocWins);
	if (resizeMallocWins > 0)
		printf("%-35s%g seconds", "Average performance increase:", resizeMallocAvgPerfInc);
	printf("\n");
	printf("%-43s%-7d", "Number of ties", resizeTies);
	printf("\n\n\n");




	free(zeroOutMallocTimes);
	free(zeroOutCallocTimes);
	free(resizeMallocTimes);
	free(resizeReallocTimes);


	return 0;
}
