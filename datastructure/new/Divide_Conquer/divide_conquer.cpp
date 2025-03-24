#include "divide_conquer.h"


//���ڷ��η� �Ķ��ַ�
//O(logn)

int dfs(vector<int>& nums, int target, int i, int j)
{
	if (i > j)
	{
		return -1;
	}
	int mid = (i + j) / 2;
	if (nums[mid] < target)
	{
		return dfs(nums, target, mid + 1, j);
	}
	else if (nums[mid] > target)
	{
		return dfs(nums, target, i, mid - 1);
	}
	else {
		return mid;
	}
}

void dfs(int n, vector<int>& src, vector<int>& buf, vector<int>& tar)
{
	//1.�ƶ�n-1�����ӷ�buf
	//2.������µ����ӷ���tar
	//3.ת��Ϊ buf��n-1�������Ƶ� tar��������
	//4.��������ƶ�
	//ʱ�临�Ӷ� O��2��n�Σ��ؼ�O��n��
	if (n == 1)
	{
		move(src, tar);
		return;
	}
	dfs(n-1, src, tar, buf);
	move(src, tar);
	dfs(n-1, buf, src, tar);
}

void move(vector<int>& src, vector<int>& tar)
{
	int pan = src.back();
	src.pop_back();
	tar.push_back(pan);
}

int binarySearch(vector<int>& nums, int target)
{
	int n = nums.size();
	//cout << target << " λ�ã� " << dfs(nums, target, 0, n-1);
	return dfs(nums, target, 0, n-1);
}

void test_divide_conquer()
{
	vector<int> nums = { 1, 3, 6, 8, 12, 15, 23, 26, 31, 35 };
	printVector(nums);
	// ���ֲ��ң�˫�����䣩
	
	for (auto num : nums)
	{
		int index = binarySearch(nums, num);
		cout << "Ŀ��Ԫ�� " << num <<" ������ = " << index << endl;
	}
	
}

void test_hanota()
{
	// �б�β�������Ӷ���
	vector<int> A = { 5, 4, 3, 2, 1 };
	vector<int> B = {};
	vector<int> C = {};

	cout << "��ʼ״̬�£�\n";
	cout << "A =";
	printVector(A);
	cout << "B =";
	printVector(B);
	cout << "C =";
	printVector(C);

	hanota(A, B, C);

	cout << "Բ���ƶ���ɺ�\n";
	cout << "A =";
	printVector(A);
	cout << "B =";
	printVector(B);
	cout << "C =";
	printVector(C);
}

TreeNode* dfs(vector<int>& preOrder, unordered_map<int, int>& inOrderMap, int root, int l, int r)
{
	if (r < l) //ע������r==l�� Ҷ�ڵ�������
	{
		return nullptr;
	}
	int rootval = preOrder[root];
	int rootOrder = inOrderMap[rootval];
	TreeNode *node = new TreeNode(rootval);
	node->left = dfs(preOrder, inOrderMap, root + 1, l, rootOrder - 1);
	node->right = dfs(preOrder, inOrderMap, root + 1 + (rootOrder - l), rootOrder + 1, r);
	return node;
}

TreeNode * buildTree(vector<int>& preOrder, vector<int>& inOrder)
{
	//�㷨�� 1. ǰ������õ����ĸ��ڵ�������������ڵ㡣
	//	   2.  ���ڵ���������������ȷ���˸��ڵ�����������������������
	//	   3.  �������ڵ� ����������
	//		4. ����������<0���˳����������յõ�������
	// ʱ�临�Ӷ�O(n) �ؼ�O��n��

	//���� �ڵ����������
	unordered_map<int, int > inOrderMap;
	for (int i = 0; i < inOrder.size(); i++)
	{
		inOrderMap[inOrder[i]] = i;
	}

	//ǰ�������  ������   ���ڵ���ǰ�������   �˸��ڵ�Ϊ������������䡣
	TreeNode *tree = dfs(preOrder, inOrderMap, 0, 0, inOrder.size() - 1);
	return tree;
}

void hanota(vector<int>& A, vector<int>& B, vector<int>& C)
{
	//��A n��Բ�� �Ƶ�C
	int n = A.size();
	dfs(n, A, B, C);
}

void test_buildtree()
{
	vector<int> preorder = { 3, 9, 2, 1, 7 };
	vector<int> inorder = { 9, 3, 1, 2, 7 };
	cout << "ǰ����� = ";
	printVector(preorder);
	cout << "������� = ";
	printVector(inorder);

	TreeNode *root = buildTree(preorder, inorder);
	cout << "�����Ķ�����Ϊ��\n";
	printTree(root);
}
