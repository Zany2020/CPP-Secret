#pragma once
#include "CShape.h"
#include "CPoint.h"
#include<iostream>
#include<vector>

// 继承自CShape, 必须是公有继承才能实现运行时的多态
	// 两个端点CPoint，这里是类的组合
	// 实现虚函数display，输出线段的两个端点坐标
	// 以及其他需要的成员函数，如构造函数、析构函数、set等

class CLine : public CShape
{
private:
	CPoint p1;
	CPoint p2;
public:
	CLine() : p1(), p2() {} // 默认构造函数，初始化端点为(0,0)
	CLine(const CPoint& point1, const CPoint& point2) : p1(point1), p2(point2) {} // 构造函数，初始化端点为指定值
	CLine(const CLine& other) : p1(other.p1), p2(other.p2) {} // 复制构造函数

	~CLine() override {}

	void setP1(const CPoint& point) { p1 = point; } // 设置第一个端点
	void setP2(const CPoint& point) { p2 = point; } // 设置第二个端点
	CPoint getP1() const { return p1; } // 获取第一个端点
	CPoint getP2() const { return p2; } // 获取第二个端点

	void display() const override;

	bool isPointOnline(const CPoint& point) const; // 判断一个点是否在线段上
	//函数尾巴的 const意思：调用这个函数的线段对象自己，也不能被修改！

	double length() const; // 计算线段的长度

	//// 选做：流运算符重载（友元函数）
	//friend ostream& operator<<(ostream& os, const CLine& line);
	//friend istream& operator>>(istream& is, CLine& line);

};