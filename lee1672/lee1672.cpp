#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>


//class Solution 
//{
//public:
//    int maximumWealth(std::vector<std::vector<int>>& accounts) 
//    {
//        std::vector<int> wealths(accounts.size());
//        int max = 0;
//
//        for (int i = 0; i < accounts.size(); i++)
//        {
//            for (int j = 0; j < accounts[i].size(); j++)
//            {
//				wealths[i] += accounts[i][j];
//                //没有给它分配空间，直接用 wealths[i] 会越界访问
//            }
//        }
//        int i = 0;
//        for(auto num : wealths)
//        {
//            if(max <= wealths[i])
//            {
//               max = wealths[i];
//			}
//            i++;
//		}
//        return max;
//    }
//};

#include <iostream>
#include <vector>
#include <numeric>  // 必须加这个头文件！

class Solution
{
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts)
    {
        int max_wealth = 0;

        // 遍历每个客户
        for (auto& customer : accounts)
        {
            // accumulate(开始, 结束, 初始值0) → 直接求和！
            int sum = accumulate(customer.begin(), customer.end(), 0);

            // 更新最大值
            max_wealth = std::max(max_wealth, sum);
        }

        return max_wealth;
    }
};

int main()
{
    std::vector<std::vector<int>> accounts = { {1,2,3}, {3,2,1} };
    Solution s;
    int m = s.maximumWealth(accounts);
    std::cout << m;
    return 0;
}