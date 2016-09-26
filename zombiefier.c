#include <stdio.h> // standard I/O library for C
#include <sys/types.h> // systems library to allow forking with pid
#include <stdlib.h> // 
#include <unistd.h>
#include <signal.h>

int WWZ;

void handleMySignal(int signaL)
{
	do
	{
		WWZ = 1;
		exit(0);
	}while(signaL == SIGCONT);
};

int main(int argc, char *argv[])
{
	int zombieCount = 0;
	int walkingDead = atoi(argv[2]);
	pid_t zombieChild = fork();

	if(signal(SIGCONT, handleMySignal) == SIG_ERR)
	{
		exit(0);
	}
	for(zombieCount = 0; zombieCount < walkingDead; zombieCount++)
	{
		if(zombieChild == 0)
		{
			exit(0);
		}
	}

	do
	{
		sleep(5);
	}while(WWZ == 0);

	for(zombieCount = 0; zombieCount < walkingDead; zombieCount++)
	{
		wait(0);
	}

	return 0;
}