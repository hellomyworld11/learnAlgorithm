#include "Searching.h"



CSearching::CSearching()
{
}


CSearching::~CSearching()
{
}

int CSearching::binarySearch(vector<int>& nums, int target)
{
	//���ϻ�ȡ�����м�ֵ��Ŀ��ֵ���бȽϡ�
	//1.���Ŀ��ֵС���м�ֵ�����������Χ���м�ֵ
	//2.���Ŀ��ֵ�����м�ֵ����������С��Χ���м�ֵ
	int i = 0;
	int j = nums.size()-1;

	while (i <= j)
	{
		int m = (i + (j - i) / 2.0f);
		if (nums[m] > target)
		{
			j = m - 1;
		}
		else if (nums[m] < target)
		{
			i = m + 1;
		}
		else {
			return m;
		}
	}
	return -1;
}

int CSearching::binarySearcnInsertion(vector<int>& nums, int target)
{
	int i = 0;
	int j = nums.size() - 1;

	while (i <= j)
	{
		int m = (i + (j - i) / 2.0f);
		if (nums[m] > target)
		{
			j = m - 1;
		}
		else if (nums[m] < target)
		{
			i = m + 1;
		}
		else {
			return m;
		}
	}
	return i;
}

void CSearching::test()
{
	CSearching searching;
	vector<int> nums = {0, 1, 2, 3, 5, 6, 7, 8};
	int index = searching.binarySearch(nums, 4);
	cout << "vector: = " << index << endl;
	printVector(nums);
	cout << "find index: = " << index << endl;

	int insertindex = searching.binarySearcnInsertion(nums, 4);
	cout << "insert 4 index: = " << insertindex << endl;
}
