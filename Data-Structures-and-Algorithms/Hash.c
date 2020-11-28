#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define maxnum 11
typedef char elemtype[maxnum + 1];
typedef int index;

typedef struct lnode
{
    elemtype data;
    struct lnode *next;
    int cnt;
} * ptrtonode;
typedef ptrtonode position;
typedef ptrtonode list;

typedef struct tblnode *Hashtable;
struct tblnode
{
    int tablesize;
    list heads;
};

int nextprime(int num)
{
    int i, p;
    if (num % 2 == 0) //num is even
        p = num + 1;
    else //num is odd
        p = num + 2;
    while (p < 1000000)
    {
        for (i = (int)sqrt(p); i > 2; i--)
            if (p % i == 0)
                break;
        if (i == 2)
            break;
        p = p + 2;
    }
    return p;
}
Hashtable creat(int tablesize)
{
    Hashtable H;
    H = (Hashtable)malloc(sizeof(struct tblnode));
    H->tablesize = nextprime(tablesize);
    H->heads = (list)malloc(H->tablesize * sizeof(struct lnode));
    for (int i = 0; i < H->tablesize; i++)
    {
        H->heads[i].data[0] = '\0';
        H->heads[i].next = NULL;
        H->heads[i].cnt = 0;
    }
    return H;
}
int hash(int key, int p)
{
    return key % p;
}
position find(Hashtable H, elemtype key)
{
    position p = NULL;
    int pos;
    pos = hash(atoi(key + 7), H->tablesize);
    p = H->heads[pos].next;
    while (p != NULL && strcmp(p->data, key) != 0)
        p = p->next;

    return p;
}
void insert(Hashtable H, elemtype key)
{
    position p = NULL, new;
    int pos;
    p = find(H, key);
    if (!p) //p==NULL
    {
        pos = hash(atoi(key + 7), H->tablesize);
        new = (list)malloc(sizeof(struct lnode));
        strcpy(new->data, key);
        new->cnt = 1;
        new->next = H->heads[pos].next;
        H->heads[pos].next = new;
    }
    else
    {
        p->cnt++;
    }
    return;
}
void scanandoutput(Hashtable H)
{
    int i, peoplecnt = 0;
    int maxcnt = 0;
    elemtype minphone;
    position ptr = NULL;
    minphone[0] = '\0';
    for (i = 0; i < H->tablesize; i++)
    {
        ptr = H->heads[i].next;
        while (ptr)
        {
            if (ptr->cnt > maxcnt)
            {
                maxcnt = ptr->cnt;
                strcpy(minphone, ptr->data);
                peoplecnt = 1;
            }
            else if (ptr->cnt == maxcnt)
            {
                peoplecnt++;
                if (strcmp(minphone, ptr->data) > 0)
                    strcpy(minphone, ptr->data);
            }
            ptr = ptr->next;
        }
    }
    if (peoplecnt == 1)
    {
        printf("%s %d", minphone, maxcnt);
    }
    else
    {
        printf("%s %d %d", minphone, maxcnt, peoplecnt);
    }
    return;
}
int main()
{
    Hashtable H;
    int n;
    scanf("%d", &n);
    H = creat(2 * n);
    for (int i = 0; i < n; i++)
    {
        elemtype key;
        scanf("%s", key);
        insert(H, key);
        scanf("%s", key);
        insert(H, key);
    }
    scanandoutput(H);
    //destroytable();
    system("pause");
    return 0;
}
