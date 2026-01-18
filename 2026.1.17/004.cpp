#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<memory>
#include<string>

//class Dog
//{
//public:
//	std::string name;
//	Dog(std::string n) : name(n)
//	{
//		std::cout << name << "-> 小狗出生了（构造）" << std::endl;
//	}
//	~Dog()
//	{
//		std::cout << name << "-> 小狗消失了（析构）" << std::endl;
//	}
//};
//
//int main()
//{
//	std::cout << "===进入main函数===" << std::endl;
//	std::shared_ptr<Dog> sp1(new Dog("旺财"));
//	{
//		std::shared_ptr<Dog> sp2 = sp1;
//		std::shared_ptr<Dog> sp3 = sp2;
//		std::cout << "【作用域内】引用计数 = " << sp1.use_count() << std::endl;
//	}
//	std::cout << "【作用域外】引用计数 = " << sp1.use_count() << std::endl;
//	std::cout << "====main函数结束====" << std::endl;
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////

//class Cat 
//{
//public:
//    Cat()
//    { std::cout << "小猫构造" << std::endl; }
//
//    ~Cat() 
//    { std::cout << "小猫析构" << std::endl; }
//};
//
//int main()
//{
//    std::unique_ptr<Cat> up1(new Cat);
//    //std::unique_ptr<Cat> up2 = up1;
//    std::unique_ptr<Cat> up3 = move(up1);
//    return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////

//class Bird 
//{
//public:
//    Bird()
//    { std::cout << "小鸟构造" << std::endl; }
//    
//    ~Bird()
//    { std::cout << "小鸟析构" << std::endl; }
//};
//
//int main() 
//{
//    Bird b; // 创建一个【栈对象】小鸟
//    std::shared_ptr<Bird> sp(&b); // 用智能指针管理这个栈对象
//    return 0;
//
//    //同一块内存被释放了两次（编译器自动释放一次 + 智能指针 delete 一次）
//    // 触发 C++ 的内存访问错误，程序崩溃
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////

// 汽车类，里面有一个 智能指针成员，指向一个发动机对象
class Engine 
{
public:
    Engine() 
    { std::cout << "发动机 → 构造" << std::endl; }
    
    ~Engine()
    { std::cout << "发动机 → 析构" << std::endl; }
};

class Car 
{
public:
    // 成员变量：用shared_ptr管理发动机对象
    std::shared_ptr<Engine> engine;
    Car() 
    {
        engine = std::make_shared<Engine>();
        //make_shared的作用是帮你在堆上创建一个指定类型的对象，并且把这个对像
        // 直接封装成一个可以用的 std::shared_ptr 智能指针，一步到位返回给你

        //堆上创建 Engine 对象 + 调用构造初始化 + 封装成 shared_ptr」的三合一操作
        // 真正的「初始化」是由Engine的构造函数完成的，make_shared只是触发了构造函数
        //「创建 + 封装」
        std::cout << "汽车 → 构造" << std::endl;
    }

    ~Car() 
    { std::cout << "汽车 → 析构" << std::endl; }
};

int main() 
{
    Car myCar;
    std::cout << "发动机的引用计数：" << myCar.engine.use_count() << std::endl;
    return 0;
}
