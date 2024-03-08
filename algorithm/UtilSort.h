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

//��������  O(nlogn)
//1. ѡ��1������  �ѱ���С�ķ�ǰ�棬������ķź��档
//2. �ֱ������� ���ұ����������� ֱ������ֻ��1����
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


//������ 
template <typename _Type>
void HeapSort(vector<_Type>& v)
{
	int len = v.size();
	// ��ʼ���� i ������һ��������_ʼ�{��
	for (int i = len / 2 - 1; i >= 0; i--)
		max_heapify(arr, i, len - 1);
	// �Ȍ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ������,�ُ����{�� ( �յ�����Ԫ��֮ǰ��Ԫ�� ),ֱ�������ꮅ
	for (int i = len - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i - 1);
	}
}

//  �����򣺣����ѣ������������ӶѶ��Ѹ�ж��������������֮ǰ���ٻָ��ѡ�
template <typename _Type>
void max_heapify(vector<_Type>& v, int start, int end) {
	// ���������ָ����ӽ��ָ��
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { // ���ӽ��ָ���ڷ�Χ�Ȳ����Ƚ�
		if (son + 1 <= end && arr[son] < arr[son + 1])
			9 / 18
			// �ȱȽσɂ��ӽ���С��ѡ������
			son++;
		if (arr[dad] > arr[son])
			// �����������ӽ����������ɣ�ֱ����������
			return;
		else { // ��t�������Ӄ����ټ����ӽ�������Ƚ�
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
