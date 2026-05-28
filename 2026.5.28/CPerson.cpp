#include "CPerson.h"

// CPerson 类的各种成员函数的实现
//CPerson::CPerson() {}
//CPerson::~CPerson() {}

void CPerson::setPerson()
{
	cout << "请输入名字:";
	cin >> name;
	cout << "性别：";
	cin >> sex;
	cout << "年龄：";
	cin >> age;
}

void CPerson::showPerson()
{
	cout << "name:" << name << "\t age:" << age << "\t sex:" << sex << endl;
}

void CPerson::setName(string n) { name = n; }
void CPerson::setSex(string s) { sex = s; }
void CPerson::setAge(int a) { age = a; }

string CPerson::get_name() { return name; }
string CPerson::get_sex() { return sex; }
int CPerson::get_age() { return age; }
