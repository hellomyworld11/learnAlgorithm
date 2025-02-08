#include "Searching.h"



CSearching::CSearching()
{
}


CSearching::~CSearching()
{
}

int CSearching::binarySearch(vector<int>& nums, int target)
{
	//不断获取区间中间值和目标值进行比较。
	//1.如果目标值小于中间值，则区间最大范围到中间值
	//2.如果目标值大于中间值，则区间最小范围到中间值
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
