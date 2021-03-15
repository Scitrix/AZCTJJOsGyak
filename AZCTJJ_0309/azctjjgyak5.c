#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int number = 5;
	int status;
	pid_t process;
	process = fork();

	if (process < 0)
	{
		perror("fork");
		return 2;
	}
	else if(process == 0)
	{
		number = number/0;
		exit(7);
	}
	if(wait(&status) != process)
	{
		perror("wait hiba");
	}
	if (WIFEXITED(status))
	{
		printf("Normalis befejezodes, visszaadott ertek = %d\n", WEXITSTATUS(status));
	}

	if (process < 0)
	{
		perror("fork hiba");
	}
	else if(process == 0)
	{
		abort();
	}
	if (wait(&status) != process)
	{
		perror("wait hiba");
	}
	if (WIFSIGNALED(status))
	{
		printf("Abnormalis befejezodes, a szignal sorszama = %d\n", WTERMSIG(status));
	}
	return 0;
}
