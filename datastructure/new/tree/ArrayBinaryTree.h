#pragma once
#include "../util.h"

class ArrayBinaryTree
{
public:
	ArrayBinaryTree(vector<int> input);

	~ArrayBinaryTree();

	vector<int> levelOrder();

	void preOrder(int rootindex = 0);

	void inOrder(int rootindex = 0);

	void postOrder(int rootindex = 0);

	int left(int i);

	int right(int i);

	int parent(int i);

	int val(int i);

	int size();

	static void test();
private:
	vector<int> tree_;
};

