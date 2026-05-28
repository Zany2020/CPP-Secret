#include "CStudent.h"

CStudent::CStudent() { m_strTeacher = ""; }
CStudent::~CStudent() { }

void CStudent::SetTeacher(std::string teaName)
{
	m_strTeacher = teaName;
}

std::string CStudent::GetTeacher()
{
	return m_strTeacher;
}
