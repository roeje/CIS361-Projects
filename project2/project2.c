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
#include <regex.h>

// #include "queue.h"
#include "list.h"

/*Main method*/
int main(int argc, char *argv[]) {

	/*Define variables*/
	int c;
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

	if (fin == 0 || fout == 0) {
        //fopen returns 0, the NULL pointer, on failure
        printf("Canot open input file\n");
        exit(-1);
   }

	int foundIden = 0;
	int runMatch = 0;
	int lineNumber = 1;
	int slashCounter = 0;
	// char iden[];


	while ((c = fgetc(fin)) != EOF ) {

		// if character is a " then skip all characters until the next " is foundIden

		if (runMatch != 0) {
			if (c == '/' && c == runMatch) {

				if (slashCounter == 1) {

					slashCounter = 0;
					continue;
				}
				else {
					runMatch = 0;
					continue;
				}
			}
			if (c == '"' && c == runMatch) {
				runMatch = 0;
				continue;
			}
         if ((isspace(c) || ispunct(c)) && c != '_' && runMatch == ' ') {
            runMatch = 0;
            continue;
         }

			if (c == '\n') {
				lineNumber = lineNumber + 1;
				if (slashCounter != 0) {
					continue;
				}
				else {
					runMatch = 0;
					continue;
				}
			}
			else {

				continue;
			}
		}

		if (c == '"') {
			runMatch = c;
			foundIden = 0;
			continue;
		}
		if (c == '/') {
			runMatch = c;
			foundIden = 0;
			slashCounter = 1;
			continue;
		}

		if (c == '\n') {
			lineNumber = lineNumber + 1;
		}

		if (isalnum(c) || c == '_') {

         if (isdigit(c) && foundIden == 0) {
            runMatch = ' ';
            foundIden = 0;
            continue;
         }
         else {
            printf("%c", c);
   			foundIden = foundIden + 1;
         }

		}
		else {
			if (foundIden) {
				printf(" - %d\n", lineNumber);
				foundIden = 0;
			}
		}


	}
   // char * line = readline(fin);


	fclose(fin);
	fclose(fout);
	return 0;
}
