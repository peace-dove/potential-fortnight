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

# 位运算

二进制数 通过控制每一位是0还是1来决定数字

1字节包含8位

一字节储存数据范围0~255 共256个值 或者-128~127

### 二进制补码 two's-complement

将一个正的数每一位取反，得到的数再加一，可以得到相反数。

因为1是00000001， 那么-1则是11111110+1，即11111111。  

### 二进制浮点数

小数

`.101`表示`1/2+0/4+1/8`

### 八进制

起始用`o(octal)`

每个八进制位对应3个二进制位

如377（8）表示为 11 111 111（2）

### 十六进制

起始用`0x`

字母可以大小写

十六进制位对应一个4位的二进制数（即4个二进制位）  

所以用两个十六进制表示一个**8位字节**很方便

### 操作运算符

#### 按位逻辑运算符

1. 二进制反码 按位取反

   ```c
   ~(10011010) //the orignal number
    (01100101) //the number
    //it will not change the number,rather it provide a new one
   newval=~val;
   printf("%d",newval);
   //or you can use
   val=~val;
   ```

2. 按位与

   ```c
   //the real number of
   (10010011) & (00111101)
   //is
   (00010001)
   //both of inputs are 1 and the output is 1
   //rather it is 0
       
    val&=0377;
   //is equal to
   val=val&0377;
   ```

3. 按位或

   ```c
   //need just one 1 and the output is 1
   val|=0010;
   val=val|=0010;
   ```

4. 按位异或

   ```c
   //there is only one 1 between the same bit of two numbers
   //the output is 1 rather is 0
   val^=0001;
   val=val^=0001;
   ```

   技巧使用

   掩码

   >`ch&=0xff;`将后面八位取出来
   >
   >因为0xff表示11111111
   >
   >将保持`ch`的后八位不变 其他位设置为0
   
   打开某一位
   >使用mask取或
   >
   >mask中为1的部分得到1 也即打开
   >
   >和0取或得到自身
   
   关闭某一位
   
   >由于mask设置为00000010
   >
   >使用flags=flags&~mask;
   >
   >也即flags&=~mask;
   >
   >可以关闭第二位
   >
   >也即和0做与运算得到0
   >
   >用1和任何数做与运算得到本身
   
   切换某一位
   >0变1 1变0
   >
   >需要变更的位置为mask标0的部分
   >
   >**和0取异或得到本身**
   >
   >**和1取异或则取反**
   >
   >使用flags^=mask;
   >mask中为1的值的为值得到切换
   
   检查位的值
   >检查这一位是否是设置为1
   >
   >首先将这一位提出 和掩码取与运算 再判等
   >
   >if ((flags & MASK) == MASK)
   >puts("Wow!");  
   >
   >其中mask为00000010
#### 移位运算符

##### 左移 <<

例如(1001)<<2得到(0100)

利用左移赋值<<=来改变量的值

##### 右移 >>

对无符号数左边空位用0补齐

对有符号数则要看系统

```c
(10001010) >> 2 // 表达式， 无符号值
(00100010) // 所有系统都得到该结果值 
```

##### 用法

快速计算针对2的幂次

相当于移动小数点

```c
number<<n;//number乘以2的n次方
number>>n;//如果number为非负， 则用number除以2的n次幂
```

### 位字段

使用一个二进制位表示开关开闭 做01判别

赋值不能超过对应字段的范围

```c
struct {
unsigned int field1 : 1;
unsigned int : 2;
unsigned int field2 : 1;
unsigned int : 0;
unsigned int field3 : 1;
} stuff;
//stuff.field3将会储存在下一个unsigned int中

struct box_props {
bool opaque : 1 ;
unsigned int fill_color : 3 ;
unsigned int : 4 ;
bool show_border : 1 ;
unsigned int border_color : 3 ;
unsigned int border_style : 2 ;
unsigned int : 2 ;
};
//该结构占16位
```



### 位字段和按位运算

使用联合可以看到 同一个储存空间储存相同的数据 通过不同的解读能够得到不一样的结论

一段数据可以看成一个结构或是一个数据

```c
1<<n表示第n位为1的整数（在二进制表示下）
    1<<3  2^3
    1<<11 2^11
```

### 对齐特性

