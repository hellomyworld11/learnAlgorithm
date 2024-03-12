#pragma once
#include <iostream>
#include <vector>
using namespace std;

/* 二叉树节点结构体 */
typedef struct TreeNode {
	int val;          // 节点值
	TreeNode *left;   // 左子节点指针
	TreeNode *right;  // 右子节点指针
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//层序遍历 广度优先遍历
vector<int> levelOrder(TreeNode *root);

//前序遍历  深度优先遍历
void PreOrder(TreeNode *root);

//中序遍历
void InOrder(TreeNode *root);

//后序
void PostOrder(TreeNode *root);