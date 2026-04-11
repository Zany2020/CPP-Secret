#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>


class MyStack 
{
	std::queue<int> q;
public:
    MyStack() {}

	void push(int x)   //5-> 4-> 3-> 2-> 1
    {
        q.push(x);
        for(int i = 0; i < q.size() - 1; ++i)
        {
            q.push(q.front());
			q.pop();
		}
    }

    int pop() 
    {
        int n = q.front();
		q.pop();
        return n;
    }

    int top() 
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    std::cout << obj->top() << std::endl;
    std::cout << obj->pop() << std::endl;
    std::cout << obj->empty() << std::endl;
    delete obj;
    return 0;
}