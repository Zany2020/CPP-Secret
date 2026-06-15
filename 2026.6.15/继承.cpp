#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class base1
{
public:
    base1() 
    {
       cout << "class base1" << endl;
    }
};

class base2 
{
public:
    base2() 
    {
        cout << "class base2" << endl;
    }
};

class level1 : public base2, virtual public base1   
      //虚基类在整个菱形继承体系中只初始化一份，其余子类遇到虚基类会直接跳过
{
public:
    level1() 
    {
        cout << "class level1" << endl;
    }
};

class level2 : public base2, virtual public base1 
{
public:
    level2() 
    {
        cout << "class level2" << endl;
    }
};

class toplevel :public level1, virtual public level2 
{
public:
    toplevel() 
    {
        cout << "class toplevel" << endl;
    }
};

void main()
{
    toplevel obj;
}

//虚基类 (virtual 继承) 最先构造，全局只构造一次
//普通继承父类，按照代码中继承声明的顺序依次构造