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
	cout << "\n插入节点 " << val << " 后，AVL 树为" << endl;
	printTree(tree.root());
}

void testRemove(AVLTree &tree, int val) {
	tree.remove(val);
	cout << "\n删除节点 " << val << " 后，AVL 树为" << endl;
	printTree(tree.root());
}

void AVLTree::test()
{
	AVLTree avlTree;

	/* 插入节点 */
	// 请关注插入节点后，AVL 树是如何保持平衡的
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

	/* 插入重复节点 */
	testInsert(avlTree, 7);

	/* 删除节点 */
	// 请关注删除节点后，AVL 树是如何保持平衡的
	testRemove(avlTree, 8); // 删除度为 0 的节点
	testRemove(avlTree, 5); // 删除度为 1 的节点
	testRemove(avlTree, 4); // 删除度为 2 的节点

							/* 查询节点 */
	TreeNode *node = avlTree.search(7);
	cout << "\n查找到的节点对象为 " << node << "，节点值 = " << node->val << endl;
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
			//两个子节点的情况  取左子树最大值 覆盖当前node 或者取右子树最小值 
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
	//获取node 平衡因子
	int factor = balanceFactor(node);
	if (factor > 1)       //左子树比右子树高，要右旋
	{
		int child_factor = balanceFactor(node->left);
		//左子树平衡因子:如果<0，则要先左旋
		if (child_factor >= 0)
		{
			return rightRotate(node);
		}
		else {
			//先左旋，后右旋
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
	}
	else if (factor < -1) //右子树比左子树高，要左旋
	{
		int child_factor = balanceFactor(node->right);
		//左子树平衡因子:如果<0，则要先左旋
		if (child_factor <= 0)
		{
			return leftRotate(node);
		}
		else {
			//先右旋，后左旋
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
	}
	return node;
}