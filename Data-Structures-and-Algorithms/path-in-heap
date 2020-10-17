#include<stdio.h>
#include<stdlib.h>
#define maxsize 1001
int heap[maxsize+1];
int t=1;
int keep[maxsize+1];
int kt=0;

void insert(int val)
{
    if(t==maxsize+1)
        return ;
    if(t==1)
        heap[t]=val;
    else
    {
        int i;
        for(i=t; heap[i/2]>val;i=i/2)
            heap[i]=heap[i/2];
        heap[i]=val;
    }
    t++;
    return ;
}

void keepandprint(int val)
{
    for(int i=val; i>0; i=i/2)
    {
        keep[kt++]=heap[i];
    }
    for(int i=0; i<kt; i++)
    {
        printf("%d",keep[i]);
        if(i!=kt-1)
            printf(" ");
    }
    printf("\n");
    for(int i=0; i<kt; i++)
        keep[i]=0;
    kt=0;
}
int main()
{
    heap[0]=-10001;
    for(int i=1; i<maxsize; i++)
        heap[i]=0;

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        insert(tmp);
    }
    for(int i=0; i<m; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        keepandprint(tmp);
    }
    return 0;
}
