#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>

//struct Entity
//{
//	int x, y;
//};

//enum class Color {Red, Green, Blue};

//int main()
//{
//	//Color c = Color::Blue;
//
//
//	return 0;
//}

#include <iostream>
#include <string>
using namespace std;

class Person 
{
public:
    int age;
    string name;
    static int totalNum;

    // 带参构造
    Person(int a, string n) 
    {
        age = a;
        name = n;
        totalNum++;
        cout << "带参构造执行" << endl;
    }

     //✅ 拷贝构造函数
    Person(const Person& obj) 
    {
        age = obj.age;   // 复制旧对象的age
        name = obj.name; // 复制旧对象的name
        totalNum++;
        cout << "拷贝构造函数执行" << endl;
    }
};
int Person::totalNum = 0;

int main() 
{
    Person p1(18, "张三"); // 带参构造 → p1:18岁，张三
    Person p2(p1);         // 拷贝构造 → p2:18岁，张三（和p1一模一样）
    Person p3 = p1;        // ✅ 等价写法，同样调用拷贝构造！

    cout << p2.name << ":" << p2.age << endl; // 张三:18
    cout << p3.name << ":" << p3.age << endl; // 张三:18
    cout << Person::totalNum << endl; // 3
    return 0;
}
