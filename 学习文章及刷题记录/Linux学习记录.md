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

  

