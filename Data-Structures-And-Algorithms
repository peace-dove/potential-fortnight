#include<stdio.h>
int a[100002];
int max(int a,int b)
{
    return (a>b)?a:b;
}
int solve(int a[],int left,int right)
{
    if(left==right)
        return a[left];
    int mid=(left+right)/2;
    int lsum=solve(a,left,mid);
    int rsum=solve(a,mid+1,right);

    int sum=0;
    int leftmax=0,rightmax=0;
    for(int i=mid;i>=left;i--)
    {
        sum+=a[i];
        if(sum>leftmax)
            leftmax=sum;
    }
    sum=0;
    for(int i=mid+1;i<right;i++)
    {
        sum+=a[i];
        if(sum>rightmax)
            rightmax=sum;
    }
    return max(max(lsum,rsum),leftmax+rightmax);
}
int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0; i<k; i++)
        scanf("%d",&a[i]);

int maxsum=solve(a,0,k);
    printf("%d",maxsum);
    return 0;
}
