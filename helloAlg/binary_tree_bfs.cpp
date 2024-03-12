#include "binary_tree_bfs.h"
#include <queue>

//广度优先遍历 O(n)
std::vector<int> levelOrder(TreeNode *root)
{
	queue<TreeNode*> que;
	que.push(root);

	vector<int> vec;
	while (!que.empty())
	{
		TreeNode *node = que.front();
		que.pop();
		vec.push_back(node->val);
		if (node->left != nullptr)
		{
			que.push(node->left);
		}
		if (node->right != nullptr)
		{
			que.push(node->right);
		}
	}
	return vec;
}

void PreOrder(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}
	std::cout << root->val << std::endl;
	PreOrder(root->left);
	PreOrder(root->right);	
}

void InOrder(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}
	InOrder(root->left);
	std::cout << root->val << std::endl;
	InOrder(root->right);
}

void PostOrder(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	std::cout << root->val << std::endl;
}
