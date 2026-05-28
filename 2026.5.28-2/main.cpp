#include "CPerson.h"
#include "CStudent.h"
#include "CTeacher.h"
using namespace std;
int main()
{
    vector<CStudent> students;  // 所有学生
    vector<CTeacher> teachers;  // 所有老师
    int choice;

    while (true)
    {
        // 菜单
        cout << "\n===== 导师选择系统 =====" << endl;
        cout << "1. 创建学生" << endl;
        cout << "2. 创建老师" << endl;
        cout << "3. 学生选择导师" << endl;
        cout << "4. 显示所有学生（含导师）" << endl;
        cout << "5. 显示所有老师（含学生）" << endl;
        cout << "0. 退出" << endl;
        cout << "请输入选项：";

        cin >> choice;

        if (choice == 0) break;

        switch (choice)
        {
            // 1. 创建学生
        case 1: {
            string name;
            cout << "请输入学生姓名：";
            cin >> name;
            CStudent stu;
            stu.SetName(name);
            students.push_back(stu);
            cout << "学生创建成功！" << endl;
            break;
        }

              // 2. 创建老师
        case 2: {
            string name;
            cout << "请输入老师姓名：";
            cin >> name;
            CTeacher tea;
            tea.SetName(name);
            teachers.push_back(tea);
            cout << "老师创建成功！" << endl;
            break;
        }

              // 3. 学生选导师
        case 3: {
            if (students.empty() || teachers.empty()) {
                cout << "请先创建学生和老师！" << endl;
                break;
            }

            // 显示学生列表
            cout << "\n学生列表：" << endl;
            for (int i = 0; i < students.size(); i++) {
                cout << i + 1 << ". " << students[i].GetName() << endl;
            }
            int stuIdx;
            cout << "选择学生（序号）：";
            cin >> stuIdx;
            stuIdx--;

            // 显示老师列表
            cout << "\n老师列表：" << endl;
            for (int i = 0; i < teachers.size(); i++) {
                cout << i + 1 << ". " << teachers[i].GetName() << endl;
            }
            int teaIdx;
            cout << "选择导师（序号）：";
            cin >> teaIdx;
            teaIdx--;

            // 绑定关系
            students[stuIdx].SetTeacher(teachers[teaIdx].GetName());
            teachers[teaIdx].AddStudent(students[stuIdx].GetName());
            cout << "选择导师成功！" << endl;
            break;
        }

              // 4. 显示所有学生 + 导师
        case 4: {
            cout << "\n===== 所有学生 =====" << endl;
            for (auto& s : students) {
                cout << "学生：" << s.GetName()
                    << "  导师：" << s.GetTeacher() << endl;
            }
            break;
        }

              // 5. 显示所有老师 + 所带学生
        case 5: {
            cout << "\n===== 所有老师 =====" << endl;
            for (auto& t : teachers) {
                t.ShowStudents();
            }
            break;
        }

        default:
            cout << "输入错误！" << endl;
        }
    }

    return 0;
}