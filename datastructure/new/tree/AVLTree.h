#pragma once

#include "../util.h"
#include "binary_tree.h"


class AVLTree
{
public:
	AVLTree();

	~AVLTree();

public:
	int height(TreeNode *node);

	int balanceFactor(TreeNode *node);
	
	void insert(int val);

	void remove(int val);

	TreeNode* search(int val);
private:
	void updateHeight(TreeNode* node);
	//Ðý×ª
	TreeNode* rotate(TreeNode *node);

	TreeNode* rightRotate(TreeNode *node);

	TreeNode* leftRotate(TreeNode *node);

	TreeNode* insertHelper(TreeNode* node, int val);

	TreeNode* removeHelper(TreeNode* node, int val);
private:
	TreeNode *root_;


};

