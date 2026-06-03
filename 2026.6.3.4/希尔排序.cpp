#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

//每隔 5 个一组的话：
//第 0 组：0，5，10
//第 1 组：1，6
//第 2 组：2，7
//第 3 组：3，8
//第 4 组：4，9
//所以i < n循环这么多次

void shellSort(std::vector<int>& arr)
{
	int n = arr.size();

	//希尔就是多了一个gap的概念，gap是每次比较的间隔，初始值为n/2，每次缩小一半，直到gap为0
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		//对每个gap进行插入排序
		for (int i = gap; i < n; ++i)
		{
			int key = arr[i];
			int j;
			for (j = i; 
				j >= gap && arr[j - gap] > key;//这里就是条件限制了
				j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = key;
		}
	}

}