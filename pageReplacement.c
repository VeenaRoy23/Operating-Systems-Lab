#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define F_SIZE 3
int pages[100];

typedef struct {
	int pageno;
	int freq;
}page;

int findIndex(int arr[],int n,int target)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==target)
		{
			return i;
		}
	}
	return -1;
}

int findIdx(page arr[],int n,int target)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i].pageno==target)
		{
			return i;
		}
	}
	return -1;
}

void FIFO(int n)
{
	int memory[F_SIZE]={-1,-1,-1};
	int pgflt=0;
	int current=0;
	for(int i=0;i<n;i++)
	{
		int page=pages[i];
		if(findIndex(memory,F_SIZE,page)==-1)
		{
			pgflt++;
			memory[current]=page;
			current=(current+1)%F_SIZE;
		}
	}
	printf("Page Faults in FIFO : %d\n",pgflt);
}

void lfu(int n)
{
	page memory[F_SIZE];
	int pgflt=0;
	for(int i=0;i<F_SIZE;i++)
	{
		memory[i].pageno=-1;
		memory[i].freq=0;
	}
	for(int i=0;i<n;i++)
	{
		int page=pages[i];
		int index=findIdx(memory,F_SIZE,page);
		if(index==-1)
		{
			pgflt++;
			int minIdx=0;
			for(int j=1;j<F_SIZE;j++){
				if(memory[j].freq<memory[minIdx].freq)
				{
					minIdx=j;
				}
			}
			memory[minIdx].pageno=page;
			memory[minIdx].freq=1;
		}
		else{
			memory[index].freq++;
		}
	}
	printf("Page Faults in LFU : %d\n",pgflt);
}

void lru(int n)
{
	int memory[F_SIZE]={-1,-1,-1};
	int pgflt=0;
	int lru=0;
	for(int i=0;i<n;i++)
	{
		int page=pages[i];
		int index=findIndex(memory,F_SIZE,page);
		if(index==-1)
		{
			pgflt++;
			memory[lru]=page;
			lru=(lru+1)%F_SIZE;
		}
		else
			lru=(index+1)%F_SIZE;
	}
	printf("PageFaults in LRU : %d\n",pgflt);
}

int main()
{
	int n;
	printf("Enter the no. of pages :");
	scanf("%d",&n);
	printf("Enter the pages\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pages[i]);
	}
	FIFO(n);
	lru(n);
	lfu(n);
}

	


