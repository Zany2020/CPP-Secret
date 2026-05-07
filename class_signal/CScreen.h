
#pragma once
	//#include "CMobilePhone.h"
	//A 包含 B → B 包含 A → 编译器死循环 → 直接报错
#include <iostream>
#include <string>
class CMobilePhone;  // 前向声明

class CScreen
{
private:
	std::string size;
	std::string resolution;
	std::string TechType;
	std::string Manufacturer;
	std::string matchModel; // 适配型号

public:
	CScreen(double s, std::string res, std::string t, std::string m, std::string model);
	void showScreenInfo();
	bool isCompatibleWithPhone(CMobilePhone* phone);
	std::string getMatchModel() const;
};