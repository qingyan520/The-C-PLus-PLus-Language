#include"speechManger.h"
SpeechManger::SpeechManger()
{
	//��ʼ����������
	this->InitSpeech();
}

SpeechManger::~SpeechManger()
{

}
void SpeechManger:: show_menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void  SpeechManger::exitsystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
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

//����12��ѡ��
void SpeechManger::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		Speaker sp;
		sp.m_name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_score[i] = 0;
		}
		//12��ѡ�ֱ��
		this->v1.push_back(i + 10001);
		//ѡ�ֱ���Լ���Ӧ��ѡ�ִ�ŵ�map������ȥ
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}