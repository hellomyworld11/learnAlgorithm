#include "binary_tree.h"


vector<int> levelOrder(TreeNode *root)
{
	vector<int> vec;
	queue<TreeNode*> queue;
	queue.push(root);

	while (root != nullptr)
	{
		TreeNode *node = queue.front();
		queue.pop();
		vec.push_back(node->val);
		if (node->left != nullptr)
			queue.push(node->left);
		if (node->right != nullptr)
			queue.push(node->right);
	}
	return vec;
}