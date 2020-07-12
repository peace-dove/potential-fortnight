注：为了便捷，每一题基本上只放上书写的函数，在调试过程中使用到了一些自己写的操作函数，还有自己的宏定义，如下。

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>//bool型使用到的头文件

typedef int ElementType;
typedef struct ListNode *PtrToNode;
struct ListNode
{
    ElementType Data;
    PtrToNode   Next;
};//结构体定义
typedef PtrToNode List;//为简洁使用了List作为ADT

struct ListNode *createlist()//创建链表函数 以-1作为终止符号 可调整为其他
{
    List head=NULL, tail=NULL;
    int t;
    scanf("%d",&t);
    while(t != -1)
    {
        List temp = (List)malloc(sizeof(List));
        temp->Data = t;
        temp->Next = NULL;
        if(tail==NULL)
            head = tail = temp;
        else
        {
            tail->Next = temp;
            tail = temp;
        }
        scanf("%d",&t);
    }
    return head;
}

void printlist( struct ListNode *head )//输出链表
{
    List p = head;
    while (p)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
}
int main()
{
    struct ListNode *head;
    struct ListNode *res;
    //操作函数 根据需求书写补充
    return 0;
}
```



1. ```c
   //使用tail指针指向最后一位 利用tail的指向储存需要逆转的s的指向
   //当s移动到tail时表明整个链表逆序已完成 返回输出尾指针
   struct ListNode *reserveList(struct ListNode * head)
   {
       struct ListNode * tail;
       tail=L;
       while(tail&&tail->Next)
           tail=tail->Next;
       struct ListNode * s,p;
       s=L;
       p=s->Next;
       while(s&&p&&s!=tail)
       {
           s->Next=tail->Next;
           tail->Next=s;
           s=p;
           p=s->Next;
       }
       return tail;
   }
   ```

2. ```c
   //用t标记当下的数字，如果下一个不同，则标记下一个
   //如果相同，则将下一个结点删除，指针向后移动一位
   struct ListNode* deleteDuplicates(struct ListNode* head)
   {
       struct ListNode* L,* q;
       L=head->Next;
       q=head;
       int t;
       t=q->val;
       while(L)
       {
           if(L->val!=t)
           {
               t=L->val;
               q=L;
               L=L->Next;
           }
   
           else
           {
               q->Next=L->Next;
               free(L);
               L=q->Next;
           }
       }
       return head;
   }
   ```

3. ```c
   //整个函数处理
   //输入结尾是 -1
   //先将两组数分别计算出来相加后再放入新的链表
   #include<stdio.h>
   #include<stdlib.h>
   #include <math.h>
   typedef int ElementType;
   typedef struct ListNode *PtrToNode;
   struct ListNode
   {
       ElementType Data;
       PtrToNode   Next;
   };
   typedef PtrToNode List;
   
   struct ListNode *createlist()
   {
       //尾插法
       List head=NULL, tail=NULL;
       int t;
       scanf("%d",&t);
       while(t != -1)
       {
           List temp = (List)malloc(sizeof(List));
           temp->Data = t;
           temp->Next = NULL;
           if(tail==NULL)
               head = tail = temp;
           else
           {
               tail->Next = temp;
               tail = temp;
           }
           scanf("%d",&t);
       }
       return head;
   }
   
   void printlist( struct ListNode *head )
   {
       List p = head;
       while (p)
       {
           printf("%d ", p->Data);
           p = p->Next;
       }
       printf("\n");
   }
   
   struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
   {
       struct ListNode *p=l1;
       int num1=0,m=0;
       while(p)
       {
           num1+=p->Data*pow(10,m);
           m++;
           p=p->Next;
       }
   
       struct ListNode *q=l2;
       int num2=0,n=0;
       while(q)
       {
           num2+=q->Data*pow(10,n);
           n++;
           q=q->Next;
       }
       int num=num1+num2;
       printf("%d %d\n",num1,num2);
   
       List head=NULL, tail=NULL;
       while(num)
       {
           int t=num%10;
           num/=10;
           List temp = (List)malloc(sizeof(List));
           temp->Data = t;
           temp->Next = NULL;
           if(tail==NULL)
               head = tail = temp;
           else
           {
               tail->Next = temp;
               tail = temp;
           }
       }
   
       return head;
   }
   int main()
   {
       struct ListNode *head1;
       struct ListNode *head2;
       struct ListNode *res;
       head1 = createlist();
       head2 = createlist();
       res=addTwoNumbers(head1,head2);
       //head=Reserve(head);
       //head=deleteDuplicates(head);
       printlist(res);
       return 0;
   }
   ```

4. ```c
   //使用两个指针分别作为奇链表和偶链表的尾部 再用一个单独头结点的进行连接
   struct ListNode* oddEvenList(struct ListNode* head)
   {
       if(head==NULL || head->Next==NULL)
           return head;
       struct ListNode *p,*q,*head2;
       p=head;//奇数结点的尾结点
       q=p->Next;//偶数结点的尾结点
       head2=head->Next;//偶数结点的头结点
       int m=3;
       while(p->Next!=NULL && q->Next!=NULL)
       {
           p->Next=q->Next;
           p=p->Next;
           q->Next=p->Next;
           q=q->Next;
       }
       p->Next=head2;//将两个链表连接
       return head;
   }
   ```
   
5. ```c
   //对这个链表遍历
   //单独设立两个链表用于存放小于分解值和大于分解值的数
   struct ListNode* partition(struct ListNode* head, int x)
   {
       struct ListNode* bs=NULL;//之前的开始
       struct ListNode* be=NULL;//之前的结尾
       struct ListNode* as=NULL;//之后的开始
       struct ListNode* ae=NULL;//之后的结尾
       while(head!=NULL)
       {
           struct ListNode* tmp=head->Next;
           head->Next=NULL;
           if(head->Data<x)
           {
               if(bs==NULL)//之前的第一位
               {
                   bs=head;
                   be=bs;
               }
               else
               {
                   be->Next=head;
                   be=be->Next;
               }
           }
           else
           {
               if(as==NULL)//之后的第一位
               {
                   as=head;
                   ae=as;
               }
               else
               {
                   ae->Next=head;
                   ae=ae->Next;
               }
           }
           head=tmp;
       }
       if(bs==NULL)
           return as;
       be->Next=as;
       return bs;
   }
   ```

6. ```c
   //删除链表中连续项之和为0的部分
   struct ListNode *removezero(struct ListNode *head)
   {
       struct ListNode *start;//开辟虚拟头结点并申请空间
       start=(List)malloc(sizeof(List));
       if(start==NULL)//若申请未成功则退出程序
           exit(1);
       start->Next=head;
       struct ListNode * h=start;
       while (h->Next!=NULL)
       {
           struct ListNode *h1=h->Next;
           struct ListNode *h2=h1;
   
           int sum=h1->Data;
   
           while (h2->Next!=NULL||sum==0)
           {
               if(sum==0)//如果和为0 将h1和h2之间的结点删除掉
               {
                   h->Next=h2->Next;
                   break;
               }
               h2=h2->Next;
   
               sum+=h2->Data;
           }//这个h结点遍历完成之后没有发现和为0 h 向后推一位
           if(sum!=0)
           {
               h=h->Next;
           }
    }
       return start->Next;
   }
   ```
   
7. ```c
   //利用归并排序的思路
   //两个链表一一比较 将其中较小的那一个放入一个新的链表 最后还有剩余的接在排序链表后面
   struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
   {
       struct ListNode* head=NULL;
       struct ListNode* tail=NULL;
       struct ListNode* p=l1;
       struct ListNode* q=l2;
   	//为防止内存泄漏 对申请空间进行检查
       while(p&&q)
       {
           if(p->Data<q->Data)
           {
               struct ListNode* temp;
               if(NULL==(temp= (struct ListNode*)malloc(sizeof(struct ListNode*))))
                   exit(1);
               temp->Data =p->Data;
               temp->Next = NULL;
               if(head==NULL)
               {
                   head=temp;
                   tail=head;
               }
               else
               {
                   tail->Next=temp;
                   tail=tail->Next;
               }
               p=p->Next;
           }
           else
           {
               struct ListNode* temp;
               if(NULL==(temp= (struct ListNode*)malloc(sizeof(struct ListNode*))))
                   exit(1);
               temp->Data =q->Data;
               temp->Next = NULL;
               if(head==NULL)
               {
                   head=temp;
                   tail=head;
               }
               else
               {
                   tail->Next=temp;
                   tail=tail->Next;
               }
               q=q->Next;
           }
       }
       if(p==NULL)
           tail->Next=q;
       if(q==NULL)
        tail->Next=p;
       return head;
   }
   ```
   
8. ```c
   //使用了写到的Reserve函数和addtwonumber函数
   //具体操作在主函数中体现
   typedef int ElementType;
   typedef struct ListNode *PtrToNode;
   struct ListNode
   {
       ElementType Data;
       PtrToNode   Next;
   };
   typedef PtrToNode List;
   
   struct ListNode *createlist()
   {
       //尾插法
       List head=NULL, tail=NULL;
       int t;
       scanf("%d",&t);
       while(t != -1)
       {
           List temp = (List)malloc(sizeof(List));
           temp->Data = t;
           temp->Next = NULL;
           if(tail==NULL)
               head = tail = temp;
           else
           {
               tail->Next = temp;
               tail = temp;
           }
           scanf("%d",&t);
       }
       return head;
   }
   
   void printlist( struct ListNode *head )
   {
       List p = head;
       while (p)
       {
           printf("%d ", p->Data);
           p = p->Next;
       }
       printf("\n");
   }
   
   
   struct ListNode *Reserve(struct ListNode * L )
   {
       List tail;
       tail=L;
       while(tail&&tail->Next)
           tail=tail->Next;
       List s,p;
       s=L;
       p=s->Next;
       while(s&&p&&s!=tail)
       {
           s->Next=tail->Next;
           tail->Next=s;
           s=p;
           p=s->Next;
       }
       return tail;
   }
   struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
   {
       struct ListNode *p=l1;
       int num1=0,m=0;
       while(p)
       {
           num1+=p->Data*pow(10,m);
           m++;
           p=p->Next;
       }
   
       struct ListNode *q=l2;
       int num2=0,n=0;
       while(q)
       {
           num2+=q->Data*pow(10,n);
           n++;
           q=q->Next;
       }
       int num=num1+num2;
       printf("%d %d\n",num1,num2);
   
       List head=NULL, tail=NULL;
       while(num)
       {
           int t=num%10;
           num/=10;
           List temp = (List)malloc(sizeof(List));
           temp->Data = t;
           temp->Next = NULL;
           if(tail==NULL)
               head = tail = temp;
           else
           {
               tail->Next = temp;
               tail = temp;
           }
       }
   
       return head;
   }
   
   int main()
   {
       struct ListNode *head1;
       struct ListNode *head2;
       struct ListNode *res;
       head1= createlist();
       head2= createlist();
       head1=Reserve(head1);
       head2=Reserve(head2);
       res=addTwoNumbers(head1,head2);
       res=Reserve(res);
       printlist(res);
       return 0;
   }
   ```

9. ```c
   struct ListNode* deleteDuplicates(struct ListNode* head)
   {
       struct ListNode* start;//虚拟设置一个头结点
       struct ListNode* h,*h1;
       start = (List)malloc(sizeof(List));
       start->Next=head;
   
       h=start;
       h1=head;
   
       int cnt=0;//统计当前数是否是重复的
       while(h1&&h1->Next)
       {
           if(h1->Data==h1->Next->Data)
           {
               cnt++;
               h1->Next=h1->Next->Next;
           }
           else
           {
               if(cnt>0)
               {
                   h->Next=h1->Next;
                   cnt=0;
               }
               else
               {
                   h=h1;
               }
               h1=h1->Next;
           }
       }
       if(cnt==1)
       {
           h->Next=h1->Next;
       }
       return start->Next;
   }
   ```

10. ```c
    //使用两个指针前后对比数据 出现不一致则返回假
    //全部匹配则返回真
    bool isPalindrome(struct ListNode* head)
    {
        if(head==NULL||head->Next==NULL)
            return true;
        struct ListNode *start,*tail;
        start=tail=head;
        while(tail->Next)
            tail=tail->Next;
        while(start->Next&&start!=tail&&start->Next!=tail)
        {
            if(start->Data!=tail->Data)
                return false;
            struct ListNode *p=head;
            while(p->Next!=tail)
                p=p->Next;
            tail=p;
            start=start->Next;
        }
        return true;
    }
    ```