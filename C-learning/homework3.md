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

4. 