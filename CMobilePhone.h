#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include<iostream>
#include <string>



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

public:
    CMobilePhone(std::string n, std::string m, std::string u, std::string num, double l, double w, double h);
    CMobilePhone(std::string n, std::string m, double l, double w, double h);
    CMobilePhone();

    //void setinfo(std::string n, std::string m, double l, double w, double h);
    void showinfo();
    void showsize();
    
    void setname(std::string n);
    void setuser(std::string u);  
    void setnumber(std::string num);

    void showuser();
	void shownumber();

    void show();
};