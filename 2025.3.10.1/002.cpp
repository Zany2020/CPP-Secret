#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

//给定两个字符串 s 和 t ，它们只包含小写字母。
//字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
//请找出在 t 中被添加的字母。
//
//示例 1：
//
//输入：s = "abcd", t = "abcde"
//输出："e"
//解释：'e' 是那个被添加的字母。
//示例 2：
//
//输入：s = "", t = "y"
//输出："y"
//
//提示：
//0 <= s.length <= 1000
//t.length == s.length + 1
//s 和 t 只包含小写字母

class Solution
{
public:
    char findTheDifference(std::string s, std::string t)
    {
		std::vector<int> count(26, 0);

        for (char ch : s)
        {
            count[ch - 'a']++;
        }
        for (char ch : t)
        {
            count[ch - 'a']--;
            if(count[ch - 'a'] < 0)
            {
                return ch;
			}
		}

		return '\0'; // 如果没有找到不同的字符，返回空字符
    }
};

int main()
{
    Solution s;
    std::string str1;
    std::string str2;

	std::cout << "请输入字符串s:";
	std::cin >> str1;
	std::cout << "请输入字符串t:";
	std::cin >> str2;
        
    std::cout << s.findTheDifference(str1, str2) << std::endl;
    return 0;
}