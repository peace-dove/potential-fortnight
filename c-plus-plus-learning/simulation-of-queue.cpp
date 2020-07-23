#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE  100

#define maxlen 1000
typedef int Datatype;
typedef struct
{
    Datatype data[maxlen];//长度为maxlen的数组
    int front,rear;//元素对应的下标
} SeqQueue;
SeqQueue *q;

SeqQueue  *InitQueue (SeqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return Q;
}
int   QueueEmpty(SeqQueue *Q)
{
    if(Q->front == Q->rear)
        return 1;
    else
        return 0; //队空时返回1，不空返回0
}
int  QueueFull (SeqQueue *Q)
{
    if(Q->front == (Q->rear + 1)%maxlen)
        return 1;
    else
        return 0; //队满时返回1，不满返回0
}
Datatype GetHead (SeqQueue   *Q)
{
    Datatype     x ;
    if (QueueEmpty(Q) )
        return (-1) ;
    else
    {
        x = Q->data[(Q->front+1)%maxlen];
        return   x ;
    }
}
void Add (SeqQueue *Q,Datatype x)
{
    if(!QueueFull(Q))  //若队不满，则进行入队运算
    {
        Q->rear = (Q->rear + 1)%maxlen;
        Q->data[Q->rear] = x;
    }
    else
        printf("queue full");
}
void  Delete (SeqQueue *Q)
{
    if(!QueueEmpty(Q)) //若队不空，则进行出队运算
        Q->front = (Q->front + 1)%maxlen;

    else
        printf("queue empty");
}

int main()
{
    q=(SeqQueue *)malloc(sizeof(SeqQueue));
    q=InitQueue(q);

    int N,num;
    scanf("%d",&N);
    while(N--)
    {
        int order;
        scanf("%d",&order);
        switch (order)
        {

        case 1:
            scanf("%d",&num);
            Add(q,num);
            break;
        case 2:
            if(QueueEmpty(q))
            {
                printf("no");
                return 0;
            }
            else
            {
                num=GetHead(q);
                Delete(q);
                printf("%d\n",num);
            }
            break;
        case 3:
            if(q->front<=q->rear)
            {
                printf("%d\n",(q->rear)-(q->front));
            }
            else
            {
                printf("%d\n",maxlen-q->front+q->rear);
            }
            break;
        default:
            printf("Error!");
        }
    }
    return 0;
}
