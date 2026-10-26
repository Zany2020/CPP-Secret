#define _CRT_SECURE_NO_WARNINGS
#include  "SqStack.h"
#include <cstdlib>
#include<iostream>

////构造函数
//SqStack::SqStack()
//{
//	base = NULL; 
//	top = 0;    
//	stacksize = 0;
//}
//
////析构
//SqStack::~SqStack()
//{
//	DestroyStack();
//}
//
////初始化
//Status SqStack::InitStack()
//{
//	if (base != NULL)
//	{
//		DestroyStack();
//	}
//
//	base = new SElemType[INIT_STACK_SIZE];
//	if (!base)
//	{
//		exit(OVERFLOW);
//	}
//
//	top = 0;
//	stacksize = INIT_STACK_SIZE;
//	return OK;
//}
//
//Status SqStack::StackEmpty() const
//{
//	return top == 0 ? TRUE : FALSE;
//}
//
//Status SqStack::StackFull() const
//{
//	return top == stacksize ? TRUE : FALSE;
//}
//
//Status SqStack::Push(SElemType e)
//{
//	if (StackFull())
//	{
//		int newSize = stacksize + STAKE_INCREMENT;
//		SElemType* newBase = new SElemType[newSize];
//		if (!newBase)
//		{
//			exit(OVERFLOW);
//		}
//		for (int i = 0; i < top; ++i)
//		{
//			newBase[i] = base[i];
//		}
//		
//		delete[] base;
//		base = newBase;
//		stacksize = newSize;
//	}
//	base[top] = e;
//	top++;
//	return OK;
//}
////出了if之后newbase变量消失，地址还在，如果没有base指针指向它，
////就会造成内存泄漏，所以要把base指向newbase，释放原来的内存。
//
//Status SqStack::Pop(SElemType* e)
//{
//	if (StackEmpty())
//	{
//		return ERROR;
//	}
//	top--;
//	*e = base[top];
//	return OK;
//}
//
//Status SqStack::GetTop(SElemType* e) const
//{
//	if (StackEmpty()) 
//	{
//		return ERROR;
//	}
//	*e = base[top - 1]; //从零开始记得
//	return OK;
//}
//
//void SqStack::Traverse() const
//{
//	if (StackEmpty()) {
//		std::cout << "栈为空，无元素可遍历" << std::endl;
//		return;
//	}
//	std::cout << "栈中元素（栈底 -> 栈顶）：";
//	for (int i = 0; i < top; i++) {
//		std::cout << base[i] << " ";
//	}
//	std::cout << std::endl;
//}
//
//void SqStack::ClearStack()
//{
//	top = 0;
//}
//
//void SqStack::DestroyStack()
//{
//	if (base != NULL)
//	{
//		delete[] base;
//		base = NULL;
//	}
//	top = 0;
//	stacksize = 0;
//}
//
////void conversion(int decimal)
////{
////	SqStack S;
////	S.InitStack();
////	int n = decimal;
////	while (n > 0)
////	{
////		S.Push(n % 8);
////		n = n / 8;
////	}
////
////	while(!S.StackEmpty())
////	{
////		SElemType e;
////		S.Pop(&e);
////		std::cout << e;
////	}
////	std::cout << std::endl;
////}
//
//void conversion(int dec, int base)
//{
//	if(dec < 0 || base < 2 || base > 16) 
//	{
//		std::cout << "输入错误" << std::endl;
//		return;
//	}
//	if(dec == 0) 
//	{
//		std::cout << "0" << std::endl;
//		return;
//	}
//	SqStack S;
//	S.InitStack();
//	int n = dec;
//	while (n != 0)
//	{
//		S.Push(n % base);
//		n = n / base;
//	}
//	SElemType e;
//	while (!S.StackEmpty())
//	{
//		S.Pop(&e);
//		if(e < 10) 
//		{
//			std::cout << e;
//		} 
//		else 
//		{
//			std::cout << (char)('A' + (e - 10));
//		}
//	}
//	std::cout << std::endl;
//}
//
//
////Status evaluatePostfix(const char* expr, int* result)
////{
////	SqStack opndStack;  // 操作数栈，直接复用已实现的SqStack
////	opndStack.InitStack();
////
////	int i = 0;
////	// 遍历表达式，遇到#或字符串结束则停止
////	while (expr[i] != '#' && expr[i] != '\0')
////	{
////		char ch = expr[i];
////
////		// 情况1：字符是数字 → 转整数后压栈
////		if (ch >= '0' && ch <= '9')
////		{
////			int num = ch - '0';  // 利用ASCII连续性，字符转整数
////			opndStack.Push(num);
////		}
////		// 情况2：字符是运算符 → 弹两个数运算，结果压栈
////		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
////		{
////			int rightNum;  // 右操作数（先弹出栈顶）
////			int leftNum;   // 左操作数（后弹出次栈顶）
////
////			// 弹出右操作数，栈空则说明表达式非法（运算符多、操作数少）
////			if (opndStack.Pop(&rightNum) != OK)
////			{
////				return ERROR;
////			}
////			// 弹出左操作数
////			if (opndStack.Pop(&leftNum) != OK)
////			{
////				return ERROR;
////			}
////
////			int calcResult;
////			switch (ch)
////			{
////			case '+': calcResult = leftNum + rightNum; break;
////			case '-': calcResult = leftNum - rightNum; break;
////			case '*': calcResult = leftNum * rightNum; break;
////			case '/':
////				// 除零错误处理
////				if (rightNum == 0)
////				{
////					return ERROR;
////				}
////				calcResult = leftNum / rightNum;  // 整数除法
////				break;
////			default: return ERROR;  // 非法运算符
////			}
////			// 运算结果重新压栈，参与后续运算
////			opndStack.Push(calcResult);
////		}
////		// 情况3：其他字符（如空格、换行）→ 直接跳过
////		else
////		{
////			i++;
////			continue;
////		}
////
////		i++;
////	}
////
////	// 遍历结束后，栈中必须恰好剩1个元素（最终结果）
////	int finalRes;
////	if (opndStack.Pop(&finalRes) != OK)
////	{
////		return ERROR;  // 栈空，无有效结果
////	}
////	if (!opndStack.StackEmpty())
////	{
////		return ERROR;  // 栈中还有多余元素，表达式非法（操作数多、运算符少）
////	}
////
////	*result = finalRes;
////	return OK;
////}


//void InfixToPostfix(const char* infix, char* postfix)
//{
//	SqStack optr; //运算符栈 OPTR，存储char类型运算符
//	optr.InitStack();
//	optr.Push('#'); //避免栈空，先压入'#'作为哨兵
//
//	int i = 0;
//	int outIdx = 0;
//	char curCh;
//	char topOp;
//
//	while (infix[i] != '#' && infix[i] != '\0')
//	{
//		curCh = infix[i];
//		if (curCh >= '0' && curCh <= '9')
//		{
//			postfix[outIdx++] = curCh;
//		}
//
//		else if (curCh == '+' || curCh == '-' || curCh == '*'
//				|| curCh == '/'|| curCh == '(' || curCh == ')')
//		{
//			optr.GetTop(&topOp);
//
//			//循环比较优先级
//			//栈外优先级 <= 栈内优先级 → 弹出栈顶运算符到后缀
//			while (getIcp(curCh) <= getIsp(topOp))
//			{
//				//左括号只和右括号配对
//				if (topOp == '(')
//					break;
//
//				// 弹出栈顶运算符，写入后缀表达式
//				optr.Pop(&topOp);
//				postfix[outIdx++] = topOp;
//
//				optr.GetTop(&topOp);
//			}
//
//			//因为上面遇到‘（’已弹出，所以此时topOp为'）'
//			if (curCh == ')')
//			{
//				optr.Pop(&topOp);
//			}
//			else
//			{
//				// 其他运算符：当前运算符入栈暂存
//				optr.Push(curCh);
//			}
//		}
//		// 其他字符（空格、换行等）直接跳过
//		else
//		{
//			i++;
//			continue;
//		}
//
//		i++; // 处理下一个字符
//	}
//
//	while(optr.GetTop(&topOp), topOp != '#')
//	{
//		optr.Pop(&topOp);
//		postfix[outIdx++] = topOp;
//	}
//
//	// 字符串末尾加结束符，保证是合法C字符串
//	postfix[outIdx] = '\0';
//
//	optr.DestroyStack(); // 释放栈内存
//}
//	
// 应用一次二元运算：弹出右、左操作数，计算后把结果压回操作数栈
static Status applyBinaryOp(SqStack<int>& opnd, char op)
{
	int rightNum = 0;
	int leftNum = 0;
	if (opnd.Pop(&rightNum) != OK)
	{
		return ERROR;
	}
	if (opnd.Pop(&leftNum) != OK)
	{
		return ERROR;
	}

	int calcRes = 0;
	switch (op)
	{
	case '+': calcRes = leftNum + rightNum; break;
	case '-': calcRes = leftNum - rightNum; break;
	case '*': calcRes = leftNum * rightNum; break;
	case '/':
		if (rightNum == 0) // 除数为 0
		{
			return ERROR;
		}
		calcRes = leftNum / rightNum;
		break;
	default:
		return ERROR;
	}

	opnd.Push(calcRes);
	return OK;
}

// 中缀表达式求值（算符优先法）
// 支持 0-9 组成的多位整数、+ - * /、圆括号，表达式以 # 结束
Status calculateInfix(const char* infix, int* result)
{
	if (infix == NULL || result == NULL)
	{
		return ERROR;
	}

	SqStack<int> opnd;  // 操作数栈
	opnd.InitStack();
	SqStack<char> optr; // 运算符栈
	optr.InitStack();
	optr.Push('#');     // 压入 # 作为界符

	int i = 0;
	char curCh = 0;
	char topOp = 0;

	while (infix[i] != '#' && infix[i] != '\0')
	{
		curCh = infix[i];

		// 1. 数字：连续读入，拼成多位整数后压栈
		if (curCh >= '0' && curCh <= '9')
		{
			int num = 0;
			while (infix[i] >= '0' && infix[i] <= '9')
			{
				num = num * 10 + (infix[i] - '0');
				++i;
			}
			opnd.Push(num);
			continue;
		}

		// 2. 运算符与括号
		if (curCh == '+' || curCh == '-' || curCh == '*' || curCh == '/'
			|| curCh == '(' || curCh == ')')
		{
			if (curCh == ')')
			{
				// 右括号：一直运算到遇到左括号
				for (;;)
				{
					optr.GetTop(&topOp);
					if (topOp == '(')
					{
						optr.Pop(&topOp); // 弹出左括号并丢弃
						break;
					}
					if (topOp == '#')
					{
						return ERROR; // 括号不匹配
					}
					char op = 0;
					optr.Pop(&op);
					if (applyBinaryOp(opnd, op) != OK)
					{
						return ERROR;
					}
				}
			}
			else
			{
				// 先弹出所有优先级不低于当前运算符的栈顶运算符并计算
				for (;;)
				{
					optr.GetTop(&topOp);
					if (topOp == '(' || topOp == '#')
					{
						break;
					}
					if (getIcp(curCh) > getIsp(topOp))
					{
						break;
					}
					char op = 0;
					optr.Pop(&op);
					if (applyBinaryOp(opnd, op) != OK)
					{
						return ERROR;
					}
				}
				optr.Push(curCh); // 当前运算符入栈
			}
			++i;
			continue;
		}

		// 3. 其他字符（空格、换行等）：跳过
		++i;
	}

	// 收尾：把栈内剩余运算符全部计算完
	for (;;)
	{
		optr.GetTop(&topOp);
		if (topOp == '#')
		{
			break;
		}
		if (topOp == '(')
		{
			return ERROR; // 括号不匹配
		}
		char op = 0;
		optr.Pop(&op);
		if (applyBinaryOp(opnd, op) != OK)
		{
			return ERROR;
		}
	}

	// 正常结束时操作数栈应恰好剩一个元素
	int finalRes = 0;
	if (opnd.Pop(&finalRes) != OK)
	{
		return ERROR;
	}
	if (!opnd.StackEmpty())
	{
		return ERROR; // 操作数多余，表达式非法
	}

	*result = finalRes;
	return OK;
}
