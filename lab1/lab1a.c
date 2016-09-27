#include <stdio.h>
#include <ctype.h>

/*
	CIS 361 - Lab 1
	Jesse Roe
*/

/*Main Function: Outputs the symbol sequence and word sequence counts*/
int main () {

	/*Initilize variables to store State, counts, and input characters*/
	char ch;
	int wordCount = 0;
	int symbolCount = 0;
	int state = 0;

	printf ("Enter text (Ctrl-D to quit).\n");

	while ( ch = getchar(), ch != EOF ) {

		/*Check if space and if so, reset state*/
		if ( isspace(ch) ) {
			state = 0;
		}

		/*Check for alphanumerical and underscore characters*/
		if ( (isalnum(ch) || ch == '_') && state != 1 ) {
			state = 1;
			wordCount++;
		}

		/*Check for Punctuation characters*/
		if ( ispunct(ch) && ch != '_' && state != 2 ) {
			state = 2;
			symbolCount++;
		}

		putchar(ch);		
	}

	/*Display the results*/
	printf ("\n# of Symbol Sequences Was: %d  &  Word Count Was: %d", symbolCount, wordCount);
	
	return 0;
}