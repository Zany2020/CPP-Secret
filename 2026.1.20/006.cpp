#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


//class Test {};
////Test 类是空类，编译器会为这个类自动生成「默认拷贝构造函数」
////ps：若手动写任意构造，编译器不再生成默认无参构造
//
//void fun(Test t)
//{}
//
//Test getObj() 
//{ 
//    Test a;
//    return a; 
//    //调用「拷贝构造函数」，
//    //把局部对象 a 的内容，拷贝到一个「函数栈外的临时匿名对象」中
//}
//
//int main() 
//{
//    Test a;
//    Test b = a;  // 场景1
//    Test c(a);   // 场景2
//    c = a; // c是已经存在的.对象，只是赋值      // 场景3
//    fun(a);      // 场景4
//    Test d = getObj(); // 场景5
//    return 0;
//}
//////////////////////////////////////////////////////////////////////////////////////////////
//
//#include <cstring>
//class String 
//{
//public:
//    char* p;
//    // 有参构造
//    String(const char* s)
//    {
//        std::cout << "调用有参构造" << std::endl;
//        p = new char[strlen(s) + 1];//6
//        strcpy(p, s);
//    }
//    // 析构函数
//    ~String()
//    {
//        std::cout << "调用析构函数，释放地址：" << (void*)p << std::endl;
//        delete[] p;
//        p = nullptr;
//    }
//};
//
//int main() 
//{
//    String s1("hello");
//    String s2 = s1; // 用s1初始化s2
//        //默认的浅拷贝构造函数，
//        ///只会把s1.p的地址值拷贝给s2.p，s1.p 和 s2.p 指向同一块堆内存地址
//
//    return 0;
//}
////运行崩溃，触发（）double free (重复释放) 错误

//////////////////////////////////////////////////////////////////////////////////////////////
//
//#include <iostream>
//using namespace std;
//class A 
//{
//public:
//    A()
//    { cout << "无参构造" << endl; }
//
//    A(const A& aa)
//    { cout << "拷贝构造" << endl; }
//};
//
//// 传值传参
//void func1(A obj) {}      //-传值传参
//// 传引用传参
//void func2(A& ref_obj) {}    //-传引用传参
//
////C++ 里的「引用（&）」可以理解为给一个已经存在的变量 / 对象起了一个 “外号”
////这个外号和原变量指向同一块内存地址，并不是创建了一个新东西
//
//A func3() 
//{
//    A temp;
//    return temp;
//    // 2. 默认拷贝构造函数（你所有初始化拷贝、return、传参都靠它）
//    //Test(const Test & t) {}
//}
//
//int main() 
//{
//    A a;
//    func1(a);
//    func2(a);//→ 引用传递，形参是实参的别名，不调用任何构造，无输出；
//             //不是新的出现就不用调用构造函数
//    A b = func3();
//    return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////

//#include <iostream>
//#include <cstring>
//using namespace std;
//class MyString
//{
//private:
//    char* str; // 堆区字符指针
//public:
//    // 有参构造：给字符串分配堆内存
//    MyString(const char* s = nullptr) //如果调用构造函数时不传参，s 就默认是 nullptr
//    {
//        if (s != nullptr) 
//        {
//            str = new char[strlen(s) + 1];
//            strcpy(str, s);
//        }
//
//        else 
//        {
//            str = nullptr;
//        }
//    }
//
//    ////////////////////////////////////////////////////////////////
//
//    //// ============ 手动实现：深拷贝 拷贝构造函数 ============
//    
////拷贝构造函数的定义就是：用一个已存在的同类对象，去初始化一个新对象 时调用的构造函数
////初始化 + 拷贝”，缺一不可。
//    MyString(const MyString& other)
//        //&（引用）是核心，const 是安全补充
//    {
//        if (other.str != nullptr)
//        {
//            str = new char[strlen(other.str) + 1];
//            strcpy(str, other.str);
//        }
//        else
//        {
//            str = nullptr;
//        }
//    }
//
//    // ============ 手动实现：深拷贝 赋值运算符重载 ============
//    MyString& operator = (const MyString& other)
//    {
//        if (this == &other)
//           //this 是 s3 的地址，&other 是 s1 的地址
//        {
//            return *this;
//        }
//
//        if (str != nullptr)
//        {
//            delete[] str;
//            str = nullptr;
//        }
//
//        if (other.str != nullptr)
//            //s2.str 指向另一块独立的堆内存，内容和 s1 相同，但地址不同（深拷贝核心）
//        {
//            str = new char[strlen(other.str) + 1];
//            strcpy(str, other.str);
//        }
//        else
//        {
//            str = nullptr;
//        }
//
//        return *this;
//    }
//    ////////////////////////////////////////////////////////////////
//
//    // 析构函数：释放堆内存
//    ~MyString() 
//    {
//        if (str != nullptr) 
//        {
//            delete[] str;
//            str = nullptr;
//        }
//    }
//
//    // 打印字符串
//    void show() 
//    {
//        if (str)
//        {
//            cout << str << endl;
//        }
//    }
//};
//
//int main() 
//{
//    MyString s1("C++ 拷贝构造");
//    MyString s2 = s1; // 拷贝构造
//                      // = 在这里是初始化，不是赋值（初始化 + 拷贝才会去调用构造函数）
//        //编译器使用默认的浅拷贝-->s2 = s1 拷贝构造时，s1 和 s2 的 str 指向同一块堆内存
//        //                       s3 = s1 赋值时，s3 的 str 也指向同一块堆内存
//        //                       析构时三个对象重复释放同一块内存，程序崩溃。
//
//    MyString s3;
//    s3 = s1;          //s3 已经创建完成，= 是赋值操作，
//                      //触发赋值运算符重载函数（默认）
//    return 0;
//}


//////////////////////////////////////////////////////////////////////////////////////////////
//基础编程题 - 实现深拷贝的拷贝构造 + 赋值重载（必写）
//定义一个 Person 类，包含两个成员：
//普通成员：int age;
//堆区成员：char* name; （姓名，堆区开辟内存）
//要求实现：
//无参构造函数、有参构造函数（初始化 age 和 name）
//析构函数（释放堆区 name 的内存）
//手动实现深拷贝的拷贝构造函数
//手动实现深拷贝的赋值运算符重载
//成员函数 showInfo() 打印姓名和年龄

#include <iostream>
#include <cstring>
class Person
{
private:
	int age;
	char* name;
public:
	/*Peoson()
	{
		age = 17;
	}*/
	//无参构造
	Person() 
	{
		age = 0;
		name = nullptr;
		std::cout << "调用无参构造" << std::endl;
	}

	//有参构造---->先初始化
	/*Person(const char* n = nullptr)
	{
		if (n != nullptr)
		{
			name = new char[strlen(n) + 1];
			strcpy(name, n);
		}
	}*/
	Person(int a, const char* n) 
	{
		age = a;
		// 堆区开辟内存
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		std::cout << "调用有参构造" << std::endl;
	}

	//-----------//深拷贝
	Person(const Person& other)
	{
		age = other.age;
		if (other.name != nullptr)
		{
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
		}
		else
		{
			name = nullptr;
		}
	}

	//-----------//深拷贝的赋值运算符重载

	Person& operator = (const Person& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (name != nullptr)
		{
			delete[] name;
			name = nullptr;
		}

		age = other.age;
		if (other.name != nullptr)
		{
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
		}
		else
		{
			name = nullptr;
		}

		std::cout << "调用赋值运算符重载" << std::endl;
		return *this;//赋值运算符重载的 “标准写法”，必须保留
	}

	void showInfo()
	{
		std::cout <<"姓名：" << name << ", 年龄：" << age << std::endl;
	}



	~Person()
	{
		if (name != nullptr)
		{
			delete[] name;
			name = nullptr;
		}
		std::cout << "调用析构函数" << std::endl;
	}

};

int main()
{
	Person p1(19, "Kana");
	Person p2 = p1;	//用已有对象初始化新对象不会打印「调用有参构造」
	Person p3(18, "Akane");
	Person p4;
	p4 = p3;

	p1.showInfo();
	p2.showInfo();
	p3.showInfo();
	p4.showInfo();
	return 0;
}