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
    
    //注册回调函数
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
    
    //我们之前没有设置EPOLLOUT
    void EnableReadWrite(int sock,bool write,bool read)
    {
        struct epoll_event evt;
        evt.data.fd=sock;
        evt.events=(read? EPOLLIN:0 ||(write ? EPOLLOUT:0))|EPOLLET;
        if(epoll_ctl(spfd,EPOLL_CTL_MOD,sock,&evt)<0)
        {
            cerr<<"epoll_ctl_error.fd"<<sock<<endl;
        }
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
            else if(errno==EINTR)
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
            //立即将fd设置为非阻塞模式
            SetNonBlock(sock);
            EventItem tmp;
            tmp.sock=sock;
            tmp.R=item->R;
            tmp.MangerCallBack(recver,sender,error);
            Epoller*epoller=item->R;
            //epoll经常会设置读时间就绪，而写时间是按需打开！
            epoller->AddEvent(sock,EPOLLIN|EPOLLET,tmp);
        }
   
    }
    return 0;
}

//0代表读取成功，返回值为-1代表读取失败
int recver_helper(int sock,string*out)
{
    while(true)
    {
        char buf[128]={0};
        ssize_t size=recv(sock,buf,sizeof(buf)-1,0);
        if(size<0)
        {
            if(errno==EAGNIN||errno==EWOULDBLOCK)
            {
                //循环读取读取完毕
                return 0;
            }
            else if(errno==EINTR)
            {
                //被信号中断继续读取
                continue;
            }
            else
            {
                //真正读取出错了
                return -1;
            }
        }
        else
        {
            buffer[size]=0;
            *out+=buffer;//将读取到的内容添加到outbuf中
        }
    }
}

int recver(EventItme*item)
{
    std::cout<<"recv event ready:"<<item->sock<<endl;
    //负责数据读取
    
    //1.需要整体读，非阻塞
    if(recver_helper(item->sock,&item->inbuffer)<=0)
    {
        //item->error_handler;
        return 0;
    }
    cout<<"client#"<<item->inbuffer<<endl;
    //2.根据发来的数据流，进行包与包之间的分离，防止粘包问题,这里是涉及到协议定制
    vector<string>messages;
    util::String::Split(item->inbuffer,messages,"X");
    //3.争对一个一个的报文协议反序列化
    
    
    
    //4.业务处理
    //5.形成响应报文，转化为字符串encode
    //6.将数据写回
    item->outbuf+=response;
    if(item->outbuffer.empty())
    item->R->EnableRendWrite(item->sock,true,true);
}

//0:成功
//1：error

int send_er_helper(int sock,std::string&in)
{
    
}
int sender(EventItem*item)
{
     
    //发送数据
    
}


int error(EventItem*item)
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
class StringUtil
{
  public:
    static void Split(strint &in,std<vector>*out,string sep)
    {
        while(true)
        {
      		size_t pos=in,find(sep);
            if(pos==string::npos)
            {
                break;
            }
            string s=in.substr(0,pos);
            cout->push_back(s);
            in.erase(0,pos+sep.size());
        }
    }
};
```

ET模式为什么要用非阻塞模式读

基于Reactor的半同步半异步的工作方式

 

```
App_Interface.hpp: Reactor.hpp ThreadPool.hpp
Log.hpp
Main.cc: App_Interface.hpp
Protocol.hpp: Util.hpp
Reactor: TcpServer.hpp
Task.hpp: Protocol.hpp
TcpServer.hpp: Util.hpp
ThreadPool.hpp: Task.hpp
Util.hpp: Log.hpp
```



```
#pragma  once                                                                                                                                                                                  
   #include"Reactor.hpp"
   
  #include"ThreadPool.hpp"
   
   int  Disposer(EventItem*item);
   int Accepter(EventItem*item)
   {
     std::cout<<"get a new lint:"<<item->sock<<endl;
    while(true)
    {
      struct sockaddr_in peer;
      socklen_t len=sizeof(peer);
      int sock=accept(item->sock,(struct sockaddr*)&peer,&len);
    
      if(sock<0)
      {
        if(errno==EAGAIN||errno==EWOULDBLOCK)
        {
          //底层没有连接了
          return 0;
        }
        else if(errno==EINTR)
        {
          continue;
        }
        else
        {
          return -1;
        }
      }
      else
      {
        //读取成功了，首先设置套接字为非阻塞模式
        Util::SetNonBlock(sock);
        EventItem tmp;
        tmp.sock=sock;
        tmp.R=item->R;
        tmp.MangerCallBack(Disposer);
       Reactor*reactor=item->R;
        reactor->AddEvent(sock,EPOLLIN|EPOLLET,tmp);
      }
    }
  }
  
  int Disposer(EventItem*item)
  {
    Task t(item->sock);
    ThreadPool::getinstance()->Push(t);
  
  }

```

![image-20220424150624826](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220424150624826.png)
