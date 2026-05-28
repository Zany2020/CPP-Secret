#pragma once
#include <iostream>
#include <string>
//#include "CMobilePhone.h"
using namespace std;

class CPerson
{
private:
	string name;
	string sex;
	int age;
public:

	void setPerson();
	void showPerson();

	void setName(string n);
	void setSex(string s);
	void setAge(int a);
	string get_name();
	string get_sex();
	int get_age();
};