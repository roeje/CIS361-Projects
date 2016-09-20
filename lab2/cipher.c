#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char encrypt(char ch, int *k, int *n);

int main(int argc, char *argv[]) {
	printf ("Starting\n");

	int choice;
	char *key = NULL;
	int *keyNumerical;
	char ch;
	int numOfCh;
	FILE *fin, *fout;

	if (argc != 5) {
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption\n");
		exit(1);
	}

	choice = argv[1];
	printf("Choice: %d\n", choice);
	key = argv[2];
	printf("Key: %s\n", key);
	keyNumerical = (int*) malloc(sizeof(key) * sizeof(int));
	numOfCh = 0;

	printf("Size of Key: %d\n", sizeof(key));

	for (int i = 0; i < sizeof(key); i++) {
		// printf("Is Upper: %d\n", isupper(key[i]));
		if ( isupper(key[i]) ) {
			keyNumerical[i] = (key[i] - 'A') % 26;
			printf("Key: %c\n", key[i]);
			printf("Converted KeyNum: %d\n", keyNumerical[i]);
		}
		// printf("Is Lower: %d\n", islower(key[i]));
		if ( islower(key[i]) ) {
			keyNumerical[i] = (key[i] - 'a') % 26;
			printf("Key: %c\n", key[i]);
			printf("Converted KeyNum: %d\n", keyNumerical[i]);
		}
	}

	printf("KeyNum at 0: %d\n", keyNumerical[0]);
	printf("KeyNum at 3: %d\n", keyNumerical[3]);
	printf("KeyNum at 4: %d\n", keyNumerical[4]);

	// convertKeyToIntArray(key, keyNumerical);

	if (choice == 2) {
		for (int i = 0; i < sizeof(keyNumerical); i++) {
			printf("keyNumerical = %d\n", keyNumerical[i]);
			keyNumerical[i] = -keyNumerical[i];
		}
	}

    fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");

    if (fin ==  NULL || fout == NULL) {
		printf("File could not be opened\n");
		exit(1);
	}
	printf("Start Encryption Process:\n");

	while ( fscanf(fin, "%c", &ch) != EOF ) {
		fprintf(fout, "%c", encrypt(ch, keyNumerical, &numOfCh));
		numOfCh++;
	}

	fclose(fin);
	fclose(fout);
	free(keyNumerical);

	return 0;
}

// int convertKeyToIntArray(char *key, int *keyNumerical) {
// 	printf("Key Size: %d\n", sizeof(key));
// 	for (int i = 0; i < sizeof(key); i++) {
// 		// printf("Is Upper: %d\n", isupper(key[i]));
// 		if ( isupper(key[i]) ) {
// 			keyNumerical[i] = (key[i] - 'A') % 26;
// 			printf("Key: %c\n", key[i]);
// 			printf("Converted KeyNum: %d\n", keyNumerical[i]);
// 		}
// 		// printf("Is Lower: %d\n", islower(key[i]));
// 		if ( islower(key[i]) ) {
// 			keyNumerical[i] = (key[i] - 'a') % 26;
// 			printf("Key: %c\n", key[i]);
// 			printf("Converted KeyNum: %d\n", keyNumerical[i]);
// 		}
// 	}
// 	return 0;
// }

char encrypt(char ch, int *k, int *num) {
	printf("Starting: N = %d \n", *num);
	int tmp = (int)fmod(*num, sizeof(k));

	printf("KeyNum at 0: %d\n", k[0]);
	printf("KeyNum at 3: %d\n", k[1]);
	printf("KeyNum at 4: %d\n", k[2]);

	printf("TempIndex: %d\n", tmp);
	if ( k < 0 ) {
		k = k + 26;
	}

	if ( isupper(ch) ) {
		return (ch - 'A' + k[tmp]) % 26 + 'A';
	}

	if ( islower(ch) ) {
		return (ch - 'a' + k[tmp]) % 26 + 'a';
	}

	return ch;
}
