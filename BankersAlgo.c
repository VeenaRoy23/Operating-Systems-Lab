#include<stdio.h>
#define MAX_P 5
#define MAX_R 3

int need[MAX_P][MAX_R];
int avail[MAX_R];
int allo[MAX_P][MAX_R];
int need_sum[MAX_R];
int work[MAX_R];
int finish[MAX_P];

int is_safe(){
	int i,j,k,flag=1;
	for(i=0;i<MAX_P;i++)
	{
		if(finish[i]==0)
		{
			for(k=0;k<MAX_R;k++)
			{
				if(need[i][k]>avail[k])
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				work[k]+=allo[i][k];
				finish[i]=1;
			}
		}
	}
	for(i=0;i<MAX_P;i++)
	{
		if(finish[i]==0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	//int n1,n2;
	//printf("Enter the no. of process: ");
	//scanf("%d",&n1);
	//printf("Enter the no. of resources: ");
	//scanf("%d",&n2);
	//MAX_R=n2;
	//MAX_P=n1;
	printf("Enter the allocation matrix :\n");
	for(int i=0;i<MAX_P;i++)
	{
		for(int j=0;j<MAX_R;j++)
		{
			scanf("%d",&allo[i][j]);
		}
	}
	printf("Enter the need matrix :\n");
	for(int i=0;i<MAX_P;i++)
	{
		for(int j=0;j<MAX_R;j++)
		{
			scanf("%d",&need[i][j]);
		}
	}
	printf("Enter the available matrix :\n");
	for(int i=0;i<MAX_R;i++)
	{
		scanf("%d",&avail[i]);
	}
	
	
	for(int i=0;i<MAX_P;i++)
	{
		for(int j=0;j<MAX_R;j++)
		{
	/*		need_sum[j]+=need[i][j];
		}
	
		for(int i=0;i<MAX_R;i++)
		{
		*/	if(allo[i][j]<need[i][j])
			{
				printf("The system is unsafe\n");
				return 0;
			}
		}
	}	
	
	for(int i=0;i<MAX_P;i++)
	{
		finish[i]=0;
	}
	
	for(int i=0;i<MAX_R;i++)
	{
		work[i]=avail[i];
	}
	if(is_safe()==1)
	{
		printf("System in safe state\n");
	}
	else{
		printf("The system is in  unsafe state\n");
	}
}

