#include "AVLTree.h"



AVLTree::AVLTree()
{
}


AVLTree::~AVLTree()
{
	freeTree(root_);
}

void testInsert(AVLTree &tree, int val) {
	tree.insert(val);
	cout << "\n����ڵ� " << val << " ��AVL ��Ϊ" << endl;
	printTree(tree.root());
}

void testRemove(AVLTree &tree, int val) {
	tree.remove(val);
	cout << "\nɾ���ڵ� " << val << " ��AVL ��Ϊ" << endl;
	printTree(tree.root());
}

void AVLTree::test()
{
	AVLTree avlTree;

	/* ����ڵ� */
	// ���ע����ڵ��AVL ������α���ƽ���
	testInsert(avlTree, 1);
	testInsert(avlTree, 2);
	testInsert(avlTree, 3);
	testInsert(avlTree, 4);
	testInsert(avlTree, 5);
	testInsert(avlTree, 8);
	testInsert(avlTree, 7);
	testInsert(avlTree, 9);
	testInsert(avlTree, 10);
	testInsert(avlTree, 6);

	/* �����ظ��ڵ� */
	testInsert(avlTree, 7);

	/* ɾ���ڵ� */
	// ���עɾ���ڵ��AVL ������α���ƽ���
	testRemove(avlTree, 8); // ɾ����Ϊ 0 �Ľڵ�
	testRemove(avlTree, 5); // ɾ����Ϊ 1 �Ľڵ�
	testRemove(avlTree, 4); // ɾ����Ϊ 2 �Ľڵ�

							/* ��ѯ�ڵ� */
	TreeNode *node = avlTree.search(7);
	cout << "\n���ҵ��Ľڵ����Ϊ " << node << "���ڵ�ֵ = " << node->val << endl;
}

int AVLTree::height(TreeNode *node)
{
	return node == nullptr ? -1 : node->height;
}

int AVLTree::balanceFactor(TreeNode *node)
{
	if (node == nullptr) return 0;
	return height(node->left) - height(node->right);
}

void AVLTree::insert(int val)
{
	root_ = insertHelper(root_, val);
}

void AVLTree::remove(int val)
{
	root_ = removeHelper(root_, val);
}

TreeNode* AVLTree::rightRotate(TreeNode *node)
{
	TreeNode *child = node->left;
	TreeNode *grandChild = child->right;

	node->left = grandChild;
	child->right = node;

	updateHeight(child);
	updateHeight(node);

	return child;
}

TreeNode* AVLTree::leftRotate(TreeNode *node)
{
	TreeNode *child = node->right;
	TreeNode *grandChild = child->left;

	node->right = grandChild;
	child->left = node;

	updateHeight(child);
	updateHeight(node);

	return child;
}

void AVLTree::updateHeight(TreeNode* node)
{
	node->height = max(height(node->left), height(node->right)) + 1;
}

TreeNode* AVLTree::insertHelper(TreeNode* node, int val)
{
	if (nullptr == node) return new TreeNode(val);

	if (node->val < val)
		node->right = insertHelper(node->right, val);
	else if (node->val > val)
		node->left = insertHelper(node->left, val);
	else 
		return node;
	
	updateHeight(node);
	node = rotate(node);
	return node;
}

TreeNode* AVLTree::removeHelper(TreeNode* node, int val)
{
	if (node == nullptr) return nullptr;
	if (node->val < val)
		node->right = removeHelper(node->right, val);
	else if (node->val > val)
		node->left  = removeHelper(node->left, val);
	else {	
		if (node->left == nullptr || node->right == nullptr)
		{
			TreeNode *child = node->left != nullptr ? node->left : node->right;
			if (child == nullptr)
			{
				delete node;
				return nullptr;
			}
			else {
				delete node;
				node = child;
			}
		}
		else {
			//�����ӽڵ�����  ȡ���������ֵ ���ǵ�ǰnode ����ȡ��������Сֵ 
			TreeNode *temp = node->right;
			while (temp->left != nullptr)
			{
				temp = temp->left;
			}

			int tempval = temp->val;
			node->val = tempval;
			node->right = removeHelper(node->right, temp->val);

		}
	}
	updateHeight(node);
	node = rotate(node);
	return node;
}

TreeNode* AVLTree::search(int val)
{
	TreeNode *cur = root_;

	while (cur != nullptr)
	{
		if (cur->val < val)
			cur = cur->right;
		else if (cur->val > val)
			cur = cur->left;
		else 
			break;
	}
	return cur;
}

TreeNode* AVLTree::root()
{
	return root_;
}

TreeNode* AVLTree::rotate(TreeNode *node)
{
	//��ȡnode ƽ������
	int factor = balanceFactor(node);
	if (factor > 1)       //���������������ߣ�Ҫ����
	{
		int child_factor = balanceFactor(node->left);
		//������ƽ������:���<0����Ҫ������
		if (child_factor >= 0)
		{
			return rightRotate(node);
		}
		else {
			//��������������
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
	}
	else if (factor < -1) //���������������ߣ�Ҫ����
	{
		int child_factor = balanceFactor(node->right);
		//������ƽ������:���<0����Ҫ������
		if (child_factor <= 0)
		{
			return leftRotate(node);
		}
		else {
			//��������������
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
	}
	return node;
}