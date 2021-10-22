

# Linux学习记录



ls 显示当前目录下文件

 ls -l 显示文件属性

ls -a显示隐藏文件

ls _al 组合指令



//在Linux中以.开头的文件为隐藏文件

pwd显示当前所处目录对应路径

cd 文件名：进入指定文件夹

cd ..:返回上级目录

Linux中到达指定文件路径是唯一的

/为Linux中路径分隔符

/：根目录

tree 显示树状结构

touch  文件名：建立指定文件

mkdir 文件夹名：创建指定文件夹

mkdir -p dir1/dir2/dir3 创建一整条路径

rmdir 文件夹名：删除文件夹

只能删除空目录./

rm -r dir1:一递归的方式进行删除

rm -rf  文件名：强制删除，不进行提示

rm -rf /:直接删除所有东西，从删库到跑路

rm *删除当前目录所有文件

*通配符：匹配当前目录下所有文件

./ 文件名 告诉系统访问的文件在当前目录下

nano :记事本

gcc test.c

./a.out

man 在Linux中查看参考手册

man 默认查看1号手册

more test.c :占满这一屏幕，只能进行下翻

cat  test.c:一次直接将所有内容输出

less  test.c:几乎和more命令一样，能进行上下翻阅

head test.c:默认查看文本前10行

head -3 test.c :查看文本前3行

tail  -10 test.c:默认查看后10行

echo “hello”> test.txt:重定向输出，将hello输出到test.txt中

每次都要重新清空文件然后重新写入

echo "hello">>test.txt:追加重定向（>>）:往文件中追加

cat > test,txt:输入重定向，从键盘输入改为从文件中读取

|：管道

find test.c

find真正要在文件系统中进行查找->直接访问磁盘

grep:行过滤工具

grep -n '9999' file.txt

简单用户切换：su -

zip test.c:压缩

unzip:解压缩

tar:打包/解包

tar czf test.tgz *

tar xzf test.tgz s

tac test.c:逆向进行输出

#include<unistd.h>

Sleep(1)

PID:当前进程的pid

  

![image-20210727190603783](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210727190603783.png)

文件类型：(第一个字符)

d:文件夹

-：普通文件

l:软链接(类似Windows得快捷方式)

b:块设备文件(例如硬盘，光驱)

p:管道文件

c:字符设备文件(例如屏幕等串口设备)

s:套接口文件

 root,普通用户（sjw）:充当拥有者，也可以充当所属组，也可以充当other

![image-20210727191929772](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210727191929772.png)

Linux中，所有的用户都要隶属于某一个组，哪怕这个组只有你一个人(面对的大部分情况)

为什么要用所属组：更灵活的进行权限配置，满足团队合作

![](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210727191929772.png)

-rw-rw-r-- 1 sjw sjw 0 Jul 26 19:30 lesson3

-rw-rw-r-- ：其中第一个表示文件类型，剩下9个字符3个3个分为1组，代表三种不同的权限

rw-:拥有者权限

rw-:所属组权限

r--:other

r：读

w:写

x:可执行

-：没有对应权限

如何阐述一个文件的权限：-rw-rw-r--

答：拥有者有读权限，写权限，没有可执行权限，所属组具有读权限，写权限，没有可执行权限，other拥有读权限，没有写权限和可执行权限

对应权限：---：第一个代表是否具有读权限，是为r，否为-

​                           第二个位置代表是否具有写权限，是为w,否为-

​                           第三个位置代表是否具有可执行权限，是为x，否为-

每个位置权限位置固定

改变权限：

改变user的权限

chmod u-r file.txt:减少user的读权限

  chmod u+x file.txt:增加user的可执行程序，但是文件不一定变得可执行，要取决于文件里面是否有二进制代码或者可执行脚本

chmod u-rwx file.txt:去掉user的所有权限

chmod u+rw file.txt:加上user的read,write权限

改变所属组(group)的权限

chmod g-r file.txt:减少所属组的读权限

chmod g-rwx file.txt:减少所属组所有权限

chmod g+rwx file.txt:加上所属组所有权限

改变other的所有权限：

chmod o+rwx file.txt:为other加上所有权限

一次对多个人多个权限进行修改：

chmod u-rwx,g-rwx,o-rwx file.txt:一次干掉所有人的所有权限

chomd u+rw,g+rw,o+w file.txt

目录：

1.cd进入目录需要：可执行权限x(必须具备的权限)

2.ls查看目录下所有文件需要：读权限

3.touch写文件需要：写权限

文件拥有者修改：sudo chown root file.txt

文件组群修改：sudo chgrp root file.txt

两者同时修改：sudo chown whb:whb file.txt

umask:

为什么创建的普通目录文件会有默认权限，并且这些为何又是当前这样

默认起始权限：666开始

凡是在umask出现的权限为不应该在七十权限位出现

不是减去

最终权限=default&(~umask)

目录777开始

粘滞位：对目录进行操作chmod a+t dir

如果目录本身是你的，那么加粘滞位后照样可以删

安装程序：sudo yum install sl

vim:代码编写工具，文本编辑器

多模式文本编辑器

默认打开为命令模式：shitf+:q退出

a变为insert插入模式

esc,再shitf+:





shift+$/shift+^:锚点，光标左右移动

shift+g,:将光标定位到结尾/shift+gg:直接到开口

n+shift+g:到第几行

光标定位到改行开头，yy,p,

gcc/g++使用：

C程序的翻译：

1.预处理（-E）：头文件的展开，宏定义的替换，去注释，条件编译

gcc -E testc.c -o test.i



2.编译：

3.汇编

4.链接

g++ test.cpp

库：减少当前开发者的工作量



动态库(.so)：



静态库(.a)：

动态链接(.so)：

优点：省空间（磁盘空间，内存空间），可执行程序体积小，加载速度快

缺点：依赖动态库，程序移植性较差



静态链接（.a）：

优点：不依赖第三方库，程序的运行可移植性较差

缺点：浪费空间

gcc生成的可执行程序，默认是动态链接的

gcc -static变成静态链接

gdb

centos7中gcc中默认生成的可执行程序时release版本的，不可以被调试

-g:以debug版本发布

debug版本携带调试信息



make/makefile实现多文件编程

make是一个命令，makefile是一个文件，两个搭配使用，完成项目的自动化构建

多文件编程方法：

方法一：

test.c,main.c,test.h

1.gcc -o mytest main.c test.c (默认不需要写test.h，会直接在当前目录下寻找test.h)

默认生成mytest

./mytest执行程序

2. gcc -c main.c -o main.o

   gcc -c test.c -o test.o

   gcc -o mytest main.o test.o

   ./mytest

方法二：make指令配合makefile文件实现多文件编程

1.在当前目录下创建名为Makefile的文件：touch Makefile

2.vim Makefile 

单个文件：

mytest:test.c(依赖关系)

​	gcc -o mytest test.c(依赖方法)

.PHONY:clean

clean:

​	rm -f mytest

make clean



多文件：

mytest:main.o test.o

​	`gcc -o main.o test.o

main.o:main.c

​	gcc -c main.c

test.o:test.c

​	gcc -c test.c

.PHONY:clean

clean:

​	rm -f *.o mytest

![image-20210809212930987](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210809212930987.png)





进度条的实现：

缓存区：并不是立即被刷新出来，

无缓冲

行缓冲

全缓冲

带\n：立即刷新，行刷新，行缓冲

不带的话

![image-20210809214445644](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210809214445644.png)

换到下一行：换行\n

回到下一行的开始：回车\r

  

![image-20210810194337010](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210810194337010.png)

git的使用：

git add

git commit -m "日志"

git push 

版本控制，分支管理，多人协作





进程的基本概念：





冯诺依曼结构：

CPU只和内存打交道

输入设备：键盘，网卡，硬盘，话筒，摄像头

输出设备：显示器，音响，网卡，硬盘

数据要进行处理，必须预装载到内存中，局部性原理，操作系统帮助完成

程序运行前必须加载到内存中：可执行程序(文件)是在硬盘上(外设)，

寄存器：不仅仅在CPU中

硬件单元传递信号是用总线(IO总线，系统总线)







操作系统：对硬件进行管理，内存管理，文件管理，驱动管理，进程管理

Linux下一切皆为文件



进程管理：

程序加载到内存中或者运行起来就叫做进程

Linux中进程的查看方法：ps aux

可执行程序-》被管理者

PCB：进程控制块



进程>可执行程序[+内核数据结构]



PCB包含哪些字段：

struct task_struct{

}

1.pid,ppid

2.优先级

3.代码和数据

4.时间片

5.上下文信息

6.连接信息



优先级：获得某种资源的顺序

tack_struct

ps aux a|head

标识符信息：pid

获取当前进程的pid:getpid()        

gitppid:获取当前进程父进程的pid 

kill pid:结束当前进程

子进程不影响父进程

每个运行的进程，都有自己的时间片

基于时间片的轮转

、、

程序计数器和上下文数据:



vs test.c

gcc工作原理：默认一次性做完四步

touch mytest.c

预处理：

gcc -E test.c -o mytest.i

-E:进行预处理工作

-o mytest.i:将预处理后的结果放到mytest.o当中去

gcc mytest.c -D os=0

-D os=0:动态设置宏定义

编译：

将C语言代码编程汇编语言

gcc -S mytest.i  -o mytest.s

-S:进行程序的翻译，到编译完截至



汇编：将汇编代码翻译成二进制文件(目标文件，可重定向文件)

gcc -c mytest.s -o mytest.o

-c:

链接：一般目标文件，只有函数调用，没有函数实现，链接的本质是将程序的调用与程序的库向关联起来

gcc mytest.o -o mytest

一般情况下gcc使用方法：gcc test.c -o mytest

gdb使用：

默认生realse版本，不可以调试

如果想调试： -g以debug方式发布

gdb mytest

list:显示代码(简称：l):l 1

run /r:运行

先显示l 1

然后打断点

b:断点  b   16 //打断点到16行

info b:查看当前断点信息

b 20

info b:

取消断点：d  Num//删除断点

P 变量名 //查看断点处的值

P &变量名//查看断点对应的地址值

n（next）:进入下一行，逐过程

s:进入函数

display i://长显示i的值

display &start：取出变量的地址

undisplay Num(i):取消监视

until  行号：跳转到指定行

 finish ：当在函数中运行时，直接结束该函数

c(continue)：直接跳转到下一个断点

info 函数名：给这个函数第一行打断点

set i=100:在监视窗口对某个值进行修改

quit:退出gdb调试



项目自动化构建工具-make/Makefile

方法一:gcc -o mytest main.c test.c//头文件默认在该目录下寻找

方法二：先将要用的文件形成二进制文件，再将两个二进制文件链接起来

```shell
gcc -c main.c -o main.o

gcc -c test.c  -o test.o

gcc -o Mytest test.o main.o
```

方法三：make指令+Makefile构建自动化项目

```shell
//Makefile实现单文件编程
touch Makefile
Mytest:test.c//依赖关系
	gcc -o Mytest test.c//依赖方法
.PHONY:clean//伪目标
clean:
	rm -f Mytest
//.PHONY:伪目标：依赖方法总是被执行的
```

```shell
//多文件编程
Mytest:test.o main.o
	gcc -o mytest test.o main.o
test.o:test.c
	gcc -c test.c
main.o:main.c
	gcc -c main.c
.PHONY:clean
clean:
	rm -f *.o mytest
```

```
//最终版Makefile
$@:依赖关系中的目标文件
$^:依赖关系中的依赖文件列表
$<:依赖关系中的一个一个的依赖文件
mytest:test.o main.o
mytest:main.o test.o
	gcc $@ $^
main.o:main.c
	gcc -c $<
test.o:test.c
	gcc -c $<
.PHONY:clean
clean:
	rm -f *.o mytest
```







创建进程

fork():创建一个子进程

```cpp
#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
    fork();
    while(1)
    {
        printf("hehe\n");
    }
    return 0;
}
```

fork之前的代码，被父进程执行，fork之后的代码，父子都可以执行

fork之后，父子进程代码共享

fork之后，父子进行那个先运行不确定，取决于操作系统调度算法

fork函数会有两次返回值，给父进程返回子进程pid，给子进程返回0

![image-20210911194317560](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210911194317560.png)

```cpp
  6   pid_t id=fork();
  7   if(id==0)
  8   {
  9     while(1)
 10     {
 11       printf("我是子进程\n");
 12       sleep(1);
 13     }
 14   }
 15   else if(id>0)
 16   {
 17     while(1)
 18     {
 19       printf("父进程\n");
 20       sleep(2);
 21     }
 22   }
 23   else
 24   {
 25     printf("进程创建失败\n");                                                   
 26   }
 27   return 0
```

![image-20210911195055735](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210911195055735.png)

结果：父子进程同时执行





进程的状态

进程状态------>数据化-------->

进程数据被保存到tack_struct中

可以同时存在多个R状态的进程

R状态的进程不一定是正在运行的，表示随时可以调用该进程

系统中所有处于R状态的进程都会被连接起来形成调度队列(run_queue)





```cpp
//休眠状态
#include<stdio.h>
#include<unistd.h>
int main()
{
  printf("I am Running\n");
  sleep(10000000);
  printf("Ending\n");
  return 0;
}
```

S状态：休眠状态(浅度睡眠)通常用来等待某种事件发生，随时可以被唤醒，也可以被杀掉

D状态:深度睡眠状态，D状态没有办法模拟，表示该进程不会被杀掉，即便是操作系统，除非重启杀掉，或者主动醒来

![image-20210911202604639](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210911202604639.png)

T状态：将进程进行暂停

X状态：死亡进程



Z状态：僵尸状态

 进程退出，在操作系统层面，曾经申请的资源，并不是被立即释放，而是要暂存一段事件，供OS(父进程)进行读取，叫做僵尸状态

为什么要有僵尸进程：

进程创建的目的：完成某种工作

当任务完成的时候，调用方应该指导任务完成得怎么样

（除非不关心）

```cpp
sjw@iZ2zedu4njy79sqivntvprZ test_9_11]$ cat test.c
#include<stdio.h>
#include<unistd.h>
int main()
{
  printf("I am Running\n");
  sleep(10000000);
  printf("Ending\n");
  return 20;
}
[sjw@iZ2zedu4njy79sqivntvprZ test_9_11]$ echo $?//查看进程码，查看最近一次进程退出时得进程码（如返回值return  0等）
//进程退出时，进程信息(退出码)是会被暂时保存起来的，相关信息被保存到task_struct,此时，该task_struct相关数据不应该被释放掉   Z
当有进程来读取信息时，task_struct被释放
如何读取信息：进程wait
```

进程退出的信息(退出码)会被暂时保存起来

保存在task_struct中，如果没有人读取，此时，task_struct相关数据不应该被释放

模拟僵尸状态:

```cpp
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  pid_t id=fork();
  if(id==0)
  {
    int count=5;
    while(count)
    {
      printf("I am child, pid:%d, ppid:%d, count:%d\n",getpid(),getppid(),count--);
    sleep(1);
    }
    printf("child exit......\n");
    exit(-1);
  }
  else if(id>0)
  {
    while(1)
    {
      printf("I am father,pid:%d, ppid:%d\n",getpid(),getppid());
      sleep(1);
    }
  }
  else
  {
    printf("fork fail\n");
  }
  return 0;
}

```

```shell
[sjw@iZ2zedu4njy79sqivntvprZ test_9_11]$ make clean
rm -rf *.o myproc
[sjw@iZ2zedu4njy79sqivntvprZ test_9_11]$ make
gcc -c test.c -o test.o
gcc -o myproc test.o
[sjw@iZ2zedu4njy79sqivntvprZ test_9_11]$ ./myproc
I am father,pid:9259, ppid:308
I am child, pid:9260, ppid:9259, count:5
I am father,pid:9259, ppid:308
I am child, pid:9260, ppid:9259, count:4
I am father,pid:9259, ppid:308
I am child, pid:9260, ppid:9259, count:3
I am father,pid:9259, ppid:308
I am child, pid:9260, ppid:9259, count:2
I am father,pid:9259, ppid:308
I am child, pid:9260, ppid:9259, count:1
I am father,pid:9259, ppid:308
child exit......
I am father,pid:9259, ppid:308
I am father,pid:9259, ppid:308
I am father,pid:9259, ppid:308
I am father,pid:9259, ppid:308
I am father,pid:9259, ppid:308
^Z

```

然后在另外一个窗口输入以下监控脚本：

```shell
while :; do ps aux | head -1 && ps aux | grep myproc|grep -v grep;echo "#############################"; sleep 1; done
```

![image-20210911210810042](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210911210810042.png)

刚开始运行时，二者都是S状态，到子进程运行完毕退出进行时，子进程编程僵尸进程

![image-20210911211033832](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210911211033832.png)  

僵尸进程的危害：

造成内存浪费

造成内存泄漏



孤儿进程

Linux中，进程关系，主要是父子关系，

孤儿进程：父进程退出，子进程还在运行

孤儿进行会立即被系统领养（操作系统：1号进程）

​	监控脚本：

```shell
while :; do ps axj | head -1 && ps axj | grep myproc|grep -v grep;echo "#############################"; sleep 1; done
```

```cpp
#include<stdio.h>
#include<stdlib.h>
#include<unstd.h>
int main()
{
	pid_t id=fork();
	if(id==0)
	{
		while(1)
		{
			printf("I am child,pid:%d,ppid:%d\n",getpid(),getppid());
			sleep(1);
		}
	}
	else if(id>0)
	{
		int count=5;
		while(count)
		{
			printf("I am father,pid:%d,ppid:%d,count:%d\n",getpid(),getppid(),count--);
		}
		exit(-1);
	}
	return 0;
}
```



查看进程:

```shell
ps aux |grep Mytest
```

进程是能够知道自己当前所处的工作目录的





进程的优先级

CPU资源分配的先后顺序，就是指进程的优先级

优先级高的进程有优先执行权利

还可以把进程绑定到指定的CPU上

```shell
ps -l:显示优先级
```

```shell
ps -la:显示更全面的信息
```

```shell
Linux中的优先级：优先级+nice值
```

```
PRI:表示进程执行的优先级，越小优先级越高
```

NI(nice)：调整优先级(-20~19)

调整进程优先级：

```shell
top
r----->进程id--->回车------>设置nice值------>q退出---->ps-la--->查看myproc的优先级
```

PRI最低为60，最高为99，每次调整时都是以80为基础进行调整的，与上次调整的没有关系

```
renice -n :调整优先级nice数据
```

独立性：多个进程独立运行，互不影响

并行：多个进程早多个CPU下分别，同时运行

并发：多个进程在一个CPU采取进程切换的方式，在一段时间内运行叫做并发



环境变量

环境变量是指在操作系统中用来指定操作系统运行环境的一些参数



常见环境变量

PATH:指定搜索路径

```shell
$ echo $PATH
```



```shell
sudo cp -f myproc /usr/bin  这样就可以直接执行了，不推荐
```

```shell
将当前路径导入环境变量PATH
export PATH=$PATH:/home/sjw/Linux_Learning
```

```shell
echo $PATH:取消环境变量
```





```shell
echo $HOME:(查看)保存当前用户所处的路径

```



```
SHELL:
echo $SHELL(查看)
```

```
env:显示当前环境变量信息
```

```
echo "hello world">/dev/pts/1
向这个终端发送东西
```

set :显示本地系统中所有的变量

unset :清除环境变量

本地变量：只在本进程内有效 

echo:显示莫格环境变量的值





main函数带参数

```cpp
//命令行参数
//argc:计数
//argv:指针数组，里面每一个都是指针
//envp:存储环境变量
int main(int argc,char*argv[],char*envp[])
{
	for(int i=0;i<argc;i++)
    {
        printf("argv[%d]:%s\n",i,argv[i]);
    }
}
./myproc -a -b -c -d
    argv[0]=./myproc
    argv[1]:-a;
    argv[2]:-b;
    argv[3]:-c;
    argv[4]:-d;
envp:用来存储环境变量
```

```cpp
#include<stdio.h>
#include<unistd.h>
int main(int argc char*argvg[],char*envp[])
{
    if(argc==2){
        if(strcmp(argv[1],"-a")==0)
        {
            printf("hello world\n");
        }
        else if(strcmp(argv[1],"-b")==0)
        {
            printf("hello bit\n");
        }
        else
        {
            printf("hello default\n");
        }
    }
    printf("argc:%d\n",argc);
}
./myporc
    argc:1
 ./myproc -a
        hello world
        argc:2
 ./myproc -b
        hello bit
        argc:2
  ./myproc -dd
         hello default
         argc:2
 
```

```cpp
//envp获取环境变量
#include<stdio.h>
int main(int argc ,char*argv[],char*envp[])
{
    int i=0;
    while(envp[i]!=NULL)
    {
        printf("envp[i]:%s\n",i,envp[i]);
        i++
    }
}
```

环境变量是一个系统级别的全局变量，更本原因是bash之下所有的进程都可以获取，本质main(,envp.....)

```cpp
#include<stdlib.h>
//getenv("PATH"):获取系统环境变量
#include<stdio.h>
int main()
{
    printf("%s\n",getenv("PATH"));
}
```



程序的地址空间

进程的地址空间

```cpp
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int g_unval;
int g_val=100;
int main(int argc,char*argv[],char*envp[])
{
    printf("code addr:%p\n",main);
    char*str="hello";
    printf("read only addr:%p\n",str);
    printf("init addr:%p\n",&g_val);
    printf("uninit addr:%p\n"&g_unval);
    int*p=malloc(4);
    printf("heap addr:%p\n",p);
    printf("stack add:%p\n",&str);
    printf("stack add:%p\n",&p);
    for(int i=0;i<argc;i++)
    {
        printf("args addr:%p\n",argv[i]);
    }
    int i=0;
    while(envp[i])
    {
        printf("env addr:%p",envp[i]);
        i++;
    }
}
```

```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/type>

int g_val=100;
int main(int argc,char*argv[],char*envp[])
{
	pid_t id=fork();
	if(id==0)
	{
	g_val=200;
		printf("child:pid:%d,ppid:%d,g_val:%d,&g_val:%p\n",getpid(),getppid(),g_val,&g_val);
	}
	else
	{
		sleep(2);
		printf("father:pid:%d,ppid:%d,g_val:%d,&g_val:%p\n",getpid(),getppid(),g_val,&g_val);
	}
	sleep(1);
}

结果：子进程中全局变量变成200，父进程还是100，但是两者的内存地址都是相等的 
证明：该地址绝对不是物理地址，而是虚拟地址
是语言层面上见到的地址而不是物理地址
我们在c/c++语言所看到的地址都是虚拟地址，物理地址，用户一般看不到，由操作系统进行统一管理
OS(操作系统)负责将虚拟地址转化为物理地址

子进程虚拟地址
			--------》转化
父进程虚拟地址
```

每一个进程都有一个进程地址空间，都有一个映射列表

子进程的写入，不会影响父进程(进程之间具有独立性，不会相互影响)



写时拷贝:写的时候单独拷贝一份空间

数据层面发生了分离



c





基地址+偏移量

进程地址空间本质使内存中的一种内核数据结构：mm_struct

在划分区域之前，必须有一个大的区域：32位最大内存：2^32字节 4GB



```cpp
struct mm_struct
{
​	unsigned int code_start;
​	unsigned int code_end;
​	unsigned int  readoly_start;
​	unsigned int readonly_end;
//
}

```

创建进程本质是系统里多了一个进程，管理进程，先描述，再组织

struct task_struct:进程控制块

还要创建mm_struct(进程地址空间)

扩大区域

ELF:Linux中可执行程序的格式

《深入理解计算机系统》

什么叫做创建进程：
task_struct ，mm_struct ,页表

为什么要有地址空间：

1.从此以后不会有任何系统级别的越界问题存在了，避免错误的访问物理内存

虚拟地址空间+页表，本质功能之一：保护内存

2.每个进程都认为看到的都是相同的空间范围(构成，顺序)

3.每个进程都认为自己在独占内存，更好的完成进程独立性以及合理使用空间





2.



队列：

 

 



进程控制：

1.进程创建：

fork函数：

```cpp
#include<unistd.h>
pid_t fork();
fork函数的返回值位pid_t,给子进程返回，给父进程返回子进程的pid
为什么又两个返回值，如何理解
 父进程可以又多个子进程，每个子进程有且只有一个父进程
 父进程：父进程不需要表示，子进程需要标识
  子进程是要执行任务的，父进程需要区分子进程，子进程不需要
    
    子进程相关性息拷贝自父进程，形成子进程对应的数据结构
    task_struct连接到系统的进程列表中
    
```

 

为何要写时拷贝：

1.进程具有独立性

2.子进程不一定会使用父进程的所有数据，写入本质是需要的时候，按需分配

延时分配：本质，可以高效使用任何内存空间



fork失败的原因：

1.系统中有太多的进程

2.用户实际的进程数量超过了限制



进程终止

```cpp
#include<stdio.h>
int main()
{
    int a=0;
    int b=0;
    int c=a+b;
    return 0;
}
```

main函数有返回值：main函数也是函数，程序运行时main函数是入口，由操作系统进行调用，返回值返回给操作系统，运行程序本质是加载，形成进程

目的：为了完成某种工作，

1.代码跑完结果对

2.代码跑完结果不对

3.代码没有跑完,程序退出(进程奔溃)

通过进程退出码判断进程是否正常退出

```shell
echo $?：查看最近一次进程退出时的退出码
```

退出码的0与!0：

退出码(0):seccess

0：只有一种情况

!0：失败却有很多种原因

man 3 strerror

```cpp
#include<stdio.h>
#include<string.h>
int main()
{
    for(int i=0;i<100;i++)
    {
        printf("%d :%s",i,strerror(i));
    }
}
```

每种退出码都有对应的字符串含义，帮助用户确认认为失败的原因





exit:

_exit:和exit几乎没有差别

差别：exit会释放进程曾经占用的资源，比如缓冲区

_exit直接结束进程，不会进行其它操作



进程异常退出

```cpp
while(1)
{
    printf(".\n");
}
ctrl+c，异常进程终止
 
    int*p;
	*p=100;

```

进程异常退出了，进程退出码就没有意义了

进程终止了，操作系统释放曾经申请的数据结构，释放曾经申请的内存，从各种队列数据结构中移除



进程等待：为了回收子进程资源，获取子进程退出信息

通常由父进程完成

一个进程一旦变成僵尸进程，无法杀死

wait方法：

pid_t wait(int status)

返回值：子进程的id

```cpp
#include<sys/wait.h>
#include<sys/types.h>
int main()
{
    pid_t id=fork();
    if(id==0)
    {
     	int count=0;
        while(count<5)
        {
            printf("I am child,pid:%d,ppid:%d\n",getpid(),getppid());
            count++;
            sleep(1);
        }
        exit(0);
    }
    else
    {
        printf("I am father,pid:%d,ppid:%d\n",getpid(),getppid());
        pid_t ret=wait(NULL);
        if(ret>=0)
        {
            printf("wait child success,%d\n",ret);
        }
        printf("FAather run.....\n");
        Sleep(10);
    }
}
```

在子进程运行期间，父进程在wait的时候，父进程在做什么？，就是在”等“子进程退出

“等”的过程叫做阻塞等待

父子谁先运行不确定，但是wait之后，大部分情况都是子进程先退出，父进程读取子进程退出信息后退出

waitpid（pid_t pid,int*status,int options）;

pid

```cpp
#include<sys/wait.h>
#include<sys/types.h>
int main()
{
    pid_t id=fork();
    if(id==0)
    {
     	int count=0;
        while(count<5)
        {
            printf("I am child,pid:%d,ppid:%d\n",getpid(),getppid());
            count++;
            sleep(1);
        }
        exit(0);
    }
    else
    {
        printf("I am father,pid:%d,ppid:%d\n",getpid(),getppid());
        int status=0;
        pid_t ret=waitpid(id,&status,0);
        if(ret>=0)
        {
            printf("wait child success,%d\n",ret);
            printf("child exit:%d\n",(status>>8)&0xFF);
        };
                    printf("child get signal:%d\n",status&0x7F);
        }；
        printf("FAather run.....\n");
        Sleep(10);
    }
}
```

等待成功，不意味着子进程运行成功

等待成功只意味着子进程退出了，不意味着子进程运行成功

status：退出结果

次低8为代表进程退出时的退出码

低7位代表进程退出时的退出信息(信号)

(status>>8)&0XFF

进程异常的时候本质是进程运行的时候出现了某种错误，导致进程收到信号

```cpp
int main()
{
    pid_t ids[10];
    for(int i=0;i<10;i++)
    {
        pid_t id=fork();
        if(id==0)
        {
            while(10--)
            printf("child do sumething:pid%d",getpid,getppid);
        }
        exit(i);
        ids[i]=id;
    }
    int count=0;
    while(count<10)
    {
        int status=0;
        //批量化wait
        pid_t ret=waitpid(ids[count],&status,0);
        
        
        count++;
    }
}
```

```
WIFEXITED(status):查看进程退出时的信号
WEXITSTATUS(status):查看退出码
```

非阻塞等待

```cpp

int main()
{
    pid_t id=for();
	if(id==0)
    {
        int count=0;
        while(cout<10)
        {
            printf("I am child,pid:%d,ppid%d",getpid(),getppid());
            sleep(1);
            count++;
        }
        exit(1);
    }
    while(1)
    {
        int status=0;
        pid _t ret=waitpid(id,&status,WNOHANG);
        if(ret>0)
        {
            printf("watit success\n");
            printf("exit codfe:%d",WEXITSTATUS(staus));
            break;
        }
        else if(ret==0)
            //子进程没有退出，等待是成功的
            printf("father do   other thing ret:%d\n",ret);
        else
        {
            printf("waitpid 
                  error\n");
                   break;
        }
    }

    return 0;
}
```

```
WNOHANG:
ret=waitpid(id,&status,WNOHANG);
ret==0,当前子进程还没有退出
```

进程程序替换

替换原理：

int execl(const char//*path,const char*  arg,...)

execl(程序路径(包含可执行程序)，代表选项)

```cpp
int main()
{
    printf("I am a process!\n");
    sleep(5);
   // execl("/usr/bin/ls","ls","-a","-i","-l",NULL);
    / execl("/usr/bin/top","top",NULL);
    //不会看到这句话
    printf("you can see me!\n");
    
}
```

当前进程在进行程序替换时，没有创建进程，是发生了进程程序替换

进程程序替换，一经替换，决不返回，后续代码不会执行

程序替换可能失败，程序后续并不会受到影响

execl系列的函数，根本不需要判断返回值，只要返回，就是失败

```cpp
int mainI()
{
    piud_t id=fork();
    if(id==0)
    {
        printf("I am a process\n");
        execl("/usr/bin/top","top",NULL);
        exit(10);
    }
    else
    {
        int status=0;
        pid_t ret=waitpid(id,&status,0);
        if(ret>0)
        {
            printf("signal:%d\n",status&)X7F;
            printf("exit code:%d\n",(status>>8)>>0xFF);
        }
    }
}
```

execlp(命令)：不需要写路径,在环境变量path中寻找

```cpp
excelp("ls","-a"，NULL);
```

execv:v代表数组

```cpp
char*myargv[]={"ls","-a","-i","-l",NULL};
execv("/usr/bin/ls",myargv);
```

execlvp:不需要写路径

```cpp
char*myargv[]={"ls","-a","-i","-l",NULL};
execlvp("ls",myargv);
```

execve/execle:两者没有本质区别





```makefile
Makefile只能生成从上到下所遇到的第一个程序
exec:wxec.c
	gcc -o $@ $^


```

```cpp
int main()
{
    printf("I am s new exe,mycmd\n");
    
}
```

make cmd

```makefile
make生成多个可执行程序
.PHONY:all
all:exec cmd
exec:exec.c
	gcc -o $@ $^
cmd:cmd.c
	gcc -o $@ $^
.PYONY:clean
clean:
	rm -rf *.o cmd exec
```

```cpp
int main()
{
    execl("./cdm");
}
```

```cpp

execl("./test.sh","test.sh");
```

```cpp
char*myenv[]={"MYENV=HELLO",NULL};

execl("./cmd","cmd",NULL,myenv);
```



基础IO

复习C语言io相关操作

认识文件系统调用接口

认识文件描述符。理解重定向

杜比fd,FILE,理解系统调用和库函数的关系

理解文件系统中的inode的概念



C语言文件操作

```cpp
#include<stdio.h>
#include<unistd.h>
#include<
using namespace std;
int main()
{
   FILE*fp=fopen("test.txt","r");
    //在当前路径创建文件：进程运行时所处的路径，
    if(fp==NULL)
    {
        perror("fopen");
        return 1;
    }
    //打开文件，一定是进程运行时打开的，
   // int count=10;
    //while(count--)
    //{
      //  fputs("hello world\n",fp);
    //}
    int ct=10;
    char buf[1024];
    while(count--)
    {
        fgets("buf",1024,fp);
        printf("%s",buf);
    }
    
    
    
    fclose(fp);
    
}
```

读写，关闭，打开都是进程完成的

任何进程在运行的时候，默认打开三个输入输出流

stdin:键盘

stdout:屏幕

stderr:显示器

extern FILE*stdin

extern FILE*stdout

extern FILE*stderror

```cpp
FILE*fp=fopen("log.txt","a");//a:append
//a:追加也是写入
w vs a:都是写入，w从开始写入，a从结尾追加
```

```
r+:
w+:
```

系统IO：

```cpp
#include<stdio.h>
#include<sys/types>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    umask(0);
    int fp=open("log.txt",O_WRONLY|O_CREAT,0666);
    //fd>0代表创建成功了
    if(fd<0)
    {
        return 1;
    }
    int ct=5;
    const char*str="hello";
    while(ct--)
    {
        write(fd,str,strlen(str));
    }
    
     printf("%d",fd);
    close(fd);
    return 0;
}
```

系统函数参数传参标志位：int 32bit,故理论上可以传递32个标志位

//二进制序列中，只有一个比特位是1

#define x 0x1

#define Y 0x2

open(arb1,arg2=x|y,arg3);



文件描述符本质是数组下标

```cpp
int main()
{
    const char*str="hello";
    write(1,str,strlen(str));
    char buf[32];
    read(0,buf,)
}
```

Linux默认打开三个文件描述符

一个进程可以打开多个文件

多个进程

系统中，任何时刻都可能存在大量已经打开的文件

文件有几部分构成：文件的属性(元信息)

文件=内容+属性

```cpp
int main()
{
    int fd=open("log.txt",O_WRN);
    if(fd<0)
    {
        return 1;
    }
    
    return 0;
}
```

重定向本质是:

文件描述符fd下标对应的struct File*指针，

```
open返会成功会返回文件描述符，失败返回-1
头文件如下：
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
O_WRONLY:只写
O_RDONLY:只读
O_WRRD:可读可写
//上述三个选项只能选择一个
O_CTREAT:如果文件不存在则创建文件

```



```
ssize_t read(int fd,void*buf,size_t count);
read返回值是读到字符的个数
fd:打开文件时得文件描述符
buf:文件缓冲区，将读到的文件内容保存到buf中
count:期望读到多少个字符
```



```
ssize_t write(fd,const void*buf,ssize_t count);
fd:打开文件时得文件描述符
buf:要写的东西
count:buf的长度（字节）

```





```cpp
//重定向myproc.c
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    umask(0);
    close(1);
    //fd=1;
	int fd=open("log.txt",O_WRONLY|O_CREAT,0666);
    if(fd<0)
    {
        perror("open");
        return 1;
    }
    printf("hello world\n");//stdout内部封装了
    fprintf(stdout,"hello fprintf\n");
    fputs("hello fputs %d %d %c\n",stdout);
    fflush(stdout);
    
    close(fd);
    return 0;
}
```

C语言FILE是一个结构体，内部封装了fd

fopen:

1.给用户申请struct FILE结构体变量，并且返回地址

2.在底层通过open打开文件，返回fd，吧把fd填充到FILE变量中的fileno

```cpp
//输入重定向myproc.c：
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    umask(0);
    close(0);
    //fd=1;
	int fd=open("log.txt",O_RDONLY|O_CREAT,0666);
    if(fd<0)
    {
        perror("open");
        return 1;
    }
  //  printf("hello world\n");//stdout内部封装了
   // fprintf(stdout,"hello fprintf\n");
    //fputs("hello fputs %d %d %c\n",stdout);
    char*buf[100];
    fgets(,buf,100,stdin);
    printf("%s",buf);
    fflush(stdout);
    
    close(fd);
    return 0;
}
```

```
echo "hello ">>log.txt
```



```cpp
//追加重定向myproc.c：
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    umask(0);
    close(0);
    //fd=1;
	int fd=open("log.txt",O_WRONLY|O_APPEND);
    if(fd<0)
    {
        perror("open");
        return 1;
    }
  //  printf("hello world\n");//stdout内部封装了
   // fprintf(stdout,"hello fprintf\n");
    //fputs("hello fputs %d %d %c\n",stdout);
    char*buf[100];
    fgets(,buf,100,stdin);
    printf("%s",buf);
    fflush(stdout);
    
    close(fd);
    return 0;
}
```



凡是显示到显示器上的内容，都是字符

凡是从键盘上读取的内容都是字符

所以键盘和显示器都被称为字符设备



vim 中格式化替换

后面加/g:全部替换

![image-20211011193824035](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211011193824035.png)

缓冲区的概念：

```cpp
#include<unistd.h>
int main()
{
    //先炮hello world,但是hello wolrd被保存到了缓冲区，没有刷新出来，没有立马显示出来，加“\n"
    printf("hello world");
    sleep(10);
}
缓冲：
    1.无缓冲
    2.行缓冲：常见的是对显示器进行刷新数据时(效率和可用性的平衡)
    3.全缓冲：对文件写入的时候采用全缓冲;


int main()
{
    printf("hello \n");
    fprintf(stdout,"helllp\n");
    
    //fflush(stdout);
    const char*str="helll write\n ";
    write(1,str,strlen(str));
    fork();
    sleep(10);
}
./test>log.txt;
//打印了2遍内容：重定向还是会改变进程的缓冲方式，c接口打了2次，系统接口打了1次，
//显示器打印：行刷新
//父进程的数据发生写实拷贝，所以i打印了2次
//write打印一次：说明write没有缓冲区

//如果缓冲区是操作系统提供的，则所有接口都要打印两次，故缓冲区是C语言自带的
缓冲区的位置：
    内存
缓冲区是谁提供的：
    语言提供的，在FILE中维护
Os也有缓冲吗：
 
struct FILE：
    1.fd
    2.用户缓冲区
```





dup2系统调用

```cpp
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    printf("hello printf\n");
    fprintf(stdout,"hello fprintf\n");
    
}
```



所有的外设硬件，都有自己的读写方法



```cpp
//重定向
int dup2(fd,1)
#include<unistd.h>

int main()
{
    int fd=open("log.txt",O_WRONLY|CREAT,0666);
    close(1);
    dup2(fd,1);
    printf("hello world\n");//stdout内部封装了
    fprintf(stdout,"hello fprintf\n");
    fputs("hello fputs %d %d %c\n",stdout);
    fflush(stdout);
    
    return 0;
}
```

  



miniShell中添加重定向

```

```

创建进程时,

子进程会继承父进程打开的文件信息

进程替换不会影响进程打开的文件



inode编号：

```
ls -i
```

1.内存文件：

2.磁盘文件：

文件=内容(之际存储到磁盘block)+属性(元信息，inode存储)

inode是任何一个文件的属性集合，Linux中几乎每一个文件都有一个inode,

Linux将属性与内容进行分离存储

inode是任何一个文件的属性集合，Linux中几乎每一个文件都有一个inode，所以为了区分inode，用inode编号

  文件=inode+内容

inode=128字节/256字节

 



文件系统：

1.什么是磁盘

几乎是唯一的一个机械设备

请描述创建一个文件的过程以及写入1kb文件的过程

先找到test.c的inode，直到Datablocks,申请空间，写入文件

描述删除一个文件是干什么

删除inode对应的位图，置为1

inode bitmap

block bitmap

拷贝文件的时候慢

删除文件的时候快

删除文件，为何可以恢复



如何理解目录以及目录创建的过程

目录也是一个文件，也有自己的inode，

内容放的是：当前目录下文件名：对应文件的inode指针(inode号)，

1.文件名并没有在inode中保存，包括目录本身

2.目录里面放的是文件和inode编号，建立映射[文件名----->inode编号]是数据

目录也是文件，也有inode属性(inode编号)也有内容



软硬连接：

区别：

1.软连接是一个独立的文件，有自己的inode,硬链接没有独立的inode

2.软连接相当于快捷方式，硬链接本质没有创建文件，只是建立了文件名和已有的inode的映射关系，并入到当前目录，相当于给文件取别名

```
软连接：
ln -s mytest test-s
```

```
硬链接：
方便目录之间通过. ..进行访问
ln mytest mytest-h
```



进入目录需要：x权限

```
动静态库本质是可执行程序的"半成品"
静态库：.a

动态库：.so

```











进程间通信

进程间通信的目的：进行数据传输，将一个进程的数据发送到另外一个进程

资源共享：

通知事件：一个进程向另一个进程发送消息

进程控制：有些进程希望完全控制另外一个进程的执行





```cpp
touch 
```



进程一般具有独立性

进程间通信，一般一定要借助第三方(OS)资源

通信本质是”数据的拷贝“，进程A------->数据拷贝到OS------->OS数据拷贝到进程B

(OS一定提供一段内存区域，能够被双方进程看到)

进程间通信本质然不同的进程先看到同一份资源(内存，文件内核缓冲等)



管道用的是文件策略，但是不会把文件刷新到磁盘，有IO存在，会降低效率，也没有必要



```
匿名管道:本质没有文件名
管道只能进行单向通信
原型：int pipe(int fp[2]);
fd为输出型参数
```



```cpp
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h
#include<sys
using namespace std;
int main()
{
    
    return 0;
}
```

1.父进程创建管道

2.父进程fork出子进程：

本质是为了让父子进程看到同一份资源

3.确认谁读谁写，关闭读写端，父进程进行读，子进程负责写数据

fd[0]:读文件描述符

fd[1]:写端文件描述符

```cpp
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
//子进程写入，父进程进行读取
int main()
{
    int fd[2]={0};
    pipe(fd);
    if(pipe<0)
    {
        perror("pipe");
        return 1;
    }
    //默认打开0，1，2文件描述符
   printf("fd[0]:%d,fd[1]:%d\n",fd[0],fd[1]);
    pid_t id=ork();
    if(id==0)
    {
        close(fd[0]);
        int count=10;
        while(count--)
        {
            write(fd[1],"hello father\n",sizeof("hello father\n"));
            sleep(1);
        }
        close(fd[1]);
        exit(0);
    }
    else
    {
        close(fd[1]);
        char buf[1024];
        while(1)
        {
           ssize_t s=  read(fd[0],buf,1024);
            if(s>0)
            {
                buf[s]='\0';
               printf("%s\n",buf);
            }
            //文件结尾
            else if(s==0)
            {
                printf("read file end!\n");
                break;
            }
            else
            {
                break;
            }
            
        }
        waitpid(id,NULL,0);
        
    }
    
    return 0;
}
```

父子进程通信不可以通过创建全局缓冲区完成通信

父进程，进程运行具有独立性，写时拷贝对全局变量做的修改子进程看不到



多执行流下(父子)，看到同一份资源，临界资源

同步与互斥：

互斥：任何适合只能够有一个正在使用某种资源

1.管道内部已经自动提供了互斥与同步机制

```cpp
#include<stdio.h>
int main()
{
    while(1)
    {
        printf("a\n");
        
    }
    return 0;
}
```

如果写段关闭，读端就会read返回值0，代表文件结束

3.如果打开文件的进程退出了，文件就会被关闭



4.管道提供流式服务

5.管道是半双工通信

6.匿名管道，适合具有血缘关系的进程进行进程间通信，常用于父子间通信



全双工：

半双工：(人在正常沟通过程中)管道

read:管道里面必须有数据

write:管道里面必须有空间

不满足上面两个条件对应进程进会被挂起

```
不write，一直read,read阻塞
不read,一直write，write阻塞
write写完，关闭，read返回值为0
read关闭，一直写，写方(child)被操作系统杀死，写入无意义
```

管道的容量：

```cpp
//测试管道容量的代码
if(id==0)
{
    int count=0;
    char a='a';
    while(1)
    {
        write(fd[1],&a,1);
        count++;
    }
}
//测试容量为:65536字节
```

命名管道:实现非父子关系进程的通信

通过名字打开同一个文件，看到同一份资源，具备通信的条件

```makefile
首先建立文件：mkfifo fifo;
//p:命名管道
touch client.c server.c;
vim Makefile;
.PHONY:all
all:client sever
client:client.c
    gcc -o $@ $^
sever:sever.c
    gcc -o $@ $^
.PHONY:clean
clean:
	rm -rf server client
```

sever.c

```cpp
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
using namespace std;
#define "myfifo"
int main()
{
    if(mkfifo("myfifo",0644)<0)
    {
        perror("mkfifo");
        return 1;
    }
    
    return 0;
}
```

client.c

```cpp
#include<stdio.h>
int main()
{
    printf("hello\n");
    return 0;
}
```

