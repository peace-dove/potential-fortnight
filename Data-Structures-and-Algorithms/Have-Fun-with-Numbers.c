/*tips and mentions
1.the max size of number is 20
2.the format of output like No with the doubled number in the following line
3.the skil of use carry
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[21];
int b[21];
int count[21];
int main()
{
    int flag=1;//to judge whether the permutation matches
    scanf("%s",a);

    int len=strlen(a);
    for(int i=0; i<len; i++)
    {
        b[i]=0;
        count[i]=0;
    }
    int tmp=0;
    int carry=0;
    for(int i=len-1; i>=0; i--)
    {
        tmp=2*(a[i]-'0');
        carry=0;
        if(tmp>=10)
        {
            tmp=tmp-10;
            carry=1;
        }
        b[i]+=tmp;

        if(i>=1)
            b[i-1]+=carry;

    }

    //for(int i=0;i<len;i++)
    //    printf("%d",b[i]);

    for(int i=0; i<len; i++)
    {
        count[a[i]-'0']++;
        count[b[i]]--;
    }

    for(int i=0; i<len; i++)
    {
        if(count[i]!=0)
            flag=0;
    }

    if(flag==0||carry==1)
    {
        printf("No\n");
        if(carry==1)
            printf("1");
        for(int i=0; i<len; i++)
            printf("%d",b[i]);
        printf("\n");
    }
    else
    {
        printf("Yes\n");
        for(int i=0; i<len; i++)
            printf("%d",b[i]);
        printf("\n");
    }
    return 0;
}
