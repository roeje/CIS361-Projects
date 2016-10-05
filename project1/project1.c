/*
	CIS 361 - Project 1
	Jesse Roe
	10/04/2016
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
void initializeEncryptArray(char key[], char encrypt[]);

// initialize the decrypt array with appropriate substitute letters based on the encrypt array
void initializeDecryptArray(char encypt[], char decrypt[]);

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]);

// Helper function to convert string to uppercase
void toUpperCase(char word[]);

/*Encryption function declaration*/
char encrypt(char ch, int *k, int *n, int *size);

// Test Functions
void testRmDuplicates();
void testToUpperCase();
void testTargetFound();
void testEncryptArray();
void testDecryptAarry();

/*Main method*/
int main(int argc, char *argv[]) {

	/*Define variables*/
   int choice;
   char *key = NULL;
   char *newKey = NULL;
   char decrypt[26], encrypt[26];
   FILE *fin, *fout;

   // Check to see if correct number of commandline parameter were passed
	if (argc != 5) {
	  printf ("Usage: cipher option key infile, outfile\n");
	  printf ("Option 1 for encryption and 2 for decryption\n");
	  exit(1);
	}

   /*Assign values from commandline to variables*/
   choice = strtol(argv[1], NULL, 10);
   key = argv[2];

   // Attempt to open files passed from commandline
	fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");

   // Check if files were opened correctly
	if (fin ==  NULL || fout == NULL) {
	  printf("File could not be opened\n");
	  exit(1);
	}

   // Remove duplicates from key and convert to uppercase
	newKey = removeDuplicates(key);
   toUpperCase(newKey);

   // Based on user input, setup arrays for decryption or encryption

   // If encryption option
	if (choice == 1) {
	  initializeEncryptArray(newKey,encrypt);

     // Call processing function
	  processInput(fin, fout, encrypt);
	}

   // Otherwise, decrypt
	else {
     initializeEncryptArray(newKey, encrypt);
	  initializeDecryptArray(encrypt, decrypt);

     // Call processing function
	  processInput(fin, fout, decrypt);
	}

   // Close files
	fclose(fin);
	fclose(fout);

	return 0;
}

char* removeDuplicates(char word[]) {
  int i, j, size, k;
  char* out;
  size = strlen(word);
  for (i = 0; i < size; i++) {
    for (j = k = (i + 1); k <= size;) {
      if (word[i] != word[k]) {
        word[j] = word[k];
        k++;
        j++;
      }
      else {
        k++;
      }
    }
  }
  out = word;
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

void initializeEncryptArray(char key[], char encrypt[]) {
   int size, i, j;
   char base = 'Z';
   size = strlen(key);
   for (i = 0; i < size; i++) {
      encrypt[i] = key[i];
   }
   for (j = size; j < 26; j++) {
      while (targetFound(key, size, base)) {
         base--;
      }
      encrypt[j] = base;
      base--;
   }
   encrypt[26] = '\0';
}

void initializeDecryptArray(char encrypt[], char decrypt[]) {
	int i;
	for (i = 0; i < 26; i++) {
		decrypt[encrypt[i] - 65] = 65 + i;
	}
	decrypt[26] = '\0';
}

void processInput(FILE * inf, FILE * outf, char substitute[]) {
   char ch;
   while (fscanf(inf, "%c", &ch) != EOF) {
      if (isalpha(ch)) {
         if (isupper(ch)) {
            fprintf(outf, "%c", substitute[ch - 65]);
         }
         else {
            fprintf(outf, "%c", tolower(substitute[toupper(ch) - 65]));
         }
      }
      else {
         fprintf(outf, "%c", ch);
      }
   }
}

void toUpperCase(char word[]) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        word[i] = toupper(word[i]);
    }
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
   char encrypt[26];
   char word[] = "testtest";
   char * key = removeDuplicates(word);
   toUpperCase(key);
   printf("Key is: %s\n", key);
   initializeEncryptArray(key, encrypt);
   printf("Encrypted Array: %s\n", encrypt);
}

void testDecryptAarry() {
   char encrypt[26], decrypt[26];
   char word[] = "feather";
   char* key = removeDuplicates(word);
   toUpperCase(key);
   printf("Key is: %s\n", key);
   initializeEncryptArray(key, encrypt);
   initializeDecryptArray(encrypt, decrypt);
   printf("Decrypt Array is: %s\n", decrypt);
}

void testToUpperCase() {
    char word[] = "hello";
    toUpperCase(word);
    printf("The word is: %s\n", word);
}
