#include <iostream>
#pragma once
#include "Worker.h"
using namespace std;


class Employ :public Worker
{
public:
	Employ(int id, string name, int dId);
	virtual void showInfo();
	virtual string getDeptName();
};