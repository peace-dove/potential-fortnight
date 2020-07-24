1. ```c
   #include <stdio.h>
   #include <stdlib.h>
   
   #define maxlen 1000
   typedef int Datatype;
   typedef struct
   {
       Datatype data[maxlen];//长度为maxlen的数组
       int front,rear;//元素对应的下标
   } SeqQueue;
   SeqQueue *q;
   
   SeqQueue  *InitQueue (SeqQueue *Q)//初始化一个新队列
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
       q=(SeqQueue *)malloc(sizeof(SeqQueue));//开辟队列空间
       q=InitQueue(q);//初始化队列
   
       int N,num;
       scanf("%d",&N);
       while(N--)//下达N个指令
       {
           int order;//指令的代号
           scanf("%d",&order);
           switch (order)
           {
           case 1://入队
               scanf("%d",&num);
               Add(q,num);
               break;
           case 2://出队并输出
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
           case 3://计算队列中个数并输出
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
   ```
   
2. ```c
   #include <stdio.h>
   #include <stdlib.h>
   
   #define maxlen 1000
   typedef char Datatype;//储存的数据为char类型
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
   
       char ch;
       int cnt=0;
       while((ch=getchar())!='?')
       {
           Add(q,ch);//向队列中压入字符
           cnt++;//计算字符个数
       }
       for(int i=0; i<cnt/2-1; i++)
       {
           //从前后向中间一一对比
           if(q->data[q->front+1+i]!=q->data[q->rear-i])
           {
               //出现一个不匹配则返回
               printf("此字符串不是回文");
               return 0;
           }
       }//全部匹配 则是回文
       printf("此字符串是回文");
       return 0;
   }
   ```
   
3. ```c++
   #include<iostream>
   #include<cstring>
   #include<stdio.h>
   using namespace std;
   int main()
   {
       int m, total;
       while (cin >> m >> total)
       {
           int arrival,check;//到达时间和操作的时间
           int sum = 0;//所有的等待时间
           int q[21]= {0}; //每个窗口操作的时长
           //memset(q,0,sizeof(q));
           for (int i = 0; i <total; i++)
           {
               cin >>arrival>>check;
               int index = 0;
               int mintime = q[0];
               for (int i = 0; i < m; i++)
               {
                   //找到操作时间最少的那个窗口
                   if (q[i] <mintime)
                   {
                       mintime = q[i];
                       index = i;
                   }
               }
               if (arrival< q[index])
               {
                   //到达时间在所有窗口操作结束之前 需要等待
                   sum += (q[index] -arrival);//操作结束时间减去到达时间为等待的时间
                   q[index]+=check;//加上新的操作的时间
               }
               else
                   q[index]=arrival+check;//有空闲窗口 该窗口操作结束的时间为到达时间加上操作时间
           }
           printf("%.2f\n", sum/total/1.0);//平均等待时间 保留两位小数
       }
       return 0;
   }
   ```

4. ```c
   #include <stdio.h>
   #include <stdlib.h>
   
   #define maxlen 1000
   typedef int Datatype;
   typedef struct
   {
       Datatype data[maxlen];//长度为maxlen的数组
       int front,rear;//元素对应的下标
   } SeqQueue;
   SeqQueue *qm,*qn;
   
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
       int m,n,k;
       scanf("%d %d",&m,&n);
       scanf("%d",&k);
   
       qm=(SeqQueue *)malloc(sizeof(SeqQueue));
       qn=(SeqQueue *)malloc(sizeof(SeqQueue));
       qm=InitQueue(qm);
       qn=InitQueue(qn);
   
       for(int a=1;a<=m;a++)
           Add(qm,a);//使用序号一一压入队列
       for(int a=1;a<=n;a++)
           Add(qn,a);
   
       while(k--)
       {//一一匹配后放入队尾 共匹配k项
           printf("%d %d\n",GetHead(qm),GetHead(qn));
           Add(qm,GetHead(qm));
           Add(qn,GetHead(qn));
           Delete(qm);
           Delete(qn);
       }
       return 0;
   }
   ```
   
5. ```c
   #include <stdio.h>
   #include <stdlib.h>
   
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
   int check(int num)
   {//检验数是否是7的倍数和含有数字7
       if(num%7==0)//是7的倍数
           return 1;
       while(num)
       {//用十进制展开后含有数字7
           int tmp=num%10;
           if(tmp==7)
               return 1;
           num/=10;
       }
       return 0;
   }
   int main()
   {
       int m,n,t;
       scanf("%d %d %d",&n,&m,&t);
       char name[20][20];
       for(int i=1; i<=n; i++)
           scanf("%s",name[i]);//用一个数组储存姓名
   
       q=(SeqQueue *)malloc(sizeof(SeqQueue));
       q=InitQueue(q);
   
       for(int i=1; i<=n; i++)
           Add(q,i);//用数字代表人名
       for(int i=1; i<m; i++)
       {//使第m人作为队首 之前的往队尾放
           Datatype tmp=GetHead(q);
           Add(q,tmp);
           Delete(q);
       }
       while(q->rear-q->front!=1)
       {
           if(check(t))//报数t
           {
               Delete(q);
           }
           else
           {
               Datatype tmp=GetHead(q);
               Add(q,tmp);
               Delete(q);
           }
           t++;
       }
       printf("%s",name[GetHead(q)]);//转为姓名输出
       return 0;
   }
   ```
   
   