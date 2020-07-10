> 7.8

# 结构体类型

将不同类型的数据合成一个整体

+ 声明同时定义

+ 省略结构体名 只定义变量

+ 先声明 再定义

```c
struct Student
{
    int num;
    char name[20];
};

struct Student *pt;
pt=&stu1;//pt=stu;pt++;
printf("%d%s",(*pt).num,pt->name);
//两种指向都是可以的
```

引用：变量名.成员名

指向结构体变量的指针，初始地址

传递结构体变量

# 链表

常动态储存分配

头指针、结点

定义例如：

```c
struct student
{
    int num;
    char name[20];
    struct student *next;
};
```

基础操作：链表创建、增加结点、删除、打印

延申操作：逆序、排序

> 7.10

LeetCode 算法导论

实际案例：酒店订餐、计算税率、成绩统计分析、成绩管理系统

位运算