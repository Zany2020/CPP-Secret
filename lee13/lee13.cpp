#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>


class Solution
{
private:
    std::unordered_map<char, int> symbolValues = 
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(std::string s)
    {
		int ans = 0;
		int n = s.size();
        for (int i = 0; i < n; ++i)
        {
			int value = symbolValues[s[i]];
            if (i < n - 1 && value < symbolValues[s[i + 1]])
            {
                ans -= value;
            }
            else
                ans += value;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    std::string str = "MCMXCIV";
    std::cout << s.romanToInt(str) << std::endl;
    return 0;
}