#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{	
	char *programName = "ls";
	char *arg1 = "-lh";
	char *arg2 = "/home";
	pid_t process;
	process = fork();

	if (process < 0)
	{
		perror("fork");
		return 2;
	}

	if (process == 0)
	{
		execlp(programName, programName, arg1, arg2, NULL);
		perror("execlp");
		return 2;
	}

	int status;
	pid_t wait_result;

	while ((wait_result = wait(&status)) != -1)
	{
		printf("Process %lu returned result: %d\n", (unsigned long) wait_result, status);
	}

	printf("All children have finished. \n");

	return 0;
}
