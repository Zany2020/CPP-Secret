
#pragma once
#include <iostream>
#include <string>
class CMobilePhone;     // Ç°ÏòÉùÃ÷
class CScreen
{
private:
	int size;
	int resolution;
	int TechnicalType;
	std::string Manufacturer;

public:
	CScreen(int size, int resolution, int TechnicalType, std::string Manufacturer);
	void showScreenInfo(int size, int resolution, int TechnicalType, std::string Manufacturer);
	bool isCompatibleWithPhone(const CMobilePhone& phone) const;
};