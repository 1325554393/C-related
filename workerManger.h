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
	Worker ** m_EmpArry;// 在堆中新建一个数组内存，存储人员对象信息
	void Add_Emp();
	void save();

	int get_EmpNum();
	void show_Emp();

	void Del_Emp();
	int IsExist(int id);

	void Mod_Emp();

	void init_Emp(); // 初始化员工

	bool m_FileEmpty;
	int m_EmpNum;// 记录在职人员
};