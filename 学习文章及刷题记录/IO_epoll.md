五种IO模型

阻塞IO：在内核将数据准备好之前，系统调用会一直等待，所有的套接字，默认都是阻塞方式

 非阻塞IO:内核没有准备好数据，内核任然会返回EWOULDBLOCK，

数据准备好则读取数据

所谓的阻塞，是用户层的感觉，再内核中的本质是进程被挂起，需要某种时间就绪，所谓的阻塞由OS发起，由OS执行

所谓的非阻塞轮询的本质是什么？在做事件的就绪检测工作，等待数据就绪，由用户发起，OS执行

信号驱动IO：内核将数据准备好的时候，使用SIGIO信号通知应用程序进行IO操作

异步IO：内核在数据拷贝完成时，通知应用程序

IO多路转接：select/poll/epoll

​				

将文件描述符设置为非阻塞模式

```cpp
#iinclude<unistd.h>
#include<fcntl.h>
int fcntl(int fd,int cmd,....);

//设置网络套接字位非阻塞模式步骤：
int fl=fcntl(fd,F_GETFL);
fcntl(fd,F_SETFL,fl|NONBLOCK);
```

```
设置标准输入位非阻塞模式
然后利用read进行读取

```

![image-20220423164738920](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220423164738920.png)

如果搓出哦了，errno(全局变量)被设置

如果非阻塞读取数据的时候数据没有就绪，read是以出错的新式返回

进一步可以通过errno进行判断（errno==EAGNINE||errno==EWOULDBLOCK）

读取时被信号终止：errno==EINTR;



epoll两种工作方式：水平触发(LT)和边缘触发(ET)

 epoller.hpp

```cpp
#include<string>
typedef int(*callback_t)(EventItem*);//const&输入，*：输出，&输入输出
class Epoller;
class EventItem
{
  	public:
    
    int sock;
    //回指Epoller
    Epoll*R;
    //有关数据处理的回调函数，用来进行逻辑解耦，应用的数据就绪等细节和数据处理模块进行使用该方法进行解耦
    callback_t recv_handler;
    callback_t send_handler;
    callback_t error_handler;
    std::string inbuffer;//读取到的数据缓冲区
    std::string outbuffer;//待发送的数据缓冲区
    
    public:
    EventItem():sock(0),R(nullptr),recv_handler(nullptr),send_handler(nullptr),error_handler(nullptr)
    {
        
    }
    
    //管理回调
    void MangerCallBack(callback_t recv,callback_t send,callback_t err)
    {
        recv_handler=recv;
        send_hadnler=send;
        error_handler=err;
    }
    
  
    
    ~EventItem()
    {
        
    }
};

class Epoller
{
    private:
    int listen_sock;
    int epfd;
    uint16_t port;
    std::unordered_map<sock,EventItem>event_items;//map影射
    public:
    
    
    void InitEpoller()
    {
        if(epfd=epoll_create(256)<0)
        {
            cerr<<"epoll create error"<<endl;
            exit(0);
        }
    }
    
    
    void AddEvent(int sock,uint32_t event,EventItem&item)
    {
        struct epoll_event ev;
        ev.events=0;
        ev.events|=event;
        ev.data.fd=sock;
        if(epoll_ctl(epfd,EPOLL_CTL_ADD,sock,&ev)<0)
        {
            std::cerr<<"epoll_ctl error!"<<endl;
        }
        else
        {
            
            event_items.insert({sock,item})
        }
    }
    
    
    void DelEvent(int sock)
    {
        if(epoll_ctl(epfd,EPOLL_CTL_DEL,sock,nullptr)<0)
        {
            cerr<<"epoll ctl error"<<endl;
        }
        event_items.erase(sock);
    }
    
    //事件分派器
    void Dispatch(int timeout)
    {
        //如果底层事件就绪，
        struct epoll_event revs[MAX_NUM];
        int num=epoll_wait(epfd,revs,MAX_NUM,timeout);
        for(int i=0;i<num;i++)
        {
            int sock=revs[i].data.fd;
            
            //读事件就绪
            if(revs[i].event&EPOLLIN)
                if(event_items[sock].recv_handler)
                    event_items[sock].recv_handler(&event_items[sock]);//读取回调被设置，调用读回调，进行数据读取
            if(revs[i].event&EPOLLOUT)
                if(event_items[sock].send_handler)
                    event_items[sock].semd_handler(&event_items[sock]);
            
            if(revs[i].events&EPOLLERR||(revs[i].event&EPOLLHUP))
                if(event_items[sock].error_handler)
                    event_items[sock].error_handler(&event_items[sock]);
            
            
        }
    }
    
    ~Epoller()
    {
        
    }
};


```

server.cc

```cpp
#include"app_interface"
#include"epoller.hpp"
int main()
{
    uint16_t port=atoi(argv[1]);
    
    //与listen_sock有关的
    int listen_sock=Sock::Socket();
    SetNonBlock(listen_sock);
    Sock::Bind(listen_sock,potr);
    Sock::Listen(listen_sock,back_log);
    
    //与epoller事件管理器有关的
    Epoller epoller;
    epoller.InitEpoller();
    EventItem item;
    item.sock=listen_sock;
    item.R=&epoller;
    
    //listen只需要关心读事件就行
    //accepter函数Todo
    item.MangerCallBack(accepter,nullptr,nullptr);
    //将我们的listen_sock托管给epoller
    epoller.ADdEvent(listen_sock,EPOLL|EPOLLET,item);
    int timeout=1000;
    while(true)
    {
        epoller.Dispatcher(timeout);
        
    }
}
```

touch app_interface.hpp

```cpp
#pragma once
#include"epoll_server.hpp"
#include""
#include<iostream>

int accepter(EventItem*item)
{
    std::cout<<"监听套接字"<<endl;
    std::cout<<"get a new link:"<<item->sock<<endl;
    while(true)
    {
        struct sockadd_in peer;
        socklen_t len=sizeof(peer);
        int sock=accept(item->sock,&peer,&len);
        
        if(sock<0)
        {
            if(errno==EAGAIN||errno==EWOULDBLOCK)
            {
                //底层没有连接了
                return 0;
            }
            if(errno==EINTR)
            {
                //读取过程被信息打断了
                continue；
            }
            else
            {
                //出错了
                return -1;
            }
            
        }
        else
        {
            //读取成功了
            EventItem tmp;
            tmp.sock=sock;
            tmp.R=item->R;
            tmp.MangerCallBack(recver,sender,error);
            Epoller*epoller=item->R;
            SetNonBlock(sock);
            epoller->AddEvent(sock,EPOLLIN|EPOLLET,tmp);
        }
   
    }
    return 0;
}

int recver(EventItme*item)
{
    //负责数据读取
    
}

int sender(EventItem*item)
{
    //发送数据
}


int sender(EventItem*item)
{
    
}
```

util.hpp

```cpp
#include<iostream>
#include<unistd.h>
#include<fcntl.h>

void SetNonBlock(int sock)
{
    int fl=fcntl(sock,F_GETFL);
    fcntl(sock,F_SETFL,fl|O_NOBLOCK);
}
```

