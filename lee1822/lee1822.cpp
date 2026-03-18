#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>




class Solution
{
public:
    int arraySign(std::vector<int>& nums)
    {
        int negatives = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                negatives++;
            }
            else if (nums[i] == 0)
            {
                return 0;
            }
        }
        if (negatives % 2 == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Solution s;
    std::vector<int> nums = { -1, -2, -3, -4, 3, 2, 1 };
    std::cout << s.arraySign(nums) << std::endl;
	return 0;
}