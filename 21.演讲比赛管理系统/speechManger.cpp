#include"speechManger.h"
SpeechManger::SpeechManger()
{
	//初始化容器属性
	this->InitSpeech();
}

SpeechManger::~SpeechManger()
{

}
void SpeechManger:: show_menu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void  SpeechManger::exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(-1);
}


void SpeechManger::InitSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVectory.clear();
	this->m_Index = 1;
}

//创建12名选手
void SpeechManger::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];
		Speaker sp;
		sp.m_name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_score[i] = 0;
		}
		//12名选手编号
		this->v1.push_back(i + 10001);
		//选手编号以及对应的选手存放到map容器中去
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}