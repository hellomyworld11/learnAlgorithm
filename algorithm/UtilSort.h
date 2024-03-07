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

//快速排序 
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
