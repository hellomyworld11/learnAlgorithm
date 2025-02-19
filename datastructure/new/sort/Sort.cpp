#include "Sort.h"


void CSort::test()
{
	CSort sort;
	vector<int> nums= {10, 6, 7, 4, 5, 4, 3, 0};
	sort.selectSort(nums);
	printVector(nums);
}

void CSort::selectSort(vector<int>& nums)
{
	//1. 每遍历一轮数组，获取一个最大(小)值,交换到未排序区间的最大(小)索引的值。
	//2. 总共需要遍历size()-1 轮，即可完成排序
	//3. 时间复杂度O(n2) 空间复杂度O(1)
	for (int i = 0; i < nums.size()-1 ; i++)
	{
		//找到最小值
		int min = i;
		for (int j = i+1; j < nums.size(); j++)
		{
			if (nums[j] < nums[min])
			{
				min = j;  //记录最小元素的索引
			}
		}
		//交换
		if (i != min)
		{
			swap(nums[i], nums[min]);
		}	
	}
}


