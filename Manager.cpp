#include "Manager.h"


Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	m_Name = name;
	m_Deptid = dId;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�  " << m_id << "\t������ " << m_Name << "\t��λ��  " << getDeptName()
		<< "\t��λְ�� ����ϰ��������" << endl;
}

string Manager::getDeptName()
{
	return "����";
}