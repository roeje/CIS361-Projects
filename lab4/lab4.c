/*
  CIS 361 - Lab 4
  Jesse Roe
  10/04/2016
*/

#include <stdio.h>
#include <string.h>

#define LEN 4

char* strnsub (char *p, int n);

int main() {
	char line[] = "His texttree was bought from that treestore";
	char *p1, *p2;

	//set p1 to the beginning of string line;
	p1 = line;

	// printf("IS EQUAL to 0: %d\n", strncmp((p1 + 8), (p1 + 34), LEN));
	while ( p1 != NULL && *p1 != '\0' ) {
		p2 = p1 + 1;
		// printf("Value at P1: %d\n", *(p1));
		while ( p2 != NULL && *p2 != '\0' ) {
			if (strncmp(p1, p2, LEN) == 0) {	// use strncmp() to compare
				// printf("DONE\n");
				goto done;
			}

			p2 = p2 + 1;
		}

		p1 = p1 + 1;
	}

	done:
		printf ("the first substring: %s\n", strnsub(p1, LEN));
		printf ("the second substring: %s\n", strnsub(p2, LEN));

	return 0;
}

// returns a string with the first n characters of string p

char* strnsub (char *p, int n) {
		char s[n]; // Create temp array to store substring
      char* out = s;
		strncpy(out, p, n); // Copy substring
		*(out + n) = '\0'; // append null character

		return out;
}
