#include<stdio.h>
#include<stdlib.h>
#define null -1
#define maxsize 12
typedef struct treenode
{
    int left;
    int right;
} tree;
tree t[maxsize];
struct que
{
    int data[maxsize];
    int head,rear;
} queue;
int check[maxsize];
int creat()
{

    int n;
    char cl,cr;
    scanf("%d",&n);
    if(n)
    {
        for(int i=0; i<n; i++)
            check[i]=0;
        for(int i=0; i<n; i++)
        {
            scanf("\n%c %c",&cl,&cr);
            if(cl!='-')
            {
                t[i].left=cl-'0';
                check[t[i].left]=1;
            }
            else
                t[i].left=null;
            if(cr!='-')
            {
                t[i].right=cr-'0';
                check[t[i].right]=1;
            }
            else
                t[i].right=null;
        }
    }
    for(int i=0; i<n; i++)
        if(!check[i])
            return i;
    return null;
}
void addq(int r)
{
    queue.data[queue.rear++]=r;
}
int delq()
{
    return queue.data[queue.head++];
}
int isempty()
{
    if(queue.head==queue.rear)
        return 1;
    else
        return 0;
}
int keep[maxsize];
int m=0;
void findleaves(int r)
{
    int tmp;
    addq(r);
    while(!isempty())
    {
        tmp=delq();
        if(t[tmp].left!=null)
            addq(t[tmp].left);
        if(t[tmp].right!=null)
            addq(t[tmp].right);
        if((t[tmp].left==null)&&(t[tmp].right==null))
            keep[m++]=tmp;
    }
}
int main()
{
    int r;
    r=creat();
    findleaves(r);
    for(int i=0; i<m; i++)
    {
        printf("%d",keep[i]);
        if(i!=m-1)
            printf(" ");
    }
    return 0;
}
