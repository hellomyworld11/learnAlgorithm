#include "binary_search_recur.h"


//基于分治法 的二分法
//O(logn)

int dfs(vector<int>& nums, int target, int i, int j)
{
	if (i > j)
	{
		return -1;
	}
	int mid = (i + j) / 2;
	if (nums[mid] < target)
	{
		return dfs(nums, target, mid + 1, j);
	}
	else if (nums[mid] > target)
	{
		return dfs(nums, target, i, mid - 1);
	}
	else {
		return mid;
	}
}

int binarySearch(vector<int>& nums, int target)
{
	int n = nums.size();
	//cout << target << " 位置： " << dfs(nums, target, 0, n-1);
	return dfs(nums, target, 0, n-1);
}

void test_divide_conquer()
{
	vector<int> nums = { 1, 3, 6, 8, 12, 15, 23, 26, 31, 35 };
	printVector(nums);
	// 二分查找（双闭区间）
	
	for (auto num : nums)
	{
		int index = binarySearch(nums, num);
		cout << "目标元素 " << num <<" 的索引 = " << index << endl;
	}
	
}
