#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include "../util.h"



/* 释放二叉树内存 */
void freeTree(TreeNode *root);


//层序遍历
vector<int> levelOrder(TreeNode *root);
//前序
void preOrder(TreeNode *root);

vector<int> preOrderIterative(TreeNode *root);

//中序
void inOrder(TreeNode *root);
//后序
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


