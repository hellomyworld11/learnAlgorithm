#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree():root_(nullptr)
{
}

BinarySearchTree::~BinarySearchTree()
{
	freeTree(root_);
}

TreeNode * BinarySearchTree::Root()
{
	return root_;
}

TreeNode *BinarySearchTree::search(int num)
{
	TreeNode *cur = root_;
	while (cur != nullptr)
	{
		if (cur->val < num)
		{
			cur = cur->right;
		}
		else if (cur->val > num)
		{
			cur = cur->left;
		}else if (cur->val == num)
		{
			return cur;
		}
	}
	return nullptr;
}

void BinarySearchTree::insert(int num)
{
	TreeNode *cur = root_;
	if (cur == nullptr)
	{
		root_ = new TreeNode(num);
		return;
	}

	TreeNode *pre = nullptr;
	while (cur != nullptr)
	{
		pre = cur;
		if (cur->val < num)
		{		
			cur = cur->right;
		}
		else if (cur->val > num)
		{
			cur = cur->left;
		}
		else if (cur->val == num)
		{
			return;
		}
	}

	if (pre->val > num)
	{
		pre->left = new TreeNode(num);
	}
	else {
		pre->right = new TreeNode(num);
	}
	
}

void BinarySearchTree::remove(int num)
{
	if (root_ == nullptr)
	{
		return;
	}

	TreeNode *cur = root_;
	TreeNode *pre = nullptr;
	while (cur != nullptr)
	{	
		if (cur->val > num)
		{
			pre = cur;
			cur = cur->left;
		}
		else if (cur->val < num)
		{
			pre = cur;
			cur = cur->right;
		}
		else   //找到
		{
			break;
		}
		
	}

	if (cur == nullptr) return;

	//0节点 1节点 情况
	if (cur->left == nullptr || cur->right == nullptr)
	{
		TreeNode *child = cur->left != nullptr ? cur->left : cur->right;
		if (cur != root_)
		{
			if (pre->left == cur)
			{
				pre->left = child;
			}
			else {
				pre->right = child;
			}
		}
		else {
			root_ = child;
		}
		delete cur;
	}
	else {
		//两个节点
		//用左子树最大节点来替代 要删除的节点 保持 左子树 < 根节点 < 右子树 
		TreeNode *tmp = cur->left;
		while (tmp->right != nullptr) //遍历到左子树最大节点
		{
			tmp = tmp->right;
		}
		int tmpval = tmp->val;
		remove(tmpval);
		cur->val = tmpval;
	}
}

void BinarySearchTree::test()
{
	/* 初始化二叉搜索树 */
	BinarySearchTree *bst = new BinarySearchTree();
	// 请注意，不同的插入顺序会生成不同的二叉树，该序列可以生成一个完美二叉树
	vector<int> nums = { 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };
	for (int num : nums) {
		bst->insert(num);
	}
	cout << endl << "初始化的二叉树为\n" << endl;
	vector<int> res =  levelOrder(bst->Root());
	printVector(res);

	/* 查找节点 */
	TreeNode *node = bst->search(7);
	cout << endl << "查找到的节点对象为 " << node << "，节点值 = " << node->val << endl;

	/* 插入节点 */
	bst->insert(16);
	cout << endl << "插入节点 16 后，二叉树为\n" << endl;
	res = levelOrder(bst->Root());
	printVector(res);

	/* 删除节点 */
	bst->remove(1);
	cout << endl << "删除节点 1 后，二叉树为\n" << endl;
	res = levelOrder(bst->Root());
	printVector(res);
	bst->remove(2);
	cout << endl << "删除节点 2 后，二叉树为\n" << endl;
	res = levelOrder(bst->Root());
	printVector(res);
	bst->remove(4);
	cout << endl << "删除节点 4 后，二叉树为\n" << endl;
	res = levelOrder(bst->Root());
	printVector(res);

	// 释放内存
	delete bst;
}
