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
	//1. ÿ����һ�����飬��ȡһ�����(С)ֵ,������δ������������(С)������ֵ��
	//2. �ܹ���Ҫ����size()-1 �֣������������
	//3. ʱ�临�Ӷ�O(n2) �ռ临�Ӷ�O(1)
	for (int i = 0; i < nums.size()-1 ; i++)
	{
		//�ҵ���Сֵ
		int min = i;
		for (int j = i+1; j < nums.size(); j++)
		{
			if (nums[j] < nums[min])
			{
				min = j;  //��¼��СԪ�ص�����
			}
		}
		//����
		if (i != min)
		{
			swap(nums[i], nums[min]);
		}	
	}
}

void CSort::bubbleSort(vector<int>& nums)
{
	//1. ÿ����һ�֣� �����ȶԣ�С�ڻ�����򽻻���ֱ��������ŵ�β��
	//2. ����n-1��  ��ֱ��û�п����������
	//ʱ�临�Ӷ� O(n2) �ؼ����Ӷ�O(1)
	int n = nums.size();
	//���������
	for (int i = 0; i < n - 1; i++)
	{
		bool bSorted = true; //�Ƿ�������
		//�ڲ������䣬�������Ƚ�
		for (int j = 0; j < n - i - 1; j++)
		{
			if (nums[j] > nums[j+1]) //������ֵ������
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
	//1. ���ΰ�Ԫ�ز��뵽�������� {10, 6, 7, 4, 5, 4, 3, 0};
	//2. ��Ҫn-1�� �� ���ݱ����Ƚ�, Ȼ����롢�ƶ�Ԫ��λ�� 
	
	//3 ��ѭ��Ч�ʵͣ��Ӵ���С����������˳��Ų������
// 	int n = nums.size();
// 	for (int i = 0; i < n -1 ; i++)
// 	{
// 		//�ڲ� ����Ƚ�
// 		int target = nums[i + 1];
// 		int j = 0;
// 		while (j < i+1)
// 		{
// 			if (target < nums[j])
// 			{//����
// 				//1.������Ų��
// 				for (int k = i; k >= j; k--)
// 				{
// 					nums[k + 1] = nums[k];
// 				}
// 				//2.�ٲ���
// 				nums[j] = target;
// 				break;
// 			}
// 			j++;
// 		}
// 	}

	//1. ��ʼ��һ�����������������䣬 �������������������дӺ���ǰ�����Ƚ�
	//2. ���С�������������Ų����ֱ����С��Ϊֹ�����롣
	//ʱ�临�Ӷ� O(n2) �ؼ����Ӷ�O(1)
	int n = nums.size();
	//���������� ����5����ֻ��Ҫ4�ֱ���
	for (int i = 1; i < n ; i++)
	{
		//target��׼�����������ֵ  j �� ����������ıȽ�����
		int target = nums[i], j = i - 1;
		while (j >= 0 && nums[j] > target) //��������������ֵС��Ų��
		{
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = target;  
	}
}

void CSort::quickSort(vector<int>& nums, int left, int right)
{
	//ʱ�临�Ӷ�O(nlog n) : �ݹ����log n  �ڱ�����n
	//�ռ临�Ӷ� O(n) ջ֡�ռ�
	if (left >= right) //���鳤��Ϊ1ʱ��ֹ
	{
		return;
	}
	//�ڱ�����
	int pivot = partition(nums, left, right);
	//�ݹ���������
	quickSort(nums, left, pivot-1);
	//�ݹ���������
	quickSort(nums, pivot + 1, right);
}

int CSort::partition(vector<int>& nums, int left, int right)
{
	//1. ��һ������Ϊ��׼����j�Ӻ���ǰ��i��ǰ���� ���jָ�����С�ڻ�׼��
	//2. iָ��������ڻ�׼ ����i��j����
	//3. ��󽻻���׼������������ķֽ���
	int i = left;
	int j = right;
	//nums[left] ��Ϊ��׼�� �õ�������������
	while (i < j)
	{
		//�����������׸�С�ڻ�׼����Ԫ��
		while ((i < j) && nums[j] >= nums[left])
		{
			j--;
		}
		//�����������׸����ڻ�׼����Ԫ��
		while ((i < j) && nums[i] <= nums[left])
		{
			i++;
		}
		//С�ڻ�׼�ĺʹ��ڻ�׼�Ľ���
		std::swap(nums[i], nums[j]);
	}
	//��׼�������ֽ���
	std::swap(nums[left], nums[i]);
	return i; //���طֽ�������
}

int CSort::partitionByMid(vector<int>& nums, int left, int right)
{
	//ȡ��λ��
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

