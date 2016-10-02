/*
	CIS 371 - Lab 3
	Jesse Roe
	09/26/2016
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main ()
{
	const int MaxSize = 75000;
	// const int MaxSize = 20000;  // Smaller testing size variable

	int i, j, temp;

	/* Initialize dynamic array pointer */
	int *dynamicArray;


	// Part one: processing a statically allocated array

	/*
		Log start of execution for static array segment
		I assumed that the declaration of the array was included in the time
		calculation
	 */


	int staticArray[MaxSize];		// declare an array

	for (i=0; i<MaxSize; i++) {		// initialize the array with a
		staticArray[i] = MaxSize-i;	// descending sequence of values
	}

	clock_t staticBegin = clock();

	for (i=0; i<MaxSize-1; i++)	{	// bubble sort data in the array
		for (j=MaxSize-1; j>i; j--) {
			if (staticArray[j-1] > staticArray[j]) {
				temp = staticArray[j-1];
				staticArray[j-1] = staticArray[j];
				staticArray[j] = temp;
			}
		}
	}

	clock_t staticEnd = clock(); // Log end of static segment

	/*
		Part two: processing a dynamically allocated array
	*/

	dynamicArray = (int*)malloc(MaxSize * sizeof(int)); // Create dynamic array of correct size

	/* Populate array with descending values */
	for (i = 0; i < MaxSize; i++) {
		*(dynamicArray + i) = (MaxSize - i);
	}

	clock_t dynamicBegin = clock(); // Log start of dynamic segment
	/* Sort array */
	for (i = 0; i < (MaxSize - 1); i++) {
		int *p;
		for (p = dynamicArray + (MaxSize - 1); p > dynamicArray + i; p--) {
			if (*(p - 1) > *p) {
				int tmp = *(p - 1);
				*(p - 1) = *p;
				*p = tmp;
			}
		}
<<<<<<< HEAD
		
	}	
=======
	}

	/*Old version*/
	// for (i = 0; i < (MaxSize - 1); i++) {
	// 	for (j = (MaxSize - 1); j > i; j--) {
	// 		if (*(dynamicArray + (j - 1)) > *(dynamicArray + j)) {
	// 			int tmp = *(dynamicArray + (j - 1));
	// 			*(dynamicArray + (j - 1)) = *(dynamicArray + j);
	// 			*(dynamicArray + j) = tmp;
	// 		}
	// 	}
	// }
>>>>>>> dev

	clock_t dynamicEnd = clock(); // Log end of dynamic segment

	/* Output Sorted Array Test */
	// printf("After Sorted Dynaimc Array:\n");
	// for (i = 0; i < MaxSize; i++) {
	// 	printf("%d\n", *(dynamicArray + i));
	// }

	// Display the amount of time used for each part above
	printf("Time used for Static Array: %lf %s\n", (double)(staticEnd - staticBegin) / CLOCKS_PER_SEC, "Seconds");

	printf("Time used for Dynamic Array: %lf %s\n", (double)(dynamicEnd - dynamicBegin) / CLOCKS_PER_SEC, "Seconds");

	/* Free up mem used for array */
	free(dynamicArray);
	return 0;
}
