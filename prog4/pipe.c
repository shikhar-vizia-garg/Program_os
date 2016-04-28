#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int main()
{

int p1[2], p2[2];
pid_t id;
char arr1[] = "Hello I want to Exit\n";
char arr2[100];
char arr3[] = "You may Exit\n";
char arr4[100];
char arr5[] = "Here I Exit\n";
char arr6[100];
pipe(p1);
pipe(p2);

id = fork();

if(id > 0)
{
close(p1[1]);
read(p1[0], arr2 , sizeof(arr2));
printf("Recieved at parent: %s\n",arr2);
close(p2[0]);
write(p2[1], arr3 ,(strlen(arr3)+1));
close(p1[1]);
read(p1[0], arr6 , sizeof(arr6));
printf("Recieved at parent: %s\n",arr6);
}

if(id == 0)
{
close(p1[0]);
write(p1[1], arr1 ,(strlen(arr1)+1));
close(p2[1]);
read(p2[0], arr4 , sizeof(arr4));
printf("Recieved at child: %s\n",arr4);
close(p1[0]);
write(p1[1], arr5 ,(strlen(arr5)+1));

}


return 0;
}
