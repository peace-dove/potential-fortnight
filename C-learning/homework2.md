> ppt作业

1. ```c
   #include <stdio.h>
   #include <stdlib.h>
   
   int fib(int n)
   {
       if(n==1||n==2)
           return 1;
       return fib(n-1)+fib(n-2);
   }
   int main()
   {
       int n,res;
       scanf("%d",&n);
       res=fib(n);
       printf("%d",res);
       return 0;
   }
   ```

2. ```c
   //(1)
   #include <stdio.h>
   #include <stdlib.h>
   int a[100][100]= {0};
   int main()
   {
       int m,n,sum=0;
       scanf("%d %d",&m,&n);//已知数组的维数
       for(int i=0; i<m; i++)
           for(int j=0; j<n; j++)
           {
               scanf("%d",&a[i][j]);
               sum+=a[i][j];
           }
       printf("%d",sum);
       return 0;
   }
   //(2)
   //给一个未知大小的二维数组 利用sizeof测得行列再求总和
   #include <stdio.h>
   #include <stdlib.h>
   int a[100][100]= {0};
   int main()
   {
       int sum=0;
       int rowsize[100]={0};
       int m;
       for(m=0;;m++)
       {
           if(!a[m][0])
               break;
           rowsize[m]=sizeof(a[m])/sizeof(int);
       }
       for(int i=0; i<m; i++)
           for(int j=0; j<rowsize[i]; j++)
           {
               sum+=a[i][j];
           }
       //int size=sizeof(a)/sizeof(int);
       //printf("%d\n",size);
       printf("%d",sum);
       return 0;
   }
   ```

3. ```c
   #include <stdio.h>
   #include <stdlib.h>
   char a[100];
   int cnt=0,flag=0;//记录单词数以及判断当前是否处在一个单词中
   int main()
   {
       gets(a);
       char *p;
       p=a;
       while(*p)
       {
           if(*p!=' '&&flag==0)
           {
               cnt++;
               flag=1;
           }
           if(*p==' '&&flag==1)
           {
               flag=0;
           }
           p++;
       }
       printf("%s\n",a);
       printf("%d",cnt);
       return 0;
   }
   ```

4. ```c
   #include <stdio.h>
   #include <stdlib.h>
   #include <math.h>
   char a[100];
   int num(char m)
   {
       if(m=='0')
           return 0;
       if(m=='1')
           return 1;
       if(m=='2')
           return 2;
       if(m=='3')
           return 3;
       if(m=='4')
           return 4;
       if(m=='5')
           return 5;
       if(m=='6')
           return 6;
       if(m=='7')
           return 7;
       if(m=='8')
           return 8;
       if(m=='9')
           return 9;
       if(m=='A')
           return 10;
       if(m=='B')
           return 11;
       if(m=='C')
           return 12;
       if(m=='D')
           return 13;
       if(m=='E')
           return 14;
       if(m=='F')
           return 15;
       return 0;
   
   }
   int tran(char s[])
   {
       int sum=0;
       char *p;
       p=s;
       while(*p)
           p++;
       p--;
       int k=0;
       for(; p>=s; p--)
       {
           sum+=num(*p)*pow(16,k);
           k++;
       }
       return sum;
   }
   int main()
   {
       gets(a);
       int int_10=tran(a);
       printf("%d",int_10);
       return 0;
   }
   ```

5. ```c
   #include <stdio.h>
   #include <stdlib.h>
   char *strcat(char *first,char *next)
   {
       char *temp=first;
       while(*temp!='\0')
           temp++;		//指向first的最后一位
       *temp=*next;
       while(*next!='\0')
           *(temp++)=*(next++);//将next连接在first后面
       return first;
   }
   int main()
   {
       char str1[30] = "I learn ", *str2 = "C language.";
       //char str1[100],str2[100];			//手动输入两串字符串进行连接
       //gets(str1);
       //gets(str2);
       //getchar();
       //scanf("%[^\n],%[^\n]",str1,str2);	//使用格式化输入
       //printf("%s %s",str1,str2);
       char *s;
       s = strcat(str1,str2);
       printf("%s\n",s);
       return 0;
   }
   ```