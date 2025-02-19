#pragma once

#include "../util.h"

//查找算法
class CSearching
{
public:
	CSearching();

	~CSearching();

	//二分法 查找双闭区间中的一个数的位置
	int binarySearch(vector<int>& nums, int target);

	//二分法 查找数插入到数组中的索引
	int binarySearchInsertion(vector<int>& nums, int target);

	//二分法 重复元素 查找数插入到数组中的索引
	int binarySearchInsertionRepeat(vector<int>& nums, int target);

	//给定一个整数数组 nums 和一个目标元素 target ，请在数组中搜索“和”为 target 的两个元素，并返回它们的数组索引。返回任意一个解即可。
	vector<int> getAddEleForTarget(vector<int>& nums, int target);

	static void test();
};

