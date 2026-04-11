#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stack>
#include<vector>


//class Solution 
//{
//public:
//    bool isValid(std::string s)
//    {
//        std::stack<int> st;
//        std::stack<int> st_;
//
//        for (int i = 0; i < s.size(); ++i)
//        {
//             if (s[i] != '(' && s[i] != '[' && s[i] != '{')
//                 st_.push(1);
//        }
//
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (s[i] == '(')
//                st.push(1);
//            else if (s[i] == '[')
//                st.push(2);
//            else if (s[i] == '{')
//                st.push(3);
//            else if (s[i] != '(' && s[i] != '[' && s[i] != '{' && st.empty())
//                return false;
//
//            else if (s[i] == ')' && !st.empty() && st.top() == 1)
//            {
//                st.pop();
//                st_.pop();
//                continue;
//            }                
//            else if (s[i] == ']' && !st.empty() && st.top() == 2)
//            {
//                st_.pop();
//                st.pop();
//                continue;
//            }                
//            else if (s[i] == '}' && !st.empty() && st.top() == 3)
//            {
//                st_.pop();
//                st.pop();
//                continue;
//            }
//        }
//
//        if (st.empty() && st_.empty())
//            return true;
//        else
//            return false;
//
//    }
//};

#include<unordered_map>
using namespace std;


class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        if (n % 2 == 1) 
        {
            return false;
        }

        unordered_map<char, char> pairs = 
        {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        //¼üÖµ¶Ô£¬pairs¡¾×ó±ß¡¿== ÓÒ±ß¡£

        stack<char> stk;
        for (char ch : s)
        {
            if (pairs.count(ch)) 
            {
                if (stk.empty() || stk.top() != pairs[ch]) 
                {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};


int main()
{
    Solution s;
    std::string str = "()";
    std::cout << s.isValid(str) << std::endl;
    return 0;
}   