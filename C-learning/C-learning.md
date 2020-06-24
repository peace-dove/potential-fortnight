> 6.24

# C语言实践与设计

## 数组与指针

>规范语言程序 书写规范

### 数组

+ 相同变量类型 储存和使用
+ 模拟现实世界的计算和处理

> 动态内存分配

+ 特点
  + **连续**存储空间
  + 数据类型相同
  + 所有元素变量字节相同

+ 定义：`int a[10];`
+ 注意
  + 下标从零开始
  + 不允许动态定义 除非函数中形参

+ 初始化
  + 完全
  + 部分 一部分赋值 其他为零
  + 未初始化 为**垃圾值**

+ 二维数组 理解为线性的 先行再列
+ 注意 `a[3][4]`定义和引用区别

`int a[3][4]={{1,2,3,4},{},{},{}};`

+ 第一维可以省 第二维不能省略

### 指针

+ 地址与取地址
  + `float x;` 变量x的地址`&x`
  + `int *p` 指向`*`
  + 每个字节都有自己的地址 地址是第一个字节的地址

```c
int *p,x;
x=5;
p=&x;
```

+ 数据类型为`int *`
+ *p表示值为5
+ p表示所指变量的地址

```c
int a,*p;
p=&a;
printf("%d",*p);
*p=12;
printf("%d",*p);
```

> 不要产生歧义

`p=&a`equals to `*p=a`

`c=*p++;` is equal to`c=*p;p++;`

`d=*++p;`equals to`++p;d=*p;`

+ 二级指针

```c
int x=1;
int *p;
int **p;
p=&x;
pp=&p;
```
+ swap a and b
```c
#include <stdio.h>
#include <stdlib.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int a,b;
    int *p1,*p2;
    scanf("%d %d",&a,&b);
    p1=&a;
    p2=&b;
    swap(p1,p2);
    printf("%d %d",a,b);
    return 0;
}
```
+ **函数指针** 返回指向返回值的指针

+ **指向函数的指针** `int (*pt)(int arr[],int n);`
	+ 小括号不能省略
	+ `pt=add;`