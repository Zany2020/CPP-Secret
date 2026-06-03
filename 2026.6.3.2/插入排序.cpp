#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

void insertSort(std::vector<int>& arr)
{
	int n = arr.size();
	for (int i = 1; i < n; ++i)
	{
		int key = arr[i];
		int j = i - 1;

		//比key大的元素后移
		while (j >= 0 && arr[j] > key)//arr[j]就是key的前一个元素，如果这个元素比key大，就把这个元素后移
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	std::vector<int> arr = { 12, 11, 13, 5, 6 };
	insertSort(arr);
	for (int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	return 0;
}