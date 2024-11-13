#include "AVLTree.h"



AVLTree::AVLTree()
{
}


AVLTree::~AVLTree()
{
}

int AVLTree::height(TreeNode *node)
{
	if (node == nullptr) return 0;

	return max(height(node->left), height(node->right)) + 1;
}

int AVLTree::balanceFactor(TreeNode *node)
{
	if (node == nullptr) return 0;
	return height(node->left) - height(node->right);
}

void AVLTree::insert(int val)
{

}

void AVLTree::remove(int val)
{

}

TreeNode* AVLTree::search(int val)
{

}


TreeNode* AVLTree::rightRotate(TreeNode *node)
{




}

TreeNode* AVLTree::leftRotate(TreeNode *node)
{
	


}