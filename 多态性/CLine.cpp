#include "CLine.h"

// CLine 类的各种成员函数的实现

void CLine::display() const
{
	std::cout << "Line: ";
	p1.display();
	std::cout << " to ";
	p2.display();
}

double CLine::length() const
{
	double dx = p2.getX() - p1.getX();
	double dy = p2.getY() - p1.getY();
	return std::sqrt(dx * dx + dy * dy);
}