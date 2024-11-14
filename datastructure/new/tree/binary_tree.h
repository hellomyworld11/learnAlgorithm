#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include "../util.h"



/* �ͷŶ������ڴ� */
void freeTree(TreeNode *root);


//�������
vector<int> levelOrder(TreeNode *root);
//ǰ��
void preOrder(TreeNode *root);

vector<int> preOrderIterative(TreeNode *root);

//����
void inOrder(TreeNode *root);
//����
void postOrder(TreeNode *root);


extern void test1();


/**
* This tree printer is borrowed from TECHIE DELIGHT
* https://www.techiedelight.com/c-program-print-binary-tree/
*/
struct Trunk {
	Trunk *prev;
	string str;
	Trunk(Trunk *prev, string str) {
		this->prev = prev;
		this->str = str;
	}
};

/* Helper function to print branches of the binary tree */
void showTrunks(Trunk *p);

void printTree(TreeNode *root, Trunk *prev, bool isRight);

void printTree(TreeNode *root);



#endif 


