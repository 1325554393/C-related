#include "Employ.h"


Employ::Employ(int id, string name, int dId)
{
	m_id = id;
	m_Name = name;
	m_Deptid = dId;
}

void Employ::showInfo()
{
	cout << "ְ����ţ�  " << m_id << "\t������ " << m_Name << "\t��λ��  " << getDeptName()
		<< "\t��λְ�� ��ɾ����������" << endl;
}

string Employ::getDeptName()
{
	return "Ա��";
}