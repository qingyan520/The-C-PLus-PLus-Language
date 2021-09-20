# Python学习记录

## 1.python初始

### 1.python输出

1.最简单的直接输出

```python
print("hello world")
```

在python中字符串用单引号和双引号是一样的，都代表str类型

2.print可以当计算器用

```python
print(5+1)  //直接输出6
```

3.连接两个字符串

```python
print("hello"+"world",8)
```

打印hello world后打印8

### 2.python的数据类型

基本与c/c++一致，也具有int,float,str，bool类型

3.条件判断



4.循环      

```python
while 条件:
    
```

```python
for 目标  in 表达式(orange):
    循环体
name="hello"
for i in name:
    print(i,end=" ")
number=["小米"，"晓华"，"helo"]
for each in number:
    print(each,len(number))
range(0,5)
list(range(5)
for i in range(5):
     print(i)   
     
for i in range(1,10,2):
     print(i)
>>>:1,3,5,7,9
 
```

> break作用：跳出当前的循环
>
> continue：结束当前循环进入下一次循环

```python
for i in range(10):
    if(i%2==0):
        print(i)
        continue
     i+=2
    print(i)
>>>:
```

列表：数组

创建普通列表

```python
member=["heh","hehe","lsl"]
number=[1,2,3,4,5]
mix=[1,"呵呵",3.15,[1,2,3]]
empty=[]

```

创建混合列表

向列表添加元素

```python
empty=[]
empty.append("hello")
len(empty)
empty.append("呵呵")
//append:只容许添加一个参数
empty.extend(["heloo","jeee"])
//extend:容许添加列表
empty.insert(0,"ll")//从第一个位置添加元素



```

列表2：

```python
从列表中获取元素
empty[0]:和数组一样
交换顺序
temp=empty[0]
empty[0]=empty[1]
empty[1]=yemp;
删除元素：
1.remove
empty.remove("hello")
2.del
del empty[1]
del empty:删除列表
empty.pop():底层为栈，返回栈顶元素
empty.pop(索引值)
列表分片
empty[1:3]:分割出[1:3)
 nmber2=empty[:]:获得列表的拷贝
              
```

列表的常用操作

```python
list1=[123]
list2=[234]
list1>list2
list
```

元组：不可以被修改的列表

```python
temp=()//元组
temp=(1,)//只有一个元素
更新元组

```

