#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>


class Solution 
{
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        for(int i = 1; i < arr.size() - 1; i++)
        {
            if(arr[i] - arr[i - 1] != arr[i + 1] - arr[i])
                return false;
	  	}
		return true;
    }

};

int main()
{
    Solution s;
	std::vector<int> arr = { 3,5,1 };
	std::cout << s.canMakeArithmeticProgression(arr) << std::endl;
}