#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>

class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            //auto it = std::unordered_map.find(target - nums[i]);
            auto it = map.find(target - nums[i]);
            if (it != map.end())
            {
                return { it->second, i };
            }
            map[nums[i]] = i;
        }
		return {};
    }
};
