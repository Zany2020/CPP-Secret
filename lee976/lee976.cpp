#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

class Solution 
{
public:
    int largestPerimeter(std::vector<int>& nums) 
    {
		int size = nums.size();
        int max = 0;

        //for (int i = 0; i < size - 1; ++i)
        //{
        //    for (int j = 0; j < size - 1; ++j)
        //    {
        //        if (i != j)
        //        {
        //            

        //        }
        //    }
        //}

		sort(nums.begin(), nums.end());

        for(int i = size - 1; i > 1; --i)
        {
            if (nums[i] < nums[i - 1] + nums[i - 2])
            {
                max = nums[i] + nums[i - 1] + nums[i - 2];
                return max;
            }
		}   
        return 0;
    }
};