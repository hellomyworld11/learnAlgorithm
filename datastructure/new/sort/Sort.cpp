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

		//���������ұ�С���������������еݹ顣�ݹ������С��
		if (pivot - left < right - pivot)
		{
			quickSort_tail(nums, left, pivot - 1);
			left = pivot + 1;  //ʣ������� �����ǵݹ����
		}
		else {
			quickSort_tail(nums, pivot + 1, right);
			right = pivot - 1; //ʣ������� �����ǵݹ����
		}

	}
}

void CSort::mergeSort(vector<int>& nums, int left, int right)
{
	//1.���: ���ϵĴ��м������飬ֱ��ÿ��������ĸ���Ϊ1
	//2.�ϲ�: ������ϲ��׶ε���˳��
	//ʱ�临�Ӷ�O(nlog(n)) �ռ临�Ӷ�O(n)

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
	//1. �Ƚ������ѡ�
	//2. ����n-1�֣������Ѷ��Ͷѵ�(����������������Ϊ�����������)����ƽ�ⱻ�ƻ��������ӶѶ����¶ѻ���
	// ʱ�临�Ӷ�O(nlogn) �ռ�O(1)
	//����
	for (int i = nums.size() / 2 - 1; i >= 0; i--)
	{
		siftDown(nums, nums.size(), i);
	}
	//�Ӷ�����ȡ���Ԫ�أ�ѭ��n-1��
	for (int i = nums.size()-1; i > 0; i--)
	{
		//�������Ԫ�غͶѵף�δ���������1
		swap(nums[0], nums[i]);
		//�����ѻ�
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
	//1. ����Χ�ֳ�n��Ͱ
	//2. ĳ����Χ��������ĳ��Ͱ
	//3. ÿ��Ͱ����������
	//4. ����ͨ���ֺ���������ź��������
	//ʱ�临�Ӷ�O(n+k) �ؼ�O(n+k)

	int k = nums.size() / 2; //�ֳ� k��Ͱ
	vector<vector<float>> buckets(k);

	for (float num : nums)
	{
		int i = num * k;  //����Χ����ĳ��Ͱ
		buckets[i].push_back(num);
	}

	for (auto& bucket : buckets)
	{//ÿ��Ͱ��������
		std::sort(bucket.begin(), bucket.end());
	}

	//�ϲ�Ͱ
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
	//1. ��ȡ���������
	//2. ��0�������������Ϊ�����±ֵ꣬ �洢��Щ���ֵĴ��� 
	//3. �����������η���nums
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

	//��Ҫ���� �����Ƕ����������޷�����ͬ��ֵ�ö�����Щ��ǰ�ͺ�����Ҫ����ԭ��������

}

