#pragma once


#include "../util.h"



TreeNode* dfs(vector<int>& preOrder, unordered_map<int, int>& inOrderMap, int root, int l, int r);


//���� ǰ������������������������  
TreeNode *buildTree(vector<int>& preOrder, vector<int>& inOrder);
