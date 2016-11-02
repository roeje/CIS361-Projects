#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

struct node {
   queue dataQueue;
   char[] name;
   struct node *next;
};

typedef struct node node;

struct node *head = NULL;
struct node *current = NULL;

void print () {
   node *tmp = head;
   printf("\n[");

   while(ptr != NULL) {
      printf("(%s) ", ptr->name);
   }
   printf(" ]\n");
}

void insert (char[] name, int data) {

   if (find(name) != NULL) {
      node *existing = find(name);
         enqueue(data,&(existing->dataQueue));
   }
   else {
      struct node *tmp = (struct node*) malloc(sizeof(struct node));

      tmp->name = name;
      initialize(&(tmp->data));
      enqueue(data, &(tmp->data));

      // Set the new nodes next equal
      tmp->next = head;

      // Set head to new node (first item)
      head = tmp;
   }
}

struct node* find (char[] name) {

   struct node* current = head;

   if (head == NULL) {
      return NULL;
   }

   while (!strcmp(current->name, name)) {
      if (current->next == NULL) {
         return NULL;
      }
      else {
         current = current->next;
      }
   }
   return current;
}

struct node* delete (char[] name) {

   struct node* current = head;
   struct node* previous = NULL;

   if (head == NULL) {
      return NULL;
   }

   while (strcmp(current->name, name)) {
      if (current->next == NULL) {
         return NULL;
      }
      else {
         previous = current;
         current = current->next;
      }
   }
   if (current == head) {
      head = head->next;
   }
   else {
      previous->next = current->next;
   }
   return current;
}
