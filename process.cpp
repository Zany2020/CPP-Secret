#define _CRT_SECURE_NO_WARNINGS
#include"CMobilePhone.h"
#include<iostream>
#include <string>

//std::string name;
//const std::string model;
//const double length;
//const double width;
//const double height;
//std::string user;
//std::string number;

CMobilePhone::CMobilePhone(std::string n, const std::string m, std::string u, std::string num, const double l, const double w, const double h)
    :model(m), length(l), width(w), height(h)
{
    name = n;
    user = u;
	number = num;
}

CMobilePhone::CMobilePhone(std::string n, std::string m, double l, double w, double h)
    :model("17"), length(149.6), width(71.5), height(8.75)
{
    name = n;
};

CMobilePhone::CMobilePhone()
    : model("17"), length(149.6), width(71.5), height(8.75)  // const变量初始化
{
    name = "iPhone";
    user = "Akane";
    number = "1145114";
}

void CMobilePhone::setname(std::string n)
{
    name = n;
}

void CMobilePhone::setuser(std::string u)
{
    user = u;
}

void CMobilePhone::setnumber(std::string num)
{
    number = num;
}

void CMobilePhone::showinfo()
{
    std::cout << "手机名: " << name << std::endl;
    std::cout << "型号: " << model << std::endl;
}

void CMobilePhone::showsize()
{
    std::cout << "尺寸: " << length << " x " << width << " x " << height << std::endl;
}

void CMobilePhone::showuser()
{
	std::cout << "用户: " << user << std::endl;
}

void CMobilePhone::shownumber()
{
    std::cout << "号码: " << number << std::endl;
}


void CMobilePhone::show()
{
    CMobilePhone::showinfo();
	CMobilePhone::showsize();
    CMobilePhone::showuser();
    CMobilePhone::shownumber();
    std::cout << std::endl;
}



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

