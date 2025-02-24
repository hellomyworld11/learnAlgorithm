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

	static void test();

};

