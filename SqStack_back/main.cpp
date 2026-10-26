#define _CRT_SECURE_NO_WARNINGS
#include "SqStack.h"
#include<iostream>

int main() 
{
    //SqStack S;
    //SElemType e;
    //Status ret;

    //ret = S.InitStack();//初始化

    //std::cout << (S.StackEmpty() ? "当前栈为空" : "当前栈非空") << std::endl;

    //S.Push(10);
    //S.Push(20);
    //S.Push(30);
    //S.Push(40);
    //S.Push(50);
    //S.Traverse();

    //ret = S.GetTop(&e);
    //if (ret == OK) 
    //{
    //    std::cout << "当前栈顶元素：" << e << std::endl;
    //}
    //else 
    //{
    //    std::cout << "取栈顶失败，栈为空" << std::endl;
    //}

    //ret = S.Pop(&e);
    //if (ret == OK)
    //{
    //    std::cout << "出栈元素：" << e << std::endl;
    //}
    //else 
    //{
    //    std::cout << "出栈失败，栈为空" << std::endl;
    //}
    //std::cout << "出栈后";
    //S.Traverse();
    //if (S.StackFull()) 
    //{   
    //    std::cout << "当前栈已满" << std::endl;
    //}
    //else {
    //    std::cout << "当前栈未满" << std::endl;
    //}

    //S.ClearStack();
    //std::cout << "清空后";
    //S.Traverse();
    //std::cout << (S.StackEmpty() ? "确认栈已清空" : "栈未清空") << std::endl;

    char postfix[256]; // 存储转换后的后缀表达式

    // 测试样例A：3+2
    const char* exprA = "3+2#";
    InfixToPostfix(exprA, postfix);
    std::cout << "样例A 中缀：" << exprA << std::endl;
    std::cout << "样例A 后缀：" << postfix << std::endl;
    std::cout << "------------------------" << std::endl;

    // 测试样例B：3*(2-1)
    const char* exprB = "3*(2-1)#";
    InfixToPostfix(exprB, postfix);
    std::cout << "样例B 中缀：" << exprB << std::endl;
    std::cout << "样例B 后缀：" << postfix << std::endl;
    std::cout << "------------------------" << std::endl;

    // 测试样例C：9+(3-2*1)*3+8/2
    const char* exprC = "9+(3-2*1)*3+8/2#";
    InfixToPostfix(exprC, postfix);
    std::cout << "样例C 中缀：" << exprC << std::endl;
    std::cout << "样例C 后缀：" << postfix << std::endl;
    std::cout << "------------------------" << std::endl;

    // 键盘输入测试
    char input[256];
    std::cout << "请输入中缀表达式（以#结束，支持0-9和+-*/()）：";
    std::cin >> input;
    InfixToPostfix(input, postfix);
    std::cout << "转换后后缀表达式：" << postfix << std::endl;

    conversion(1348, 8); 
    conversion(10, 2);
    conversion(255, 16);

    //S.DestroyStack();

    return 0;
}

