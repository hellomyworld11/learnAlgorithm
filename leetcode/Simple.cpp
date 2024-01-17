#include "Simple.h"



Simple::Simple()
{
}


Simple::~Simple()
{
}

//给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
//nums = [1,1,0,1,1,1] 3
int Simple::findMaxConsecutiveOnes(vector<int>& nums)
{
	int len = nums.size();
	if (len <= 0 || len >= pow(10, 5))
	{
		return -1;
	}
	//求1个数
	int ans = 0;
	int val = 0;
	for (int i = 0; i < len; i++)
	{
		if (nums[i] == 1)
		{
			val++;
		}
		if (nums[i] == 0 || i == len - 1)
		{		
			ans = max(ans, val);
			val = 0;  //重新计数
		}
	}
	return max(ans, val);
}

void Simple::moveZeroes(vector<int>& nums)
{
	//算法就是直接把非零的元素按原先顺序依次放开头，
	//[0,1,0,3,12]
	int t_curIndex = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != 0)
		{
			if (i != t_curIndex)
			{
				nums[t_curIndex] = nums[i];
				nums[i] = 0;
			}
			t_curIndex++;
		}
	}
}

// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
int Simple::removeElement(vector<int>& nums, int val)
{
	//[3,2,2,3]
	int t_curIndex = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != val)
		{
			if (i != t_curIndex)
			{
				nums[t_curIndex] = nums[i];
				nums[i] = 0;
			}
			t_curIndex++;
		}
	}
	return t_curIndex;
}
