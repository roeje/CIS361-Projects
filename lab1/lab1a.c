#include <stdio.h>
#include <ctype.h>

int main () {
	char ch;

	printf (“Enter text (Ctrl-D to quit).\n”);
	while ( ch = getchar(), ch != EOF ) {
		if ( islower(ch) ) {
			ch = toupper(ch);
		}
		else {
			ch = tolower(ch);
		}
		putchar(ch);
	}
	return 0;
}