#include<stdio.h>
#include<stdlib.h>
#define P 5
#define R 3

int need[P][R],avail[R],allo[P][R],finish[P];
int count=0;

int is_safe()
{
    for(int i=0;i<P;i++)
    {
        finish[i]=0;
    }
    int work[R];
    for(int i=0;i<R;i++)
    {
        work[i]=avail[i];
    }
  for(int l=0;l<P;l++)
    {
        for(int i=0;i<P;i++)
        {
        if(finish[i]==0){
            int flag=0;
            for(int j=0;j<R;j++)
            {
                if(work[j]<need[i][j])
                {
                    flag=1;
                    break;
                }
            }
                if(flag==0)
                {
                    finish[i]=1;
                    //count++;
                    for(int k=0;k<R;k++)
                    {
                        work[k]+=allo[i][k];
                    }
                }
            }
        }
    }
    for(int i=0;i<P;i++)
    {
        if(finish[i]==0)
        {
            return -1;
        }
    }
    return 1;
}


int main()
{
    printf("Allocation\n");
    for(int i=0;i<P;i++)
    {
        for(int j=0;j<R;j++)
        {
            scanf("%d",&allo[i][j]);
        }
    }
    printf("Need\n");
    for(int i=0;i<P;i++)
    {
        for(int j=0;j<R;j++)
        {
            scanf("%d",&need[i][j]);
        }
    }
    printf("Available\n");
    for(int i=0;i<R;i++)
    {
        scanf("%d",&avail[i]);
    }
    if(is_safe()==1)
    {
        printf("SAFE\n");
    }
    else
    {
        printf("UNSAFE\n");
    }
}
