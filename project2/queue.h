#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define  EMPTY 0
#define  FULL  10000

typedef unsigned int data;
typedef enum {FALSE, TRUE} boolean;

struct elem {
   data d;
   struct elem *next;
};

typedef struct elem elem;

struct queue {
   int cnt;
   data added[10000];
   elem *front;
   elem *rear;
};

typedef struct queue queue;
void initialize (queue *q);
void enqueue (data d, queue *q);
data dequeue (queue *q);
data front (const queue *q);
boolean empty (const queue *q);
boolean full (const queue *q);
boolean containsValue(const queue *q, data value);
