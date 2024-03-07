#pragma once
#include <iostream>
#include <vector>
using namespace std;

//ð������ O(n2)

template <typename _Type>
void BubbleSort(vector<_Type>& v)
{
	int len = v.size();
	for (int i = 0; i < len - 1; i++) //�����ų������������������ 5����ֻ��Ҫð��4��
	{
		for (int j = 0; j < len - 1 - i; j++) // ÿ��ð��ʱ��Ҫ �ж��Ƿ�Ҫ�������ֵĴ���
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
			}
		}
	}
}

//ѡ������ O(n2)
template <typename _Type>
void SelectSort(vector<_Type>& v)
{
	int len = v.size();
	int min;
	for (int i = 0; i < len - 1; i++) //�ֲ��������
	{
		min = i;
		for (int j = i+1; j < len ; j++) //�����ֲ�����������ȡ��Сֵ
		{
			if (v[j] < v[min])
			{
				min = j;
			}
		}
		if (i != min)  //��ȡ��Сֵ �ŵ���ǰ��
		{
			swap(v[i], v[min]);
		}
	}
}

//�������� 0(N2)
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

//�������� 
template <typename _Type>
void QuickSort(vector<_Type>& v)
{
	QuickSubSort(v, 0, v.size() - 1);
}

template <typename _Type>
void QuickSubSort(vector<_Type>& v, int low, int high)
{
	if (low >= high)  //  ������־
		return;
	int first = low;  //  ��λ�±�
	int last = high;  //  ��λ�±�
	_Type key = v[first];  //  ���һ��Ϊ��׼
	while (first < last)
	{
		//  ���ȵ�һ��С���Ƶ�ǰ��
		while (first < last && v[last] >= key)
			last--;
		if (first < last)
			v[first++] = v[last];
		//  ���ȵ�һ������Ƶ�����
		while (first < last && v[first] <= key)
			first++;
		if (first < last)
			v[last--] = v[first];
	}
	//  ��׼��λ
	v[first] = key;
	//  ǰ��ݹ�
	QuickSubSort(v, low, first - 1);
	//  ���ݹ�
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
