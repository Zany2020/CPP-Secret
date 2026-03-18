#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

//class Solution 
//{
//public:
//    bool isMonotonic(std::vector<int>& nums)
//    {
//		std::vector<int> num = nums;
//		std::sort(num.begin(), num.end());
//        if(num == nums)
//			return true;
//		std::sort(num.rbegin(), num.rend());
//		if (num == nums)
//			return true;
//		return false;
//    }
//};


class Solution 
{
public:
    bool isMonotonic(std::vector<int>& nums) 
    {
        return is_sorted(nums.begin(), nums.end()) || is_sorted(nums.rbegin(), nums.rend());
    }
};
//is_sorted()函数是C++ STL中的一个算法函数，用于检查一个范围内的元素是否已经按照非递减（升序）或非递增（降序）的顺序排列。
//它接受两个迭代器作为参数，分别指向范围的开始和结束位置。如果范围内的元素满足排序条件，则返回true；否则返回false。


int main()
{
    std::vector<int> nums = { 1, 2, 3, 4 };
    Solution s;
	std::cout << s.isMonotonic(nums) << std::endl;
}