#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

class Solution
{
public:
    std::string toLowerCase(std::string s)
    {
        for(char ch : s)
        {
            if(ch >= 'A' && ch <= 'Z')
                ch += 32;
		}
        return s;
    }
};