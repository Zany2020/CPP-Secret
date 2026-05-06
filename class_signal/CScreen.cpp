#include "CScreen.h"
#include "CMobilePhone.h"

// CScreen 类的各种成员函数的实现
CScreen::CScreen(int size, int resolution, int TechnicalType, std::string Manufacturer)
	: size(size), resolution(resolution), TechnicalType(TechnicalType), Manufacturer(Manufacturer) { }
//构造函数初始化成员变量

void CScreen::showScreenInfo(int size, int resolution, int TechnicalType, std::string Manufacturer)
{
	std::cout << "屏幕尺寸: " << size << " 英寸" << std::endl;
	std::cout << "分辨率: " << resolution << " 像素" << std::endl;
	std::cout << "技术类型: " << TechnicalType << std::endl;
	std::cout << "制造商: " << Manufacturer << std::endl;
}

bool CScreen::isCompatibleWithPhone(const CMobilePhone& phone) const
{
	std::cout << "是否符合：ok" << std::endl;
	return true; // 这里暂时返回true，表示兼容
}