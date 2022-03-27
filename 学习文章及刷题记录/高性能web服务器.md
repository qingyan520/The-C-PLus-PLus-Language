高性能web服务器

###### TcpServer.cpp

```cpp
//TcpServer.hpp
#pragma once
#include<iostream>
#include<sys/tyeps.h>
#include<sys/socket.h>
#include<cstdlib.h>
#include<netinet/in.h>
#incldue<arpa/inet.h>
#include<string>
#include<cstring>
#include<pthread.h>
#include<unistd.h>
#include"Log.hpp"

#define PORT 8080
#define BACKLOG 5
class TcpServer{
    private:
    	int port;
    	int listen_sock;
   		static TcpServer*svr;
    private:
    TcpServer(int _port):port(_port),	 listen_sock(-1){
        
    }
    
    TcpServer(const TcpServer&s){
        
    }
    
    
    public:
    static TcpServer*getinstance(int port)
    {
        static pthread_mutex lock=PTHREAD_MUTEX_INITIALIZER;
        
        if(nullptr==svr){
            pthread_mutex_lock(&lock);
            if(nullptr==svr){
                svr=new TcpServer(port);
                svr->InitServer();
            }
            pthread_mutex_unlock(&lock);
        }
        retuen svr;
    }
    void InitServer(){
        Socket();
        Bind();
        Listen();
        LOG(INFO,"Tcp Init Success!");
    }
    
    void Socket()
    {
        listen_socket=socket(AF_INET,SOCK_STREAM,0);
        if(listen_sock<0)
        {
            //cout<<"socket error!"<<endl;
            LOG(FATAL,"socket error!");
            exit(1);
        }
            int flags=1;  setsockopt(listen_sock,SOL_SOCKET,SO_REUSEADDR,&flags,sizeof(flags));
    }
    LOG(INFO,"create socket....success!");
    
    void Bind()
    {
        struct sockaddr_in local;
        memset(&local,0,sizeof(local));
        local.sin_family=AF_INET;
        local.sin_port=htons(port);
        local.sin_addr.s_add=INADDR_ANY;
        
  		if(bind(listen_sock,(struct sockaddr*)&local,sizeof(local))<0)
        {
            LOG(FATL,"bind error!");
            exit(2);
        }
        LOG(INFO,"bind success!");
    }
    
    void Listen()
    {
        if(listen(listen_sock,BACKLOG)<0)
        {
            LOG(FATAL,"listen error!");
            exit(3);
        }
        LOG(INFO,"listen success!");
    }
    
    void Sock()
    {
        return listen_sock;
    }
    
    
    ~TcpServer(){
        if(listen_sock>=0)
        {
            close(listen_sock);
        }
    }
};
TcpServer*TcpServer::svr=nullptr;
```

###### Main.cc

```cpp
#include"TcpServer.hpp"
#include"HttpServer.hpp"
#include<memory>
static void Usage(string proc)
{
    std::cout<<"Usage:\n\t"<<proc<<" port"<<endl;
}
int main(int argc,char*argv)
{
    if(argc!=2)
    {
        Usage(argv[0]);
        exit(4);
    }
   int port=atoi(srgv[1]);
   std::shared_ptr<HttpServer>http_server((new HttpServer(port)));
    http_server->InitServer();
    http_server->Loop();
	return 0;
}
```

###### Log.hpp

```cpp
#pragma once
#include<iostream>
#include<string>
#include<ctime>
#define INFO 1
#define WARNING 2
#define ERROR 3
#define FATAL 4

#define LOG(level,message) Log(#level,message,__FILE__,__LINE__)

void Log(str::string level,std::string message,sstd::file_name,int line)
{
    //显示当前时间
    char now[64]={0};
    time_t tt=time(nullptr);
    struct tm*ttime;
    ttime=localtime(&tt);
    strftime(now,64,"%Y-%m-%d %H:%M:%S",ttime);
    
    std::cout<<"["<<now<<""<<"["level<<"]"<<"["<<message<<"]"<<"["<<file_name<<"]"<<"["<<line<<"]"<<endl;
}
```

###### Makefile

```makefile
bin=httpserver
cc=g++
LD_FLAGS=-std=c++11 -lpthread
src=main.cc
$(bin):$(src)
	$(cc) -o $@ $^ $(LD_FLAGS)
.PHONY:clean
	rm -rf bin
```

###### HttpServer.hpp

```cpp
#pragma once

#include<iostream>
#include"TcpServer.hpp"
#include<pthread.h>
#include"Protocol.hpp"
#include"Log.hpp"
classe HttpServer{
    private:
    int port;
    TcpServer*tcp_server;
    bool stop;
    public:
    HttpServer(int _port=PORT):port(_port),tcp_server(nullptr),stop(false){
        
    }
    
    void InitServer(){
 tcp_server=TcpServer::getinstance(port);
        
    }
    
    void Loop(){
        int listen_sock=tcp_server->Sock();
        while(!stop){
            LOG(INFO,"Loop Begin");
            struct sockaddr_in peer;
            socklen_t len=sizeof(peer);
           int sock=accept(listen_sock,&peer,&len);
            if(sock<0)
            {
                
                continue;
            }
            
            LOG(INTO,"Get a new link");
            
            int*_sock=new int(sock);
            
            pthread_t tid;
            pthread_create(&tid,nullptr,Entrancee::HandRequest,_sock);
            
            pthread_detach(tid);
        }
    }
    
    ~HttpServer(){
        
    }
};
```

###### Protocol.hpp

```cpp
#pramga once
#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<Util.h>
#include<string.h>
#include<vector>
#include<string stream>
#include<unorder_map>
#define SEP ": "
class HttpRequest{
    public:
    
    std::string request_line;
    std::vector<string>request_header;
    std::string blank;
    std::string request_body;
      //解析后的结构
    std::string method;
    std::string uri;
    std::string version; std::unorder_map<std::string,std::string>header_kv;
};

class HttpReponse{
    public:
    std::string status;
    std::vector<string>response_header;
    std::string blank;
    std::response_body;
  
};


//读取请求，分析请求，构建响应
//IO通信
class EndPoint{
    private:
    int sock;
    HttpRequest http_request;
    HttpResponse http_response;
    private:
    void RecvHttpRequestLine(){
        Util::ReadLine(sock,http_request.request_line);
        http_request.request_line.pop_back();
    }
    void RecvHttpRequestHeader(){
        std::string line;
        while(line!="\n")
        {
            line.clear();
            Util::Readline(sock,line);
		   line.pop_back();            http_request.request_header.push_back(line);  
        }
        if(line=="\n")
        {
            http_request.blank=line;
        }
    }
    
    //解析http请求行
    void  ParseHttpRequestLine(){
        string ss( http_request.line);
       	ss>>http_request.method>>http_requesst.rui>>http_request.verison;
        
    }
    
    //解析http报头，拆分成kv模型
    void ParseHttpRequestHeader() {
            std::string key;
            std::string value;
    	for(auto &iter:http_request.header){
        
            if(Util::CutString(iter,key,value,SEP)){
                 http_request.header_kv.insert(make_pair(key,value));
            }
           
        }      
        
    }
    public:
    
    EndPoint(int _sock):sock(_sock){
        
    }
    
    //接受http请求，将请求一行一行进行读取，拆分请求行和请求报头
    void RecvHttpquest(){
        this->RecvHttpRequestLine();
        this->void RecvHttpRequestHeader();
    }
    
    //解析http协议，将请求行拆分成method，uri，version
    //将请求报头拆分成kv形式
    void ParseHttpRequest(){
        ParseHttpRequestLine();
       ParseHttpRequestHeader();
    }
    
    void BuildHttpResponse(){
        
    }
    
    void SendHttpResponse(){
        
    }
    
    ~EndPoint(){
        
    }
};


class Entrance{
    public:
    static void*HandlerRequest(void*_sock){
        LOG(INFO,"Hander Request Begin");
        itn sock=*(int*)_sock;
        delete _sock;
        std::cout<<"get a new link..."<<sock<<std::endl;
        
       // #ifndef DEBUG
        
       // #define DEBUG
        //	char buffer[4096]={0};
       // recv(sock,buffer,sizoef(buffer),0);
       // cout<<"============Being======"<<endl;
       // std::cout<<buffer<<endl;
         //  cout<<"============End======"<<endl;
        //#endif
        
      //  std::string line;
       // Util::ReadLine(sock,line);
       // cout<<line<<endl;
        //close(sock);
        EndPoint*ep=new EndPoint(sock);
        ep->RecvHttpRequest();
        ep->ParseHttpRequest();
        ep->BuiltHttpResponse();
        ep->SendHttpResponse();
        delete ep;
        
        LOG(INFO,"Hander Request End");
        return nullptr;
    }
    
};
```

###### Util.gpp

```cpp
#pragma once
//工具类
#include<iostream>
#include<string>
#include<sys/socket.h>
#include<sys/types.h>
class Util{
public:
    stat int ReadLine(int sock,std::string&out)
    {
        char ch='x';
        
        while(ch!='\n'){
            ssize_t s=recv(sock,&ch,1,0);
            if(s>0)
            {
                if(ch=='\r'){
                    //\r->\n or \r\n ->\n
                    recv(sock,&ch,1,MSG_PEEK);
                    if(ch=='\n'){
                        //窥探成功，这个字符，一定存在，
                        recv(sock,&ch,1,0);
                    }
                    else{
                        ch='\n';
                    }
                }
                //1.普通字符
                //2.\n
                out.push_back(ch);
            }
            else if(s==0){
                return 0;
            }
            else{
                return -1;
            }
        }
        return out.size();
    }
    stat bool CutString(const std::string&target,std::string &key_out,str::string value_out,string sep){
     size_t pos=target.find(sep);
        if(pos!=std::string::npos)
        {
            key_out=target.substr(0,pos);
            value_out=target.substr(pos+sep.size());
            return true;
        }
        return false;
    }
}
```

1.读取请求：读取的基本单位，按照行进行读取，兼容各种行分隔符（同意转化为按照\n结尾）

请求行

请求报头

空行

请求正文：

```
1.是否有正文需要读取，Method==POST进行判断
2.确认正文有多少字节需要读取，有Content-Lengthj
```

2.分析请求



3.构建响应并返回

