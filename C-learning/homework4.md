1. ```c
   #define SIZE  100
   typedef int ElemType;
   //元素为一个数的栈
   typedef struct
   {
       int top;//栈顶 元素个数
       ElemType *base;//栈底
       int stacksize;//栈的大小
   } sqstack;
   //元素为栈的栈结构
   typedef struct
   {
       int top;
       sqstack *base;//重点 栈中间的元素栈
       int stacksize;
   } SetOfStacks;
   
   int initstack(sqstack S)
   {
       S.base=(ElemType *)malloc(SIZE*sizeof(ElemType));
       if(!S.base)
           return -1;  /* 初始化失败*/
       S.top=0;          /*空栈标志*/
       S.stacksize = SIZE;
       return 0;  /* 初始化成功 */
   
   }
   
   //将x入栈
   int  push( sqstack *S, ElemType x )
   {
       if (S->top == S->stacksize)
       {
           S->base=(ElemType *)realloc(S->base,(S->stacksize+1)*sizeof(ElemType));
           if(!S->base)
               return -1;
           S->stacksize++;
       }
       S->base[S->top++] = x;
       return 0 ;
   }
   //将一个栈单元放入大的结构栈中
   int  pushs( SetOfStacks *st, sqstack *S )
   {
       if (st->top == st->stacksize)
       {
           st->base=(sqstack *)realloc(st->base,(st->stacksize+1)*sizeof(sqstack));
           if(!st->base)
               return -1;
           st->stacksize++;
       }
       st->base[st->top++] = *S;
       return 0 ;
   }
   //弹出栈顶的元素
   int pop(sqstack *S, ElemType *e)
   {
       if (S->top==0)
       {
           printf("Stack is empty");
           return -1;
       }
       *e=S->base [-- S->top ] ;
       return 0;
   }
   //弹出栈结构栈顶的栈
   int pops(SetOfStacks *st,sqstack *S)
   {
       if (st->top==0)
       {
           printf("SetOfStack is empty");
           return -1;
       }
       *S=st->base[--st->top ] ;
       return 0;
   }
   //判断一个栈是否为空
   int stackempty(sqstack S)
   {
       if (S.top==0)
           return  1 ;  /* true */
       else
           return  0 ;  /* false */
   }
   
   //返回值是一个栈结构的函数 传入参数为操作列表和栈的大小
   SetOfStacks sot(int ope[][2], int size)
   {
       sqstack st;//当前最顶层游离的一个栈
       SetOfStacks A;//总的栈结构
   
       for(int i = 0; ope[i][0]==0||ope[i][0]==1; i ++)
       {
           //push
           if(ope[i][0] == 1)
           {
               //A为空
               if(A.stacksize == 0)
               {
                   //判断st是否已满
                   if(st.stacksize== size)
                   {
                       pushs(&A,&st);//将st放入A中
                       initstack(st);//初始化一个新的st
                       push(&st,ope[i][1]);//新元素放入st
                   }
                   else//st没有满 直接放入
                       push(&st,ope[i][1]);
               }
               else//A不为空
               {
                   if(A.base[A.stacksize - 1].stacksize < size)//A栈顶那个栈没有满
                       push(&A.base[A.stacksize - 1],ope[i][1]);
                   else//A栈顶那个栈满了
                   {
                       if(st.stacksize == size)//游离的st也满了
                       {
                           pushs(&A,&st);//将st放入A中
                           initstack(st);//初始化一个新的st
                           push(&st,ope[i][1]);//新元素放入st
                       }
                       else//游离的st没有满
                           push(&st,ope[i][1]);
                   }
               }
           }
           else//pop
           {
               int tmp;
               sqstack tmps;
   
               if(stackempty(st))//st为空
               {
                   //弹出A顶栈的栈的元素
                   pop(&A.base[A.stacksize-1],&tmp);
                   //当弹出之后可能为空 所以要判断顶栈是否为空
                   if(stackempty(A.base[A.stacksize-1]))  //为空则弹出顶栈
                       pops(&A,&tmps);
               }
               else//st不为空
                   pop(&st,&tmp);//元素弹出
           }
       }
       if(!stackempty(st))//处理最后st不空
           pushs(&A,&st);//st再放入A
       return A;
   }
   ```

2. ```c
   //使用栈的一些函数实现了队列的push和pop操作
   typedef int ElemType;
   typedef struct
   {
       int top;//栈顶 元素个数
       ElemType *base;//栈底
       int stacksize;//栈的大小
   } sqstack;
   //使用两个栈维护一个队列 内容存储在栈中
   typedef struct
   {
       sqstack s1;
       sqstack s2;
   } queen;
   
   int initstack(sqstack S)
   {
       S.base=(ElemType *)malloc(SIZE*sizeof(ElemType));
       if(!S.base)
           return -1;  /* 初始化失败*/
       S.top=0;          /*空栈标志*/
       S.stacksize = SIZE;
       return 0;  /* 初始化成功 */
   
   }
   
   //将x入栈
   int  push( sqstack *S, ElemType x )
   {
       if (S->top == S->stacksize)
       {
           S->base=(ElemType *)realloc(S->base,(S->stacksize+1)*sizeof(ElemType));
           if(!S->base)
               return -1;
           S->stacksize++;
       }
       S->base[S->top++] = x;
       return 0 ;
   }
   //将x入队列 也即放入s1栈中
   void qpush(queen q,ElemType x)
   {
       push(&q.s1,x);
   }
   //弹出栈顶的元素
   int pop(sqstack *S, ElemType *e)
   {
       if (S->top==0)
       {
           printf("Stack is empty");
           return -1;
       }
       *e=S->base [-- S->top ] ;
       return 0;
   }
   //弹出队列中元素
   //将s1中的元素全部放入s2中 从s2中pop则是队列的先进先出顺序
   //可以pop后再放回s1
   //可以检验下s2中是否还有元素 有就直接pop s2 没有元素再将现在s1中所有元素放入s2
   int qpop(queen q,ElemType *e)
   {
       if(q.s1.stacksize==0||q.s2.stacksize==0)
       {
           printf("The queen is empty!");
           return -1;
       }
       if(q.s2.stacksize!=0)
           pop(&q.s2,e);
       else
       {
           while(q.s1.top!=0)
           {
               pop(&q.s1,e);
               push(&q.s2,*e);
           }
           pop(&q.s2,e);
       }
       return 0;
   }
   ```

3. ```c
   #include <stdio.h>
   #include <stdlib.h>
   #include <time.h>
   #define SIZE  100
   typedef int ElemType;
   typedef struct
   {
       int top;//栈顶 元素个数
       ElemType *base;//栈底
       int stacksize;//栈的大小
   } sqstack;
   
   
   int initstack(sqstack S)
   {
       S.base=(ElemType *)malloc(SIZE*sizeof(ElemType));
       if(!S.base)
           return -1;  /* 初始化失败*/
       S.top=0;          /*空栈标志*/
       S.stacksize = SIZE;
       return 0;  /* 初始化成功 */
   
   }
   int gettop(sqstack S,ElemType *e)
   {
       if(S.top==0)
       {
           printf("empyt\n");
           return -1;
       }
       *e=S.base[S.top-1];
       return 0;
   }
   //将x入栈
   int  push( sqstack *S, ElemType x )
   {
       if (S->top == S->stacksize)
       {
           S->base=(ElemType *)realloc(S->base,(S->stacksize+1)*sizeof(ElemType));
           if(!S->base)
               return -1;
           S->stacksize++;
       }
       S->base[S->top++] = x;
       return 0 ;
   }
   
   //弹出栈顶的元素
   int pop(sqstack *S, ElemType *e)
   {
       if (S->top==0)
       {
           printf("Stack is empty");
           return -1;
       }
       *e=S->base [-- S->top ] ;
       return 0;
   }
   
   int stackempty(sqstack S)
   {
       if (S.top==0)
           return  1 ;  /* true */
       else
           return  0 ;  /* false */
   }
   
   int main()
   {
       char input[10],ch;
       int m=0;
       while((ch=getchar())!='\n')
       {
           if(ch!=' ')
               input[m++]=ch;
       }
   
       sqstack s;
       initstack(s);
   
       for(int i=0; i<m; i++)
       {
           if(input[i]>='0'&&input[i]<='9')
           {
               push(&s,input[i]-'0');
           }
           else if(input[i]=='+')
           {
               if(s.top<2)
                   return -1;
               int sum=0;
               sum=s.base[s.top-1]+s.base[s.top-2];
               push(&s,sum);
           }
           else if(input[i]=='D')
           {
               int sum=0;
               sum=2*s.base[s.top-1];
               push(&s,sum);
           }
           else
           {
               int t;
               pop(&s,&t);
           }
       }
       int sum=0;
       while(s.top!=0)
       {
           int tmp;
           gettop(s,&tmp);
           sum+=tmp;
           pop(&s,&tmp);
           s.top--;
       }
       printf("The score is %d.\n",sum);
       return 0;
   }
   ```

4. 