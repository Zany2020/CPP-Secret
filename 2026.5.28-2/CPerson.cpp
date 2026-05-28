#include "CPerson.h"

CPerson::CPerson()
{
	m_strName = "0";
	m_nAge = 0;
	m_strSex = "0";
}//构造函数初始化

CPerson::~CPerson()
{ }//析构函数

void CPerson::SetName(const std::string& name)
{
	m_strName = name;
}//设置名字

std::string CPerson::GetName() const
{
	return m_strName;
}//获取名字