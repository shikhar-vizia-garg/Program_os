#include<iostream>
#include<fstream>
using namespace std;
int main()
{
int i,n,p,j;
char a[100],temp;
ifstream fp;

fp.open("no.txt");
int count = 0;
     

    while(!fp.eof())
    {
        fp>>a[count];
        count++;
    }
    

n=count-1;
for(p=0;p<n-1;p++)          
{

for(j=0;j<n-p-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];           
a[j]=a[j+1];
a[j+1]=temp;
}
}

}
fp.close();
ofstream fo;
fo.open("no.txt");
i=0;
while(i<n)
{
  fo<<a[i]<<" ";

  i++;

}
fo.close();
cout<<"\nNumbers are sorted\n";

return 0;
}

