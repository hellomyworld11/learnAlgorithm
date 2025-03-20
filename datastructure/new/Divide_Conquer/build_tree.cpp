#include "build_tree.h"

TreeNode* dfs(vector<int>& preOrder, unordered_map<int, int>& inOrderMap, int root, int l, int r)
{

}

TreeNode * buildTree(vector<int>& preOrder, vector<int>& inOrder)
{
	//算法： 1. 前序遍历得到树的根节点和两个子树根节点。
	//	   2.  根节点在中序遍历里可以确定此根节点的左子树区间和右子树区间
	//	   3.  子树根节点 继续此流程
	//		4. 当子树区间<0，退出构建。最终得到整个树

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
