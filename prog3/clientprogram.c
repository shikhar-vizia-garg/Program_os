#include<stdio.h>
#include<unistd.h>
int main(int argc, char **argv)
{
printf("%d",getpid());
        printf("hello");
        int i;
        int a=argv[0][0]-48;
        for(i=0;i<a;i++)
        {
        printf("%d ",i);
        }
        return 0;
}
