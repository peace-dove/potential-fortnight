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

> word作业

1. ```c
   #include <stdio.h>
   #include <stdlib.h>
   
   int main()
   {
       char a[100];
       gets(a);
       char *p=a;
       while(*p)
       {
           printf("%c",*p);
           p++;
       }
       printf("\n");
       return 0;
   }
   ```

2. ```c
   #include <stdio.h>
   #include <stdlib.h>
   char a[50]="I am student";
   int main()
   {
       char b[50];
       gets(b);
       char *p,*q;
       p=a,q=b;
       while(*q)
       {
           *(p++)=*(q++);
       }
       *p='\0';
       char *t=a;
       while(*t)
       {
           printf("%c",*t);
           t++;
       }
       printf("\n");
       //puts(a);
       //puts(b);
       return 0;
   }
   ```

3. ```c
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
       char str1[30] = "I love ", *str2 = "China!";
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

4. ```c
   #include <stdio.h>
   #include <stdlib.h>
   char a[50];
   int main()
   {
       gets(a);
       char *p=a;
       while(*p)
       {
           p++;
       }
       p--;
       for(; p>=a; p--)
           printf("%c",*p);
       printf("\n");
       return 0;
   }
   ```

5. ```c
   #include <stdio.h>
   #include <stdlib.h>
   char a[50];
   int num[50]= {0};
   int cnt=0,m=0;
   int main()
   {
       gets(a);
       char *p=a;
       while(*p)
       {
           if(*p>='0'&&*p<='9')
           {
               cnt++;
               num[m++]=*p-48;
           }
           p++;
       }
       printf("%d numbers\n",cnt);
       for(int i=0; i<m; i++)
           printf("%d",num[i]);
       return 0;
   }
   ```

6. ```c
   #include <stdio.h>
   #include <stdlib.h>
   char a[50];
   char res[50];
   int m=0,cnt=0;
   int main()
   {
       gets(a);
       char *p=a;
       while(*p)
       {
           if((*p>='A'&&*p<='Z')||(*p>='a'&&*p<='z'))
               cnt++;
           else
               res[m++]=*p;
           p++;
       }
       printf("%d numbers\n",cnt);
       for(int i=0; i<m; i++)
           printf("%c",res[i]);
       return 0;
   }
   ```
   
7. ```c
   //(1)使用静态数组
   #include <stdio.h>
   #include <stdlib.h>
   char tmp[20];
   int replace(char *p)
   {
       int cnt=0,m=0;
   
       while(*p)
       {
           if(*p=='t'||*p=='T')
           {
               tmp[m++]=*p-15;
               cnt++;
           }
           else
               tmp[m++]=*p;
           p++;
       }
       return cnt;
   }
   int main()
   {
       char str[20];
       gets(str);
       char *p=str;
       int res=replace(p);
       printf("%d\n",res);
       printf("%s",tmp);
       return 0;
   }
   //(2)使用指针传递参数
   #include <stdio.h>
   #include <stdlib.h>
   int replace(char *p)
   {
       int cnt=0;
       while(*p)
       {
           if(*p=='t'||*p=='T')
           {
               *p-=15;
               cnt++;
           }
           p++;
       }
       return cnt;
   }
   int main()
   {
       char str[20];
       gets(str);
       char *p=str;
       int res=replace(p);
       printf("%d\n",res);
       printf("%s",str);
       return 0;
   }
   ```

8. ```c
   #include <stdio.h>
   #include <stdlib.h>
   char week[8][10]= {" ",
                      "Monday",
                      "Tuesday",
                      "Wednesday",
                      "Thursday",
                      "Friday",
                      "Saturday",
                      "Sunday"
                     };
   int main()
   {
       int w;
       scanf("%d",&w);
       if(!(w>=1&&w<=7))
       {
           printf("Input Error!");
           return 0;
       }
       printf("%s",week[w]);
       return 0;
   }
   ```

9. ```c
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   struct
   {
       char str[10];
       int len;
   } s[5],tmp;
   int main()
   {
       char a[5];
       int m=0;
       for(int i=0; i<5; i++)
       {
           gets(s[i].str);
           s[i].len=strlen(s[i].str);
       }
       for(int i=0; i<5; i++)
           for(int j=i+1; j<5; j++)
               if(s[i].len>s[j].len)
               {
                   tmp=s[i];
                   s[i]=s[j];
                   s[j]=tmp;
               }
       for(int i=0; i<5; i++)
       {
           if(s[i].len<3)
               a[m++]=' ';
           else
               a[m++]=s[i].str[2];
       }
       a[m]='\0';
       printf("%s",a);
       return 0;
   }
   ```

10. ```c
    #include <stdio.h>
    #include <malloc.h>
    void swap(int *a,int n)
    {
    
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(a[i]>a[j])
                {
                    int tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                }
    
    }
    int main()
    {
        int n;
        int *a=0;
        int i;
        scanf("%d",&n);
        a=(int *)malloc(sizeof(int)*n);
    
        for(i=0; i<n; i++)
        {
            a[i]=rand();
        }
        swap(a,n);
        for(i=0; i<n; i++)
        {
            printf ("p[%d]=%d\n",i,a[i]);
        }
        free(a);
        return 0;
    }
    ```