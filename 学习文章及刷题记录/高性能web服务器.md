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
#include<sys/wait.h>

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
#include<sys/stat.h>
#include<sys/sendfile.h>
#include<fcntl.h>
#define SEP ": "
#define WEB_ROOT "wwwroot"
#define HOME_PAGE "index.html"
#define HTPP_VERSION "HTTP/1.0"

#define OK 200
#define NOT_FOUND 404
static std::string Code2Desc(int code)
{
    switch(code){
        case 200:
            return "OK";
        case 404:
            return "Not Found";
    }
}


static string Suffix(const string &str)
{
 	unordered_map<string,string>suffix2desc={
        {".html","text/html"},
        {".jpg","application/x-jpg"}
        {".css","text/css"},
        {".js","application/javascript"},
        {".xml","application/rs+xml"}
    }
    auto iter=suffix2desc.find(str);
    if(iter!=suffix2desc.end())
    {
        rerurn iter->second;
    }
    return "text/html";
}

class HttpRequest{
    public:
    
    std::string request_line;
    std::vector<string>request_header;
    std::string blank;
    std::string request_body;
      //解析后的结构
    std::string method;
    std::string uri;//path?参数
    std::string version; std::unorder_map<std::string,std::string>header_kv;
    int content_length=0;
    std::stringpath;
    std::string query_string;
    bool cgi=false;
    std::string suffix;
};

class HttpReponse{
    public:
    std::string status;
    std::vector<string>response_header;
    std::string blank;
    std::response_body;
  	int status_code=OK;
    int fd;
    int size;
  
 };


//读取请求，分析请求，构建响应
//IO通信
class EndPoint{
    private:
    int sock;
    HttpRequest http_request;
    HttpResponse http_response;
    int code;
    
    
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
		   line.pop_back();           
            http_request.request_header.push_back(line);  
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
    
    //读取正文部分
    bool IsNeedRecvHttpRequestBody(){
        auto &method=http_request.method;
        if(method=="POST"){
            auto &header_kv=http_request.header_kv;
            auto iter=header_kv.find("Content-Length");
            if(iter!=header_kv.end()){
                http_rrequest.content_length=stoi(iter->second);
                return true;
            }
        }
        return false;
    }
    
    
    void RecvHttpRequestBody(){
        if(IsNeedRequestBody()){
            int content_length=http_request.content_length;
            auto &body=http_request.request_body;
            char ch=0;
            while(content_length){
                ssize_t=recv(sock,&ch,1,0);
                if(s>0){
                    body.push_back(ch);
                    content_length--;
                }
            }
        }
    }
    
    int ProcessNonCgi(int size)//返回简单的静态网页
    {
        http_response.fd=open(http_request.path.c_str(),O_RDONLY);
        if(http_response.fd>=0)
        {
             http_response.status_line=VERSION;
        	http_response.status_line+=" ";
        	http_response.status_line+=to_string(http_response.status_code);
        	http_response.status_line+=" ";
        	http_response.status_line+=Code2Desc(http_response.status_code);
        	http_response.status_line+="\r\n";   
            http_response.size=size;
            
            std::string content_length_string="Content-Length: ";
            content_length+=to_string(size);
            centent_lenght+="\r\n";
            string content_type="Content-Type: ";
            content_type+=Suffix2Desc(http_request.suffix);
            content_type+="\r\n";
            http_response.response_header.push(content_length);
            http_response.response_header.push(content_type);
            //获得文件扩展名
            
            return OK;
        }
        return 404;
            
 
        
        
        return 0;
    }
    
    int ProcessCgi()
    {
        //父进程数据
        auto &query_string=http_request.query_string;//GET
        
        auto &body_text=http_request.requestr_body;//POST
        
        string query_string_env;
        string method_env;
        
        	auto &bin=http_requestt.path;//要让子进程执行的目标可执行程序，一定存在
        	int input[2];//父进程读，子进程写
        	int output[2];//父进程写，子进程读
        	if(pipe(intput)<0)
            {
                LOG(ERROR,"pipe input error!")l
             	return 404;
            }
        	if(pipe(output)<0)
            {
                LOG(ERROR,"pipe output error!");
                return 404;
            }
		   //创建子进程，让子进程执行程序
            pid_t pid=fork();
            if(pid==0)
            {
                //站在子进程的角度，input[1]是用来写入的，写出， ----》
                //outp[0]是用来用来读取的，读入,重定向到标准
                close(input[0]);
                close(output[1]);
                
                
                method_env="MEHTOD=";
                method_env+=http_request.method;
                putenv(method_env.c_str());
                if(http_request.method=="GET")
                {
                    query_string_env="QUERY_STRING=";
                    query_string_env+=query_string;
                    putenv(query_string_env.c_str());
                }
                //替换成功之后，目标子进程如何得知，对应的文件描述符是多少呢？不需要，读0，写1即可
                dup2(output[0],0);
                dup2(intput[1],1);
               
               	execl(bin.c_str(),bin.c_str(),nullptr);
                close(input[0]);
                close(output[1])
                exit(1);
                //exec相关函数
            }
            else if(pid<0)//error
            {
                LOG(ERROR,"Fork Error!");
                return 404;
            }
            else//parent
            {
                
                close(input[1]);
                close(output[0]);
                
                if(http_request.method=="POST")
                {
                   
                    const cjar*start=body_text.c_str();
                    int total=0;
                    int size=0;
                    while(( size=write(output[1],start+total,body_text.size()-total))>0)
                    {
                       
                        if(size>0)
                        {
                            total+=size;
                        }
                    }
                }
                
          
                waitpid(pid,nullptr,0);
			                   
            }
        	return OK;
        
    }
    
    public:
    
    EndPoint(int _sock):sock(_sock){
        
    }
    
    //接受http请求，将请求一行一行进行读取，拆分请求行和请求报头
        //解析http协议，将请求行拆分成method，uri，version
    //将请求报头拆分成kv形式
    void RecvHttpquest(){
        this->RecvHttpRequestLine();
        this->void RecvHttpRequestHeader();
        
        ParseHttpRequestLine();
        ParseHttpRequestHeader();
        RecvHttpRequestBody();
    }
    

    //处理请求
    void BuildHttpResponse(){
          std::string _path;
        std::size_t found=0;
          auto&code=http_response.status_code; 	
          if(http_request.method!="GET"&&http_request.method!="POST"){
          	 //非法请求  
              LOG(WARNING,"method is not right!");
              code=NOT_FOUNT;
         	  goto END;
              
            
        }
        
        if(http_request.method=="GET")
        {
            //判断是否带参数
            int pos=http_request.uri.find("?");
            if(pos!=std::npos){
                http_request.path=http_request.uri.substr(0,pos);
                http_request.query_string=http_request.uri.substr(pos+1,string::npos);
                http_quest.cgi=true;
                
            }
            else
            {
                http_request.path=http_request.uri;
            }
        }
        else if(http_request.method=="POST"){
            //POST
            http_request.cgi=true;
        }
        else{
            //do_Nothing
        }
      	_path=http_request.path;
        http_request.path=WEB_ROOT;
        http_request.path+=_path;
        if(http_request.path[path.size()-1]=='/')
        {
            http_request.path+=HOME_PAGE;
        }
        
        struct stat st;
        int size=0;
        if(stat(http_request.path.c_str(),&st)==0)
        {
            //说明资源存在
            if(S_ISDIR(st.st_mode)){
                //说明请求的资源是目录，也是不被容许的，需要做一下相关处理
                //虽然是一个目录，但是绝对不会以/结尾
                 http_request.path+="/";
                http_request.path+=HOME_PAGE;
                stat(http_request.path.c_str(),&st);
            }
            if((st.st_mode&S_IXUSR)||(st.mode&S_IXGRP)||(st.st_mode&S_IXOTH)){
                //需要进行特殊处理
                http_request.cgi=true;
            }
            size=st.st_size;
            
        }
        else
        {
            //资源不存在
            std::string info=http_request.path;
            info+="Nod Found";
            LOG(WARNING,info);
            code=NOT_FOUND;
            goto END;
        }
        
        //后缀填充
       	found=http_request.path.rfind(".");
        if(found==string::npos)
        {
            http_request.suffix=".html";
        }
        else
        {
            http_request.suffix=http_request.path.substr(found);
        }
        
        if(http_request.cgi){
            ProcesCgi();
          
        }
        else
        {
            //1.目标网页一定是存在的
            //2.返回并不是单单返回网页，而是要构建http响应
            //
            code=ProcesNonCgi(size);//简单的网页返回，静态网页
        }
        
        
        END:
        if(code!=OK){
            
        }
        return;
        
    }
    
    void SendHttpResponse(){
        					    send(sock,http_response.status_line.c_str(),http_respconse.status_line.size(),0);
        for(auto iter:http_response.response_header)
        {
            send(sock,iter.c_str(),iter.size(),0);
        }
        send(sock,http_response.blank.size(),http_response.blank.size(),0);
        sendfile(sock,http_response.fd,nullptr,http_response.size);
        c
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

路径表明了服务器上面的某种资源，是从根目录开始吗？//不一定，一般情况下需要指明web根目录，里面必须有一个index.html

path要拼接前缀

这个路径对应的资源是否是存在吗？

存在就是可以访问读取的吗?，不一定，可能是目录

什么时候，需要使用CGI来进行数据处理呢？只要用户上传数据！

2.分析请求



3.构建响应并返回





 约定：让目标被替换后的进程，读取管道定价与读取标志输入，写入管道，等价于写道标准输出



程序替换只替换代码和数据，不替换内核进程相关的数据结构，包括文件描述符表

可以在exec*系列前进行重定向

环境遍历是具有全局属性的(可以被子进程继承下去)，不受exec*程序替换的影响



子进程如何区分，从标准输入读取环视从环境变量里面拿到数据？？

