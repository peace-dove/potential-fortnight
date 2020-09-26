#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
struct SNode
{
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize )
{
    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->Data=(ElementType *)malloc(MaxSize*sizeof(ElementType));
    if(!S->Data)
    {
        printf("Malloc Error.");
        exit(-1);
    }
    S->MaxSize=MaxSize;
    S->Top1=-1;
    S->Top2=MaxSize;

    return S;

}
bool Push( Stack S, ElementType X, int Tag )
{
    if(S==NULL)
        return false;
    if(S->Top1+1==S->Top2)
    {
        printf("Stack Full\n");
        return false;
    }
    if(Tag==1)
    {
        S->Top1++;
        S->Data[S->Top1]=X;
    }
    else//tag==2
    {
        S->Top2--;
        S->Data[S->Top2]=X;
    }
    return true;
}
ElementType Pop( Stack S, int Tag )
{
    if(!S)
        return ERROR;
    if(Tag==1)
    {
        if(S->Top1<0)
        {
            printf("Stack %d Empty\n",Tag);
            return ERROR;
        }
        return S->Data[S->Top1--];
    }
    else
    {
        if(S->Top2>S->MaxSize-1)
        {
            printf("Stack %d Empty\n",Tag);
            return ERROR;
        }
        return S->Data[S->Top2++];
    }
    return true;
}
Operation GetOp()
{
    char Push[] = "Push";
    char Pop[] = "Pop";
    char End[] = "End";
    char s[100];
    scanf("%s", s);

    if (strcmp(Push, s) == 0)
        return push;
    if (strcmp(Pop, s) == 0)
        return pop;
    if (strcmp(End, s) == 0)
        return end;
    return end;
}
void PrintStack(Stack S, int Tag)
{
    printf("Pop from Stack %d:", Tag);
    if (Tag == 1)
    {
        while (S->Top1 != -1)
        {
            printf(" %d", S->Data[S->Top1--]);
        }
    }
    else
    {
        while (S->Top2 != S->MaxSize)
        {
            printf(" %d", S->Data[S->Top2++]);
        }
    }
    putchar('\n');
}
/*
Operation GetOp()
{
    char c[5];
    scanf("%s",c);
    if(strcmp(c,"push"))
        return push;
    else if(strcmp(c,"pop"))
        return pop;
    else
        return end;
}
void PrintStack( Stack S, int Tag )
{
    if(Tag==1)
    {
        int t=S->Top1-1;
        while(t>=0)
        {
            printf("%d",S->Data[t]);
            if(!t)
                printf(" ");
            t--;
        }
    }
    else
    {
        int t=S->Top2+1;
        while(t<=S->MaxSize-1)
        {
            printf("%d",S->Data[t]);
            if(t!=S->MaxSize-1)
                printf(" ");
            t++;
        }
    }
}
*/
int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done )
    {
        switch( GetOp() )
        {
        case push:
            scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag))
                printf("Stack %d is Full!\n", Tag);
            break;
        case pop:
            scanf("%d", &Tag);
            X = Pop(S, Tag);
            if ( X==ERROR )
                printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}
