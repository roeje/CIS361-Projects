/*
	CIS 361 - Project 2
	Jesse Roe
	11/08/2016
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

	/*
		Declare various variables that are used to maintain character counts
	*/
	int foundIden = 0;
	int runMatch = 0;
	int lineNumber = 1;
	int slashCounter = 0;
	char iden[100];
	iden[0] = 0;

	// Iterate over all characters in file
	while ((c = fgetc(fin)) != EOF) {

		// if character is a " then skip all characters until the next " is foundIden
		if (runMatch != 0) {
			/*
				Various logic to detect different types of comments. uses counter variables to
				determine if a // or /* is used.
			*/
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

			// Check for ending double quote in string
			if (c == '"' && c == runMatch) {
				runMatch = 0;
				continue;
			}

			// Check for first character of a identifier being a digit.
         if ((isspace(c) || ispunct(c)) && c != '_' && runMatch == ' ') {
            runMatch = 0;
            continue;
         }

			// Check for new lines that end // comments and strings
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

		// Check if characer is double quote if it is, reset the current word count and trigger a string case.
		if (c == '"') {
			runMatch = c;
			foundIden = 0;
			continue;
		}

		// Check if character is a slash, if it is, reset word count and trigger comment case.
		if (c == '/') {
			runMatch = c;
			foundIden = 0;
			slashCounter = 1;
			continue;
		}

		// Check for new line, and increment line counter
		if (c == '\n') {
			lineNumber = lineNumber + 1;
		}

		// If character is a number, letter, or underscore,
		if (isalnum(c) || c == '_') {

         if (isdigit(c) && foundIden == 0) {
            runMatch = ' ';
            foundIden = 0;
            continue;
         }
         else {
				strncat(iden, &c, 1);
   			foundIden = foundIden + 1;
         }
		}

		// If we dont match any of the above, the word is finished and we can add to list
		else {
			if (foundIden) {
				insert(iden, lineNumber);
				memset(&iden[0], 0, sizeof(iden));
				foundIden = 0;
			}
		}
	}

	// Call list function that writes the contents of the list to an output file.
	writeToFile(fout);

	// Close all files
	fclose(fin);
	fclose(fout);
	return 0;
}
