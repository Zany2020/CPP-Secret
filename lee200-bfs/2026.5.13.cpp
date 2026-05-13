#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>

//class Solution 
//{
//private:
//    void bfs(int start)
//    {
//        std::queue<int> q;
//        q.push(start);
//        
//    }
//
//public:
//    int numIslands(std::vector<std::vector<char>>& grid)
//    {
//        int nr = grid.size();
//        int nc = grid[0].size();
//        bool vis[nr * nc] = {false};
//
//        
//
//        for (int i = 0; i < nr; ++i)
//        {
//            for (int j = 0; j < nc; ++j)
//            {
//                if (grid[i][j] == '1')
//                {
//                    island_num++;
//                    bfs(i * nc + j);
//                }
//            }
//        }
//        
//        return island_num;
//    }
//};

class Solution 
{
public:
    int numIslands(std::vector<std::vector<char>>& grid) 
    {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();
            
		int island_num = 0;
        for (int i = 0; i < nr; ++i)
        {
            for (int j = 0; j < nc; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++island_num;
                    std::queue<std::pair<int, int>> neighbor;
                    neighbor.push({i, j});
                    grid[i][j] = '0';

                    while (!neighbor.empty())
                    {
                        auto rc = neighbor.front();
                        neighbor.pop();
                        int row = rc.first;
                        int col = rc.second;

                        if(row - 1 >= 0 && grid[row - 1][col] == '1')
                        {
							neighbor.push({ row - 1, col }); grid[row - 1][col] = '0';
                        }
                        if(row + 1 < nr && grid[row + 1][col] == '1')
                        {
                            neighbor.push({ row + 1, col }); grid[row + 1][col] = '0';
                        }
                        if(col - 1 >= 0 && grid[row][col - 1] == '1')
                        {
                            neighbor.push({ row, col - 1 }); grid[row][col - 1] = '0';
                        }
                        if(col + 1 < nc && grid[row][col + 1] == '1')
                        {
                            neighbor.push({ row, col + 1 }); grid[row][col + 1] = '0';
                        }

                    }
                }
            }
        }
		return island_num;
    }
};

int main()
{
    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    Solution s;
    std::cout << s.numIslands(grid) << std::endl;
    return 0;
}