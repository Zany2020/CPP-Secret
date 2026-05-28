#pragma once
#include "CStudent.h"
#include <vector>

class CTeacher : public CPerson
{
public:
	CTeacher();
	~CTeacher();

	void AddStudent(const std::string& stuName);
	void ShowStudents() const;
	//void SetName(const std::string& name);
	//重复定义会报错！！！！！！！！！！！！！
	//！！！！！！！！！！！！！！！

private:
	std::vector<std::string> m_students; // 存储学生姓名的容器

};