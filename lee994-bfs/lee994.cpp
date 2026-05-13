#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

class Solution
{
public:
    int orangesRotting(std::vector<std::vector<int>>& grid)
    {
		int nr = grid.size();
		int nc = grid[0].size();
		std::queue<std::pair<int, int>> q;
		int fresh = 0;

		int dx[] = { -1, 1, 0, 0 };
		int dy[] = { 0, 0, -1, 1 };

		for (int i = 0; i < nr; ++i)
		{
			for (int j = 0; j < nc; ++j)
			{
				if(grid[i][j] == 2)
					{ q.push({ i, j });}
				else if (grid[i][j] == 1)
					{ fresh++;}
			}
		}

		if(fresh == 0)	{ return 0; }
		int minutes = 0;

		while (!q.empty())
		{
			int size = q.size();
			minutes++;

			for (int i = 0; i < size; ++i)
			{
				/*auto [x,y] = q.front(); q.pop();*/
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				//组合，d=0 → dx=-1，dy=0 → 向上（只变行，列不动）

				for (int d = 0; d < 4; ++d)
				{
					int nx = x + dx[d];
					int ny = y + dy[d];

					if (nx >= 0 && nx < nr && ny >= 0 && ny < nc && grid[nx][ny] == 1)
					{
						grid[nx][ny] = 2;
						fresh--;
						q.push({ nx, ny });
					}
				}

			}
		}
		return fresh == 0 ? minutes - 1 : -1;
    }
};

int main()
{
	Solution sol;
	std::vector<std::vector<int>> grid =
	{
		{ 2, 1, 1 },
		{ 1, 1, 0 },
		{ 0, 1, 1 }
	};
	int result = sol.orangesRotting(grid);
	std::cout << "Minimum minutes: " << result << std::endl;
	return 0;
}