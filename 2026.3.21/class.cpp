#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<vector>

class Student
{
private:
	std::string name;
	int age;
	std::string ID;
public:
	Student(std::string const& name, int age, std::string const& ID)
		// std::string 支持拷贝，但加上 & 后，函数不会创建新的字符串副本，而是直接使用传入的原字符串
		:name(name), age(age), ID(ID) {}


	void showInFo()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Age: " << age << std::endl;
		std::cout << "ID: " << ID << std::endl;
	}

};

int main()
{
	Student REM("rem", 17, "20200710");
	REM.showInFo();

	return 0;
}