#pragma once
constexpr auto OK = 1;
constexpr auto ERROR = 0;
constexpr auto OVERFLOW = -1;
constexpr auto TRUE = 1;
constexpr auto FALSE = 0;

constexpr auto INIT_STACK_SIZE = 100;
constexpr auto STAKE_INCREMENT = 10;

//typedef 给类型起别名
typedef int Status;  //函数返回类型状态
typedef char SElemType; //栈元素类型改为char


class SqStack
{
private:
	SElemType* base;//栈底指针
	int top; //栈顶指针
	int stacksize; // 栈大小

public:
	SqStack();
	~SqStack();

	Status InitStack(); //初始化
	Status StackEmpty() const;//判断是否为空
	Status StackFull() const;//判断是否为满
	Status Push(SElemType e);// 元素入栈
	Status Pop(SElemType* e);// 栈顶元素出栈，e带回结果
	Status GetTop(SElemType* e) const;
	void Traverse() const;// 遍历栈（栈底→栈顶输出）
	void ClearStack(); // 清空栈（保留内存）
	void DestroyStack(); // 销毁栈（释放内存）


};

void conversion(int dec, int base);
//Status evaluatePostfix(const char* expr, int* result);

void InfixToPostfix(const char* infix, char* postfix);