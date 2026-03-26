#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<string>


class Solution 
{
public:
    bool checkStraightLine(std::vector<std::vector<int>>& coordinates) 
    {
		int size_1 = coordinates.size();
		int size_2 = coordinates[0].size();
        std::vector<int>Slope(size_1);

        for (int i = 1; i < size_1; i++)
        {
            Slope[i - 1] = (coordinates[i][1] - coordinates[i - 1][1]) / (coordinates[i][0] - coordinates[i - 1][0]);
        }

        for (int i = 1; i < size_1 - 1; i++)
        {
            if (Slope[i] != Slope[i - 1])
            {
                return false;
            }
		}
		return true;
    }
};

int main()
{
	std::vector<std::vector<int>> coordinates = { {0,0}, {0,1}, {0,-1} };
    Solution s;
    std::cout << s.checkStraightLine(coordinates) << std::endl;
    return 0;
}