#include<iostream>#include<istream>//读文件#include<ostream>//写文件
#include<fstream>
using namespace std;
struct ServerInfo
{
	char _ip[32];
	int _potr;
};
struct ConfigManger
{
public:
	ConfigManger(const char* configfile = "bitserver.config") :
		_configfile(configfile)
	{

	}

	//以文本的方式打开写
	void WriteText(const ServerInfo& info)
	{

		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._potr << endl;
	}
	//从文本中读取内容
	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._potr;
		ifs.close();
	}

	string _configfile;
};
int main()
{
	ServerInfo a;
	ConfigManger b;
	b.ReadText(a);


	return 0;
}