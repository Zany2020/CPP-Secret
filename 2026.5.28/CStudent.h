#pragma once
#include "CPerson.h"


class CStudent : public CPerson
{
	// 继承自CPerson, 可以根据需要设置继承方式可以根据需要添加数据成员和成员函数
private:
	string classid;
	float score;
public:
	CStudent();//	{	cout << "student 子类构造函数" << endl;	}
	~CStudent();//{}

	void setStudent();
	//{	}

	void showStudent();
	//{	}

};
