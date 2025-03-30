#pragma once

#include "../util.h"
#include "../tree/binary_tree.h"


//1 ǰ�����������һ�ö���������������¼����ֵΪx�Ľڵ㣬�뷵�ؽڵ��б�

//1.1 ��¼���н� ���ǲ�֪���˽ڵ������е�·��
void preOrder_1(TreeNode *root, int x, vector<TreeNode*>& res);

//1.2 ��¼���н� ͬʱ��¼���˽��·��
void preOrder_2(TreeNode *root, int x, vector<TreeNode*>& path, vector<vector<TreeNode*>>& res);

//1.3 ��¼���н� ͬʱ��¼���˽��·��,��Ҫ��·���ﲻ����ĳ����exclude
void preOrder_3(TreeNode *root, int x, int exclude, vector<TreeNode*>& path, vector<vector<TreeNode*>>& res);



//���ݷ���� template

bool isSolution(vector<TreeNode*>& state, int x);

void recordSolution(vector<TreeNode*>& state, vector<vector<TreeNode*>>& res);

bool isValid(vector<TreeNode*>& state, TreeNode* choice, int exclude);

void makeChoice(vector<TreeNode*>& state, TreeNode* choice);

void undoChoice(vector<TreeNode*>& state, TreeNode* choice);

void backtrack_template(vector<TreeNode*>& state, int x, int exclude, vector<TreeNode*>& choices, vector<vector<TreeNode*>>& res);









void testPreOrder_traversal_compact();