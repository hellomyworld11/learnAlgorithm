#pragma once
#include <iostream>
#include <vector>
using namespace std;

/* �������ڵ�ṹ�� */
typedef struct TreeNode {
	int val;          // �ڵ�ֵ
	TreeNode *left;   // ���ӽڵ�ָ��
	TreeNode *right;  // ���ӽڵ�ָ��
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//������� ������ȱ���
vector<int> levelOrder(TreeNode *root);

//ǰ�����  ������ȱ���
void PreOrder(TreeNode *root);

//�������
void InOrder(TreeNode *root);

//����
void PostOrder(TreeNode *root);