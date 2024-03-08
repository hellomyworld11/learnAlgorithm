#pragma once
#include <iostream>
#include <vector>
using namespace std;

//冒泡排序 O(n2)

template <typename _Type>
void BubbleSort(vector<_Type>& v)
{
	int len = v.size();
	for (int i = 0; i < len - 1; i++) //控制排出最大数的字数，比如 5个数只需要冒泡4次
	{
		for (int j = 0; j < len - 1 - i; j++) // 每轮冒泡时需要 判断是否要交换数字的次数
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
			}
		}
	}
}

//选择排序 O(n2)
template <typename _Type>
void SelectSort(vector<_Type>& v)
{
	int len = v.size();
	int min;
	for (int i = 0; i < len - 1; i++) //局部排序次数
	{
		min = i;
		for (int j = i+1; j < len ; j++) //遍历局部无序区，获取最小值
		{
			if (v[j] < v[min])
			{
				min = j;
			}
		}
		if (i != min)  //获取最小值 放到最前面
		{
			swap(v[i], v[min]);
		}
	}
}

//插入排序 0(N2)
template <typename _Type>
void InsertSort(vector<_Type>& v)
{
	int len = v.size();
	for (int i = 1; i < len - 1; i++)
	{
		_Type temp = v[i];
		int j = i - 1;
		while ( j >= 0)
		{
			if (temp < v[j])
			{
				v[j + 1] = v[j];
				v[j] = temp;
				j--;
			}
			else
				break;
		}
	}
}

//快速排序  O(nlogn)
//1. 选择1个基数  把比它小的放前面，比它大的放后面。
//2. 分别对左边区 和右边区进行排序 直到区域只有1个数
template <typename _Type>
void QuickSort(vector<_Type>& v)
{
	QuickSubSort(v, 0, v.size() - 1);
}

template <typename _Type>
void QuickSubSort(vector<_Type>& v, int low, int high)
{
	if (low >= high)  //  结束标志
		return;
	int first = low;  //  低位下标
	int last = high;  //  高位下标
	_Type key = v[first];  //  设第一个为基准
	while (first < last)
	{
		//  将比第一个小的移到前面
		while (first < last && v[last] >= key)
			last--;
		if (first < last)
			v[first++] = v[last];
		//  将比第一个大的移到后面
		while (first < last && v[first] <= key)
			first++;
		if (first < last)
			v[last--] = v[first];
	}
	//  基准置位
	v[first] = key;
	//  前半递归
	QuickSubSort(v, low, first - 1);
	//  后半递归
	QuickSubSort(v, first + 1, high);
}


//堆排序 
template <typename _Type>
void HeapSort(vector<_Type>& v)
{
	int len = v.size();
	// 初始化， i 從最後一個父结点開始調整
	for (int i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len - 1);
	// 先將第一個元素和已经排好的元素前一位做交换,再從新調整 ( 刚调整的元素之前的元素 ),直到排序完畢
	for (int i = len - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

//  堆排序：（最大堆，有序区）。从堆顶把根卸出来放在有序区之前，再恢复堆。
template <typename _Type>
void max_heapify(vector<_Type>& v, int start, int end) {
	// 建立父结点指标和子结点指标
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { // 若子结点指标在范围內才做比较
		if (son + 1 <= end && arr[son] < arr[son + 1])
			9 / 18
			// 先比较兩個子结点大小，选择最大的
			son++;
		if (arr[dad] > arr[son])
			// 如果父结点大於子结点代表调整完成，直接跳出函数
			return;
		else { // 否則交换父子內容再继续子结点和孙结点比较
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

template <typename _Type>
void PrintVec(vector<_Type>& v);
template <typename _Type>
void PrintVec(vector<_Type>& v)
{
	for (auto val : v)
	{
		std::cout << val << " ";
	}
	std::cout << "\n";
}
