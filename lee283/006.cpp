#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//请注意 ，必须在不复制数组的情况下原地对数组进行操作。
//
//示例 1:
//输入: nums = [0, 1, 0, 3, 12]
//输出 : [1, 3, 12, 0, 0]
//
//示例 2 :
//
//    输入 : nums = [0]
//    输出 : [0]
//
//    提示 :
//    1 <= nums.length <= 104
//    - 231 <= nums[i] <= 231 - 1


//class Solution 
//{
//public:
//    void moveZeroes(std::vector<int>& nums) 
//    {
//        std::sort(nums.begin(), nums.end());
//        int count = 0;
//        int n = 0;
//
//        for (auto i : nums)
//        {
//            if (i == 0)
//            {
//                count++;
//            }
//        }
//
//       //int number = sizeof(nums);
//       //sizeof(nums) 计算的是 vector 这个对象本身的内存大小!!
//
//        int number = nums.size();
//       for (int i = 0; i < number - count; i++)
//       {
//           nums[i] = nums[count + i];
//       }
//       for (int i = 0; i < count; i++)
//       {
//           nums[number - count + i] = 0;
//       }
//    }
//};


//class Solution 
//{
//public:
//    void moveZeroes(std::vector<int>& nums) 
//    {
//        int count = 0;
//        int n = 0;
//
//        for (auto i : nums)
//        {
//            if (i == 0)
//            {
//                count++;
//            }
//        }
//
//       //int number = sizeof(nums);
//       //sizeof(nums) 计算的是 vector 这个对象本身s的内存大小!!
//
//        int number = nums.size();
//        int m = 0;
//
//           for (int i = 0; i < number; i++)
//           {
//               if (nums[i] != 0)
//               {
//                   nums[m] = nums[i];
//                   m++;
//               }
//           }
//
//        
//       for (int i = 0; i < count; i++)
//       {
//           nums[number - count + i] = 0;
//       }
//    }
//};
//
//int main()
//{
//    std::vector<int> nums = { 1, 0, 0, 1 };
//    Solution s;
//    s.moveZeroes(nums);
//
//    for (auto i : nums)
//        std::cout << i << " ";
//    
//    return 0;
//}

//双指针：
class Solution {
public:
    void moveZeroes(std::vector<int>& nums) 
    {
        int n = nums.size(), left = 0, right = 0;
        while (right < n)
        {
            if (nums[right])
            {
                std::swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
