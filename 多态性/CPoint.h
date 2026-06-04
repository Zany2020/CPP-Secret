#pragma once
#include"CShape.h"

// 包含两个数据成员x和y，表示点的坐标
// 实现虚函数display，输出点的坐标
// 以及其他需要的成员函数，如构造函数、析构函数、set等
class CPoint : public CShape 
{
private:
	double x;
	double y;
public:
	CPoint() : x(0.0), y(0.0) {} // 默认构造函数，初始化坐标为(0, 0)
	CPoint(double x_d, double y_d) : x(x_d), y(y_d) {} // 构造函数，初始化坐标为指定值
	CPoint(const CPoint& other) : x(other.x), y(other.y) {} // 复制构造函数
	~CPoint() override {} // override确保正确重写父类的虚析构函数

	void setX(double x_) { x = x_; } // 设置x坐标
	void setY(double y_) { y = y_; } // 设置y坐标
	double getX() const { return x; } // 获取x坐标
	double getY() const { return y; } // 获取y坐标

	void display() const override;

	//friend ostream& operator<<(ostream& os, const CPoint& p);
	//friend istream& operator>>(istream& is, CPoint& p);

};
