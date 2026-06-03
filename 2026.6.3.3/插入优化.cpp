#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

void binaryInsertionSort(std::vector<int>& arr)
{
	int n = arr.size();
	for (int i = 1; i < n; ++i)
	{
		int key = arr[i];
		int left = 0;
		int right = i - 1;

		while (left <= right)
		{
			int mid = (right + left) / 2;
			if(arr[i] < arr[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		//left is the position to insert key

		for(int j = i - 1; j >= left; --j)
		{
			arr[j + 1] = arr[j];
		}
		arr[left] = key;
	}


}