/*
	CIS 361 - Project 1
	Jesse Roe
	09/19/2016
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// remove duplicate characters in array word and return the result string
char * removeDuplicates(char word []);

// search the first num characters in array charArray for character target
int targetFound(char charArray[], int num, char target);

// initialize the encrypt array with appropriate cipher letters according to the given key
void initializeEncyptArray(char key[], char encrypt[]);

// initialize the decrypt array with appropriate substitute letters based on the encrypt array
void initializeDecyptArray(char encypt[], char decrypt[]);

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]);

/*Encryption function declaration*/
char encrypt(char ch, int *k, int *n, int *size);

// Test Functions
void testRmDuplicates();
void testTargetFound();
void testEncryptArray();


/*Main method*/
int main(int argc, char *argv[]) {

  testRmDuplicates();

  //testTargetFound();

  //testEncryptArray();

	/*Define variables*/
	int choice;
	char *key = NULL;
	char *newKey;
	char ch;
	int numOfCh;
	int size;
	FILE *fin, *fout;
  
	if (argc != 5) {
	  printf ("Usage: cipher option key infile, outfile\n");
	  printf ("Option 1 for encryption and 2 for decryption\n");
	  exit(1);
	}
 
	/*Assign values to variables*/
	choice = strtol(argv[1], NULL, 10);
	key = argv[2];
	
	fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");

	if (fin ==  NULL || fout == NULL) {
	  printf("File could not be opened\n");
	  exit(1);
	}

	newKey = removeDuplicates(key);
	
	if (choice == 1) {
	  
	  initializeEncyptArray(newKey,encrypt);  
	  
	  processInput(fin, fout, encrypt);
	  
	}
	else {
	  
	  initializeDecyptArray(newKey, decrypt);
	  processInput(fin, fout, decrypt);
	}

	
	// /*Encrypt/decrypt each file*/
	// while ( fscanf(fin, "%c", &ch) != EOF ) {
	// 	fprintf(fout, "%c", encrypt(ch, keyNumerical, &numOfCh, &size));
	// }
	
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}

// Not working yet, need to create new array to store non duplicate characters
char* removeDuplicates(char word[]) {
  char tmp[(int)strlen(word)];
  int i, j, size, k;
  size = strlen(word);
  for (i = 0; i < size; i++) {
    
    for (j = k = (i + 1); k <= size;) {
      if (word[i] != word[k]) {
        tmp[i] = word[k];
        k++;
        j++;
      }
      else {
        k++;
      }
    }
  }

  char* out  = word;
  return out;
}

int targetFound(char charArray[], int num, char target) {
   int i;
   for (i = 0; i < num; i++) {
      if (charArray[i] == target) {
         return 1;
      }
   }
   return 0;
}

void initializeEncyptArray(char key[], char encrypt[]) {
   int size = strlen(key);
   printf("Size: %d\n", size);
   char base = 'Z';
   int i;

   for (i = 0; i < size; i++) {
      encrypt[i] = key[i];
   }

   int j;
   for (j = size; j < 26; j++) { 
        
         while (targetFound(encrypt, (size - 1), base)) {
            base--;
         }
         encrypt[i] = base;
      
 	 printf("%c\n", encrypt[j]);
   }
   encrypt[26] = '\0';
}

void initializeDecyptArray(char encypt[], char decrypt[]) {

	int i;

	for (i = 0; i < 26; i++) {
		decrypt[encrypt[i] - 65] = 65 + i;
	
	}

	encrypt[26] = '\0';

}

void processInput(FILE * inf, FILE * outf, char substitute[]) {
  
  
  while ( fscanf(fin, "%c", &ch) != EOF ) {
    fprintf(fout, "%c", substitute[ch]);
  }

}

/*Encryption Function*/
char encrypt(char ch, int *k, int *num, int *size) {
	
	int tmp = *num % *size;

	if ( k[tmp] < 0 ) {
		k[tmp] = k[tmp] + 26;
	}

	if ( isupper(ch) ) {
		char x = (ch - 'A' + k[tmp]) % 26 + 'A';
		*num = *num + 1;
		return x;
	}

	if ( islower(ch) ) {
		char x = (ch - 'a' + k[tmp]) % 26 + 'a';
		*num = *num + 1;
		return x;
	}

	return ch;
}

void testRmDuplicates() {
	char tmp[] = "testtest";
	printf("New string is: %s\n", removeDuplicates(tmp));
}

void testTargetFound() {

   char tmp[] = "hello there";
   printf("String is: hello there\n");
   printf("Does the String contain: ");
   char target = 't';
   printf("%c\n", target);

   int x;
   x = targetFound(tmp, 11, target);

   printf("Result is: %d\n",x);
}

void testEncryptArray() {
   char encr[26];
   char word[] = "testtest";


   char * key = removeDuplicates(word);

   printf("Key is: %s\n", key);
   initializeEncyptArray(key, encr);
   printf("Encrypted Array: %d\n", (char)encr[0]);
}