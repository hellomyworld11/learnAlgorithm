#pragma once


#include "../util.h"



TreeNode* dfs(vector<int>& preOrder, unordered_map<int, int>& inOrderMap, int root, int l, int r);


//基于 前序遍历和中序遍历构建二叉树  
TreeNode *buildTree(vector<int>& preOrder, vector<int>& inOrder);
