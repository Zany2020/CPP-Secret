#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>


//下沉
void siftDown(std::vector<int>& arr, int n, int root) //一般vector后都加&表示直接改变值性质如位置但不修改值
{
	int largest = root; 
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < n && arr[left] > arr[largest]) 
	{
		largest = left;
	}

	if (right < n && arr[right] > arr[largest]) 
	{
		largest = right;
	}

	if (largest != root) 
	{
		std::swap(arr[root], arr[largest]);
		siftDown(arr, n, largest);
	}

}

void heapSort(std::vector<int>& arr) 
{
	int n = arr.size();
	// 构建最大堆
	for (int i = n / 2 - 1; i >= 0; i--) 
	{
		siftDown(arr, n, i);
	}
	// 逐个从堆中取出元素
	for (int i = n - 1; i > 0; i--) 
	{
		std::swap(arr[0], arr[i]);
		siftDown(arr, i, 0);//形成大顶堆，然后在通过交换排序到后面
	}
}

void printArray(const std::vector<int>& arr) 
{
	for (int num : arr) 
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

int main() 
{
	std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
	std::cout << "原始数组: ";
	printArray(arr);
	heapSort(arr);
	std::cout << "排序后的数组: ";
	printArray(arr);
	return 0;
}