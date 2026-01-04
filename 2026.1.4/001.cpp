#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////////////

//int my_qsort(int a, int b)
//{
//	return a < b;  
//	//名字也一样比较ascall码值谁大排哪边
//	//不能有 = 号！！！（sort的规则就是如此如果有等于可能会一直移动后越界）
//}
//
//int main()
//{
//	//sort函数-->包含<algorithm>头文件
//	//sort(起始迭代器/指针, 结束迭代器/指针, cmp);
//	//cmp是比较函数
//
//
//	vector <int> m(11);
//	for (int i = 10; i >= 0; i--)//i--循环结束了才减，i=0附了值才减
//		m[i] = 10 - i;
//
//	m.push_back(-1);
//	for (int i = 0; i < 12; i++)
//		cout << m[i] << " ";
//	cout << endl;
//
//	sort(m.begin(), m.end(), my_qsort);//sort默认从小到大排序
//
//	for (int i = 0; i < 12; i++)
//		cout << m[i] << " " ;
//
//	return 0;
//}
///////////////////////////////////////////////////////////////////////////////

//#include<cctype>
////c语言里的是cype.h
//int main()
//{
//	char i = '1';
//	cout << isalpha(i) << endl;//字母？
//	cout << islower(i) << endl;//小写字母？
//	cout << isupper(i) << endl;//大写字母？
//	cout << isalnum(i) << endl;//字母 or 数字？
//							   //这里返回的是随机值
//	cout << isspace(i) << endl;//是 空格 or \n之类的东西吗？
//	cout << tolower(i) << endl;//转化成小写字母
//	//cout << toupper(i) << endl;   //转化为大写字母
//
//	//反正非零真，零为假
//	char s = toupper(i);
//	cout << s << endl;
//
//	//注意isspace(i)和tolower(i)传入值和返回值都是int，char直接输出是ascall码值，
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////

//int main()
//{
//	auto i = 0;
////	//这里的auto会自动判断类型，但一定要有初定义
//	//初定义限制之后的修改等
//
//	int a[5] = { 1 };
//
//	for (auto i : a)//相当于python里的for i in a；
//	{
//		i++;
//	}
//	for(auto i : a)
//		cout << i << " ";
//
//	cout << endl;
//	for (auto& i : a)//这里的&传地址相当于指针了，会改变原本的值
//	{
//		i++;
//		cout << i << " ";
//	}
//
//	cout << endl;
//	for (auto i : a)
//		cout << i << " ";
//
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////
#include<string>

int main()
{
	string s = to_string(123.1);
	//将数字转换成字符（串）常量
	//当传入 double 或 float 类型参数时，to_string 会默认将其转换为 保留 6 位小数的字符串

	cout << s << endl;

	printf("%s\n", s.c_str());//如果用printf就要在后面加.c_str()

	int a = stoi("123");//转化为int型
	int b = stod("123.1");//转化为double型

	return 0;
}