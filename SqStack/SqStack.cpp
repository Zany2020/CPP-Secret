#define _CRT_SECURE_NO_WARNINGS
#include  "SqStack.h"
#include <cstdlib>
#include<iostream>

//构造函数
SqStack::SqStack()
{
	base = NULL; 
	top = 0;    
	stacksize = 0;
}

//析构
SqStack::~SqStack()
{
	DestroyStack();
}

//初始化
Status SqStack::InitStack()
{
	if (base != NULL)
	{
		DestroyStack();
	}

	base = new SElemType[INIT_STACK_SIZE];
	if (!base)
	{
		exit(OVERFLOW);
	}

	top = 0;
	stacksize = INIT_STACK_SIZE;
	return OK;
}

Status SqStack::StackEmpty() const
{
	return top == 0 ? TRUE : FALSE;
}

Status SqStack::StackFull() const
{
	return top == stacksize ? TRUE : FALSE;
}

Status SqStack::Push(SElemType e)
{
	if (StackFull())
	{
		int newSize = stacksize + STAKE_INCREMENT;
		SElemType* newBase = new SElemType[newSize];
		if (!newBase)
		{
			exit(OVERFLOW);
		}
		for (int i = 0; i < top; ++i)
		{
			newBase[i] = base[i];
		}
		
		delete[] base;
		base = newBase;
		stacksize = newSize;
	}
	base[top] = e;
	top++;
	return OK;
}
//出了if之后newbase变量消失，地址还在，如果没有base指针指向它，
//就会造成内存泄漏，所以要把base指向newbase，释放原来的内存。

Status SqStack::Pop(SElemType* e)
{
	if (StackEmpty())
	{
		return ERROR;
	}
	top--;
	*e = base[top];
	return OK;
}

Status SqStack::GetTop(SElemType* e) const {
	if (StackEmpty()) {
		return ERROR;
	}
	*e = base[top - 1]; //从零开始记得
	return OK;
}

void SqStack::Traverse() const
{
	if (StackEmpty()) {
		std::cout << "栈为空，无元素可遍历" << std::endl;
		return;
	}
	std::cout << "栈中元素（栈底 -> 栈顶）：";
	for (int i = 0; i < top; i++) {
		std::cout << base[i] << " ";
	}
	std::cout << std::endl;
}

void SqStack::ClearStack()
{
	top = 0;
}

void SqStack::DestroyStack()
{
	if (base != NULL)
	{
		delete[] base;
		base = NULL;
	}
	top = 0;
	stacksize = 0;
}

void conversion(int decimal)
{
	SqStack S;
	S.InitStack();
	int n = decimal;
	while (n > 0)
	{
		S.Push(n % 8);
		n = n / 8;
	}

	while(!S.StackEmpty())
	{
		SElemType e;
		S.Pop(&e);
		std::cout << e;
	}
	std::cout << std::endl;
}