#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;


//class Solution 
//{
//public:
//    std::string addBinary(std::string a, std::string b)
//    {
//        int n, m;
//        if(a.size() < b.size())
//			m = a.size(), n = b.size();
//		else if (a.size() > b.size())
//            m = b.size(), n = a.size();
//        else
//			m = n = a.size();
//		std::vector<char> res(m + 1, '0');
//        for (int i = m - 1, int j = n; i >= 0, j >= 0; --i, --j)
//        {
//            if( )
//        }
//    }
//};
S
#include<cstring>
class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string builder;

        //循环相加两个字符串相同长度的低位数部分
        while (i >= 0 && j >= 0)
        {
            int sum = carry;
            std::cout << "a---" << a.at(i) - '0' << std::endl;
            std::cout << "b---" << b.at(j) - '0' << std::endl;
            sum += a.at(i--) - '0';
            sum += b.at(j--) - '0';
            carry = sum / 2; //是否进位
            builder += to_string((sum % 2));
        }

        // 如果 a 还没遍历完成（a串比b串长），则继续遍历添加 a 的剩余部分
        while (i >= 0) 
        {
            int sum = carry + a.at(i--) - '0';
            carry = sum / 2;
            builder += to_string(sum % 2);
        }

        // 如果 b 还没遍历完成（b串比a串长），则继续遍历添加 b 的剩余部分
        while (j >= 0) {
            int sum = carry + b.at(j--) - '0';
            carry = sum / 2;
            builder += to_string(sum % 2);
        }

        //如果 carry 不等于0 还有个进位数没加进去，需要补充
        if (carry == 1) {
            builder += to_string(carry);
        }

        //反转字符串获得正常结果
        reverse(builder.begin(), builder.end());
        return builder;
    }
};

int main()
{
    Solution s;
    string a = "1010";
    string b = "1011";
    cout << s.addBinary(a, b) << endl;
    return 0;
}