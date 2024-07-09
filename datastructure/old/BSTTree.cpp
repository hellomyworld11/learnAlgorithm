#include "BSTTree.h"



CBSTTree::CBSTTree()
{
}


CBSTTree::~CBSTTree()
{
}

Node* CBSTTree::Insert(ElemType elem, Node*& bst)
{
	if (bst == nullptr)
	{
		bst = new Node;
		bst->data = elem;
		bst->left = nullptr;
		bst->right = nullptr;
	}
	else
	{
		if (elem < bst->data)
		{
			bst->left = Insert(elem, bst->left);
		}
		else if (elem > bst->data) 
		{
			bst->right = Insert(elem, bst->right);
		}
	}
	return bst;
}

Node* CBSTTree::Delete(ElemType elem, Node*& bst)
{
	if (bst == nullptr)
	{
		return nullptr;
	}
	Node *tmp = nullptr;
	if (elem < bst->data)
	{
		bst->left = Delete(elem, bst->left);
	}
	else if (elem > bst->data)
	{
		bst->right = Delete(elem, bst->right);
	}
	else {
		//被删除节点有两个子节点  可以取左子树中最大或者右子树中最小的替代被删除的节点作为父节点
		if (bst->left && bst->right)
		{
			tmp = Min(bst->right);
			bst->data = tmp->data;
			bst->right = Delete(tmp->data, bst->right);
		}
		else {//被删除节点 有 1或者0个子节点
			tmp = bst;
			if (!bst->left && !bst->right)
			{
				bst = nullptr;
			}
			else if (bst->left && !bst->right)
			{
				bst = bst->left;
			}
			else if (!bst->left  && bst->right)
			{
				bst = bst->right;
			}
			delete tmp;
		}
	}
	return bst;
}

Node* CBSTTree::Find(ElemType elem, Node*& bst)
{
	if (bst == nullptr)
	{
		return nullptr;
	}
	if (elem < bst->data)
	{
		return Find(elem,bst->left);
	}
	else if (elem > bst->data)
	{
		return Find(elem, bst->right);
	}
	else if (elem == bst->data)
	{
		return bst;
	}
	return nullptr;
}

Node* CBSTTree::Max(Node*& bst)
{
	if (bst == nullptr)
	{
		return nullptr;
	}
	while (bst->right)
	{
		bst = bst->right;
	}
	return bst;
}

Node* CBSTTree::Min(Node*& bst)
{
	if (bst == nullptr)
	{
		return nullptr;
	}
	while (bst->left)
	{
		bst = bst->left;
	}
	return bst;
}

void CBSTTree::in_order(Node*& bst)
{
	if (bst)
	{
		in_order(bst->left);
		std::cout << bst->data;
		in_order(bst->right);
	}
}
