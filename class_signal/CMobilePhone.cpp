#include "CMobilePhone.h"
#include "CPerson.h"
#include <iostream>

CMobilePhone::CMobilePhone(std::string n, std::string m, double l, double w, double h,
    std::string u, std::string num, double s, std::string res,
    std::string tech, std::string manu, std::string modelMatch)
    : name(n), model(m), length(l), width(w), height(h),
    user(u), number(num),
    screen(s, res, tech, manu, modelMatch)  { }

void CMobilePhone::showParameter()
{
    std::cout << "手机名: " << name << std::endl;
    std::cout << "型号: " << model << std::endl;
    std::cout << "尺寸: " << length << " x " << width << " x " << height << std::endl;
    std::cout << "用户: " << user << std::endl;
    std::cout << "号码: " << number << std::endl;
    screen.showScreenInfo();
}

void CMobilePhone::call(CPerson* p)
{
    if (!p)
    {
        std::cout << "拨打失败，未知的联系人。" << std::endl;
        return;
	}
    if (p->getName().empty())
    {
        std::cout << "太穷了没手机" << std::endl;
        return;
	}
	std::cout << this->getUser() << "正在使用" << this->getName() << "给" << p->getName() << "打电话" << std::endl;
}

std::string CMobilePhone::getModel() const { return model; }
std::string CMobilePhone::getUser() const { return user; }
std::string CMobilePhone::getName() const { return name; }
void CMobilePhone::setUser(std::string newUser) { user = newUser; }



////std::string name;
////const std::string model;
////const double length;
////const double width;
////const double height;
////std::string user;
////std::string number;
//
//CMobilePhone::CMobilePhone(std::string n, const std::string m, std::string u, std::string num, const double l, const double w, const double h)
//    :model(m), length(l), width(w), height(h)
//{
//    name = n;
//    user = u;
//	number = num;
//}
//
//CMobilePhone::CMobilePhone(std::string n, std::string m, double l, double w, double h)
//    :model("17"), length(149.6), width(71.5), height(8.75)
//{
//    name = n;
//};
//
//CMobilePhone::CMobilePhone()
//    : model("17"), length(149.6), width(71.5), height(8.75)  // const变量初始化
//{
//    name = "iPhone";
//    user = "Akane";
//    number = "1145114";
//}
//
//void CMobilePhone::setname(std::string n)
//{
//    name = n;
//}
//
//void CMobilePhone::setuser(std::string u)
//{
//    user = u;
//}
//
//void CMobilePhone::setnumber(std::string num)
//{
//    number = num;
//}
//
//void CMobilePhone::showinfo()
//{
//    std::cout << "手机名: " << name << std::endl;
//    std::cout << "型号: " << model << std::endl;
//}
//
//void CMobilePhone::showsize()
//{
//    std::cout << "尺寸: " << length << " x " << width << " x " << height << std::endl;
//}
//
//void CMobilePhone::showuser()
//{
//	std::cout << "用户: " << user << std::endl;
//}
//
//void CMobilePhone::shownumber()
//{
//    std::cout << "号码: " << number << std::endl;
//}
//
//
//void CMobilePhone::show()
//{
//    CMobilePhone::showinfo();
//	CMobilePhone::showsize();
//    CMobilePhone::showuser();
//    CMobilePhone::shownumber();
//    std::cout << std::endl;
//}



//name = "iPhone";
//const std::string mode = "15";
//const double length = 149.6;
//const double width = 71.5;
//const double height = 8.75;
//user = "Akane";
//number = "1145114";




//void CMobilePhone::setinfo(std::string n, std::string m, const double l, const double w, const double h)
//                //通过 :: 明确归属 CMobilePhone 类
//{
//    name = n;
//}

