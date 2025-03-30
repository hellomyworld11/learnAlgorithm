#pragma once

#include "../util.h"
#include "../tree/binary_tree.h"


//1 前序遍历，给定一棵二叉树，搜索并记录所有值为x的节点，请返回节点列表。

//1.1 记录所有解 但是不知道此节点在树中的路径
void preOrder_1(TreeNode *root, int x, vector<TreeNode*>& res);

//1.2 记录所有解 同时记录到此解的路径
void preOrder_2(TreeNode *root, int x, vector<TreeNode*>& path, vector<vector<TreeNode*>>& res);

//1.3 记录所有解 同时记录到此解的路径,并要求路径里不包含某个数exclude
void preOrder_3(TreeNode *root, int x, int exclude, vector<TreeNode*>& path, vector<vector<TreeNode*>>& res);



//回溯法框架 template

bool isSolution(vector<TreeNode*>& state, int x);

void recordSolution(vector<TreeNode*>& state, vector<vector<TreeNode*>>& res);

bool isValid(vector<TreeNode*>& state, TreeNode* choice, int exclude);

void makeChoice(vector<TreeNode*>& state, TreeNode* choice);

void undoChoice(vector<TreeNode*>& state, TreeNode* choice);

void backtrack_template(vector<TreeNode*>& state, int x, int exclude, vector<TreeNode*>& choices, vector<vector<TreeNode*>>& res);









void testPreOrder_traversal_compact();