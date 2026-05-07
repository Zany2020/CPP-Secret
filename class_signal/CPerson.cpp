#include "CPerson.h"
#include "CMobilePhone.h"
#include <iostream>

CPerson::CPerson(std::string n, int a, bool g, CMobilePhone* p)
	: name(n), age(a), gender(g), phone(p)	{ }

void CPerson::whoareyou()
{
	std::cout << "我是" << name << "，今年" << age << "岁。我是" 
		<< (gender ? "男生" : "女生") << "。" << std::endl;
}

void CPerson::callsomeone(CPerson* p)
{
    std::cout << name << "想要打电话给" << (p ? p->getName() : "未知人") << std::endl;

    if (!phone)
    {
        std::cout << name << "很穷没有手机" << std::endl;
        return;
    }

    phone->call(p); 
}

std::string CPerson::getName() const { return name; }
CMobilePhone* CPerson::getPhone() const { return phone; }
void CPerson::setPhone(CMobilePhone* newPhone) { phone = newPhone; }