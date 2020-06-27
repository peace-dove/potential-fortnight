1. ```c
   #include <stdio.h>
   #include <stdlib.h>
   int a[5]= {0};
   int cnt=2;
   int main()
   {
       while(cnt--)
       {
           scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);
           for(int i=0; i<5; i++)
               for(int j=i+1; j<5; j++)
                   if(a[i]<a[j])
                   {
                       int temp=a[i];
                       a[i]=a[j];
                       a[j]=temp;
                   }
           printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
       }
       return 0;
   }
   ```

2. ```c
   #include <stdio.h>
   #include <stdlib.h>
   int a[10][10]= {0}; //假设最大为10*10 可以修改
   int main()
   {
       int n;
       scanf("%d",&n);
       for(int i=0; i<n; i++)
           for(int j=0; j<n; j++)
               scanf("%d",&a[i][j]);
       for(int i=0; i<n; i++)
           for(int j=i+1; j<n; j++)
           {
               int temp=a[i][j];
               a[i][j]=a[j][i];
               a[j][i]=temp;
           }
       for(int i=0; i<n; i++)
       {
           for(int j=0; j<n; j++)
               printf("%d ",a[i][j]);
           printf("\n");
       }
       return 0;
   }
   ```

3. ```c
   #include <stdio.h>
   #include <stdlib.h>
   
   int a[10][10]={0};//假设最大为10*10 可以修改大小
   int main()
   {
       int n;//输入方阵的大小
       scanf("%d",&n);
       for(int i=0; i<n; i++)
       {
           for(int j=0; j<n; j++)
               scanf("%d",&a[i][j]);
       }
       int found=1;
       for(int i=0; i<n; i++)
           for(int j=i+1; j<n; j++)
           {
               if(a[i][j]!=a[j][i])
               {
                   found=0;
                   break;
               }
           }
       if (found==0)
           printf("no\n");
       else
           printf("yes\n");
       return 0;
   }
   ```

4. ```c
   #include <stdio.h>
   #include <stdlib.h>
   int a[10]= {0};
   void swap(int *a,int *b)
   {
       int t=*a;
       *a=*b;
       *b=t;
   }
   int main()
   {
       int n;
       int max,maxnum;
       scanf("%d",&n);
       for(int i=0; i<n; i++)
           scanf("%d",&a[i]);
       max=a[0];
       maxnum=0;
       for(int i=1; i<n; i++)
           if(max<a[i])
           {
               max=a[i];
               maxnum=i;
           }
       int *p1,*p2;
       p1=&a[maxnum];
       p2=&a[n-1];
       swap(p1,p2);
       for(int i=0; i<n; i++)
       {
           printf("%d",a[i]);
           if(i!=n-1)
               printf(" ");
       }
       return 0;
   }
   ```

5. ```c
   #include <stdio.h>
   #include <stdlib.h>
   #define N 7
   int a[N]= {0};
   int b[N]= {0};
   void swap(int *a,int *b)
   {
       int t=*a;
       *a=*b;
       *b=t;
   }
   int main()
   {
       int n;
       scanf("%d",&n);
       for(int i=0; i<n; i++)
           scanf("%d",&a[i]);
       int m=0;
       for(int i=n-1; i>=0; i--)//利用a的首地址偏移
       {
           b[m++]=*(a+i);
       }
       for(int i=0; i<n; i++)
       {
           printf("%d",b[i]);
           if(i!=n-1)
               printf(" ");
       }
       return 0;
   }
   ```

6. ```c
   #include <stdio.h>
   #include <stdlib.h>
   #define N 7
   int a[N]= {0};
   int b[N]= {0};
   int main()
   {
       int n;
       scanf("%d",&n);
       for(int i=0; i<n; i++)
           scanf("%d",&a[i]);
       int *p;
       p=&a[n-1];
       for(int i=0; i<n; i++)//利用指针往前偏移
       {
           b[i]=*p;
           p--;
       }
       for(int i=0; i<n; i++)
       {
           printf("%d",b[i]);
           if(i!=n-1)
               printf(" ");
       }
       return 0;
   }
   ```

7. ```c
   #include <stdio.h>
   #include <stdlib.h>
   int a[10][10]= {0};
   int main()
   {
       int m,n;
       scanf("%d %d",&m,&n);
       for(int i=0; i<m; i++)
           for(int j=0; j<n; j++)
               scanf("%d",&a[i][j]);
       for(int i=0; i<m; i++)
       {
           for(int j=0; j<n; j++)
               printf("%d ",a[i][j]);//a[i][j]即是二维数组的元素指针
           printf("\n");
       }
       return 0;
   }
   ```

8. ```c
   #include <stdio.h>
   #include <stdlib.h>
   int a[10][10]= {0};
   int main()
   {
       int m,n;
       scanf("%d %d",&m,&n);
       for(int i=0; i<m; i++)
           for(int j=0; j<n; j++)
               scanf("%d",&a[i][j]);
       for(int i=0; i<m; i++)
       {
           for(int j=0; j<n; j++)
   
               printf("%d ",*(*(a+i)+j));//行的指针
           printf("\n");
       }
       return 0;
   }
   ```
   
9. ```c
   //(1)
   #include <stdio.h>
   #include <stdlib.h>
   int fac(int n)
   {
       if(n==1||n==0)
           return 1;
       return n*fac(n-1);
   }
   int main( )
   {
       int m;
       float k;
       printf("input m:");
       scanf("%d",&m);
       k=fac(m);
       printf("result=%f",k);
       return 0;
   }
   //(2)
   #include <stdio.h>
   #include <stdlib.h>
   void fac(int n,float *p1)
   {
       if(!n)
       {
           *p1=1;
           return;
       }
       int f=1;
       for(int i=1; i<=n; i++)
           f*=i;
       *p1=f;
       return;
   }
   int main( )
   {
       int m;
       float k,*p;
       p=&k;
       printf("input m:");
       scanf("%d",&m);
       fac(m,p);
       printf("result=%f",k);
       return 0;
   }
   ```

10. ```C
    #include <stdio.h>
    #include <stdlib.h>
    char *strcat(char *first,char *next)
    {
        char *temp=first;
        while(*temp!='\0')
            temp++;
        *temp=*next;
        while(*next!='\0')
            *(temp++)=*(next++);
        return first;
    }
    int main()
    {
        char str1[30] = "I learn ", *str2 = "C language.";
        //char str1[100],str2[100];
        //gets(str1);
        //gets(str2);
        //getchar();
        //scanf("%[^\n],%[^\n]",str1,str2);
        //printf("%s %s",str1,str2);
        char *s;
        s = strcat(str1,str2);
        printf("%s\n",s);
        return 0;
    }
    ```

