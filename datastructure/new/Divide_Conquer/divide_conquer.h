#pragma once
#include "../util.h"
#include "../tree/binary_tree.h"

//1.分治法 查找
int dfs(vector<int>& nums, int target, int i, int j);

int binarySearch(vector<int>& nums, int target);


//2.分治法 构建二叉树
TreeNode* dfs(vector<int>& preOrder, unordered_map<int, int>& inOrderMap, int root, int l, int r);

//基于 前序遍历和中序遍历构建二叉树  
TreeNode *buildTree(vector<int>& preOrder, vector<int>& inOrder);

//3.分治法 汉诺塔
void hanota(vector<int>& A, vector<int>& B, vector<int>& C);
//汉诺塔核心算法
void dfs(int n, vector<int>& src, vector<int>& buf, vector<int>& tar);
//移动一个圆盘
void move(vector<int>& src, vector<int>& tar);



void test_buildtree();

void test_divide_conquer();

void test_hanota();