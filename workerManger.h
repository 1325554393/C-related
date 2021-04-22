#pragma once
#include <iostream>
#include "Worker.h"
#include "Boss.h"
#include "Manager.h"
#include "Employ.h"
using namespace std;

#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();

	void ShowMenu();
	void ExitSystem();
	Worker ** m_EmpArry;// �ڶ����½�һ�������ڴ棬�洢��Ա������Ϣ
	void Add_Emp();
	void save();

	int get_EmpNum();
	void show_Emp();

	void Del_Emp();
	int IsExist(int id);

	void Mod_Emp();

	void init_Emp(); // ��ʼ��Ա��

	bool m_FileEmpty;
	int m_EmpNum;// ��¼��ְ��Ա
};