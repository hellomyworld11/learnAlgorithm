#pragma once

//ƽ�������  �����������������߶Ȳ�<=1  
//bf = �������߶� - �������߶�
//bfΪ�� ����
//bfΪ�� ����

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

