#pragma once
#include <iostream>
#include <string>


class CShape 
{
public:
	virtual void display() const = 0; // 纯虚函数，要求派生类必须实现
	virtual ~CShape() {} // 虚析构函数，确保派生类对象被正确销毁
};
