#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>




void downAdjust(std::vector<int>& heap, int i, int len)
{
	while (true)
	{
		int maxIdx = i;

		//找到左右节点中最大的那个
		if(2 * i <= len && heap[2 * i] > heap[maxIdx])
			//完全二叉树中左节点为2*i
			maxIdx = 2 * i;

		if (2 * i + 1 <= len && heap[2 * i + 1] > heap[maxIdx])
			//完全二叉树中右节点为2*i+1
			maxIdx = 2 * i + 1;

		if (maxIdx == i)//如果父节点最大，则不需要调整
			break;

		std::swap(heap[i], heap[maxIdx]);
		i = maxIdx;
	}
}

//建堆
void buildHeap(std::vector<int>& arr)
{
	int n = arr.size() - 1;//因为下标1开始
	for (int i = n / 2; i > 0; --i)
		//建堆从n/2开始调整，因为n/2+1到n都是叶子节点，不需要调整
	{
		downAdjust(arr, i, n);
	}
}


void heapSort(std::vector<int>& arr)
{
	int n = arr.size();
	buildHeap(arr);

	for (int i = n; i > 1; --i)
	{
		std::swap(arr[1], arr[i]);
		downAdjust(arr, 1, i - 1);
	}

}


int main()
{
	std::vector<int> arr = { 0, 3, 5, 1, 2, 4 };//下标从1开始
	heapSort(arr);
	for(int i = 1; i < arr.size(); ++i)
		std::cout << arr[i] << " ";

	return 0;
}