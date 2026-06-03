#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

void bubbleSort(std::vector<int>& arr)
{
	int n = arr.size();
	int last = n - 1;
	int idx = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		bool sorted = false;
		for(int j = 0; j < last; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				sorted = true;
				idx = j;
			}
		}

		last = idx;
		if (!sorted) break;
	}

}

int main()
{
	std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
	bubbleSort(arr);
	std::cout << "Sorted array: \n";
	for (int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	return 0;
}