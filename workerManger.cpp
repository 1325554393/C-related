#include "workerManger.h"
#include "Employ.h"
#include "Manager.h"
#include "Boss.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->m_FileEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) // 若为真，则代表空文件
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->m_FileEmpty = true;
		ifs.close();
		return;
	}

	int num = this->get_EmpNum();
	cout << "职工人数为： " << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArry = new Worker*[this->m_EmpNum];
	this->init_Emp();
}

WorkerManager::~WorkerManager()
{
	delete[]this->m_EmpArry; // 删除原有内存空间
	this->m_EmpArry = NULL;
}

void WorkerManager::ShowMenu()
{
	cout << "****************************************" << endl;
	cout << "********  欢迎使用职员管理系统  ********" << endl;
	cout << "********  0.退出管理系统        ********" << endl;
	cout << "********  1.增加职工信息        ********" << endl;
	cout << "********  2.显示职工信息        ********" << endl;
	cout << "********  3.删除离职员工        ********" << endl;
	cout << "********  4.修改职工信息        ********" << endl;
	cout << "********  5.查找职工信息        ********" << endl;
	cout << "********  6.按照编号排序        ********" << endl;
	cout << "********  7.清除所有信息        ********" << endl;
	cout << "****************************************" << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "数量：  " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace = new Worker*[newSize];//数据类型为指针类型，故开辟了一个内存，里面是work父类的指针变量,指向各子类对象， 再新建一个指针类型的指针去维护这段内存
		if (this->m_EmpArry != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArry[i];
			}
		}
		// 添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入员工编号：" << endl;
			cin >> id;
			cout << "请输入员工name：" << endl;
			cin >> name;
			cout << "1.worker：" << endl;
			cout << "2.manager：" << endl;
			cout << "3.boss：" << endl;
			cin >> dSelect;

			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employ(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 2);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		this->m_EmpArry = newSpace;// 将指针指向新内存
		newSpace = NULL;
		this->m_EmpNum = newSize; 

		this->m_FileEmpty = false;

		cout <<"添加成功！" << endl;

		this->save();
	}
	else
	{
		cout << "数据有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArry[i]->m_id << " "
			<< this->m_EmpArry[i]->m_Name << " "
			<< this->m_EmpArry[i]->m_Deptid << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id&&ifs >> name&&ifs >> dId)
	{
		num++; //下一行
	}
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id&&ifs >> name&&ifs >> dId)
	{
		Worker *worker = NULL;
		if (dId == 1)
		{
			worker = new Employ(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArry[index] = worker;
		index++;
	}

	ifs.close();
}

void WorkerManager::show_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArry[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入编号： " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArry[i] = this->m_EmpArry[i + 1];
			}
			this->m_EmpNum--;
			this->save();

			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败" << endl;
		}
	}

	system("pause");
	system("cls");
}
	
int WorkerManager::IsExist(int id)
{
	int index = 0;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArry[i]->m_id == i)
		{
			index = i;
			break;
		}
		return -1;
	}
	return index;
}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "文件为空" << endl;
	}
	else
	{
		cout << "请输入员工编码：" << endl;
	}
}


