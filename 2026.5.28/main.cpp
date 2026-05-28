#define _CRT_SECURE_NO_WARNINGS

#include "CPerson.h"
#include "CStudent.h"
#include "CTeacher.h"
using namespace std;
//参考的main函数，可以根据自己的情况修改
int main()
{
    // 自行写一些测试代码来验证 CPerson、CStudent 和 CTeacher 类的功能
    // 需要保证有输出

    CStudent stu;
    cout << "--- 输入学生信息 ---" << endl;
    stu.setStudent();
    stu.showStudent();

    cout << "-------------------------" << endl;

    // 测试教师
    CTeacher tea;
    cout << "--- 输入教师信息 ---" << endl;
    tea.setTeacher();
    tea.showTeacher();

    return 0;
}

