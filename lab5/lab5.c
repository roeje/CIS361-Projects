/*

	CIS 371 - Lab 5
	Jesse Roe
	10/13/2016

*/

#include <stdio.h>
#include <stdlib.h>

struct Mark {
	int x;
	int y;
};

typedef struct Mark Mark;

/* load the structure that p points to with the date from f */
void getInfo (FILE * f, Mark * p);

/* write the data stored in structure item into output file f */
void printInfo (FILE * f, Mark item);

/* compare what pointers a and b point to; to be used by qsort() */
int compare (const void * a, const void * b);

int main()
{
	Mark list[100];
	Mark mark;
	int size = 0, i, col = 0;
	FILE * fin;

	fin = fopen ("lab5.dat", "r");
	if ( fin == NULL )
	{
		printf ("Cannot open file.\n");
		exit(1);
	}

	while ( !feof(fin) )
	{
		getInfo (fin, &mark);
		list[size++] = mark;
	}

	// Qsort with custom comparitor function
	qsort(list, size , sizeof(mark), compare);

	for (i = 0; i < size; i++)
	{
		printInfo (stdout, list[i]);
		if ( ++col % 5 == 0 )
			printf("\n");
	}
	printf("\n");

	fclose (fin);

	return 0;
}

/* complete the following helper functions */

void getInfo (FILE * f, Mark * p)
{

	// read two integers from the input file and
	// store them in the structure that p points to
 	int x;
	int y;
	int success;

	// Read in each pair of ints
	success = fscanf(f, "%d %d", &x, &y);

	// If read successfully, save int pair in Mark struct
	if (success > 0) {
		(*p).x = x;
		(*p).y = y;
	}
	else {
		printf("Error Reading Line From File...\n");
		return;
	}
}

// Display each pair in array of Marks
void printInfo (FILE * f, Mark item)
{
	// display each mark in format of (x, y)
	// and five marks per line
	fprintf(f, "(%d,%d)", item.x, item.y);
}

// Custom compair function for qsort)()
int compare (const void * a, const void * b)
{
	// compare two structures
	// return 0 if they are equal, a value less than 0 if the first
	// comes before the second, a value greater than 0 otherwise

	// Store the values for x and y for both Marks in local variables
	int xA = ((Mark *)a) -> x;
	int yA = ((Mark *)a) -> y;
	int xB = ((Mark *)b) -> x;
	int yB = ((Mark *)b) -> y;

	/* Logic to sort - Assumed that the printer will run from the bottom of the
		page (small values of y) to the top of the page (large values of y) since
		this was not specified by the instructions. Values of y are considered
		first when sorting, if the values of y are equal, then the values of x are
		considered to make the x values increase (printing from left to right).
	*/
	if (yA == yB) {
		if (xA < xB) {
			return -1;
		}
		else if (xA > xB) {
			return 1;
		}
		else {
			return 0;
		}
	}

	/*
	 	Sort so that y starts small (the bottom of the page) and increase in value
		(printing toward the top of the page)
	*/
	if (yA < yB) {
		return -1;
	}
	else {
		return 1;
	}
}
