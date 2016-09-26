/*
Author: Omar Mohammed Mousa
Student ID #: 006181240
Title: Zombiefier
Description: C program that intakes two arguments from command line to create 1 to n amount of zombie processes by sleeping the parent process.
	     By using signal (-SIGCONT) the parent process should resume and reap all zombie processes and terminate program
*/
#include <stdio.h> // standard input/output library
#include <sys/types.h>  // data types will be using pid_t
#include <stdlib.h> // process control library
#include <unistd.h> // process control library
#include <signal.h>// signal handling library 

int WWZ = 0; // global variable to keep process running

void handler(int signaL) // signal handling function 
{
	do
        {
        	WWZ = 1;
	  	exit(0);
        }while(signaL == SIGCONT); // when SIGCONT is called kills zomies and terminates the program
};

int main(int argc, char *argv[]) // main takes in two arguments argc: argument counter, argv: takes in an array of strings for hpw many zombies should be created
{
        int x; // basic integer variables
        int walkingDead = atoi(argv[2]); // the # of zombies to create
        pid_t zombieChild; // the process that will be forked

        if(signal(SIGCONT,handler) == SIG_ERR)
       {
                exit(1);
	  }
        for(x=0; x < walkingDead; x++)
        {
                zombieChild = fork();     // forking the parent process to make zombie processes
                if(zombieChild == 0)
                {
                        exit(0);
                }
        }

        do
        {
                sleep(1); // sleeps process for 60 seconds
        }while(WWZ == 0);

        for(x = 0; x < walkingDead; x++)
        {
                wait(0); 			
        }

return 0;
}
