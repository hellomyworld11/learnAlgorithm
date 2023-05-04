#include "AVLTree.h"



AVLTree::AVLTree()
{
}


AVLTree::~AVLTree()
{
}

//��������
//1.���������ӽ�㶨��ΪL��
//2.��L�����������bst����������
//3.�ٽ�bst�ĳ�L��������
//4.���L�滻bst��Ϊ����㡣
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
