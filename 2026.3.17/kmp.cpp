#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
//abcabcabcabc

class Solution {
public:
    bool kmp(const std::string& query, const std::string& pattern)
    {
        int n = query.size();
        int m = pattern.size();
		std::vector<int> fail(m, -1);//fail[i]初始全为-1，表示没有前缀；
        for (int i = 1; i < m; ++i) 
        {
			int j = fail[i - 1];//j表示next数组的下标
                                //j为-1，表示没有前缀，
                                //j为0，表示前缀长度为1，j为1，表示前缀长度为2，以此类推
			while (j != -1 && pattern[j + 1] != pattern[i]) //!= -1表示前面还有前缀，pattern[j + 1] != pattern[i]表示（下一串）前缀和（下一串）后缀不匹配
            {
				j = fail[j];//往前回退到存档点，继续比较（下一串）前缀和（下一串）后缀
				            //j这里是代表next[j]，回退到fail[j]的位置，继续比较
            }
            if (pattern[j + 1] == pattern[i]) 
            {
                fail[i] = j + 1;
            }
        }
        int match = -1;
        for (int i = 1; i < n - 1; ++i) 
        {
			while (match != -1 && pattern[match + 1] != query[i]) //防止匹配到原字符串的首位，所有q直接从1开始匹配，掐头去尾只到n-1
            {
                match = fail[match];
            }
            if (pattern[match + 1] == query[i]) 
            {
                ++match;
                if (match == m - 1) //防止匹配到原字符串的首位，所有掐头去尾只到m-1
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool repeatedSubstringPattern(std::string s) 
    {
        return kmp(s + s, s);
    }
};

int main()
{
    Solution x;
    std::string a = "abcabcabcabc";
    bool m = x.repeatedSubstringPattern(a);
    std::cout << m << std::endl;
    return 0;
}

//自己f11看吧