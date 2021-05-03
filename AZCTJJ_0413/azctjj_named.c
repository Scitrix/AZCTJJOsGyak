#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MSIZE 10

int main(){
   char inBuffer[MSIZE];
   int p[2], nbytes, pid;
   if (pipe(p) < 0){
       perror("Pipe hiba");
       exit(1);
   }
   pid = fork();
   if (pid < 0)
      exit(2);
   if (pid == 0){
      printf("Child: Most irok a pipe-ba!\n");
      write(p[1], "RD AZCTJJ", MSIZE);
   }
//Parent Kiolvassa
   else if (pid > 0 ){
      wait(NULL);
      read(p[0], inBuffer, MSIZE);
      printf("Kiolvasott ertek: %s\n", inBuffer);
   }
return 0;
}