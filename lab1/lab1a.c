#include <stdio.h>
#include <ctype.h>

int main () {
	char ch;
	int wordCount = 0;
	int symbolCount = 0;
	int state = 0;

	printf ("Enter text (Ctrl-D to quit).\n");
	while ( ch = getchar(), ch != EOF ) {
		if ( isspace(ch) ) {
			state = 0;
		}
		if ( (isalnum(ch) || ch == '_') && state != 1 ) {
			state = 1;
			wordCount++;
		}
		if ( ispunct(ch) && ch != '_' && state != 2 ) {
			state = 2;
			symbolCount++;
		}
		// putchar(ch);		
	}
	printf ("Your Symbol Count Was: %d -  Your Word Count Was: %d", symbolCount, wordCount);
	// printf ("Your Word Count Was: %d\n", wordCount);
	
	return 0;
}