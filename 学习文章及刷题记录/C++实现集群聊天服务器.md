C++实现集群聊天服务器

技术栈

Json序列化和反序列化

muduo网络库开发

nginx源码编译安装和环境部署

nginx的tcp负载均衡器配置

redis缓存服务器编程

基于发布——-订阅的服务器中间件redis消息队列编程实践

Mysql数据库编程

CMake构建项目编译环境

Github托管项目



项目需求

1.客户端新用户注册

2.客户端用户登录

3.添加好友和群组

4.好友聊天

5.群组聊天

6.nginx配置tcp负载均衡

7.集群聊天系统支持客户端跨服务器通信



项目目标

1.掌握服务器的网络I/O模块，业务模块，数据模块分层的设计思想

2.掌握C++muduo网络课的编程以及实现原理

3.掌握Json的编程应用

4.掌握nginx配置部署tcp负载均衡器的应用和原理

5.掌握中间件应用场景和基于发布——订阅的服务器中间件redis消息队列编程实



json示例代码

```cpp
	void func3()
	{
		json js;
    	js["id"]="hello";
        
        string sendbuf=js.dump();
	}
```

json的反序列化

```cpp
	string recvbuf=func3();
	//从json字符串反序列化 数据对象		 
	json js =json::parse(recvbuf);
	cout<<js["msg_type"]<<endl;
	
```





muduo网络库编程

/usr/lib

/usr/local/lib

muduo库需要连接 libmuduo_base libmuduo_net.so libpthread.so

-lmuduo_net    -lmuduo_base    -lpthread

```cpp
//muduo网络库给用户提供了两个主要的类，
//TcpServer:用于编写服务器程序的
//TcpClient:用于编写客户端程序
//能够把网络I/O的代码和业务代码区分开
//用户的连接和断开     用户的可读写事件
#include<muduo/net/TcpServer.h>
#include<muduo/net/Eventloop.h>
#include<iostream>
#include<functional>
#include<string>
using namespace std;
using namespace muduo::net;
using namespace placeholders;
//基于muduo开发服务器程序
//1.组合TCPServer对象
//2.创建EventLoop事件循环对象的指针
//3.明确TcpServer构造函数需要什么参数，输出ChatServer的构造函数
//4.当前服务器类的构造函数中，注册处理连接的回调函数和处理读写事件的回调函数
//5.设置合适的服务端线程数量，muduo会自己划分I/O线程和worker线程
class ChatServer
{	public:
 	ChatServer(EventLoop*loop,//事件循环
               const InetAddress&listenAddr,//Ip+Port
               const string&nameArg)://服务器的名字
 _server(loop,listenAddr,nameArg),_loop(loop)
 {
     //给服务器重组测用户用户连接的创建和断开回调
     _server.setConnectionCallBack(std::bind(&ChatServer::onConnection,this,_1));
     //给服务器注册用户读写事件回调
     _server.setMessageCallback((std::bind(&ChatServer::onMessage,this,_1,_2,_3)))
     
      //设置服务器端的线程数量,一个I/O线程，3个worker线程
        _server.setThreadNum(4);
     
 }
 	
 	//开启事件循环
 	void start()
    {
        _server.start();
    }
 
  	private:
 	
 //专门处理用户的连接创建和断开
 	void onConnection(const TcpConnectionPtr&conn)
    {
        if(conn->connected())
        cout<<conn->peerAddress().toIpPort()<<"->"<<
            conn->localAddress().toIpPort()<<"state:online"<<endl;
        else
        {
            cout<<conn->peerAddress().toIpPort()<<"->"<<
            conn->localAddress().toIpPort()<<"state:offline"<<endl;
            conn->shutdown();//close(fd);
            //_loop->quit();
        }
    }
 
 
 	void onMessage(const TcpConnectionPtr&conn,//连接
                   Buffer*buf,//缓冲区
                   Timestamp time //接收到数据的时间信息
                  )
    {
        string buf=buffer.retrieveAllAsString();
        cout<<"recv data:"<<buf<<"time:"<<time.toString()<<endl;
        conn->send(buf);
    }
 
 	muduo::net::TcpServer _server;//#1
    EventLoop*_loop;  //#2
};

int main()
{
    EventLoop loop;//epoll;
    InetAddress addr("127.0.0.1",8080);
    ChatServer server(&loop,addr,"ChatServer");
    server.start();//启动服务listenfd epoll_ctl=>epoll
    loop.loop(); //epoll_wait以阻塞方式等待新用户连接，已连接用户的读写事件
    return 0;
}

```

