#pragma once
#include "../util.h"
#include "binary_tree.h"

class BinarySearchTree
{
public:
	BinarySearchTree();

	~BinarySearchTree();

	TreeNode *Root();

	TreeNode *search(int num);

	void insert(int num);

	void remove(int num);

	static void test();
private:
	TreeNode *root_;

};

