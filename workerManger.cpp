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
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->m_FileEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) // ��Ϊ�棬�������ļ�
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArry = NULL;
		this->m_FileEmpty = true;
		ifs.close();
		return;
	}

	int num = this->get_EmpNum();
	cout << "ְ������Ϊ�� " << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArry = new Worker*[this->m_EmpNum];
	this->init_Emp();
}

WorkerManager::~WorkerManager()
{
	delete[]this->m_EmpArry; // ɾ��ԭ���ڴ�ռ�
	this->m_EmpArry = NULL;
}

void WorkerManager::ShowMenu()
{
	cout << "****************************************" << endl;
	cout << "********  ��ӭʹ��ְԱ����ϵͳ  ********" << endl;
	cout << "********  0.�˳�����ϵͳ        ********" << endl;
	cout << "********  1.����ְ����Ϣ        ********" << endl;
	cout << "********  2.��ʾְ����Ϣ        ********" << endl;
	cout << "********  3.ɾ����ְԱ��        ********" << endl;
	cout << "********  4.�޸�ְ����Ϣ        ********" << endl;
	cout << "********  5.����ְ����Ϣ        ********" << endl;
	cout << "********  6.���ձ������        ********" << endl;
	cout << "********  7.���������Ϣ        ********" << endl;
	cout << "****************************************" << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "������  " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace = new Worker*[newSize];//��������Ϊָ�����ͣ��ʿ�����һ���ڴ棬������work�����ָ�����,ָ���������� ���½�һ��ָ�����͵�ָ��ȥά������ڴ�
		if (this->m_EmpArry != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArry[i];
			}
		}
		// ���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������Ա����ţ�" << endl;
			cin >> id;
			cout << "������Ա��name��" << endl;
			cin >> name;
			cout << "1.worker��" << endl;
			cout << "2.manager��" << endl;
			cout << "3.boss��" << endl;
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
		this->m_EmpArry = newSpace;// ��ָ��ָ�����ڴ�
		newSpace = NULL;
		this->m_EmpNum = newSize; 

		this->m_FileEmpty = false;

		cout <<"��ӳɹ���" << endl;

		this->save();
	}
	else
	{
		cout << "��������" << endl;
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
		num++; //��һ��
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
		cout << "�ļ������ڻ���Ϊ��" << endl;
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
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "�������ţ� " << endl;
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

			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ��" << endl;
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
		cout << "�ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "������Ա�����룺" << endl;
	}
}


