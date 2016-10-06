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

// Remove duplicates from passed string
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

// Check if passed char is present in string
int targetFound(char charArray[], int num, char target) {
   int i;
   for (i = 0; i < num; i++) {
      if (charArray[i] == target) {
         return 1;
      }
   }
   return 0;
}

// Setup encryption array with key and alph characters
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

// Setup decryption array using encryption array
void initializeDecryptArray(char encrypt[], char decrypt[]) {
	int i;
	for (i = 0; i < 26; i++) {
		decrypt[encrypt[i] - 65] = 65 + i;
	}
	decrypt[26] = '\0';
}

// Read input from file, encrypt/decrypt, write to output file
void processInput(FILE * inf, FILE * outf, char substitute[]) {
   char ch;
   while (fscanf(inf, "%c", &ch) != EOF) {

      // If alpha encrypt/decrypt
      if (isalpha(ch)) {

         // If uppercase, encrypt/decrypt directly and write out
         if (isupper(ch)) {
            fprintf(outf, "%c", substitute[ch - 65]);
         }

         // Else, convert input to uppercase, encrypt/decrypt, and wite out
         else {
            fprintf(outf, "%c", tolower(substitute[toupper(ch) - 65]));
         }
      }

      // Else simply write out non alpha characters
      else {
         fprintf(outf, "%c", ch);
      }
   }
}

// Convert passed string to uppercase
void toUpperCase(char word[]) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        word[i] = toupper(word[i]);
    }
}
