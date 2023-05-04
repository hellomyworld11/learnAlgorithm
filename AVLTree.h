#pragma once

//平衡二叉树  所有树的左右子树高度差<=1  
//bf = 左子树高度 - 右子树高度
//bf为正 右旋
//bf为负 左旋

typedef struct Node {
	int data;
	int bf;
	Node* left = nullptr;
	Node* right = nullptr;
};

class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	void R_Rotate(Node *& bst);
	void L_Rotate(Node* &bst);

};

