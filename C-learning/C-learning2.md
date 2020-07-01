> 7.1

# 字符串和指针

### 字符串常量与指针

```c
char *message;
message="Hello world!";
```

```c
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *p="Hello world!";
    printf("%s\n",p);
    while(*p!='\0')
        printf("%c",*p++);
    return 0;
}
```

### 数组指针作为参数

+ 数组元素下标 也即直接将这个数传入函数
+ 数组名

不允许动态分配 需要分配内存 动态改变

+ 实参表示一个固定的地址
+ 形参表示一个指针

### 指向字符串的指针做参数

### 函数

定义和返回值

+ 多个`return` 执行一个
+ 没有`return` 返回值不确定

函数的书写

+ 申明在主函数之前
+ 直接写在主函数前
+ 建立独特的头文件书写自己的函数
  + 注 使用`" "`将头文件包括起来 寻找路径不一样

指向函数的指针