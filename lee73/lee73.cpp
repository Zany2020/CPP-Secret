#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>>& matrix)
    {
		int n = matrix.size();
		int m = matrix[0].size();
		std::vector<int> rows(n), cols(m);

		for (int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if (matrix[i][j] == 0)
				{
					rows[i] = 1;
					cols[j] = 1;
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(rows[j] == 1 || cols[j] == 1)
				{
					matrix[i][j] = 0;
				}

			}
		}

		return;
    }
};
