//learn from bilibili

#include<stdio.h>
#include<stdlib.h>
typedef struct polynode *polynomial;
typedef struct polynode
{
    int coef;
    int expn;
    struct polynode *next;
} poly;
void attach(int c,int e,polynomial *prear)
{
    polynomial p;
    p=(polynomial)malloc(sizeof(struct polynode));
    p->coef=c,p->expn=e,p->next=NULL;
    (*prear)->next=p;
    *prear=p;
}
polynomial creat()
{
    polynomial p,rear,t;
    p=(polynomial)malloc(sizeof(struct polynode));
    p->next=NULL;
    rear=p;
    int c,e,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&c,&e);
        attach(c,e,&rear);
    }
    t=p;
    p=p->next;
    free(t);
    return p;
}
polynomial add(polynomial pa,polynomial pb)
{
    polynomial t1,t2,rear,t3,p;
    t1=pa;
    t2=pb;

    p=(polynomial)malloc(sizeof(struct polynode));
    p->next=NULL;
    rear=p;

    while(t1&&t2)
    {
        if(t1->expn>t2->expn)
        {
            attach(t1->coef,t1->expn,&rear);
            t1=t1->next;
        }
        else if(t1->expn<t2->expn)
        {
            attach(t2->coef,t2->expn,&rear);
            t2=t2->next;
        }
        else //exp==
        {
            if(t1->coef+t2->coef)
            {
                attach(t1->coef+t2->coef,t1->expn,&rear);
                t1=t1->next;
                t2=t2->next;
            }
        }
    }
    while(t1)
    {
        attach(t1->coef,t1->expn,&rear);
        t1=t1->next;
    }
    while(t2)
    {
        attach(t2->coef,t2->expn,&rear);
        t2=t2->next;
    }
    t3=p;
    p=p->next;
    free(t3);
    return p;
}
void print(polynomial p)
{
    if(!p)
    {
        printf("0 0");
        return ;
    }
    polynomial t;
    t=p;
    while(t)
    {
        printf("%d %d",t->coef,t->expn);
        if(t->next)
            printf(" ");
        t=t->next;
    }
    return ;
}
int main()
{
    polynomial pa,pb,pc;
    pa=creat();
    pb=creat();
    pc=add(pa,pb);
    print(pc);

    return 0;
}
