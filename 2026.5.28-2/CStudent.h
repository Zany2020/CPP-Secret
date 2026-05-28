#pragma once
#include "CPerson.h"

class CStudent : public CPerson
{
public:
	CStudent();
	~CStudent();
	void SetTeacher(std::string teaName);
	std::string GetTeacher();


private:
	std::string m_strTeacher;
};