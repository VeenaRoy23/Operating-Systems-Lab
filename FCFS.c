#include<stdio.h>

struct process{
	int id;
	int at;
	int bt;
	int ct;
	int wt;
	int tat;
}array[10];

void read(int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Enter process id,arrival time and burst time\n");
		scanf("%d%d%d",&array[i].id,&array[i].at,&array[i].bt);
	}
}

void sort(int n)
{
	struct process p;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(array[j].at>array[j+1].at)
			{
				p=array[j];
				array[j]=array[j+1];
				array[j+1]=p;
			}
		}
	}
}

void FCFS(int n)
{
	float total_wt=0,total_tat=0;
	array[0].wt=0;
	array[0].ct=array[0].at+array[0].bt;
	array[0].tat=array[0].bt+array[0].wt;
	float total_bt=array[0].bt;
	total_wt+=array[0].wt;
	total_tat+=array[0].tat;
	for(int i=1;i<n;i++)
	{
		array[i].wt=total_bt-array[i].at;
		array[i].ct=array[i].wt+array[i].bt+array[i].at;
		array[i].tat=array[i].wt+array[i].bt;
		total_wt+=array[i].wt;
		total_tat+=array[i].tat;
		total_bt+=array[i].bt;
		
	}
	
	float avg_tat=total_tat/n;
	float avg_wt=total_wt/n;
	printf("Average WT : %f\n",avg_wt);
	printf("Average TAT : %f\n",avg_tat);
}

int main()
{
	int n;
	printf("Enter the number of processes: \n");
	scanf("%d",&n);
	read(n);
	sort(n);
	FCFS(n);
	printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",array[i].id,array[i].at,array[i].bt,array[i].ct,array[i].tat,array[i].wt);
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
