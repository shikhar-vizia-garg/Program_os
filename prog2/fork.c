#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	int i;
	for(i=0;i<4;i++){
		pid=fork();
		if(pid>0){
		printf("Parent id :%d\n",getpid());
		printf("Child id: %d\n",pid);
		continue;
		}
		else if(pid==0){
		break;
		}
		else{
		printf("error");
		}
	}
	return 0;
}
