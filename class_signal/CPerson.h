#pragma once
#include <iostream>
#include <string>

class CMobilePhone;  // 前向声明

class CPerson
{
private:
    std::string name;
    int age;
    bool gender;
    CMobilePhone* phone;  // 指针仅声明
public:
    CPerson(std::string n, int a, bool g, CMobilePhone* p);

    void whoareyou();
    void callsomeone(CPerson* p);

    std::string getName() const;
    CMobilePhone* getPhone() const;
    void setPhone(CMobilePhone* newPhone);
};

