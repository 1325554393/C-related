#include "Employ.h"


Employ::Employ(int id, string name, int dId)
{
	m_id = id;
	m_Name = name;
	m_Deptid = dId;
}

void Employ::showInfo()
{
	cout << "职工编号：  " << m_id << "\t姓名： " << m_Name << "\t岗位：  " << getDeptName()
		<< "\t岗位职责： 完成经理给的任务" << endl;
}

string Employ::getDeptName()
{
	return "员工";
}