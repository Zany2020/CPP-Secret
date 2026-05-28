#pragma once
#include <iostream>
#include <string>

class CPerson
{
public:
	CPerson();
	~CPerson();

	void SetName(const std::string& name);
	std::string GetName() const;

protected:
	std::string m_strName;
	int m_nAge;
	std::string m_strSex;
};
