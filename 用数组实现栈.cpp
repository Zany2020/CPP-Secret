#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>


class ArrayStack
{
private:
	int* arr;
	int top;
	int capacity;

public:
	ArrayStack(int size = 10)
	{
		capacity = size;
		arr = new int[capacity];
		top = -1;
	}//// 构造函数：初始化栈

	~ArrayStack()
	{
		delete[] arr;
	}//// 析构函数：释放内存

	bool isFull()
	{
		return top == capacity - 1;
	}//// 判断栈是否满

	bool isEmpty()
	{
		return top == -1;
	}//// 判断栈是否空

	int size()
	{
		return top + 1;
	}//// 获取栈的大小

	bool push(int val)
	{
		if (isFull())
		{
			std::cout << "Stack overflow" << std::endl;
			return false;
		}
		arr[++top] = val;
		return true;
	}

	bool pop()
	{
		if (isEmpty())
		{
			std::cout << "Stack underflow" << std::endl;
			return false;
		}
		top--;// 弹出栈顶元素,不用理那个元素的值了,直接把top往下移就行了，
			  //下次push的时候会覆盖掉那个位置的值
		return true;
	}

	int getTop()
	{
		if(isEmpty())
		{
			std::cout << "Stack is empty" << std::endl;
			return -1; // 返回-1表示栈空
		}
		return arr[top];
	}

	void printStack()
	{
		if(isEmpty())
		{
			std::cout << "Stack is empty" << std::endl;
			return;
		}
		for (int i = 0; i <= top; ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

};

int main()
{
	ArrayStack st(5);

	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);

	std::cout << "Stack contents: " << st.getTop() << std::endl;
	
	st.pop();
	st.printStack();

	st.push(60);
	st.push(70); // 这次会提示栈满
	st.printStack();
	
	return 0;
}