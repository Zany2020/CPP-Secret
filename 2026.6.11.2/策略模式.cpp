#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class CalcVolume 
{
public:
    virtual double calculateVolume() const = 0;
    virtual ~CalcVolume() {}
};

class SphereVolume : public CalcVolume
{
private:
    double radius; 
public:
    SphereVolume(double r) : radius(r) {}
    double calculateVolume() const override;
};

class CylinderVolume : public CalcVolume
{
private:
    double radius;
    double height;
public:
    CylinderVolume(double r, double h) : radius(r), height(h) {}
    double calculateVolume() const override;
};

class CubeVolume : public CalcVolume
{
private:
    double side;  
public:
    CubeVolume(double s) : side(s) {}
    double calculateVolume() const override;
};

// 类外实现成员函数（也可写在类内）
double SphereVolume::calculateVolume() const
{
    return (4.0 / 3.0) * M_PI * pow(radius, 3);
}

double CylinderVolume::calculateVolume() const
{
    return M_PI * pow(radius, 2) * height;
}

double CubeVolume::calculateVolume() const
{
    return pow(side, 3);
}

//3. 定义【容器类】，持有策略对象指针，提供统一接口调用
        //代表 容器「拥有」一个计算策略
        
class CContainer
{
private:
    CalcVolume * volumeCalculator;  // 持有抽象策略类指针（核心：组合关系）
public:
    CContainer(CalcVolume* cal) : volumeCalculator(cal) {}
    double getVolume() const;
};

double CContainer::getVolume() const
{
    // 多态调用：通过基类指针执行对应策略的算法
    return volumeCalculator->calculateVolume();
}


int main()
{
    SphereVolume sphereCal(5.0);   
    CylinderVolume cylinderCal(3.0, 10.0); 
    CubeVolume cubeCal(4.0);        

    // 2. 创建【容器对象】，绑定对应的计算策略
    CContainer container1(&sphereCal);
    CContainer container2(&cylinderCal);
    CContainer container3(&cubeCal);

    // 3. 统一接口调用，输出体积
    std::cout << "球体体积：" << container1.getVolume() << std::endl;
    std::cout << "圆柱体体积：" << container2.getVolume() << std::endl;
    std::cout << "正方体体积：" << container3.getVolume() << std::endl;

    return 0;
}