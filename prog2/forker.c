#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int main()
{
	fflush(stdout);
	printf("parent: %d My ID: %d     \n",getppid(),getpid());
	fflush(stdout);
	fork();
	wait();
	fork();
	wait();
	printf("parent: %d My ID: %d     \n",getppid(),getpid());
	fflush(stdout);
	return 0;
}
