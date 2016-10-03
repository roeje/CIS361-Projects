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

/*Main method*/
int main(int argc, char *argv[]) {

  char encrypt[], decrypt[];

	// /*Define variables*/
	// int choice;
	// char *key = NULL;
	// int *keyNumerical;
	// char ch;
	// int numOfCh;
	// int size;
	// FILE *fin, *fout;
  //
	// if (argc != 5) {
	// 	printf ("Usage: cipher option key infile, outfile\n");
	// 	printf ("Option 1 for encryption and 2 for decryption\n");
	// 	exit(1);
	// }
  //
	// /*Assign values to variables*/
	// choice = strtol(argv[1], NULL, 10);
	// key = argv[2];
	// keyNumerical = (int*) malloc(strlen(key) * sizeof(int));
	// numOfCh = 0;
  //
	// /*Size of dynamically allocated array*/
	// size = strlen(key);
  //
	// /*Build integer array from key string*/
	// int i;
	// for (i = 0; i < strlen(key); i++) {
  //
	// 	if ( isupper(key[i]) ) {
	// 		keyNumerical[i] = (key[i] - 'A') % 26;
	// 	}
  //
	// 	if ( islower(key[i]) ) {
	// 		keyNumerical[i] = (key[i] - 'a') % 26;
	// 	}
	// }
  //
	// /*Invert key values for decryption*/
	// if (choice == 2) {
	// 	for (int i = 0; i < size; i++) {
	// 		keyNumerical[i] = -keyNumerical[i];
	// 	}
	// }
  //
  //   fin = fopen(argv[3], "r");
	// fout = fopen(argv[4], "w");
  //
  //   if (fin ==  NULL || fout == NULL) {
	// 	printf("File could not be opened\n");
	// 	exit(1);
	// }
  //
	// /*Encrypt/decrypt each file*/
	// while ( fscanf(fin, "%c", &ch) != EOF ) {
	// 	fprintf(fout, "%c", encrypt(ch, keyNumerical, &numOfCh, &size));
	// }
  //
	// fclose(fin);
	// fclose(fout);
	// free(keyNumerical);

	return 0;
}


char* removeDuplicates(char word[]) {
  int i, j, size, k;
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

  char* out  = word;
  return out;
}

int targetFound(char charArray[], int num, char target) {


  return 1;
}

void initializeEncyptArray(char key[], char encrypt[]) {



}

void initializeDecyptArray(char encypt[], char decrypt[]) {



}

void processInput(FILE * inf, FILE * outf, char substitute[]) {



}

/*Encryption Function*/
char encrypt(char ch, int *k, int *num, int *size) {

	/*Calculate Mod*/
	/*fmod wasnt working in c99 mode for some reason*/
	// int tmp = (int)fmod(*num, (double)*size);
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
