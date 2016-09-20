#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char encrypt(char ch, int *k, int *n, int *size);

int main(int argc, char *argv[]) {

	int choice;
	char *key = NULL;
	int *keyNumerical;
	char ch;
	int numOfCh;
	int size;
	FILE *fin, *fout;

	if (argc != 5) {
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption\n");
		exit(1);
	}

	choice = strtol(argv[1], NULL, 10);
	printf("Choice: %d\n", choice);
	key = argv[2];
	printf("Key: %s\n", key);
	keyNumerical = (int*) malloc(strlen(key) * sizeof(int));
	numOfCh = 0;
	size = strlen(key);

	printf("Size of Key: %d\n", strlen(key));

	for (int i = 0; i < strlen(key); i++) {
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

	// printf("KeyNum at 0: %d\n", keyNumerical[0]);
	// printf("KeyNum at 3: %d\n", keyNumerical[3]);
	// printf("KeyNum at 4: %d\n", keyNumerical[4]);
	// printf("KeyNum at 4: %d\n", keyNumerical[8]);

	// convertKeyToIntArray(key, keyNumerical);

	if (choice == 2) {
		for (int i = 0; i < size; i++) {
			printf("keyNumerical = %d\n", keyNumerical[i]);
			keyNumerical[i] = -keyNumerical[i];
			printf("keyNumerical After = %d\n", keyNumerical[i]);
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
		fprintf(fout, "%c", encrypt(ch, keyNumerical, &numOfCh, &size));
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

char encrypt(char ch, int *k, int *num, int *size) {
	int tmp = (int)fmod(*num, (double)*size);

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
