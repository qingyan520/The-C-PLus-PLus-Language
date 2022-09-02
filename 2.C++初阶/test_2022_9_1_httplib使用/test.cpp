#include<iostream>
#include"httplib.h"
#include<windows.h>
#include<functional>
void hello(const httplib:: Request& req, httplib::Response& rsp)
{
	rsp.body="hello";
	rsp.content_length_ = 6;
	rsp.set_header("content_type", "text");
	rsp.status = 200;

}

int main()
{
	httplib::Server svr;
	svr.Get("/", hello);

	svr.listen("127.0.0.1", 8080);
}