
#include "list.h"

node *head = NULL;
node *current = NULL;

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

void writeToFile (FILE *file) {
   node *tmp = head;
   // printf("\n[");

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
   // printf(" ]\n");
}

void insert (char nameValue[], int data) {
   printf("String: %s\n", nameValue);

   // Create temp node for find return value
   node *existing;

   // Determine if node already exists in linked list
   if ((existing = find(nameValue)) != NULL) {
      printf("Found Existing:\n");
      enqueue(data, &(existing->dataQueue));
   }
   else {
      printf("Creating New Node\n");
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

node* find (char nameValue[]) {

   node* current = head;

   if (head == NULL) {
      return NULL;
   }
   printf("\n");
   printf("NameValue: %s\n", nameValue);
   printf("Current->name: %s\n", current->name);
   printf("Compare: %d\n" , strcmp(current->name, nameValue));
   printf("\n");

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
