#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

// ====================== 1. 抽象（Abstraction）======================
class Person
{
protected:
	// 封装：属性私有化/受保护，仅通过成员函数访问
	std::string name;
	int age;

public:
	/// 构造函数（封装：初始化属性)
	Person(std::string n, int a)
		:name(n), age(a) { }
	
	 // 纯虚函数：抽象出"展示信息"的行为，具体实现由子类决定,强制派生类实现统一行为
	virtual void showinfo() const = 0; // 纯虚函数，Person是抽象类

	// 纯虚函数：抽象出"工作/学习"的行为，具体实现由子类决定
	virtual void doWork() const = 0;

	//析构函数：虚析构保证子类析构时正确调用
	virtual ~Person() = default;
};

// ====================== 2. 封装（Encapsulation） + 3. 继承（Inheritance）======================
// 子类1：Student（学生），继承自Person
// 继承：复用Person的属性（name/age）和抽象行为，扩展自身特性
class Student : public Person
{
private:
	std::string ID; // 学生特有属性
	float score;   // 学生成绩
public:
	// 构造函数：调用父类构造函数初始化继承的属性，再初始化自身属性
	Student(std::string n, int a, std::string id, float s)
		: Person(n, a), ID(id), score(s) { }
	
	// 封装：提供私有属性的访问接口（只读）
	float getAverageScore() const 
	{
		return score;
	}

	// 重写父类纯虚函数：实现学生的"展示信息"（多态基础）'
	void showinfo() const override 
					//override的核心作用是：告诉编译器 “我这个成员函数是用来重写基类中对应的虚函数的”
	{
		std::cout << "学生信息：姓名=" << name << ", 年龄=" << age 
				  << ", 学号=" << ID << ", 成绩=" << score << std::endl;
	}

	// 重写父类纯虚函数：实现教师的"授课"行为（多态基础）
	void doWork() const override 
	{
		std::cout << name << "学生完成面向对象编程实践" << std::endl;
	}

	// ====================== 4. 多态（Polymorphism）======================
	// 多态：父类指针/引用指向子类对象，调用时自动执行子类的重写函数
	// 统一接口处理不同子类对象，体现"一个接口，多种实现"

	void personDoWork(const Person& person) 
	{
		person.doWork();  // 根据传入的实际对象（Student/Teacher）执行不同的doWork
	}


};

int main()
{
	Student s("Alice", 20, "S12345", 95.5);
	s.showinfo(); // 调用学生的展示信息
	s.personDoWork(s); // 调用学生的工作行为（多态）

	Person* p = &s; // 父类指针指向学生对象
	p->showinfo(); // 调用学生的展示信息（多态）
	p->doWork(); // 调用学生的工作行为（多态）

	//personDoWork() 是 Student 类的成员函数，而非 Person 基类的成员函数，
	//而 p 是 Person* 类型的指针 —— 基类指针只能访问基类中声明的成员（包括虚函数），无法直接访问子类独有的成员函数

	return 0;
}