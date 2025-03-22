#include "build_tree.h"

TreeNode* dfs(vector<int>& preOrder, unordered_map<int, int>& inOrderMap, int root, int l, int r)
{
	if (r < l) //注意这里r==l是 叶节点的情况。
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
	//算法： 1. 前序遍历得到树的根节点和两个子树根节点。
	//	   2.  根节点在中序遍历里可以确定此根节点的左子树区间和右子树区间
	//	   3.  子树根节点 继续此流程
	//		4. 当子树区间<0，退出构建。最终得到整个树
	// 时间复杂度O(n) 控件O（n）

	//构建 节点的中序索引
	unordered_map<int, int > inOrderMap;
	for (int i = 0; i < inOrder.size(); i++)
	{
		inOrderMap[inOrder[i]] = i;
	}

	//前序遍历，  索引表   根节点在前序的索引   此根节点为代表的树的区间。
	TreeNode *tree = dfs(preOrder, inOrderMap, 0, 0, inOrder.size()-1);
	return tree;
}

void test_buildtree()
{
	vector<int> preorder = { 3, 9, 2, 1, 7 };
	vector<int> inorder = { 9, 3, 1, 2, 7 };
	cout << "前序遍历 = ";
	printVector(preorder);
	cout << "中序遍历 = ";
	printVector(inorder);

	TreeNode *root = buildTree(preorder, inorder);
	cout << "构建的二叉树为：\n";
	printTree(root);
}
