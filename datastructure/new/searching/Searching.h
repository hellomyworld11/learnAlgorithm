#pragma once

#include "../util.h"

class CSearching
{
public:
	CSearching();

	~CSearching();

	//���ַ� ����˫�������е�һ������λ��
	int binarySearch(vector<int>& nums, int target);

	//���ַ� ���������뵽�����е�����
	int binarySearchInsertion(vector<int>& nums, int target);

	//���ַ� �ظ�Ԫ�� ��������ߵ�Ŀ������
	int binarySearchInsertionRepeat(vector<int>& nums, int target);

	static void test();
};

