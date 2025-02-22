#include "Sort.h"


void CSort::test()
{
	CSort sort;
	//vector<int> nums= {10, 6, 7, 4, 5, 4, 3, 0};
	//vector<int> nums = { 0, 1, 2, 5, 7, 9, 10 };
	//vector<int> nums = { 0, 1, 2, 5, 7, 9, 10 };
	//sort.selectSort(nums);
	//sort.bubbleSort(nums);
	vector<int> nums;
	generateNums(10000, nums);
	printVector(nums);
	cout << "-----------" << endl;
	sort.insertSort(nums);
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

void CSort::bubbleSort(vector<int>& nums)
{
	//1. 每遍历一轮， 两两比对，小于或大于则交换，直到最大数放到尾部
	//2. 遍历n-1轮  ，直到没有可排序的区间
	//时间复杂度 O(n2) 控件复杂度O(1)
	int n = nums.size();
	//外层是轮数
	for (int i = 0; i < n - 1; i++)
	{
		bool bSorted = true; //是否已排序
		//内层是区间，并两两比较
		for (int j = 0; j < n - i - 1; j++)
		{
			if (nums[j] > nums[j+1]) //交换大值到后面
			{
				swap(nums[j], nums[j + 1]);
				bSorted = false;
			}
		}
		if (bSorted)
		{
			break;
		}
	}
}

void CSort::insertSort(vector<int>& nums)
{
	//1. 依次把元素插入到有序区间 {10, 6, 7, 4, 5, 4, 3, 0};
	//2. 需要n-1轮 的 数据遍历比较, 然后插入、移动元素位置 
	
	//3 次循环效率低，从大往小遍历过程中顺便挪动即可
// 	int n = nums.size();
// 	for (int i = 0; i < n -1 ; i++)
// 	{
// 		//内层 插入比较
// 		int target = nums[i + 1];
// 		int j = 0;
// 		while (j < i+1)
// 		{
// 			if (target < nums[j])
// 			{//插入
// 				//1.先往后挪动
// 				for (int k = i; k >= j; k--)
// 				{
// 					nums[k + 1] = nums[k];
// 				}
// 				//2.再插入
// 				nums[j] = target;
// 				break;
// 			}
// 			j++;
// 		}
// 	}

	int n = nums.size();
	//外层控制轮数 比如5个数只需要4轮遍历
	for (int i = 1; i < n ; i++)
	{
		//target是准备放入区间的值  j 是 已排序区间的比较索引
		int target = nums[i], j = i - 1;
		while (j >= 0 && nums[j] > target) //如果比排序区间的值小，挪动
		{
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = target;  
	}
}

