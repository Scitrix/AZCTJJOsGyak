#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
 char command[20];
 printf("Adjon meg egy parancsot: \n");
 scanf("%s", command);
 printf("a valasztott parancs: \n %s", command);
 system(command);

}
