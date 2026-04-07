#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include <unordered_map>


class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map;
        for (auto i = 0; i < nums.size(); ++i)
        {
            auto iter = map.find(target - nums[i]);
			//iter也是一个pair，iter->first是key（下标），iter->second是value（值）
            if (iter != map.end())
            {
				return { iter->second, i };
            }
			//map[i] = nums[i];
            map[nums[i]] = i;
			//这里下标nums[i]是key，值i是value
        }
        return {};
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    auto result = s.twoSum(nums, target);
    for (auto i : result)
    {
        std::cout << i << " ";
    }
	return 0;
}