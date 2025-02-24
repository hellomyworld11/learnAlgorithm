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
	generateNums(20, nums);
	printVector(nums);
	cout << "-----------" << endl;
	//sort.insertSort(nums);
	sort.quickSort(nums, 0, nums.size()-1);
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

	//1. 初始第一个数当作已排序区间， 区间后的数依次往区间中从后往前遍历比较
	//2. 如果小于区间的数，则挪动，直到不小于为止。插入。
	//时间复杂度 O(n2) 控件复杂度O(1)
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

void CSort::quickSort(vector<int>& nums, int left, int right)
{
	//时间复杂度O(nlog n) : 递归层数log n  哨兵划分n
	//空间复杂度 O(n) 栈帧空间
	if (left >= right) //数组长度为1时中止
	{
		return;
	}
	//哨兵划分
	int pivot = partition(nums, left, right);
	//递归左子数组
	quickSort(nums, left, pivot-1);
	//递归右子数组
	quickSort(nums, pivot + 1, right);
}

int CSort::partition(vector<int>& nums, int left, int right)
{
	//1. 第一个数作为基准数，j从后往前，i从前往后 如果j指向的数小于基准，
	//2. i指向的数大于基准 交换i和j的数
	//3. 最后交换基准和两个子数组的分界线
	int i = left;
	int j = right;
	//nums[left] 作为基准数 得到左右两个区间
	while (i < j)
	{
		//从右往左找首个小于基准数的元素
		while ((i < j) && nums[j] >= nums[left])
		{
			j--;
		}
		//从左往右找首个大于基准数的元素
		while ((i < j) && nums[i] <= nums[left])
		{
			i++;
		}
		//小于基准的和大于基准的交换
		std::swap(nums[i], nums[j]);
	}
	//基准交换到分界线
	std::swap(nums[left], nums[i]);
	return i; //返回分界线索引
}

int CSort::partitionByMid(vector<int>& nums, int left, int right)
{
	//取中位数
	int m =  medianThree(nums, left, (left + right )/ 2, right);
	swap(nums[m], nums[left]);

	partition(nums, left, right);
}

int CSort::medianThree(vector<int>& nums, int left, int mid, int right)
{
	int l = nums[left], m = nums[mid], r = nums[right];
	if ((l <= m && m <= r) || (r <= m && m <= l))
	{
		return mid;
	}
	if ((m <= l && l <= r) || (r <= l && l <= m))
	{
		return l;
	}
	return r;
}

