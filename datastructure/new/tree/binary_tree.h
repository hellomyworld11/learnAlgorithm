#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include "../util.h"


//二叉树节点
struct TreeNode {
	int val;
	int height;
	TreeNode *parent = nullptr;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
	TreeNode() = default;
	explicit TreeNode(int x, TreeNode *parent = nullptr) :val(x), parent(parent) {}
};


//层序遍历
vector<int> levelOrder(TreeNode *root);




#endif =


