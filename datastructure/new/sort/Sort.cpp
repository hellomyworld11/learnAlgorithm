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


