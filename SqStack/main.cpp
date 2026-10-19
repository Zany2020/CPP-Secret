#define _CRT_SECURE_NO_WARNINGS
#include "SqStack.h"
#include<iostream>

int main() 
{
    SqStack S;
    SElemType e;
    Status ret;

    ret = S.InitStack();//初始化

    std::cout << (S.StackEmpty() ? "当前栈为空" : "当前栈非空") << std::endl;

    S.Push(10);
    S.Push(20);
    S.Push(30);
    S.Push(40);
    S.Push(50);
    S.Traverse();

    ret = S.GetTop(&e);
    if (ret == OK) 
    {
        std::cout << "当前栈顶元素：" << e << std::endl;
    }
    else 
    {
        std::cout << "取栈顶失败，栈为空" << std::endl;
    }

    ret = S.Pop(&e);
    if (ret == OK)
    {
        std::cout << "出栈元素：" << e << std::endl;
    }
    else 
    {
        std::cout << "出栈失败，栈为空" << std::endl;
    }
    std::cout << "出栈后";
    S.Traverse();
    if (S.StackFull()) 
    {   
        std::cout << "当前栈已满" << std::endl;
    }
    else {
        std::cout << "当前栈未满" << std::endl;
    }

    S.ClearStack();
    std::cout << "清空后";
    S.Traverse();
    std::cout << (S.StackEmpty() ? "确认栈已清空" : "栈未清空") << std::endl;

    conversion(1348);
    S.DestroyStack();

    return 0;
}
