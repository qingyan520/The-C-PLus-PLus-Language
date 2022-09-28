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

项目目录

```
bin
build
include/server
src
test
threadparty
CMakeLists.txt
```

CMakeLists.txt

```cmake
cmake_minmum_required(VERSION 3.0)
project(chat)

#配置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

#配置最终可执行文件的输出路径
set(EXECUTABKE_OUPPUT_PATH ${PROJECT_SECURE_DIR}/bin)

#配置头文件的搜索路径
include_directories(${PROJECT_SOURCE_DIR}/inclde)
include_directories(${PROJECT_SOURCE_DIR}/include/server)

#加载子目录
add_subdirectory(src)

```

src下面的CMakeList.txt

```cmake
add_subdirectory(server)
```

src/sercer

```cmake
#指定可执行文件
aux_source_directory(. SRC_LIST)
add_exxcutable(ChatServer ${SRC_LIST})

target_link_libraries(ChatServer muduo_net muduo_base pthread)
```



###### ChatServer.hpp

```cpp
#include<muduo/net/TcpServer.h>
#include<muduo/net/EventLoop.h>
using namespace muduo;
using namespace muduo::net;
class ChatServer{
    public:
    ChatServer(EventLoop*loop,const InetAddress&listenAddr,
              const string name)
    {
        
    }
    
    void start();
    
    private:
    
    //上报连接回调相关的回调函数
    void  onConnetion(const TcpConnectionPtr&);
    
    
    void onMessage(const TcpConnectionPtr&,Buffer*,TimeStamp);
    
    TcpServer _server;
    EventLoop*_loop;
};
```

###### ChatServer.cpp

```cpp
#include"ChatServer.hpp"
#include"ChatService.hpp"
#include<funcitonal>
using namespace std;
using namespace placeholders;

//连接回调
void ChatServer::onConnect(const TcpCOnnectionPtr&conn)
{
    if(!conn->connected())
    {
        CHatService::instance()->clientCloseException(conn);
        conn->shutdown();
    }
}

//上报读写相关事件的回调函数
void ChatServer::onMessage(const TcpConnectionPtr&conn,Buffer*buffer,Timestamp tome)
{
    string buf=buffer->retrieveAllAsString();
    //数据的反序列化
    json js=json::parse(buf);
    //解耦网络模块和业务模块
    //通过js["msgid"]获取业务handler
    auto msgHandler=ChatService::instance()->getHandler(js["msgid"].get<int>());
    //回调消息绑定好的时间处理器，来执行相应的业务处理
    msgHandler(conn,js,time);
    
}
```



###### main.cpp

```cpp
#include<iostream>
#include<signal.h>
#include"chatserver.cpp"
#include"ChatService.hpp"
//处理服务器ctrl+c结束后，充值user的状态信息
void resetHandler(int)
{
    CHatService::instance->reset();
    exit(0);
}
int main()
{
    signal(SIGINT,resetHandler);
	EventLoop loop;
    InetAddress addr("127.0.0.1",6000);
    ChatServer server(&loop,addr,"ChatServer");
    Server.start();
    loop.loop();
    return 0;
}
```





###### chatservice.hpp

```cpp
#include<iostream>
#include<unordered_map>
#include<map>
//聊天服务器业务类
using namespace std;
using namespace muduo::net;
using namespace mudo;
#include<funcitonal>
#include<muduo/net/TcpConnetion.h>
#include"json.hpp"
#include<string>
#include<mutex>
//处理消息的回调方法类型
using MsgHandler=std::function<void(const TcpConnectionPtr&conn,json&js,Timestamp)>;

class ChatService
{
	public:
    //获取单例对象的接口函数
    static ChatService*instance()
    {
        
    }
    //处理登录业务
    void login(const TcpConnectionPtr&conn,json&js,Timestamp time));
    //处理注册业务
    void reg(const TcpConnectionPtr&conn,json&js,Timestamp time0);
    
    //一对一聊天业务
    void oneChat(const TcpConnectionPtr&conn,json&js,Timestamp time0);
    
    //获取消息对应的处理器
    MagHandler getHander(int msgid);
    {
        
    }
    
    //处理客户端异常退出
    void clientCloseException(const TcpConnectionPtr&con);
    
    //服务器异常，业务重置方法
    void reset();
    
    //添加好友业务
    void addFriend(const TcpCOnnectionPtr&conn,json*js,Timestamp time);
    
    private:
    ChatService();
    
    //存储消息id和器对应的业务处理方法
    unordered_map<int,MagHandler>_handlerMap;
    
    //存储连接
    unordered_map<int,TcpCOnnectionPtr>_userConnMap;
    
    //定义互斥锁，保证_userConnMap的线程安全
    mutex _connMutex;
    
    //数据操作类对象
    UserModel _userModel;
    OfflineMsgModel _offlineMsgModel;
    FriendModel _friendModel;
}
```

###### chatservice.cpp

```cpp
#include"chaservice.hpp"
#include"public.hpp"
#include<muduo/base/Logging.h>
#include"usermodul.h"
using namespace muduo;
ChatService*ChatCservice::instance()
{
    static ChatServer server;
    return &service;
}
//注册消息以及对应的handler回调操作
ChatService::ChatService()
{
     _msgHandlerMap.insert({LOGIN_MSG,std::bind(&ChatServoce::log,this,_1,_2,_3)});
    _msgHandlerMap.insert(REG_MSG,std::bind(&ChatService::reg,this,_1,_2,_3));
    _msgHandlerMap.insert(ONE_CHAT,std::bind(&ChatService::oneChat,_1,_2,_3);
}

//处理登录业务 OMR 业务层操作的都是对象 DAO
void ChatService::login(const TcpConnectionPtr&conn,json&js,Timestamp time)
{
   int id=js["id"].get<int>();
    string pwd=js["password"];
    User user=_userModel.query(id);
    if(user.getId()==id&&user.getPwd()==pwd)
    {
        if(user.getState=="online")
        {
            //该用户已经登录，不容许重复登录
            json response;
        	response['msgid']=LOGIN_MSG_ACK;
        	response["errno"]=2;
        	response["errmsg"]="该账号已经登录，请重新输入新账号";
        	con->send(response.dump());
        }
        else
        {
            //登录成功，记录用户连接信息
            {
              	lock_gurad<mutex>lock(_conMutex);
            	_userConnMap.insert({id,conn});
            }
            
            
            //登录成功，更新用户状态信息
            user.setState("online");
            
            
            _userModel.updataState(user);
        	json response;
        	response['msgid']=LOGIN_MSG_ACK;
       	 	response["errno"]=0;
        	response["id"]=user.getId();
        	response["name"]=user.getName();
            
            //查询该用户是否有离线消息
            vector<string>vec=_offlineMsgModel.query(id);
            if(!vec.empty())
            {
                responce["offlinemsg"]=vec;
                //读取该用户的离线消息后，把该用户的所有离线消息给发送之后删除
                _offlineMsgModel.remove(id);
            }
            
            //查询用户的好友信息并返回
            vector<User> userVec=_friendModel.query(id);
            if(!userVec.empty())
            {
                vector<string>vec2;
                for(User&user:userVec)
                {
                    json js;
                    js["id"]=user.getid();
                    js["name"]=user.getName();
                    js["state"]=user.getState();
                    vec2.Push_back(js.dump);
                }
                r
            }
            
        	con->send(response.dump());
        }
    }
    else
    {
        //改用户在不存在，登录失败
        
        json response;
        response['msgid']=LOGIN_MSG_ACK;
        response["errno"]=1;
        response["errmsg"]="用户名或者密码错误";
        con->send(response.dump());
    }
}
//处理注册业务
void ChatService::reg(const TcpConnectionPtr&conn,json&js,Timestamp time)
{
     string name=js["name"];
    string pwd=js["password"];
    User user;
    user.setName(name);
    user.setPwd(pwd);
   	bool state=_userModel.insert(user);
    if(state)
    {
        //注册成功
        json response;
        response['msgid']=REG_MSG_ACK;
        response["errno"]=0;
        response["id"]=user.getId();
        con->send(response.dump());
    }
    else
    {
        //注册失败
        json response;
        response['msgid']=REG_MSG_ACK;
        response["errno"]=1;
        
        con->send(response.dump());
    }
}

//获取消息对应的处理器
MsgHandler ChatService::getHandler(int msgid)
{
    //记录错误日志，msgid没有对应的事件处理回调
    auto it=_msgHanflerMap.find(msgid);
    if(it==_msgHandler.end())
    {
       
        //返回一个空操作
        return [=](const TcpConnectionPtr&conn,json&js,Timestamp time)->void{
             LOG_ERROR<"msgid:"<<msgid<<"can not find handler！";
        };
    }
    else
    {
     	 return _msgHandlerMap[msgid];    
    }
}


//处理客户端异常退出
void ChatService::clientCloseException(const TcpConnectionPtr&con)
{
     User user;
    {
        lock_guard<mutex>lock(_connMutex);
   		
    	for(auto it=_userCOnnMap.begin();it!=_userConnMap.end();++it)
   		 {
        	if(it->second==conn)
       		 {
           		 //从map表删除用户的连接信息
           		 user.SetId(it->first);
            	_userConnMap.erase(it);
           		 break;
        }
    }
    }
    
    //更新用户的信息
    if(user.getId()!=-1)
    {
     	 user.setState("offline");
    	_userModel.updateState(user);   
    }
}

 //一对一聊天                         
void ChatService::oneChat(const TcpConnectionPtr&conn,json&js,Timestamp time0)
{
    int toid=js["to"].get<int>();
    
    {
        lock_guard<mutex>lock(_connMutex);
        auto it=_userConnMap.find(toid);
        if(it!=_user.ConnMap.end())
        {
            //toid在线，转发消息  服务器主动推送消息
            it->second->send(js.dump());
            return;
        }
    }
    
    _foolineMsgModel.insert(toid,js.dump());

}
                          
                          
void CHatService::rest()
                          {
                              //把online状态用户重置为offline
                              _userModel.resetstate();
                          }
                          
//添加好友业务，msgid id friendid;                          
void ChatService::addFriend(const TcpCOnnectionPtr&conn,hson*js,Timestamp time)                          {
    int userid=(*js)["id"].get<int>();
    int friendid=(*js)["friendid"].get<int>();
    _friendModel.insert(userid,friendid);
    
}
```



###### Public.hpp

```cpp
#pramgma once
//server和client的公共文件
snum EnMsgType{
	  LOGIN_MSG=1,//登录消息
      LOGIN_MSG_ACK，//登录响应
  	  REG_MSG,//注册消息
      REG_MSG_ACK,//注册响应消息
 	  ONE_CHAT_MSG,//聊天信息       
      ADD_FRIEND_MSG,//添加好友信息
      CREATE_GROUP_MSG,//创建群组
      ADD_GROUP_MSG,//加入群组
      GROUP_CHAT_MSG,//群聊天
};
```

db.h

```cpp
#include<mysql/mysql.h>
#include<string>
#include<muduo/base/Logging.h>
using namespace std;

MYSQL*getConnection()
{
    
}
```

db.cpp

```cpp
#include"db.h"


```

user.hpp

```cpp
#include<string>
using namespace std;
//匹配User表的ORM表
class User{
  private:
    int id;
    string name;
    string password;
    string state;
  public:
    User(int id=-1,string name="",string pwd="",string state="offline" )
    {
        this->id=id;
        thie->name=name;
        this->password=pwd;
        this->state=state;
    }
    
    void SetId(int id)
    {
        this->id=id;
    }
    
    void SetName(string name)
    {
        this->name=name;
    }
    
    void SetPwd(string pwd)
    {
        this->password=pwd;
    }
    
    void SetState(string state)
    {
        this->state=state;
    }
    
    
     int GetId()
    {
        return this->id;
    }
    
    string GetName()
    {
        return this->name;
    }
    
    string SetPwd()
    {
        return this->password;
    }
    
    string SetState()
    {
        return this->state;
    }
    
};
```

usermodel.hpp

//user表的操作类

```cpp
#include "User.hpp"
class UserModel{
  public:
    //User表的增加方法
    bool insert(User&user);
    
    //根据用户号码查询用户信息
    User query(int id);
    
    //更新用户的状态信息
    bool void updateState(User user);
    
    //重置用户的状态信息
    void resetState();
};
```

usermodul.cpp

```cpp
#include"usermodel.hpp"
#include"db.h"
#include<iostream>
using namespace std;
bool UserModel::insert(User&user)
{
    //1.组装sql语句
    char sql[1024]={0};
    sprintf(sql,"insert into User(name,password,state) values('%s','%s','%s')"user.getName().c_str(),user.getPwd().c_str(),user.getState().c_str());
    
    MYSQL mysql;
    if(mysql.connect())
    {
        if(mysql.update(sql))
        {
            //获取插入成功的用户数据生成的主键id
            user.setId(mysql_insert_id(musql.getConnection()));
            return true;
        }
    }
    return false;
    
}

User UserModel::query(int id)
{
    //1.组装sql语句
    char sql[1024]={0};
    sprintf(sql,"select * from user where id=%d",id;
    
    MYSQL mysql;
    if(mysql.connect())
    {
        MYSQL_RES*res=mysql,query(sql);
        if(res!=nullptr)
        {
            MYSQL_ROW row=mysql_fetch_row(res);
            if(row!=nullptr)
            {
                User user;;
                user.setId(atoi(row[0]));
                user.setId(row[1]);
                user.setPwd(row[2]);
                user.setState(row[3]);
                mysql_free_result(res);
                return user;
            }
        }
    }
    return User();
}
            
bool usemodel::updateState(User user)
 {
                 //1.组装sql语句
    char sql[1024]={0};
    sprintf(sql,"update user set state ='%s' where id=%d",user.GetState().c_str(),user.Getid());
    
    MYSQL mysql;
    if(mysql.connect())
    {
        if(mysql.update(sql))
        {
            return true;
        }
    }
    return false;
}
            void UserModel::resetState()
            {
                char sql[1024]="update User set state='offline' where state='online'";
                Mysql mysql;
                if(mysql.connect())
                {
                    mysql.update(sql);
                }
            }
      
```

FriendModel.hpp

```cpp
#include<vector>
//提供好友信息
class FriendModel
{
    public:
    //添加好友关系
    void insert(int userid,int friend);
    
    //返回用户好友列表 friendid
    vector<User> query(int userid);
    
};
```

FriendModel.cpp

```cpp
void FriendModel::insert(int userid,int friendid)
{
    char sql[1024]={0};
    sprintf(sql,"insert into friend values(%d,%d)",userid,friendid);
    Mysql mysql;
    if(mysql.connect())
    {
        mysql.update(sql);
    }
}
}

//返回好友列表
 vector<User> FriendModel::query(int userid)
 {
     char sql[1024]={0};
    sprintf(sql,"select a.id,a.name,a.state from User a inner join friend b on b.friendid=a.id where  ")
    vector<User>vec;
    Mysql mysql;
    if(mysql.connect())
    {
        MYSQL_RES*res=mysq.query(sql);
        if(res!=nullptr)
        {
            //把userid用户的所有离线消息放入到vec中返回
            MYSQL_ROW row;
            while(row=mysql_fetch_row(res)!=nullptr)
            {
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setState(row[2]);
                vec.push_back(user);
            }
            mysql_free_result(res);
        }
    }
    return vec;
 }
```



offlinemessagemodel.hpp

```cpp
#include<string>
#include<list>
//提供离线消息表的操作结课方法
class OfflineMsgModel
{
    public:
    //存储用户的离线消息
    void insert(int userid,string msg);
    //删除用户离线消息
    void remove(int userid);
    //查询用户的离线消息
    vector<string> query(int userid);
};
```

offlinemessagemodel.cpp

```cpp
//存储离线消息
void OfflineMsgModel::insert(int userid,string msg)
{
    char sql[1024]={0};
    sprintf(sql,"insert into offlinemessage values(%d,'%s')",userid,msg.c_str());
    Mysql mysql;
    if(mysql.connect())
    {
        mysql.update(sql);
    }
}

//删除用户的离线消息
void OfflineMsgModel::remove(int userid)
{
    char sql[1024]={0};
    sprintf(sql,"delete from offlinemessage where id=%d".userid);
    
    Mysql mysql;
    if(mysql.connect())
    {
        mysql.update(sql);
    }
}

//查询用户的离线消息
vector<string> OfflineMsgModel::query(int userid)
{
    char sql[1024]={0};
    sprintf(sql,"select message from offlinemsg where id=%d",id);
    vector<string>vec;
    Mysql mysql;
    if(mysql.connect())
    {
        MYSQL_RES*res=mysq.query(sql);
        if(res!=nullptr)
        {
            //把userid用户的所有离线消息放入到vec中返回
            MYSQL_ROW row;
            while(row=mysql_fetch_row(res)!=nullptr)
            {
                vec.push_back(row[0]);
            }
            mysql_free_result(res);
        }
    }
    return vec;
}
```

群组添加部分：

![image-20220521194146540](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220521194146540.png)



![image-20220521194243911](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220521194243911.png)

![image-20220521194404636](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220521194404636.png)

![image-20220521194747839](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220521194747839.png)

![image-20220521194937481](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220521194937481.png)

![image-20220521195627827](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220521195627827.png)

![image-20220521201018874](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220521201018874.png)



```sql
create table GroupUser(groupid int comment '组id' not null,userid int comment '组员id' not null,grouprole enum('creator','normal') comment '组内角色' default 'normal' ,primary key(groupid,userid));
```

OfflineMessage表：存储离线消息

```sql
create table OfflineMessage(userid int comment '用户id' not null,message varchar(500) comment '离线消息(存储json字符串)' not null);
```



客户端开发

1.首页功能开发及测试

```cpp
#include"json.hpp"
#include<iostream>
#include<thread>
#include<string>
#include<vector>
#include<chrono>
#include<ctime>
using namespace std;
using json=nlohman::json;

#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include"group.hpp"
#include"User/.hpp"
#include"public.hpp"

//记录当前系统登录的用户信息
User g_currentUser;

//记录当前用户的好友列表信息
vector<User>g_currentUserFriendList;

//记录当前登录用户的群组列表信息
vector<Group>g_currentUserGroupList;

//显示当前登录成功用户的级别信息
void showCurrentUserDate();

//接收线程
void readTaskHandler(int clientfd);

//获取系统时间(聊天信息需要添加时间信息)
string getCurrentTime();

//主聊天页面程序显示
void mainMenu();

//聊天客户端程序实现，main线程用作发送线程，子线程用作接受线程
int main(int argc,char**argv)
{
    if(argc<3)
    {
        cerr<<""<<endl;
    }
    
    char*ip=argv[1];
    uint16_t port=atoi(argv[2]);
    
    //创建client端的socket
    int clientfd=socket(AF_INET,SOCK_STREAM,0);
    if(clientfd<0)
    {
        cerrL<<"create socket error"<<endl;
        exit(-1);
    }
    
    //填写链接client需要的server的信息ip+port;
    sockadddr_int server;
    meset(&server,0,sizeof(sockaddr_in));
    
    server.sin_famliy=AF_INET;
    server.sin_port=htons(port);
    server.sin_addr.s_addr=inet_addr(ip);;
    
    //client和server进行连接
    if(connect(clientfd,(sockaddr*)&server,sizeof(sockaddr_in)))
    {
        cerr<<"connect server error"<<endl;
        close(clientfd);
        exit(-1);
    }
    
    //main线程用于接受用户输入，负责发送数据
    for(;;)
    {
        //显示首页菜单，登录，注册，退出
        cout<<"1.login"<<endl;
        cout<<"2.register"<<endl;
        cout<<"3.quit"<<endl;
        cout<<"choice:";
        int choice=0;
        cin>>choice;
        cin.get();//读掉缓冲区残留的回车
        
        switch(choice)
        {
            case 1:
                int id=0;
                char pwd[50]={0};
                cout<<"userid:"<<endl;
                cin>>id;
                cin.get();
                cout<<"userpwd:"<<endl;
                cin.getline(pwd,50);
                
                json js;
                d
        }
    }
    
    
}
```



![image-20220524133201193](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220524133201193.png)





![image-20220524133309731](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220524133309731.png)



![image-20220524133338709](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220524133338709.png)





![image-20220524133413050](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220524133413050.png)

nginx配置tcp负载均衡

```
---with stream 激活tcp负载均衡模块
tar -axvf nginx-1.12.2.tar.gz
cd nginx-1.12.2
./configure  --with-stream
sudo make&&make install
默认安装在usr/local/nginx


cd /usr/local/nginx
cd sbin
cd conf //配置文件
vim nginx.conf

stream
{
	server{
		listen 8000;
		
	}
}
http
```

![image-20220526144548298](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20220526144548298.png)

![image-20220526150042883](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20220526150042883.png)

redis编程

```cpp
//redis.hpp
#include<hiredis/hiredis.h>
#include<thread>
#include<functional>
using namespace std;

//redis作为集群服务器通信的发布----订阅消息队列
class Redis
{
    public:
    Redis();
    ~Redis();
    
    //连接redis服务器
    bool connect();
    
    //向redis指定的通道channel发布消息
    bool publish(int channel,string message);
    
    //向redis指定通道subscribe订阅消息
    bool subscribe(int channel);
    
    //向redis指定的通道unsubscribe取消订阅消息
    bool unsubscribe(int channel);
    
    //在独立线程中接受订阅通道中的消息
    void observer_channel_message();
    
    //初始化业务层上报通道消息的回调对象
    void init_notify_handler(function<void(int,string)>fn);
    
    private:
    //hiredis同步上下文图形，负责public消息
    redisContext*_public_context;
    
    //hiredis同步上下文对象，负责subscribe消息
    redisContext*_subcribe_context;
    
    //回调操作，收到订阅的消息，给service层上报
    function<void(int,string)>_notify_message_handler;
    
};
```







自己实现云服务器的步骤与遇到的问题

1.muduo网络库部分编写

> 忘记加头文件
>
> json form modern c++在gcc 4.8.5时用引用编译出错，升级gcc版本或者改用指针

2.ChatService类的编写

> 绑定每一个事件的对应的回调函数

3.数据库部分编程

>利用C语言实现连接数据库
>
>数据库分层管理：每个表建立一个类管理
>
>数据库连接失败
>
>读取与写入时得编码格式必须与数据库格式保持一直

4.注册功能的实现

5.登录功能的实现

6.一对一聊天功的得实现

7.离线消息发送的实现

8.异常处理

> 当客户端断开连接时我们要将客户端从_useConMap中获取id和TcpConnectionPtr.然后将他从其中删除，然后从数据库中更改状态为离线
>
> 当服务器被ctrl+c异常终止时，我们应该捕捉当前信号，然后将所有人的登录状态置为offline

9.线程安全的处理

> 每一个连接都保存在_userMap中，在操作这张表的时候，我们要注意线程安全问题

