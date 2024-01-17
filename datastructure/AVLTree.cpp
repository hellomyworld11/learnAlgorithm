#include "AVLTree.h"



AVLTree::AVLTree()
{
}


AVLTree::~AVLTree()
{
}

//右旋步骤
//1.将它的左孩子结点定义为L，
//2.将L的右子树变成bst的左子树，
//3.再将bst改成L的右子树
//4.最后将L替换bst成为根结点。
void AVLTree::R_Rotate(Node * &bst)
{
	if (bst == nullptr)
	{
		return;
	}
	Node *L = bst->left;
	bst->left = L->right;
	L->right = bst;
	bst = L;
}

void AVLTree::L_Rotate(Node* &bst)
{
	if (bst == nullptr)
	{
		return;
	}
	Node *R  = bst->right;
	bst->right = R->left;
	R->left = bst;
	bst = R;
}
