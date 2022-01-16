黑马程序员Linux系统编程



子进程被父进程回收、

作用：

1.阻塞等待

2.回收子进程资源

3.查看死亡原因

pid_t wait(int*staus)

status：传出参数

返回值：

1.返回成功，终止子进程id

失败 返回-1   

```cpp
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
    pid_t pid=fork();
    if(pid==0)
    {
        printf("I am child,will die\n");
        sleep(2);
        return 100;
    }
    else if(pdi>0)
    {
        printf("I am parent,wait for child die\n");
        int status;
        pid_t wpid=wait(&status);
        printf("wait ok,wpid=%d,pid=%d\n",wpid,pid);
        //正常死亡
        if(WIFEXITED(status))
        {
            printf("child exit with %d\n",WEXITSTATUS(status));
        }
        //非正常死亡：kill -9
        if(WIFSIGNALED(sstatus))
        {
            printf("child killed by %d\n",WTERMIG(status));
        }
        while(1)
        {
            sleep(1);
        }
    }
    return 0;
}
```

子进程死亡原因：

正常死亡：WIFEXITED

如果WIFECXITED为真，使用WEIXIRSATUS

 

waitpid

```cpp
pid_t waitpid(pid_t pid int*status,int options)

pid :
<-1:组id
-1：回收任意
0：回收和调用组进程id相同组内的子进程
>0:回收指定的pid

options:
0与wait一样，会发生组设
WNOHANG如果当前没有子进程退出，会立刻返回

返回值：
如果设置了WNOHANG，那么没有子进程退出，返回0
如果子进程退出，返回推出的pid

返回失败：
-1
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	 pid_t pid=fork();
    if(pid==0)
    {
        printf("! am child ,pid=%d\n",getpid());
        sleep(2);
    }
    else if(id>0)
    {
        printf("I am parent,pid=%d\n",getpid());
        
       int ret;
        while((ret= waitpid(-1,NULL,WNOHANG))==0)
        {
			sleep(1);
        }
        
        printf("ret=%d\n",ret);
        ret=waitpid(-1,NULL,WNOHANG);
        if(ret<0)
        {
            perror("wait err\n");
        }
        while(1)
        {
            sleep(2);
        }
    }
    return 0;
}
```

用wait回收多个子进程

用waitpid回收多个子进程







进程间通信

IPC：进程间通信，通过内核提供的缓冲区进行数据交换的机制

IPC通信的方式：
pipe:管道----最简单

fifo:有名管道

mmap:文件映射共享IO----速度最快

本地socket-----最快

信号：携带信息量最小

共享内存

消息队列

PIPE通信

![image-20210930185441979](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210930185441979.png)

```
常见的通信方式：单工(广播)，半双工(对讲机)，全双工(打电话)
管道：半双工通信

```

管道的使用

int pipe(int pipefd[2])

pipdfd读文件描述符，0代表读，1代表写

返回值：失败返回-1，成功返回0



```cpp
#include<stdio.h>
int main()
{
    int fd[2];
    pipe(fd);
    pid_t id=fork();
    if(id==0)
    {
        sleep(3);
        write(fd[1],"hello",5);
        
    }
    else if(id>0)
    {
        char buf[12]={0};
        int ret=red(fd[0],buf,size(buf));
        if(ret>0)
        {
            write(STDOUT_FILENO,buf,ret);
            
        }
    }
    return 0;
}
```



父子进程实现pipe通信，实现ps aus| grep bash

```cpp
#include<stdio.h>
#include<unistd.h>
int main()
{
    int fd[2];
    pipe(fd);
    pid_t id=fork();
    if(id==0)
    {
        dup2(fd[!],STDOUT_FILENO);
        execlp("ps","ps","aux",NULL);
    }
    else if(id>0)
    {
        //1.先重定向
        dup2(fd[0],STDIN_FILENO);
        //2.execlp
    execlp("grep","grep","bash",NULL);
    }
    return 0;
}
```

```cpp
#include<stio.h>
#include<unistd.h>
int main()
{
    int fd[2];
    pipe(fd);
    pid_t id=fork();
    if(id==0)
    {
        //子进程
        sleep(3);
        write(fd[1],"hello",5);
    }
    else if(id>0)
    {
        chsr buf[1024]={0};
        int ret=read(fd[0],buf,sizeof(buf));
        //read默认是堵塞的，阻塞等待，不需要等待
            if(ret>0)
            {
                write(STDOUT_FILENO,buf,ret);
            }
    }
    else
    {
        
    }
    return 0;
}
```

父子进程实现pipe通信，实现ps aux|grep bash

```cpp
#include<stdio.h>
#include<unistd.h>
int main()
{
    int fd[2];
    pipe(fd);
    pid_t id=fork();
    if(id==0)
    {
        colse(fd[0]);
        //son--->ps
        dup2(fd[1],STDOUT_FILENO);//标准输出重定向到管道的写端
        execlp("ps","ps","aux",NULL);
    }
    else if(id>0)
    {
        close(fd[1]);
        //1.重定向，标准输入重定向到管道的读端
        dup2(fp[0],SDTIN_FILENO);
      
        //execlp4
        execlp("greP","grep","bash",NULL);
    }
    return 0;
}
```

管道的读写行为

读管道：

1.写端全部关闭：read会读到0，相当于读到文件末尾

2.写端没有全部关闭：

有数据：read读到数据

没有数据：read阻塞 fcntl可以更改为非阻塞



写管道：

1.读端全部关闭：产生一个信号SIGPIPE，程序异常终止

2.读端未全部关闭：

管道已满：write阻塞

管道未满：write正常写入

 

管道的优势与劣势：

优点：简单，

缺点：直接有血缘关系的进程通信

，父子进程单方面通信，如果需要双向通信，需要创建多根管道



FIFO

