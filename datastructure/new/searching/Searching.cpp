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

int CSearching::binarySearchInsertion(vector<int>& nums, int target)
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

int CSearching::binarySearchInsertionRepeat(vector<int>& nums, int target)
{
	int i = 0;
	int j = nums.size() - 1;
	while (i <= j)
	{
		int m = i + (j - i) / 2.0f;
		if (nums[m] > target)
		{
			j = m - 1;
		}
		else if (nums[m] < target)
		{		
			i = m + 1;
		}
		else {
			j = m - 1;
		}
	}
	return i;
}

std::vector<int> CSearching::getAddEleForTarget(vector<int>& nums, int target)
{
	//1. ������������ʱ
// 	vector<int> res;
// 	for (int i = 0; i < nums.size(); i++)
// 	{
// 		for (int j = i+1; j < nums.size(); j++)
// 		{
// 			if ((nums[i] + nums[j]) == target )
// 			{
// 				return{i, j};
// 			}
// 		}
// 	}

	//��Ӧ leetcode  ����֮�� ʹ�ù�ϣ��洢��ֵ
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++)
	{
		if (map.find(target - nums[i]) != map.end())
		{
			return{i, map[target-nums[i]]};
		}
		map.emplace(nums[i], i);
	}

	return {};
}

void CSearching::test()
{
	CSearching searching;
	vector<int> nums = {2, 7, 11, 15};
	vector<int> res =  searching.getAddEleForTarget(nums, 13);
	printVector(res);
}
