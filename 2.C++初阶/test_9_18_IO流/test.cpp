#include<iostream>#include<istream>//���ļ�#include<ostream>//д�ļ�
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

	//���ı��ķ�ʽ��д
	void WriteText(const ServerInfo& info)
	{

		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._potr << endl;
	}
	//���ı��ж�ȡ����
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