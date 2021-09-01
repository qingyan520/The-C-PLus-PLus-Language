# Linux学习记录

## 1.常见指令及权限理解

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
