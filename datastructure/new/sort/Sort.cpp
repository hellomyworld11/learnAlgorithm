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

