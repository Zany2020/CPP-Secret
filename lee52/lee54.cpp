#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cmath>


//class Solution 
//{
//public:
//    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
//    {
//		int rows = matrix.size();
//		int cols = matrix[0].size();
//		std::vector<int> result;
//
//        for (int i = 0; i < rows; ++i)
//        {
//            result.push_back(matrix[0][i]);
//            if (i == rows - 1)
//            {
//                for (int j = 1; j < cols; ++j)
//                {
//					result.push_back(matrix[j][rows - 1]);
//                }
//
//            }
//        }
//};


class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return {};		

        int rows = matrix.size();
        int cols = matrix[0].size();
		int total = rows * cols;
        std::vector<int> res(total);

		int startx = 0, starty = 0;
        int loop = std::min(rows, cols) / 2;//循环
        int mid = std::min(rows, cols) / 2;
		int offset = 1;
        int count = 0;
        int i, j;

        while (loop--)
        {
            i = startx;
            j = starty;

            for (j = starty; j < starty + cols - offset; ++j)
                res[count++] = matrix[i][j];
            for (i = startx; i < startx + rows - offset; ++i)
                res[count++] = matrix[i][j];
            for(; j > starty; --j)
                res[count++] = matrix[i][j];
            for (; i > startx; --i)
                res[count++] = matrix[i][j];

            startx++;
            starty++;
            offset += 2;

        }

        if (std::min(rows, cols) % 2)//如果min(rows, columns)为奇数的话，需要单独给矩阵最中间的位置赋值
        {
            if (rows > cols)
            {
                for (int i = mid; i < mid + rows - cols + 1; ++i)
                {
                    res[count++] = matrix[i][mid];
                }
            }
            else
            {
                for (int i = mid; i < mid + cols - rows + 1; ++i)
                {
                    res[count++] = matrix[mid][i];
                }
            }
        }

        return res;
    }
};