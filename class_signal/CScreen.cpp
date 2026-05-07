#include "CScreen.h"
#include "CMobilePhone.h"
#include <iostream>

CScreen::CScreen(double s, std::string res, std::string t, std::string m, std::string model)
	: size(std::to_string(s)), resolution(res), TechType(t), Manufacturer(m), matchModel(model) {}

void CScreen::showScreenInfo()
{
	std::cout << "屏幕尺寸: " << size << " 英寸" << std::endl;
	std::cout << "分辨率: " << resolution << " 像素" << std::endl;
	std::cout << "技术类型: " << TechType << std::endl;
	std::cout << "制造商: " << Manufacturer << std::endl;
}

bool CScreen::isCompatibleWithPhone(CMobilePhone* phone)
{
	if (!phone) return false;
	return phone->getModel() == this->matchModel;
}

std::string CScreen::getMatchModel() const
{
	return matchModel;
}