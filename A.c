#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>

#define SECONDS_TO_TERMINATE 5

bool waiter = true;

void sign_base(int sig)
{
	printf("A got signal\n");
	waiter = 0;
}

int main()
{
	signal(SIGUSR1, sign_base);

	pid_t id = fork();

	if(id == 0)
	{
		execl("./B", "program B",  NULL);
	}

	while (waiter)
		sleep(0);
	sleep(SECONDS_TO_TERMINATE);

	if (waitpid(id, NULL, WNOHANG) == 0)
	{
		printf("Program B did not finish within %d seconds\nTeminating B and subprograms...\n", SECONDS_TO_TERMINATE);
		killpg(getpgid(id), SIGTERM);
		printf("B terminated\n");
	}	
		
	exit(EXIT_SUCCESS);
}