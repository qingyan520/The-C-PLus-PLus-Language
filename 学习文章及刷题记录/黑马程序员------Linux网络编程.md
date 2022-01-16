黑马程序员------Linux网络编程

![image-20210926170619437](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210926170619437.png)

以太网帧协议：借助mac地址完成数据报传递

mac地址：网卡编号(ifconfig可以看到)

arp协议：根据IP地址获取mac地址

网络层：IP协议

IP段格式：

4位版本：ipv4,ipv6

8位生存时间(TTL):最多能经过多少跳

32位源IP地址：数据发送端地址

32位目的IP地址：数据接收端地址

 传输层：
UDP协议：

16位端口号：对应一个进程

16位目的端口

2^16次方：端口号的最大值：65535

 

TCP

16位源端口

16位目的端口

32位序号

32位确认序号

6个标志位

16个滑动窗口 

 

tcp,udp传输层协议

tcp:面向连接的安全的流式传输协议

​       连接的时候进行三次握手

​        数据发送的时候会进行数据的确认

​            数据丢失止之后，会进行数据的重传

udp:面向无连接的不安全的报式传输

​        连接时不会握手

​		数据发送出来就不管了

​         如果数据包丢了会全丢

socket编程：

socket式网络通信的接口，里面封装了传输层协议(TCP/UDP)



IP+端口可以访问特定进程

socket编程-----网络IO编程

-读写操作：read/write

创建一个套接字，得到的是文件描述符

管道------内核缓冲区，内存中的一块存储空间

写缓冲区

读缓冲区



TCP三次挥手

 

```cpp
socket();
if(argc<2)
{
    exit(-1);
}
int port=atoi(argv[1]);
int  fd=socket(AF_INET,SOCK_STREAM,0);
//连接服务器
struct socket_in setv;
serv.sin_family=AF_INET;
serv.sin_port=htons(port);
serv.sin
```

TCP三次握手

标志位：

SYN：请求建立连接

ACK：应答

FIN：断开连接的标志位

连接需要三次握手

客户端发起连接请求，携带SYN+32位的序号(随机产生)，可以携带数据

服务器端：

检测SYN的值是否为1，为1代表第一次握手成功，回复ACK



client_tcp.c

```cpp
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<arpa/inet.h>
int main(int argc,char*argv[])
{
    if(argc<2)
    {
        printf("");
        exit(1);
    }
    int potr=atoi(arga[1]);
    //创建套接字
    int fd=socket(AF_INET,sock_STREAM,0);
    //绑定服务器
    struct sockadddr_in serv;
    serv.sin_family=AF_INET;
    serv.sin_Port=honts(port);
    servv.sin_addr.s_addr=h
    
}
```

