#pragma once
#include "../util.h"

//�����㷨
class CSort
{
public:
	CSort()=default;

	~CSort()=default;

	//1.ѡ������
	void selectSort(vector<int>& nums);
	//2.ð������
	void bubbleSort(vector<int>& nums);
	//3.��������
	void insertSort(vector<int>& nums);
	//4.��������
	void quickSort(vector<int>& nums, int left, int right);
	//4.1 �ڱ�����
	int partition(vector<int>& nums, int left, int right);
	//4.2 �ڱ����ְ���λ��
	int partitionByMid(vector<int>& nums, int left, int right);
	int medianThree(vector<int>& nums, int left, int mid, int right);
	//4.3 β�ݹ��Ż�
	void quickSort_tail(vector<int>& nums, int left, int right);
	
	//5. �鲢����
	void mergeSort(vector<int>& nums, int left, int right);
	void merge(vector<int>& nums, int left, int mid, int right);

	//6. ����
	void heapSort(vector<int>& nums);
	void siftDown(vector<int>& nums, int n, int i);

	//7.Ͱ��
	void bucketSort(vector<float>& nums);

	//8.��������
	void countingSort(vector<int>& nums);

	static void test();

};

