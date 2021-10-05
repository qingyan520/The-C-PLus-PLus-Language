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



列表

```python
a=list()
a
>>>[]
b="I love you"
b=list(b)
>>>b
>>>['I',' l'.........'y','o','u']

>>>len("ABC")#len返回长度
>>>3

max(1,2,3,4,5)#返回最大值
>>>5
max(b)
>>>v
numbers=[1，18，0，-98，34，54，76，32]
max(numbers)
>>>>76

min(1,2,3,4)#返回最小值
>>>1

max和min里面的数据类型要一致

tuple2=(3,1,2,4,5)
sum(tuple2)
>>15
sum(tuple2,10)#后面再加一个数字
>>>25

sorted(tuple2)
>>>>1,,2,3,4,5

a=list(reversed(tuple2))#翻转

list(enumerate(numbers))
>>>>[(0,1),(1,18),(2,13)]

a=[1,2,3,4,5,6,7,8]
b=[4,5,6,7,8]
list(zip(a,b))
>>>>[(1,4),(2,5),(3,6),(4,7),(5,8)]
```



函数的书写

```python
def MYfunc():
    print("hello myfunc")
>>>MYfunc()#调用函数

```

```python
#带参数函数的书写
def test(name):
    printf(name+"hello")
>>>test("python")
>>>pythonhello 

def test(nums1,nums2):
    printf(nums1+nums2)
>>>>test(1,2)
>>>>3
```

函数的返回值

```python
def add(nums1,nums2):
    return (nums1+nums2)
>>>>print(add(1,10))
>>>111
```

形参和实参

```python
#函数定义过程中的位置叫做形参
#实际传递的值叫做实参
```

关键字参数

```python
def test(name,word):
    printf("name"+"word")
>>>def("name","hello")
#或者可以直接进行指定

```

默认参数

```python
def test(name="hello",word="python"):
    print(name+" "+world)

```

命令行参数

```python
def test(*parmas,exp):
    print("参数的长度为：",Len(parmas),exp)
    printf("第二个参数是："，psrmas[1])
>>>>test('h',1,2,3,exp="jell")
```

```
global:定义函数为全局变量
```



在python中函数容许函数定义嵌套调用与使用

