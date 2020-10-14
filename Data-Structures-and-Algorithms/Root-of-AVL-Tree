//learn from mooc and pta. Thanks.

#include<stdio.h>
#include<stdlib.h>

#define ElementType int
typedef struct AVLNode *Position;
typedef Position AVLTree;

struct AVLNode
{
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

int Max(int a, int b)
{
    return a>b?a:b;
}
int GetHeight(AVLTree A)
{
    if(!A)
        return -1;
    return A->Height;
}
AVLTree SingleLeftRotation ( AVLTree A )
{
    if(A->Left)
    {
        AVLTree B = A->Left;
        A->Left = B->Right;
        B->Right = A;
        A->Height = Max( GetHeight(A->Left), GetHeight(A->Right) ) + 1;
        B->Height = Max( GetHeight(B->Left), A->Height ) + 1;
        return B;
    }
    return NULL;
}
AVLTree SingleRightRotation ( AVLTree A )
{
    if(A->Right)
    {
        AVLTree B=A->Right;
        A->Right=B->Left;
        B->Left=A;
        A->Height=Max(GetHeight(A->Left),GetHeight(A->Right))+1;
        B->Height=Max(A->Height,GetHeight(B->Right))+1;
        return B;
    }
    return NULL;
}
AVLTree DoubleLeftRightRotation ( AVLTree A )
{
    if(A->Left&&A->Left->Right)
    {
        A->Left = SingleRightRotation(A->Left);

        return SingleLeftRotation(A);
    }
    return NULL;
}


AVLTree DoubleRightLeftRotation ( AVLTree A )
{
    if(A->Right&&A->Right->Left)
    {
        A->Right=SingleLeftRotation(A->Right);
        return SingleRightRotation(A);
    }
    return NULL;
}

AVLTree Insert( AVLTree T, ElementType X )
{
    if (!T)
    {
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;

    }
    else if (X<T->Data)
    {
        T->Left = Insert( T->Left, X);
        if ( GetHeight(T->Left)-GetHeight(T->Right) == 2 )
        {
            if ( X < T->Left->Data )
                T = SingleLeftRotation(T);
            else
                T = DoubleLeftRightRotation(T);
        }
    }
    else if ( X > T->Data )
    {
        T->Right = Insert( T->Right, X );
        if ( GetHeight(T->Left)-GetHeight(T->Right) == -2 )
        {
            if ( X > T->Right->Data )
                T = SingleRightRotation(T);
            else
                T = DoubleRightLeftRotation(T);
        }
    }
    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right) ) + 1;

    return T;
}
int main()
{
    AVLTree A=NULL;
    int n,val;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&val);
        A=Insert(A,val);
    }
    printf("%d",A->Data);
    return 0;
}
