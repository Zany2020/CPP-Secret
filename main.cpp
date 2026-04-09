#define _CRT_SECURE_NO_WARNINGS
#include"CMobilePhone.h"
// 在main中，通过构造函数创建手机对象

    // TODO: 利用构造函数A创建一个实体对象、一个指针对象

    // TODO: 利用无参构造函数B创建一个实体对象、一个指针对象

    // TODO: 调用showinfo、showsize分别输出四部手机的属性。

    // TODO: 用delete 销毁两个指针对象。

int main()
{
    CMobilePhone p1("iPhone", "17 ", "Akane", "1145114", 149.6, 71.5, 8.75);
    CMobilePhone* ptr1 = new CMobilePhone();

    CMobilePhone p2;
    CMobilePhone* ptr2 = new CMobilePhone();

   // p1.show();

	ptr1->setname("iPhone");
	ptr1->setuser("Kana");
	ptr1->setnumber("114514");
	ptr1->show();


	//p2.show();
	
	p2.setname("iPhone");
	p2.setuser("Ruby");
	p2.setnumber("114516"); 
	p2.show();

	ptr2->setname("iPhone");
	ptr2->setuser("Aqua");
	ptr2->setnumber("114515");
	ptr2->show();

    delete ptr1;    
    delete ptr2;

    return 0;
}
