
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

struct node {
   queue dataQueue;
   struct node *next;
   char name[100];
};

typedef struct node node;

void print ();
void writeToFile (FILE *file);
void insert (char name[], int data);
node* find (char name[]);
node* delete (char name[]);
