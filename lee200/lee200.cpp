#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>


class Solution 
{
private:
    void dfs(std::vector<std::vector<char>>& grid, int r, int c)
    {
		int nr = grid.size();
		int nc = grid[0].size();
		grid[r][c] = '0';

        //上
        if(r - 1 >= 0 && grid[r - 1][c] == '1')  {dfs(grid, r - 1, c);}
		//下
		if (r + 1 < nr && grid[r + 1][c] == '1') { dfs(grid, r + 1, c); }
		//左
		if (c - 1 >= 0 && grid[r][c - 1] == '1') { dfs(grid, r, c - 1); }
		//右
		if (c + 1 < nc && grid[r][c + 1] == '1') { dfs(grid, r, c + 1); }
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid)//注意是char
    {
		int nr = grid.size();
		if (!nr) { return 0; }
		int nc = grid[0].size();
		int num_islands = 0;

		for (int i = 0; i < nr; ++i)
		{
			for (int j = 0; j < nc; ++j)
			{
				if (grid[i][j] == '1')
				{
					++num_islands;
					dfs(grid, i, j);
				}
			}
		}
		
		return num_islands;
    }
};

int main()
{
	std::vector<std::vector<char>> grid = { {'1','1','1','1','0'},
											{'1','1','0','1','0'},
											{'1','1','0','0','0'},
											{'0','0','0','0','0'} };
	Solution s;
	std::cout << s.numIslands(grid) << std::endl;
	return 0;
}