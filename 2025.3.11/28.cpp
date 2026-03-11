#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>



//如果P【cur - 1】= P【comp】，则next【cur】= comp + 1
//如果P【cur - 1】!= P【comp】，则comp = next【comp】，继续比较，直到comp = 0或者P【cur - 1】= P【comp】



class Solution
{
public:
	std::vector<int> getNext(const std::string& pattern)
		//abcabcabd  pattern(文本)
		//111111111  next(共同数)
	{
		if (pattern.size() < 2)
		{
			return { 0 };//前两位都是0
		}

		std::vector<int> next(pattern.size());//文本包含的数字
		next[0] = 0;
		next[1] = 0;
		int comp = 0;//comp是next数组中一个位置的值（数字），表示当前字符之前的最长公共前后缀长度
		int cur = 2;
		while (cur < pattern.size())
		{
			if (pattern[cur - 1] == pattern[comp])//相同的字符
			{
				next[cur] = comp + 1;//当前字符的最长公共前后缀长度是comp+1
				cur++;
				comp++;
			}
			else if(comp > 0)
			{
				comp = next[comp];
			}
			else
			{
				next[cur++] = 0;
			}
		}

		return next;
	}

	int kmp(std::string str, std::string pattern)
	{
		std::vector<int> next = getNext(pattern);
		int sCur = 0;
		int pCur = 0;
		while (sCur < str.size() && pCur < pattern.size())
		{
			if (str[sCur] == pattern[pCur])
			{
				sCur++;
				pCur++;
			}
			else if (pCur > 0)
			{
				pCur = next[pCur];
			}
			else
			{
				sCur++;
			}
		}
		return pCur == pattern.size() ? sCur - pCur : -1;
	}



};



int main()
{
	std::string s1, s2;
	//s1是文本串，s2是模式串
	std::cout << "请输入字符串s1：";
	std::cin >> s1 ;
	std::cout << std::endl << "请输入字符串s2：";
	std::cin >> s2 ;

	if (s1.empty())
	{
		std::cout << "错误：模式串不能为空！" << std::endl;
		return 1;  // 非0返回值表示程序异常退出
	}
	if (s2.empty())
	{
		std::cout << "错误：文本串不能为空！" << std::endl;
		return 1;  // 非0返回值表示程序异常退出
	}
	if (s2.size() > s1.size())
	{
		std::cout << "错误：模式串长度不能大于文本串长度！" << std::endl;
		return 1;  // 非0返回值表示程序异常退出
	}

	int matchIndex = Solution().kmp(s1, s2);

	if(matchIndex != -1)
	{
		std::cout << "模式串在文本串中的起始位置为：" << matchIndex << std::endl;
	}
	else
	{
		std::cout << "模式串在文本串中未找到！" << std::endl;
	}

	return 0;
}