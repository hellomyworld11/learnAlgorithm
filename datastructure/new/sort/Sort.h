#pragma once
#include "../util.h"

//排序算法
class CSort
{
public:
	CSort()=default;

	~CSort()=default;

	//1.选择排序
	void selectSort(vector<int>& nums);
	//2.冒泡排序
	void bubbleSort(vector<int>& nums);
	//3.插入排序
	void insertSort(vector<int>& nums);
	//4.快速排序
	void quickSort(vector<int>& nums, int left, int right);
	//4.1 哨兵划分
	int partition(vector<int>& nums, int left, int right);
	//4.2 哨兵划分按中位数
	int partitionByMid(vector<int>& nums, int left, int right);
	int medianThree(vector<int>& nums, int left, int mid, int right);
	//4.3 尾递归优化
	void quickSort_tail(vector<int>& nums, int left, int right);
	
	//5. 归并排序
	void mergeSort(vector<int>& nums, int left, int right);
	void merge(vector<int>& nums, int left, int mid, int right);

	//6. 堆排
	void heapSort(vector<int>& nums);
	void siftDown(vector<int>& nums, int n, int i);

	//7.桶排
	void bucketSort(vector<float>& nums);

	//8.计数排序
	void countingSort(vector<int>& nums);

	static void test();

};

