#include "Manager.h"


Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	m_Name = name;
	m_Deptid = dId;
}

void Manager::showInfo()
{
	cout << "职工编号：  " << m_id << "\t姓名： " << m_Name << "\t岗位：  " << getDeptName()
		<< "\t岗位职责： 完成老板给的任务" << endl;
}

string Manager::getDeptName()
{
	return "经理";
}