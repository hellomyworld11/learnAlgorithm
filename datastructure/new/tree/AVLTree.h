#pragma once

#include "../util.h"
#include "binary_tree.h"


class AVLTree
{
public:
	AVLTree();

	~AVLTree();

	static void test();

public:
	int height(TreeNode *node);

	int balanceFactor(TreeNode *node);
	
	void insert(int val);

	void remove(int val);

	TreeNode* search(int val);
	
	TreeNode* root();
private:
	void updateHeight(TreeNode* node);
	//Ðý×ª ÖØµãÕÆÎÕ
	TreeNode* rotate(TreeNode *node);

	TreeNode* rightRotate(TreeNode *node);

	TreeNode* leftRotate(TreeNode *node);

	TreeNode* insertHelper(TreeNode* node, int val);

	TreeNode* removeHelper(TreeNode* node, int val);
private:
	TreeNode *root_;


};

