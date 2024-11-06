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



#endif 


