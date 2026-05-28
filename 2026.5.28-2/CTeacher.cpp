#include "CTeacher.h"
#include <vector>
#include <iostream>

CTeacher::CTeacher() { }
CTeacher::~CTeacher() { }

void CTeacher::AddStudent(const std::string & stuName) 
{
	m_students.push_back(stuName);
}

void CTeacher::ShowStudents() const
{
    std::cout << "老师：" << m_strName << " 带的学生：";
    if (m_students.empty()) 
    {
        std::cout << "暂无学生";
    }
    else 
    {
        for (const auto& s : m_students) 
        {
            std::cout << s << "  ";
        }
    }
    std::cout << std::endl;
}