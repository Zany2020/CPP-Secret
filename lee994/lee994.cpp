#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

//class Solution 
//{
//   // 腐烂橘子是：所有坏橘子 → 同时 → 开始腐烂周围这是一层一层扩散，所以必须用 BFS（队列）
//
//    //void dfs(std::vector<std::vector<int>>& grid, int r, int c, int time)
//    //{
//    //    int nr = grid.size();
//    //    int nc = grid[0].size();
//    //    time++;
//
//    //    if(r - 1 >= 0 && grid[r - 1][c] == 1) { dfs (grid, r - 1, c, time); }
//    //    if(r + 1 < nr && grid[r + 1][c] == 1) { dfs (grid, r + 1, c, time); }
//    //    if(c - 1 >= 0 && grid[r][c - 1] == 1) { dfs (grid, r, c - 1, time); }
//    //    if(c + 1 < nc && grid[r][c + 1] == 1) { dfs (grid, r, c + 1, time); }
//    //}
//
//public:
//    int orangesRotting(std::vector<std::vector<int>>& grid) 
//    {
//        int nr = grid.size();      
//        int nc = grid[0].size();
//        if (nr == 0 || nc == 0) return 0;
//        int time = 0;
//
//        for (int i = 0; i < nr; ++i)
//        {
//            for (int j = 0; j < nc; ++j)
//            {
//                if (grid[i][j] == 2)
//                {
//                    bfs(grid, i, j, 0);
//                    time++;
//                }
//            }
//        }
//
//        for (int i = 0; i < nr; ++i)
//        {
//            for (int j = 0; j < nc; ++j)
//            {
//                if (grid[i][j] == 1)
//                    return -1;
//            }
//        }
//
//        return time;
//    }
//};
//
//int main()
//{
//    std::vector<std::vector<int>> grid  = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
//    Solution sol;
//    int result = sol.orangesRotting(grid);
//    std::cout << "Time taken: " << result << std::endl;
//}
//我会回来的。