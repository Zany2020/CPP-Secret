#include "CStudent.h"

// CStudent 类的各种成员函数的实现
CStudent::CStudent() { cout << "student 子类构造函数" << endl; }
CStudent::~CStudent() {}

void CStudent::setStudent()
{
	setPerson();
	cout << "id:" << endl;
	cin >> classid;
	cout << "score:" << endl;
	cin >> score;
}

void CStudent::showStudent()
{
	cout << "\n===student's information" << endl;
	showPerson();
	cout << "班号：" << classid << "\t 成绩：" << score << endl;
}

