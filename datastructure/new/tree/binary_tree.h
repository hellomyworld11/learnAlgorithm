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



#endif 


