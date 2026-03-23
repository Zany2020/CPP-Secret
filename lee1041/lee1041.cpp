#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>



class Solution
{
public:
    bool isRobotBounded(std::string instructions) 
    {
		std::vector<std::vector<int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int derecIndex = 0;
		int x = 0, y = 0;
        for(char c : instructions)
        {
            if(c == 'G')
            {
                x += directions[derecIndex][0];
                y += directions[derecIndex][1];
            }
            else if(c == 'L')
            {
				derecIndex = (derecIndex + 3) % 4;//向左转相当于右转3次
            }
            else
            {
				derecIndex = (derecIndex + 1) % 4;//向右转相当于右转1次
            }
		}

		return derecIndex != 0 || (x == 0 && y == 0);
    }
};