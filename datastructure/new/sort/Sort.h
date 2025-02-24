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

	static void test();

};

