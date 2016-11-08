/*
   Basic queue implemention
   Based on implementation in A Book on C - Programming in C 4th
*/

#include "queue.h"

void initialize (queue *q) {
   q->cnt = 0;
   q->front = NULL;
   q->rear = NULL;
}

data dequeue (queue *q) {
   data d;
   elem *p;

   d = q->front->d;
   p = q->front;
   q->front = q->front->next;
   (q->added)[q->cnt] = -1;
   q->cnt--;
   free(p);
   return d;
}

void enqueue (data d, queue *q) {
   elem *p;

   p = malloc(sizeof(elem));
   p->d = d;
   p->next = NULL;

   if (!empty(q)) {
      q->rear->next = p;
      q->rear = p;
   }
   else {
      q->front = q->rear = p;
   }
   (q->added)[q->cnt] = d;
   q->cnt++;
}

data front (const queue *q) {
   return (q->front->d);
}

boolean empty (const queue *q) {
   return ((boolean)(q->cnt == EMPTY));
}

boolean full (const queue *q) {
   return ((boolean)(q->cnt == FULL));
}

boolean containsValue(const queue *q, data value) {
   // data list[10000] = q->added;
   int i;
   for (i = 0; i < sizeof(q->added); i++) {
      if ((q->added)[i] == value) {
         return 1;
      }
   }
   return 0;
}
