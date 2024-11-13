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
		else   //�ҵ�
		{
			break;
		}
		
	}

	if (cur == nullptr) return;

	//0�ڵ� 1�ڵ� ���
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
		//�����ڵ�
		//�����������ڵ������ Ҫɾ���Ľڵ� ���� ������ < ���ڵ� < ������ 
		TreeNode *tmp = cur->left;
		while (tmp->right != nullptr) //���������������ڵ�
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
	/* ��ʼ������������ */
	BinarySearchTree *bst = new BinarySearchTree();
	// ��ע�⣬��ͬ�Ĳ���˳������ɲ�ͬ�Ķ������������п�������һ������������
	vector<int> nums = { 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };
	for (int num : nums) {
		bst->insert(num);
	}
	cout << endl << "��ʼ���Ķ�����Ϊ\n" << endl;
	vector<int> res =  levelOrder(bst->Root());
	printVector(res);

	/* ���ҽڵ� */
	TreeNode *node = bst->search(7);
	cout << endl << "���ҵ��Ľڵ����Ϊ " << node << "���ڵ�ֵ = " << node->val << endl;

	/* ����ڵ� */
	bst->insert(16);
	cout << endl << "����ڵ� 16 �󣬶�����Ϊ\n" << endl;
	res = levelOrder(bst->Root());
	printVector(res);

	/* ɾ���ڵ� */
	bst->remove(1);
	cout << endl << "ɾ���ڵ� 1 �󣬶�����Ϊ\n" << endl;
	res = levelOrder(bst->Root());
	printVector(res);
	bst->remove(2);
	cout << endl << "ɾ���ڵ� 2 �󣬶�����Ϊ\n" << endl;
	res = levelOrder(bst->Root());
	printVector(res);
	bst->remove(4);
	cout << endl << "ɾ���ڵ� 4 �󣬶�����Ϊ\n" << endl;
	res = levelOrder(bst->Root());
	printVector(res);

	// �ͷ��ڴ�
	delete bst;
}
