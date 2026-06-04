#include "CShape.h"
#include "CPoint.h"
#include "CLine.h"
using namespace std;
//参考的main函数，可以根据自己的情况修改

	// 测试运行时的多态性，类中各种方法等
	// 需要保证有输出

int main()
{
	CPoint p1;
	CPoint p2(3.0, 4.0);
	CPoint p3(p2); // 复制构造函数
	p1.display();
	p2.display();
	p3.display();

	cout << "\n===== 测试CLine =====" << endl;
	CLine line1;        // 默认构造
	CLine line2(p1, p2);// 带参数构造
	CLine line3(line2); // 拷贝构造
	line1.display();
	line2.display();
	line3.display();

	cout << "\n===== 测试多态性 =====" << endl;
	CShape* shape1 = &p2; // 基类指针指向点对象
	CShape* shape2 = &line2;// 基类指针指向线段对象
	shape1->display();    // 调用CPoint的display
	shape2->display();    // 调用CLine的display


	return 0;
}