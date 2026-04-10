#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

#define doub(x) x*2

int main() {

    for (int i = 1; i <= 3; i++)
        cout << i << "double is " << doub(i) << endl;
	//如果没有括号的话，无论是否缩进，for循环体内的语句都只有一条，
    //即cout << i << "double is " << doub(i) << endl;，而不是两条。

    cout << "1+2 double is " << doub((1 + 2)) << endl;

    return 0;

}

