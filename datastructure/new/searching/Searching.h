#pragma once

#include "../util.h"

//�����㷨
class CSearching
{
public:
	CSearching();

	~CSearching();

	//���ַ� ����˫�������е�һ������λ��
	int binarySearch(vector<int>& nums, int target);

	//���ַ� ���������뵽�����е�����
	int binarySearchInsertion(vector<int>& nums, int target);

	//���ַ� �ظ�Ԫ�� ���������뵽�����е�����
	int binarySearchInsertionRepeat(vector<int>& nums, int target);

	//����һ���������� nums ��һ��Ŀ��Ԫ�� target �������������������͡�Ϊ target ������Ԫ�أ����������ǵ�������������������һ���⼴�ɡ�
	vector<int> getAddEleForTarget(vector<int>& nums, int target);

	static void test();
};

