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

	static void test();

};

