#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//抽象基类
class Container
{
public:
	virtual double getVolume() const = 0;  //纯虚函数:没有函数体的虚函数	 
	//语法特征：唯一标识:在虚函数声明末尾加上 = 0
	//所有继承自Container的派生类必须实现这个函数,
	//只要类中包含至少一个纯虚函数，这个类就不能被实例化
	virtual ~Container() {};
};

class Sphere : public Container
{
private:
	double radius;
public:
	Sphere(double r) : radius(r) {}

	double getVolume() const override//显式声明这个函数是重写基类的虚函数
	{
		return (4.0 / 3.0) * M_PI * pow(radius, 3);
	}
};

class Cylinder : public Container
{
private:
	double radius;
	double height;
public:
	Cylinder(double r, double h) : radius(r), height(h) {}
	double getVolume() const override
	{
		return M_PI * pow(radius, 2) * height;
	}
};

class Cube : public Container
{
private:
	double side;
public:
	Cube(double s) : side(s) {}
	double getVolume() const override
	{
		return pow(side, 3);
	}
};

int main()
{
	Container* containers[3];
	containers[0] = new Sphere(5.0);
	containers[1] = new Cylinder(3.0, 7.0);
	containers[2] = new Cube(4.0);
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "Volume of container " << i + 1 << ": " << containers[i]->getVolume() << std::endl;
	}
	for (int i = 0; i < 3; ++i)
	{
		delete containers[i];
	}
	return 0;
}
