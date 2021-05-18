#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include"Speaker.h"
using namespace std;

//设计演讲比赛管理类
class SpeechManger
{
public:
	SpeechManger();
	void show_menu();
	void exitsystem();
	~SpeechManger();

	//初始化容器
	void InitSpeech();

	//成员属性
	//保存第一轮比赛选手的编号
	vector<int>v1;
	//第一轮晋级的选手容器编号
	vector<int>v2;

	//胜出前三名选手容器编号
	vector<int>vVectory;

	//存放编号及具体从选手
	map<int, Speaker>m_Speaker;

	//存放比赛轮数
	int m_Index;


	//初始化创建12名选手
	void createSpeaker();
};


