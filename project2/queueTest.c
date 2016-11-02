
/*Test For queue.c*/

#include "queue.h"

int main(void) {

   int c;
   int cnt_a = 0;
   int cnt_b = 0;
   data pid;
   queue a, b;

   initialize(&a);
   initialize(&b);

   printf("Starting Test...\n");

   while((c == getchar()) != EOF) {

      switch (c) {
         case 'A':
            assert(scanf("%u,", &pid) == 1);
            if (!full(&a)) {
               enqueue(pid,&a);
            }
            break;
         case 'B':
            assert(scanf("%u", &pid) == 1);
            if (!full(&b)) {
               enqueue(pid, &b);
            }
         break;
      }

   }

   printf("\nA's schedule:\n");
   while (!empty(&a)) {
      pid = dequeue(&a);
      printf(" Job %u is %d\n", ++cnt_a, pid);
   }

   printf("\nB's schedule:\n");
   while (!empty(&b)) {
      pid = dequeue(&b);
      printf(" Job %u is %d\n", ++cnt_b, pid);
   }

   return 0;
}
