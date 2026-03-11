#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


class Solution
{
public:
    bool isAnagram(std::string s,std::string t) 
    {
        if (s.length() != t.length())
			return false;
        //≈≈–Ú
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
		return s == t;
    }
};

int main()
{


}