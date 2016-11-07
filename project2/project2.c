/*
	CIS 361 - Project 2
	Jesse Roe
	10/31/2016
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// #include "queue.h"
#include "list.h"

/*Main method*/
int main(int argc, char *argv[]) {

	/*Define variables*/

   FILE *fin, *fout;


   // Check to see if correct number of commandline parameter were passed
	if (argc != 3) {
	  printf ("Usage: project2.c infile outfile\n");
	  exit(1);
	}

   printf("File In: %s\n",argv[1]);
   printf("File Out: %s\n",argv[2]);


   // Attempt to open files passed from commandline
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");


   char * line = readline(fin);

	return 0;
}
