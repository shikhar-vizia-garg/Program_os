#include<iostream>
#include<fstream>
using namespace std;

int main (){
	ifstream fin;
	fin.open("num.txt");
	int arr[100];
	int i=0;
	while(!fin.eof())
	{
		fin>>arr[i];
		i++;
	}
	i--;

	for(int j=0;j<i-1;j++){
		for(int k=0;k<i-j-1;k++)
		{
		    if (arr[k] > arr[k+1])
              {
                  int temp=arr[k];
                  arr[k]=arr[k+1];
                  arr[k+1]=temp;
              }
		}
	}
	fin.close();
	ofstream fout;
	fout.open("num.txt");
	for(int j=0;j<i;j++)
    {cout<<arr[j]<<" ";
		fout<<arr[j]<<" ";}
		fout.close();
	return 0;
}
