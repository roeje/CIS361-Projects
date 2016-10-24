/*

	CIS 371 - Lab 6
	Jesse Roe
	10/24/2016

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 80
#define MAXARG 20

void background (char * cmd);

int main() {

   char cmd[MAXLINE];
   for (; ;) {
      printf("mysh$ ");
      fgets(cmd, MAXLINE, stdin); // read a command from the user
      // if the command in cmd is “exit\n”, then terminate this program;
      if (strcmp(cmd,"exit\n") == 0) {
         printf("Exit...\n");
         return 0;
      }

      printf("%s\n", cmd);

      // otherwise, create a child process to handle that command.
      int value = fork();

      if (value == 0) {
         printf("Running Command\n");
         background(cmd);
      }
   }

	return 0;
}

void background (char * cmd) {

   printf("In Background\n");

   int i = 0;
   char *tmp;
   char *argv[MAXARG];

   tmp = strtok(cmd, "\t \n");
   while(tmp != NULL && tmp != "\n") {
      printf("TMP: %s\n", tmp);
      strcpy(argv[i], tmp);
      tmp = strtok(NULL, "\t \n");
      i++;
   }
   printf("ARGV: %s\n", argv);

   execvp(argv[0], argv);
   // Here you may use strtok(cmd, "\t \n") to get each token
   // from cmd and then store it in array argv sequentially.
   // strtok() returns NULL when the end of cmd is reached.


}
