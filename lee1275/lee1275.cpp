#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>


class Solution 
{
public:
    std::string tictactoe(std::vector<std::vector<int>>&moves)
    {
        int tmp[3][3]{};
        int i = 1;
        for (auto v : moves)
        {
			tmp[v[0]][v[1]] = i;
            i = -i;
        }

        if(abs(tmp[0][0] + tmp[1][1] + tmp[2][2]) == 3 || abs(tmp[0][2] + tmp[1][1] + tmp[2][0]) == 3)
            return tmp[1][1] > 0 ? "A" : "B";
        for (int i = 0; i < 3; ++i)
        {
            if (abs(tmp[i][0] + tmp[i][1] + tmp[i][2]) == 3)
                return tmp[i][0] > 0 ? "A" : "B";
            if (abs(tmp[0][i] + tmp[1][i] + tmp[2][i]) == 3)
                return tmp[0][i] > 0 ? "A" : "B";
        }
		return moves.size() == 9 ? "Draw" : "Pending";

    }
};