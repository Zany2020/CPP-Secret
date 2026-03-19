//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<climits>
//#include<vector>
//
//class Solution
//{
//private:
//	std::vector<std::vector<int>> mat;
//	const int ROWS = 3;
//	const int COLS = 3;
//
//	bool isRowmax(int i, int j)
//	{
//		int max_val = mat[i][0];
//		for(int col = 1; col < COLS; col++)
//		{
//			if(mat[i][col] > max_val)
//			{
//				max_val = mat[i][col];
//			}
//		}
//		return mat[i][j] == max_val;
//	}
//
//	bool isColMin(int i, int j)
//	{
//		int min_val = mat[0][j];
//		for (int row = 1; row < ROWS; row++)
//		{
//			if (min_val > mat[row][j])
//			{
//				min_val = mat[row][j];
//			}
//		}
//		return mat[i][j] == min_val;
//	}
//
//public:
//	Solution()
//	{
//		mat.resize(ROWS, std::vector<int>(COLS));
//		readMatrix();
//	}
//
//	void readMatrix()
//	{
//		for (int i = 0; i < ROWS; ++i)
//		{
//			for (int j = 0; j < COLS; ++j)
//			{
//				std::cin >> mat[i][j];
//			}
//		}
//	}
//
//	void findSaddlePoints()
//	{
//		bool judge = true;
//		for (int i = 0; i < ROWS; ++i)
//		{
//			for (int j = 0; j < COLS; ++j)
//			{
//				if (isRowmax(i, j) && isColMin(i, j))
//				{
//					std::cout << i << " " << j << mat[i][j];
//					judge = false;
//				}
//			}
//		}
//		if (judge)
//			std::cout << "Not Found";
//	}
//
//};
//
//int main()
//{
//	Solution solution;
//	solution.findSaddlePoints();
//	return 0;
//}


#include<iostream>
#include<algorithm>
#include<string>
#include<climits>
#include<vector>
#include <fstream>

class Solution
{
private:
	std::vector<std::vector<int>> mat;
	static const int ROWS = 4;
	static const int COLS = 5;

	bool isRowmax(int i, int j)
	{
		int max_val = INT_MIN;	
		for (int col = 0; col < COLS; col++)
		{
			if (mat[i][col] > max_val)
			{
				max_val = mat[i][col];
			}
		}
		return mat[i][j] == max_val;
	}

	bool isColMin(int i, int j)
	{
		int min_val = INT_MAX;
		for (int row = 0; row < ROWS; row++)
		{
			if (min_val > mat[row][j])
			{
				min_val = mat[row][j];
			}
		}
		return mat[i][j] == min_val;
	}

public:
	Solution()
	{
		mat.resize(ROWS, std::vector<int>(COLS));
	}

	void findSaddlePoints(int m[ROWS][COLS])
	{
		bool judge = true;
		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLS; ++j)
			{
				mat[i][j] = m[i][j];
			}
		}
		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLS; ++j)
			{
				if (isRowmax(i, j) && isColMin(i, j))
				{
					std::cout << i << " " << j << " " << mat[i][j] << std::endl;
					judge = false;
				}
			}
		}
		if (judge)
			std::cout << "Not Found";
	}

};

int main()
{
	Solution solution;
	int m[4][5] = {
		{2,3,4,5,6},
		{3,4,5,6,8},
		{3,1,2,5,9},
		{3,4,1,8,7}

	};
	solution.findSaddlePoints(m);
	return 0;
}