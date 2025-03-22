#include "build_tree.h"

TreeNode* dfs(vector<int>& preOrder, unordered_map<int, int>& inOrderMap, int root, int l, int r)
{
	if (r < l) //ע������r==l�� Ҷ�ڵ�������
	{
		return nullptr;
	}
	int rootval = preOrder[root];
	int rootOrder = inOrderMap[rootval];
	TreeNode *node = new TreeNode(rootval);
	node->left = dfs(preOrder, inOrderMap, root+1, l, rootOrder-1);
	node->right = dfs(preOrder, inOrderMap, root + 1 + (rootOrder - l), rootOrder+1, r);
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
	TreeNode *tree = dfs(preOrder, inOrderMap, 0, 0, inOrder.size()-1);
	return tree;
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
