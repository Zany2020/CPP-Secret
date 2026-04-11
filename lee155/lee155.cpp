#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>

class MinStack 
{
	std::stack<int> x_stack;
	std::stack<int> min_stack;
public:
    MinStack() 
    {
        int top = -1;
		int* date = new int [10000];
    }

    void push(int val) 
    {
		x_stack.push(val);
        if (min_stack.empty() || val <= min_stack.top()) 
        {
            min_stack.push(val);
        }
    }

    void pop()
    {
		if (!x_stack.empty())
        {
            if (!x_stack.empty() && x_stack.top() == min_stack.top())
            {
                min_stack.pop();
            }
            x_stack.pop();
        }
    }

    int top() 
    {
        if (!x_stack.empty())
        {
            return x_stack.top();    
        }
        return 0;
    }

    int getMin() 
    {
        if (!min_stack.empty())
        {
            return min_stack.top();
        }
        return 0;
    }
};

int main()
{
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int param_3 = obj->getMin();
    std::cout << param_3 << std::endl;
    obj->pop();
    int param_4 = obj->top();
    std::cout << param_4 << std::endl;
    int param_5 = obj->getMin();
    std::cout << param_5 << std::endl;
    return 0;
}