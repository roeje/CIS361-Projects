#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "list.h"

/*Main method*/
int main(void) {

	/*Define variables*/
   char a[] = "Test 1";
   char b[] = "Test 2";
   char c[] = "Test 3";

   int i;
   for (i = 0; i < 3; i++) {
      insert(a, i);
   }
   for (i = 0; i < 3; i++) {
      insert(b, i);
   }
   for (i = 0; i < 3; i++) {
      insert(c, i);
   }


   // Check to see if correct number of commandline parameter were passed
	// if (argc != 5) {
	//   printf ("Usage: project2.c option key infile, outfile\n");
	//   exit(1);
	// }


	return 0;
}
