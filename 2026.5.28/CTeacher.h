#pragma once
#include "CStudent.h"
using namespace std;

class CTeacher : public CPerson
{
private:
	string title;
	string dept;
public:
	CTeacher();//{}
	~CTeacher();//{}

	void showTeacher();
	//{}
	void setTeacher();
	//{}
};
