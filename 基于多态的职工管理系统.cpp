#include <iostream>
#include "Worker.h"
#include "Employ.h"
#include "Manager.h"
#include "Boss.h"
#include "workerManger.h"
using namespace std;

int main()
{

	/*Worker *worker = NULL;
	worker = new Employ(1, "����", 1);
	worker->showInfo();*/

	WorkerManager wm;
	wm.ShowMenu();

	cout << "��������Ĳ����� ";
	int choice;
	cin >> choice;

	while (choice)
	{
		switch (choice)
		{
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.show_Emp();
			break;
		case 3:
			wm.Del_Emp();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 0:
			wm.ExitSystem();
			break;
		default:
			system("cls");
		}
		cout << "��������Ĳ����� ";
		cin >> choice;
	}

	system("pause");

	return 0;
}