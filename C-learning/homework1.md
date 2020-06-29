1. ```c
   //利用数组储存输入 利用气泡法排序
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
   int a[10][10]= {0}; //假设最大为10*10 可以修改为更大
   int main()
   {
       int n;
       scanf("%d",&n);
       for(int i=0; i<n; i++)
           for(int j=0; j<n; j++)
               scanf("%d",&a[i][j]);//输入n阶矩阵
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
   
   int a[10][10]={0};//假设最大为10*10 可以修改大小为更大
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
                   break;//出现一个不匹配则退出循环
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
   void swap(int *a,int *b)//利用指针交换
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
       for(int i=1; i<n; i++)//遍历一遍找到最大和最大的序号
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
       for(int i=0; i<n; i++)
       {
           b[i]=*p;
           p--;//利用指针往前偏移
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
   //(1)fac有返回值 利用递归求得阶乘值
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
   //(2)fac函数无返回值 使用指针和外界联系
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
    
11. ```c
    #include <stdio.h>
    #include <stdlib.h>
    int fac(int n)
    {
        if(!n)
            return 1;
        return n*fac(n-1);
    }
    int uniquePaths(int m,int n)//对于没有障碍的问题可以转化为组合问题
    {
        return fac(m+n-2)/fac(m-1)/fac(n-1);
    }
    int main()
    {
        int m,n;
        scanf("%d %d",&m,&n);
        int k=uniquePaths(m,n);
    	printf("共有%d条路径",k);
        return 0;
    }
    ```

12. ```c
    #include <stdio.h>
    #include <stdlib.h>
    int a[100][100];
    int m,n;
    int uniquePaths(int row, int col)//有障碍的利用递推
    {
        if(a[row][col]==1)//遇到障碍 则这条路走不通 路径数为零
            return 0;
        if(row==m-1&&col==n-1)//到达终点 则有一条通路达成
            return 1;
        if(row==m-1)
            return uniquePaths(row,col+1);//到达最下面行 只往右边搜索
        if(col==n-1)
            return uniquePaths(row+1,col);//到达最右面行 只往下边搜索
        return uniquePaths(row+1,col)+uniquePaths(row,col+1);//对于任意一个点是右边和下面路径数之和
    }
    int main()
    {
    
        scanf("%d %d",&m,&n);
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        int k=uniquePaths(0,0);
        printf("共有%d条路径",k);
        return 0;
    }
    ```

13. ```c
    #include <stdio.h>
    #include <stdlib.h>
    int a[20][20]= {0};
    void rotate(int matrixRowSize, int matrixColSize)//顺时针旋转90°
    {
        for(int i=0; i<matrixRowSize; i++)//先按照主对角线对称
            for(int j=i+1; j<matrixColSize; j++)
            {
                int temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
        for(int i=0; i<matrixRowSize; i++)//再按照竖直轴对称
            for(int j=0; j<matrixColSize/2; j++)
            {
                int temp=a[i][j];
                a[i][j]=a[i][matrixColSize-j-1];
                a[i][matrixColSize-j-1]=temp;
            }
    
    }
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        rotate(n,n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
        return 0;
    }
    ```

14. ```c
    #include <stdio.h>
    #include <stdlib.h>
    int* spiralOrder(int (*matrix)[3], int matrixRowSize, int matrixColSize)
    {
        int *m=(int*)malloc(sizeof(int));
        int cnt=0;
        //按照层数由外向内顺时针旋转放入m空间 利用四次循环
        for(int layer=0; (layer<(matrixRowSize/2+1))&&(layer<(matrixColSize/2+1)); layer++)
        {
            for(int j=layer; j<=matrixColSize-layer-1; j++)
                m[cnt++]=matrix[layer][j];
            for(int i=layer+1; i<=matrixRowSize-layer-1; i++)
                m[cnt++]=matrix[i][matrixColSize-layer-1];
            for(int j=matrixColSize-layer-2; j>=layer; j--)
                m[cnt++]=matrix[matrixRowSize-layer-1][j];
            for(int i=matrixRowSize-layer-2; i>layer; i--)
                m[cnt++]=matrix[i][layer];
        }
        return m;
    }
    int main()
    {
        int a[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
        int matrixRowSize=3,matrixColSize=3;
        int *returnnum=spiralOrder(a, matrixRowSize, matrixColSize);
        int *p;
        for(p=returnnum; p<returnnum+9; p++)
        {
            printf("%4d",*p);
        }
        return 0;
    }
```
    
    

