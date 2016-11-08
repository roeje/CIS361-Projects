/*
   Created by Jesse Roe

   Linked list implementation in C

*/


#include "list.h"

node *head = NULL;
node *current = NULL;

/*
   Print linked list to console
*/
void print () {
   node *tmp = head;
   printf("\n[");

   while(tmp != NULL) {
      printf("(%s, ", tmp->name);
      queue a = tmp->dataQueue;
      while (!empty(&a)) {
         int pid = dequeue(&a);
         printf("%d, ", pid);
      }
      printf(")\n");
      tmp = tmp->next;
   }
   printf(" ]\n");
}

/*
   Write linked list to provided file
*/
void writeToFile (FILE *file) {
   node *tmp = head;

   while(tmp != NULL) {
      fprintf(file, "%s ", tmp->name);
      queue a = tmp->dataQueue;
      while (!empty(&a)) {
         int pid = dequeue(&a);
         fprintf(file, "%d, ",pid);
      }
      fprintf(file, "\n");
      tmp = tmp->next;
   }
}

/*
   Insert data into front of list
*/
void insert (char nameValue[], int data) {

   // Create temp node for find return value
   node *existing;

   // Determine if node already exists in linked list
   if ((existing = find(nameValue)) != NULL) {

      // Check if queue already contains data
      if (containsValue(&(existing->dataQueue), data)) {
         return;
      }
      else {
         enqueue(data, &(existing->dataQueue));
      }

   }
   else {
      node *tmp = (node*) malloc(sizeof(node));

      strcpy(tmp->name, nameValue);
      initialize(&(tmp->dataQueue));
      enqueue(data, &(tmp->dataQueue));

      // Set the new nodes next equal
      tmp->next = head;

      // Set head to new node (first item)
      head = tmp;
   }
}

/*
   Locate a node in the list or return NULL
*/
node* find (char nameValue[]) {

   node* current = head;

   if (head == NULL) {
      return NULL;
   }

   while (strcmp(current->name, nameValue) != 0) {
      if (current->next == NULL) {
         return NULL;
      }
      else {
         current = current->next;
      }
   }
   return current;
}

/*
   Delete a node from the list
*/
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
