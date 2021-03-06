> 7.22

# 队列

### 基本概念

#### 定义

数据元素的集合 队头元素 队尾元素

入队出队顺序相同

数据类型可以是原子类型 也可以是结构体类型

访问受限 队头(front)允许删除 队尾(rear)允许插入元素

#### 基本运算

置空 `initqueue(Q)`

判断队列是否空 `queueempty(Q)`

判断队列是否满 `queuefull(Q)` 对顺序队列使用多

入队`add(Q,x)`

出队`delete(Q)`

### 顺序队列 基本算法 应用举例

#### 基本概念

连续地址 数组

设立两个指针 头指针和尾指针

通常使 头指针指向对头前一个位置 尾指针指向队尾当前位置

数组有实在空间 指针是一个变量指向地址

#### 操作实现

队空 `front=rear`

队满 `rear=maxsize-1`

队列长度 `rear-front`

入队` rear++ `再将`rear`指向元素取出

出队` front++` 再将`front`指向元素取出

#### 循环队列

rear遇到边界则指向0 循环队列 可以采用模运算

判断队空队满 当头尾都相等时

1. 上一步是add 记录上一步操作内容
2. 将仅剩一个位置时当作队列满状态 先判断rear+1<front 不让rear指针追上front指针
3. 循环队列时判断 `(1+Q->rear)%maxlen==Q->front`

### 链队列 基本算法 应用举例

队列的链式存储结构简称为链队列

一个链队列由头指针和尾指针唯一确定