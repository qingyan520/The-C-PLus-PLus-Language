```
pifod Server;
//找到Server 对应的进程pid
```



传输层：



Udp协议

无连接

不可靠：没有

1.udp如何



Tcp协议：传输控制协议

确认应答机制

报文的有序也是可靠性的一种

确认序号(n),是对应的的32为序号+1，代表告知对方，你给我的n个字节之前的n个字节我已经收到了，下次从n+1开始发送

tcp是具有接受和发送缓冲区的

write/send将数据拷贝到缓冲区，

16位窗口大小：填充的是自身的接收缓冲区中剩余空间的大小(这样就支持流量控制)

tcp16位校验和：校验报文是否传输正确



三次握手

SYN：

ACK+SYN

一般而言ACK字段是被经常设置的，只有在连接建立阶段，SYN被设置

ACK

1.三次握手属于通信细节，上层用户不需要关心

双方OS自动完成

2.connect()->发起三次握手，accept()获取已经建立好的连接，已经完成三次握手的连接

四次挥手

FIN

ACK

FIN

ACK

存在很多的客户端连接server：a.面向链接是tcp可靠性的一种

b.OS要管理连接？？先描述在组织



URG：紧急指针是否有效

PSH：尽快把缓冲区数据交付给上层

 

建立连接是3次握手，但是不是100%成功

client认为自己建立连接成功是在发出最火一个ACK，不管对方是否收到，都认为自己建立好了连接

server来讲自己收到ACK时才完成了三次握手，建立连接成功

client和server认为建立连接成功是有时间差的

ACK丢失：client认为连接已经建立好了，server认为连接建立还没有完成

怎么办？

连接建立好—->发送数据——>server(tcp:RST)

连接双方有问题时可以适合用RST进行连接重置





确认应答机制

超时重传

  



1.全双工协议，连接建立的核心药物，首先要检验双方的通信信道是联通的

三次握手是验证双方通信信道的最小次数

2.连接建立异常的情况下，一定建立的链接是在client端

谁最后发送ACK，谁就先维护链接

如果是偶数次建立链接，最后的异常链接一定是挂在server端，占用大量服务器资源

![image-20220420191811536](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220420191811536.png)

四次挥手

client—–>Server:FIN

Server—–>Client:ACK

(上面两次挥手代表Client断开连接成功)

Server——>Client:FIN
Client——>Server:ACK

(Server向客户端断开连接)

断开连接的一方，如果是发起的一方，进入FIN_WAIT_1状态

![image-20220420194130995](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220420194130995.png)

为何主动断开的一方在四次挥手之后不会立刻进入close状态？

主动断开连接的一方要短暂的进入time_wait状态

为什么要进行time_wait:

1.可以通过等待，较大概率保证最后一个ACK被对方收到

2.保证双方通信信道上的正常数据在网络中，尽可能的消散

理解time_wait状态







滑动窗口描述的是：发送方不用等待ACK一次所能发送的最大最大量
