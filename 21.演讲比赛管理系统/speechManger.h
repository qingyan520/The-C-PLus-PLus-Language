#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include"Speaker.h"
using namespace std;

//����ݽ�����������
class SpeechManger
{
public:
	SpeechManger();
	void show_menu();
	void exitsystem();
	~SpeechManger();

	//��ʼ������
	void InitSpeech();

	//��Ա����
	//�����һ�ֱ���ѡ�ֵı��
	vector<int>v1;
	//��һ�ֽ�����ѡ���������
	vector<int>v2;

	//ʤ��ǰ����ѡ���������
	vector<int>vVectory;

	//��ű�ż������ѡ��
	map<int, Speaker>m_Speaker;

	//��ű�������
	int m_Index;


	//��ʼ������12��ѡ��
	void createSpeaker();
};


