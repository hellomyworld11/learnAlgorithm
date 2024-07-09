#pragma once

//平衡二叉树  所有树的左右子树高度差<=1  
//bf = 左子树高度 - 右子树高度
//bf为正(左子树高于右子树) 右旋
//bf为负(右子树高于左子树) 左旋
//对最小不平衡子树进行左旋或者右旋


typedef struct Node {
	int data;
	int bf;
	Node* left = nullptr;
	Node* right = nullptr;
};

//平衡二叉树
class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	void R_Rotate(Node *& bst);
	void L_Rotate(Node* &bst);

};

