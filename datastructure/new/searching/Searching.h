#pragma once

#include "../util.h"

class CSearching
{
public:
	CSearching();

	~CSearching();

	//二分法 查找双闭区间中的一个数的位置
	int binarySearch(vector<int>& nums, int target);

	//二分法 查找数插入到数组中的索引
	int binarySearchInsertion(vector<int>& nums, int target);

	//二分法 重复元素 查找最左边的目标索引
	int binarySearchInsertionRepeat(vector<int>& nums, int target);

	static void test();
};

