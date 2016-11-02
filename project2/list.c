
#include "list.h"

void print () {
   node *tmp = head;
   printf("\n[");

   while(tmp != NULL) {
      printf("(%s) ", tmp->name);
   }
   printf(" ]\n");
}

void insert (char nameValue[], int data) {

   if (find(nameValue) != NULL) {
      node *existing = find(nameValue);
         enqueue(data,&(existing->dataQueue));
   }
   else {
      node *tmp = (node*) malloc(sizeof(node));

      tmp->name = nameValue;
      initialize(&(tmp->dataQueue));
      enqueue(data, &(tmp->dataQueue));

      // Set the new nodes next equal
      tmp->next = head;

      // Set head to new node (first item)
      head = tmp;
   }
}

node* find (char nameValue[]) {

   node* current = head;

   if (head == NULL) {
      return NULL;
   }

   while (!strcmp(current->name, nameValue)) {
      if (current->next == NULL) {
         return NULL;
      }
      else {
         current = current->next;
      }
   }
   return current;
}

node* delete (char nameValue[]) {

   node* current = head;
   node* previous = NULL;

   if (head == NULL) {
      return NULL;
   }

   while (strcmp(current->name, nameValue)) {
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
