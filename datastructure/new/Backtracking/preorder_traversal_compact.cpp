#include "preorder_traversal_compact.h"

void preOrder_1(TreeNode *root, int x, vector<TreeNode*>& res)
{
	if (root  == nullptr)
	{
		return;
	}

	if (root->val == x)
	{
		res.push_back(root);
	}
	preOrder_1(root->left, x, res);
	preOrder_1(root->right, x, res);
}

void testPreOrder_traversal_compact()
{
	TreeNode *root = vectorToTree(vector<int>{1, 7, 3, 4, 5, 6, 7});
	cout << "\n初始化二叉树" << endl;
	printTree(root);

	// 前序遍历
	preOrder(root);

	cout << "\n输出所有值为 7 的节点" << endl;
	vector<int> vals;
	for (TreeNode *node : res) {
		vals.push_back(node->val);
	}
	printVector(vals);
}
