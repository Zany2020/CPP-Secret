#include "CTeacher.h"

// CTeacher 类的各种成员函数的实现
CTeacher::CTeacher() {}
CTeacher::~CTeacher() {}

void CTeacher::setTeacher()
{
    setPerson();
    cout << "请输入职称：";
    cin >> title;
    cout << "请输入部门：";
    cin >> dept;
}
void CTeacher::showTeacher()
{
    cout << "\n===教师信息===" << endl;
    showPerson();
    cout << "title:" << title << "\t dept:" << dept;
}