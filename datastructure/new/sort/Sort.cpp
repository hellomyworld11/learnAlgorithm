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
	generateNums(50, nums);
	printVector(nums);
	cout << "-----------" << endl;
	//sort.insertSort(nums);
	//sort.quickSort(nums, 0, nums.size()-1);
	//sort.mergeSort(nums, 0, nums.size() - 1);
	//sort.heapSort(nums);
	//vector<float> floatnums = { 0.49f, 0.96f, 0.82f, 0.09f, 0.57f, 0.43f, 0.91f, 0.75f, 0.15f, 0.37f };
	//sort.bucketSort(floatnums);
	sort.countingSort(nums);
	//printVector(floatnums);
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

	return partition(nums, left, right);
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

void CSort::quickSort_tail(vector<int>& nums, int left, int right)
{
	while (left < right)
	{
		int pivot = partition(nums, left, right);

		//左边区间比右边小，排序左边区间进行递归。递归层数会小点
		if (pivot - left < right - pivot)
		{
			quickSort_tail(nums, left, pivot - 1);
			left = pivot + 1;  //剩余大区间 继续非递归快排
		}
		else {
			quickSort_tail(nums, pivot + 1, right);
			right = pivot - 1; //剩余大区间 继续非递归快排
		}

	}
}

void CSort::mergeSort(vector<int>& nums, int left, int right)
{
	//1.拆分: 不断的从中间拆分数组，直到每个子数组的个数为1
	//2.合并: 子数组合并阶段调整顺序。
	//时间复杂度O(nlog(n)) 空间复杂度O(n)

	if (left >= right)
	{
		return;
	}

	int mid = left + (right - left) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	merge(nums, left, mid, right);
}

void CSort::merge(vector<int>& nums, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	vector<int> temps;
	while ((i <= mid) && (j <= right))
	{
		if (nums[i] < nums[j])
		{
			temps.emplace_back(nums[i++]);
		}
		else {
			temps.emplace_back(nums[j++]);
		}
	}

	while (i <= mid)
	{
		temps.emplace_back(nums[i++]);
	}
	while (j <= right)
	{
		temps.emplace_back(nums[j++]);
	}

	for (int i = 0; i < temps.size(); i++)
	{
		nums[left + i] = temps[i];
	}
}

void CSort::heapSort(vector<int>& nums)
{
	//1. 先建立最大堆。
	//2. 遍历n-1轮，交换堆顶和堆底(把最大数放最后面作为已排序的区间)，堆平衡被破坏，继续从堆顶往下堆化。
	// 时间复杂度O(nlogn) 空间O(1)
	//建堆
	for (int i = nums.size() / 2 - 1; i >= 0; i--)
	{
		siftDown(nums, nums.size(), i);
	}
	//从堆中提取最大元素，循环n-1轮
	for (int i = nums.size()-1; i > 0; i--)
	{
		//交换最大元素和堆底，未排序区间减1
		swap(nums[0], nums[i]);
		//继续堆化
		siftDown(nums, i, 0);
	}
}

void CSort::siftDown(vector<int>& nums, int n, int i)
{
	while (true)
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int m = i;

		if (l < n && nums[l] > nums[m])
		{
			m = l;
		}
		if (r < n && nums[r] > nums[m])
		{
			m = r;
		}
		
		if (m == i)
		{
			break;
		}

		swap(nums[m], nums[i]);
		i = m;
	}
}

void CSort::bucketSort(vector<float>& nums)
{
	//1. 按范围分成n个桶
	//2. 某个范围的数放入某个桶
	//3. 每个桶内数字排序
	//4. 所有通数字合入成最终排好序的数组
	//时间复杂度O(n+k) 控件O(n+k)

	int k = nums.size() / 2; //分成 k个桶
	vector<vector<float>> buckets(k);

	for (float num : nums)
	{
		int i = num * k;  //按范围放入某个桶
		buckets[i].push_back(num);
	}

	for (auto& bucket : buckets)
	{//每个桶单独排序
		std::sort(bucket.begin(), bucket.end());
	}

	//合并桶
	int i = 0;
	for (auto& bucket : buckets)
	{
		for (float num : bucket)
		{
			nums[i++] = num;
		}
	}
}

void CSort::countingSort(vector<int>& nums)
{
	//1. 获取数组最大数
	//2. 从0遍历至最大数作为数组下标，值 存储这些数字的次数 
	//3. 遍历数组依次放入nums
	int m = 0;
	for (auto num : nums)
	{
		m = std::max(num, m);
	}

	vector<int> counter(m+1, 0);
	for (auto num : nums)
	{
		counter[num]++;
	}

	int k = 0;
	for (int i = 0; i < counter.size(); i++)
	{
		for (int j = 0; j < counter[i]; j++)
		{
			nums[k++] = i;
		}
	}

	//需要考虑 数组是对象的情况，无法决定同样值得对象哪些是前和后，所有要按照原数组来排

}

