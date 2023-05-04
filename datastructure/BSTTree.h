#pragma once
#include <iostream>
typedef int ElemType;
typedef struct Node {
	ElemType data;
	Node *left = nullptr;
	Node *right = nullptr;
};


class CBSTTree
{
public:
	CBSTTree();
	~CBSTTree();
	Node* Insert(ElemType elem, Node* &bst);
	Node* Delete(ElemType elem, Node* &bst);
	Node* Find(ElemType elem,Node* &bst);
	Node* Max(Node* &bst);
	Node* Min(Node* &bst);
	void in_order(Node* &bst);
private:
	Node *root;
};

