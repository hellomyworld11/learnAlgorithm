#pragma once
#include "../util.h"
#include "../tree/binary_tree.h"

//1.���η� ����
int dfs(vector<int>& nums, int target, int i, int j);

int binarySearch(vector<int>& nums, int target);


//2.���η� ����������
TreeNode* dfs(vector<int>& preOrder, unordered_map<int, int>& inOrderMap, int root, int l, int r);

//���� ǰ������������������������  
TreeNode *buildTree(vector<int>& preOrder, vector<int>& inOrder);

//3.���η� ��ŵ��
void hanota(vector<int>& A, vector<int>& B, vector<int>& C);
//��ŵ�������㷨
void dfs(int n, vector<int>& src, vector<int>& buf, vector<int>& tar);
//�ƶ�һ��Բ��
void move(vector<int>& src, vector<int>& tar);



void test_buildtree();

void test_divide_conquer();

void test_hanota();