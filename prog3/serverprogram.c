#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
system("ps");
printf("enter num");
char str[2];
scanf("%s",str);
char * n[2];

n[0]=str;
printf("hi");
if(fork()==0)
{
printf("%d",getpid());
printf("blah");
execv("./clientprogram",n);
printf("bye");}



return 0;
}
