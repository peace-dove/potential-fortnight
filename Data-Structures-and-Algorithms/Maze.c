#include <stdio.h>
#include <stdlib.h>

#define maxsize 100

char maze[10][10]=
{
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ','#',' ',' ',' ','#',' ','#'},
    {'#',' ',' ','#',' ',' ',' ','#',' ','#'},
    {'#',' ',' ',' ',' ','#','#',' ',' ','#'},
    {'#',' ','#','#','#',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
    {'#',' ','#',' ',' ',' ','#',' ',' ','#'},
    {'#',' ','#','#','#',' ','#','#',' ','#'},
    {'#','#',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};
typedef struct
{
    int x;
    int y;
} PosType;
typedef struct node
{
    PosType seat;
    int di;
} Elem;
typedef struct stack
{
    Elem a[maxsize];
    int top;
} SqStack;

void initstack(SqStack *s)
{
    (*s).top=0;
}
void push(SqStack *s,Elem e)
{
    if((*s).top==maxsize-1)
    {
        printf("Push Error.");
        return ;
    }
    (*s).a[(*s).top]=e;
    (*s).top++;
}
void pop(SqStack *s,Elem *e)
{
    if((*s).top==0)
    {
        printf("Pop Error.");
        return ;
    }
    *e=(*s).a[--(*s).top];
}
int isempty(SqStack s)
{
    if(s.top==0)
        return 1;
    return 0;
}
int Pass(PosType curpos)
{
    if(maze[curpos.x][curpos.y]==' ')
        return 1;
    return 0;
}
void Footprint(PosType curpos)
{
    maze[curpos.x][curpos.y]='@';//@ means has chosen
}
void Markprint(PosType curpos)
{
    maze[curpos.x][curpos.y]='$';//$ means cant choose
}
PosType Nextpose(PosType curpos,int i)
{
    PosType tmp;
    tmp.x=tmp.y=0;
    switch(i)
    {
    case 1:
    {
        tmp.x=curpos.x;
        tmp.y=curpos.y+1;
        return tmp;
    }
    case 2:
    {
        tmp.x=curpos.x+1;
        tmp.y=curpos.y;
        return tmp;
    }
    case 3:
    {
        tmp.x=curpos.x;
        tmp.y=curpos.y-1;
        return tmp;
    }
    case 4:
    {
        tmp.x=curpos.x-1;
        tmp.y=curpos.y;
        return tmp;
    }
    }
    return tmp;
}
int mazepath(PosType start,PosType end)
{
    SqStack s;
    initstack(&s);
    PosType curpos=start;
    do
    {
        if(Pass(curpos))
        {
            Footprint(curpos);
            Elem e;
            e.seat=curpos;
            e.di=1;
            push(&s,e);
            if((curpos.x==end.x)&&(curpos.y==end.y))
                return 1;
            curpos=Nextpose(curpos,1);
        }
        else
        {
            Elem e;
            pop(&s,&e);
            while(e.di==4&&!isempty(s))
            {
                Markprint(e.seat);
                pop(&s,&e);
            }
            if(e.di<4)
            {
                e.di++;
                push(&s,e);
                curpos=Nextpose(e.seat,e.di);
            }
        }
    }
    while(!isempty(s));
    return 0;
}
void print()
{
    for(int i=0; i<=9; i++)
    {
        for(int j=0; j<=9; j++)
        {
            printf("%c",maze[i][j]);
            if(j!=9)
                printf(" ");

        }
        if(i!=9)
            printf("\n");
    }
}
int main()
{
    PosType start,end;
    start.x=start.y=1;
    end.x=end.y=8;
    mazepath(start,end);
    print();
    return 0;
}
