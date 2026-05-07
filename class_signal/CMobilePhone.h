#define _CRT_SECURE_NO_WARNINGS
#include "CScreen.h"
#include<iostream>
#include <string>

class CPerson;

class CMobilePhone
{
private:
    std::string name;
    const std::string model;
    const double length;
    const double width;
    const double height;
    std::string user;
    std::string number;
    CScreen screen;  // 组合：仅声明

public:
    // 仅声明
    CMobilePhone(std::string n, std::string m, double l, double w, double h,
        std::string u, std::string num, double s, std::string res,
        std::string tech, std::string manu, std::string modelMatch);

    void showParameter();
    void call(CPerson* p);

    // get/set 仅声明
    std::string getModel() const;
    std::string getUser() const;
    std::string getName() const;
    void setUser(std::string newUser);
};
