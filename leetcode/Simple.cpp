#include "Simple.h"



Simple::Simple()
{
}


Simple::~Simple()
{
}

//����һ������������ nums �� ��������������� 1 �ĸ�����
//nums = [1,1,0,1,1,1] 3
int Simple::findMaxConsecutiveOnes(vector<int>& nums)
{
	int len = nums.size();
	if (len <= 0 || len >= pow(10, 5))
	{
		return -1;
	}
	//��1����
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
			val = 0;  //���¼���
		}
	}
	return max(ans, val);
}

void Simple::moveZeroes(vector<int>& nums)
{
	//�㷨����ֱ�Ӱѷ����Ԫ�ذ�ԭ��˳�����ηſ�ͷ��
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

// ����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�
// ��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
// Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
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

// ���룺head = [1, 2, 3, 4, 5], n = 2
// �����[1, 2, 3, 5]
ListNode* Simple::removeNthFromEnd(ListNode* head, int n)
{	
	//����ָ�� �Ȱѿ�ָ��ƫ��n���� ��ͬ��ƫ�ƣ�ָ����ָ��ָ��գ���ʱ��������β������ָ�����һ������Ŀ��ɾ���ڵ�
	ListNode* dummy = new ListNode(0, head);
	ListNode* first = head;
	ListNode* second = dummy;
	for (int i = 0; i < n; ++i) {
		first = first->next;
	}
	while (first) {
		first = first->next;
		second = second->next;
	}
	second->next = second->next->next;
	ListNode* ans = dummy->next;
	delete dummy;
	return ans;
}

//���룺head = [1,2,3,4]
//�����[2, 1, 4, 3]
ListNode* Simple::swapPairs(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)return head;

	// ��һ���ڵ��next ָ�� �ڶ����ڵ��next
	// �ڶ����ڵ��next ָ���һ���ڵ� 
	// ��һ���ڵ�ָ��next
	ListNode* newHead = head->next;
	head->next = swapPairs(newHead->next); //�Ӻ���ǰ����
	newHead->next = head;
	return newHead;
}
