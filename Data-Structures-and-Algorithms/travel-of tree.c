//needed polished

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 31
typedef struct TNode *tree;
struct TNode
{
    int Data;
    tree Left;
    tree Right;
};

tree preBinTree(int s1[], int s2[], int k)
{
    int i, t;
    if(k == 0)
        return NULL;
    tree BT = (tree)malloc(sizeof(struct TNode));
    t = s1[k-1];
    BT->Data = t;
    for(i = 0; i < k; i ++)
        if(s2[i] == t)
            break;
    BT->Left = preBinTree(s1, s2, i);
    BT->Right = preBinTree(s1+i, s2+i+1, k-i-1);

    return BT;
}
tree posBinTree(int s1[], int s2[], int k)
{
    int i, t;
    if(k == 0)
        return NULL;
    tree BT = (tree)malloc(sizeof(struct TNode));
    t = *s1;
    BT->Data = t;
    for(i = 0; i < k; i ++)
        if(s2[i] == t)
            break;
    BT->Left = posBinTree(s1+1, s2, i);
    BT->Right = posBinTree(s1+i+1, s2+i+1, k-i-1);

    return BT;
}
void putBinTree(tree BT)
{
    tree s[MAXSIZE];
    int t = 0, k = 1;
    s[t] = BT;
    while(t != k)
    {
        if(!t)
        {
            printf("%d", s[t]->Data);
        }
        else
        {
            printf(" %d", s[t]->Data);
        }
        if(s[t]->Left)
        {
            s[k] = s[t]->Left;
            k = (k+1) % MAXSIZE;
        }
        if(s[t]->Right)
        {
            s[k] = s[t]->Right;
            k = (k+1) % MAXSIZE;
        }
        t = (t+1) % MAXSIZE;
    }
}

int main()
{
    int i, n;
    int s1[MAXSIZE], s2[MAXSIZE];
    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d", &s1[i]);
    for(i = 0; i < n; i ++)
        scanf("%d", &s2[i]);
    tree BT = posBinTree(s1, s2, n);
    putBinTree(BT);

    return 0;
}
