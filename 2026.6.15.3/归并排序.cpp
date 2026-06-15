#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

void shifDown(std::vector<int>& arr, int i, int n)//大根堆调整
{
	while (true)
	{
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < n && arr[left] > arr[largest])
			largest = left;
		if (right < n && arr[right] > arr[largest])
			largest = right;

		if (largest == i)
			break;

		std::swap(arr[i], arr[largest]);
		i = largest;
	}
}

void heapSort(std::vector<int>& arr)
{
	int n = arr.size();

	for (int i = n / 2 - 1; i >= 0; i--)
		shifDown(arr, i, n);//构建大根堆（单次）

	for (int i = n - 1; i > 0; i--)
	{
		std::swap(arr[0], arr[i]);
		shifDown(arr, 0, i);
	}
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	heapSort(arr);
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
	return 0;
}