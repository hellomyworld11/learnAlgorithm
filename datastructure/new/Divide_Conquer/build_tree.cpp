#include "build_tree.h"

TreeNode* dfs(vector<int>& preOrder, unordered_map<int, int>& inOrderMap, int root, int l, int r)
{

}

TreeNode * buildTree(vector<int>& preOrder, vector<int>& inOrder)
{
	//�㷨�� 1. ǰ������õ����ĸ��ڵ�������������ڵ㡣
	//	   2.  ���ڵ���������������ȷ���˸��ڵ�����������������������
	//	   3.  �������ڵ� ����������
	//		4. ����������<0���˳����������յõ�������

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
