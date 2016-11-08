/*
   Created by Jesse Roe
   Basic queue implemention
   Based on implementation in A Book on C - Programming in C 4th
*/

#include "queue.h"

/*
   Setup basic elemnets of q
*/
void initialize (queue *q) {
   q->cnt = 0;
   q->front = NULL;
   q->rear = NULL;
}

/*
   Dequeue front of queue
*/
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

/*
   Insert one element into queue
*/
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

/*
   Return first element of queue
*/
data front (const queue *q) {
   return (q->front->d);
}

/*
   Check if queue is empty
*/
boolean empty (const queue *q) {
   return ((boolean)(q->cnt == EMPTY));
}

/*
   Check if queue is full
*/
boolean full (const queue *q) {
   return ((boolean)(q->cnt == FULL));
}

/*
   Check if queue already contains a certain value
*/
boolean containsValue(const queue *q, data value) {
   // data list[10000] = q->added;
   int i;
   for (i = 0; i < (q->cnt); i++) {
      if ((q->added)[i] == value) {
         return 1;
      }
   }
   return 0;
}
