#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<memory>
#include<string>


//class iPhone 
//{
//public:
//    std::string brand;
//    iPhone(std::string b) : brand(b)    // 构造函数接收string类型的b
//    { std::cout << brand << "手机 构造" << std::endl; }
//    
//    ~iPhone()
//    { std::cout << brand << "手机 析构" << std::endl; }
//};
//
//
//int main() 
//{
//    std::weak_ptr<iPhone>  wp;  // 定义一个弱智能指针x
//    {
//        std::shared_ptr<iPhone> sp = std::make_shared<iPhone>("苹果");
//        wp = sp;    // 弱指针指向共享指针管理的对象
//        std::cout << "【作用域内】计数：" << wp.use_count() << std::endl;
//        std::cout << "【作用域内】对象是否存活：" << !wp.expired() << std::endl;
//                            //expired() 是 std::weak_ptr 专属成员函数
//                            //返回 true → 指针指向的对象已经被销毁 / 失效 / 不存在了；
//                            //返回 false → 指针指向的对象还存活、有效，可以正常访问。
//    }
//    std::cout << "【作用域外】计数：" << wp.use_count() << std::endl;
//    std::cout << "【作用域外】对象是否存活：" << !wp.expired() << std::endl;
//
//    // 尝试通过weak_ptr访问对象，补全代码：如何安全访问？
//    // 这里写访问代码
//    return 0;
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////////


//class Pen 
//{
//public:
//    Pen() 
//    { std::cout << "钢笔构造" << std::endl; }
//    
//    ~Pen()
//    { std::cout << "钢笔析构" << std::endl; }
//};
//
//class Student 
//{
//public:
//    std::unique_ptr<Pen> pen;
//    Student() 
//    { pen = std::make_unique<Pen>(); }
//    
//    ~Student() 
//    {} // 无需手动写delete，智能指针自动释放
//};
//
//// 函数返回一个unique_ptr
//std::unique_ptr<Pen> getPen() 
//{
//    std::unique_ptr<Pen> up(new Pen);
//    return up;//合法
//    //unique_ptr 可以作为函数的返回值，编译器自动优化为移动语义，合法且高效
//}
//
//int main() 
//{
//    Student stu;
//    std::unique_ptr<Pen> myPen = getPen();
//    return 0;
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////////


//class Food 
//{
//public:
//    Food()
//    { std::cout << "食物构造" << std::endl; }
//    
//    ~Food() 
//    { std::cout << "食物析构" << std::endl; }
//};
//
//class Person 
//{
//public:
//    std::shared_ptr<Food> food;
//    Person(std::shared_ptr<Food> f) : food(f) {}
//    //（前一个f）形参 f 是这个传入的共享指针的「副本」（局部形参）
//     
//                           //这个冒号是 C++ 中的 初始化列表语法，
//                           //作用是：在构造函数函数体执行之前，提前初始化当前类的成员变量
//                           //这里表示初始化food为f（把构造函数的形参f赋值给food）
//};
//
//int main()
//{
//    std::shared_ptr<Food> f = std::make_shared<Food>();
//    Person p1(f);
//    Person p2(f);
//    //传入shared_ptr类型的参数，或给shared_ptr赋值，都会让【引用计数 + 1】
//    std::cout << "食物的引用计数：" << f.use_count() << std::endl;
//    p1.food.reset();
//    //reset()的作用是「放弃所有权 + 计数 - 1」
//    //reset：让 p1.food 这个共享指针，主动放弃对 Food 对象的所有权（托管权）
//    std::cout << "reset后计数：" << f.use_count() << std::endl;
//    return 0;
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 经典的双向引用场景：老师有学生，学生有老师
class Student; // 前置声明
class Teacher 
{
public:
    std::string name;
    std::shared_ptr<Student> stu; // 老师持有学生的共享指针
    //也能改成weak
    
    Teacher(std::string n) : name(n) 
    { std::cout << name << "老师 构造" << std::endl; }
   
    ~Teacher()
    { std::cout << name << "老师 析构" << std::endl; }
};

class Student 
{
public:
    std::string name;
    //std::shared_ptr<Teacher> tea; // 学生持有老师的共享指针 → 互相持有！
    std::weak_ptr<Teacher> tea;//改版！
    
    Student(std::string n) : name(n) 
    { std::cout << name << "学生 构造" << std::endl; }
    
    ~Student() 
    { std::cout << name << "学生 析构" << std::endl; }
};

int main()
{
    std::shared_ptr<Teacher> t = std::make_shared<Teacher>("王");
    std::shared_ptr<Student> s = std::make_shared<Student>("小明");
    
    t->stu = s;//老师对象的stu持有学生的 shared_ptr → 学生的计数 + 1（作为值传进去的+1）
    s->tea = t;//学生对象的tea持有老师的 shared_ptr → 老师的计数 + 1

    std::cout << "老师的引用计数：" << t.use_count() << std::endl;
    std::cout << "学生的引用计数：" << s.use_count() << std::endl;
    return 0;
}
//只会打印构造函数，永远不会打印析构函数；问题本质：shared_ptr 的循环引用，导致内存泄漏
//改了之后t不加1了，结束调用delete销毁所以变量，包括std::shared_ptr<Student> stu;
//这个变量销毁后student减1，加上函数结束调用的减1加起来就是减2变0了

















