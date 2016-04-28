#include<stdio.h>
#define N 100
#define M 100
int max[M][N];
int allocated[M][N];
int need[M][N];
int available[N];
int work[N];
int finish[M];//boolean 0 or 1 
int safestate[M];
int request[N];
int flag=0;

//m=no of processes
//n=no of resources
void init(int m){
	int i=0;
	for(i=0;i<m;i++){
		finish[i]=0;safestate[i]=0;
	}
	
}
void resourcerequest(int pno,int m,int n){
	int i,j;
	for(i=0;i<n;i++){
		if(request[i]>need[pno][i]){
			flag=1;
			break;		
		}	
	}
	for(i=0;i<n;i++){
		if(request[i]>available[i]){
			flag=1;
			break;		
		}	
	}
	if(flag==1){
		printf("It can not be granted\n");
		return;	
	}	
	for(i=0;i<n;i++){
		allocated[pno][i]+=request[i];
		available[i]-=request[i];
		need[pno][i]-=request[i];	
	}
	init(m);
	if(safestatealgo(m,n)==1){
                printf("The safe state is as follows:\n");
		for(j=0;j<m;j++){
			printf("%d ",safestate[j]);		
		}
		printf("Request has been granted\n");		
	}
	else{
		printf("Request has not been granted because not in safe state\n");
	}
}

void fillneed(int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			need[i][j]=max[i][j]-allocated[i][j];		
		}	
	}
}

int safestatealgo(int m,int n){
	int i,j,k,t;
	k=0;
	for(i=0;i<n;i++){
		work[i]=available[i];	
	}

	for(t=0;t<m;t++){
		for(j=0;j<m;j++){
			flag=0;
			if(finish[j]==1){
				//printf("t:%d\n",t);
				continue;			
			}
			for(i=0;i<n;i++){
				if(need[j][i]>work[i]){
					flag=1;
					break;
				}		
			}
			if(flag==0){
				finish[j]=1;
				//printf("j:%d\n",j);				
				safestate[k]=j;
				k++;
				for(i=0;i<n;i++){
					work[i]+=allocated[j][i];		
				}
			}
		}	
	}
	
	for(i=0;i<n;i++){
		if(finish[i]==0)
			return 0;			
	}
	return 1;		
}

int main(){
	int m,n,i,j,procno;
	printf("Enter the no of processes and no of resources");
	scanf("%d %d",&m,&n);
	printf("Enter the max array\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&max[i][j]);		
		}	
	}
	printf("Enter the allocated array\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&allocated[i][j]);		
		}	
	}
	printf("Enter the available array\n");
	for(j=0;j<n;j++){
		scanf("%d",&available[j]);		
	}
	fillneed(m,n);
	if(safestatealgo(m,n)==1){
		printf("The safe state is as follows:\n");
		for(j=0;j<m;j++){
			printf("%d ",safestate[j]);		
		}
		printf("\nEnter the process no:");
		scanf("%d",&procno);
		printf("\nEnter the request array...\n");
		for(j=0;j<n;j++){
			scanf("%d",&request[j]);		
		}		
		resourcerequest(procno,m,n);
	}
	else{
		printf("Not in safe state\n");
	}
						
	return 0;
}
