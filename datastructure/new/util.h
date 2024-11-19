#pragma once


#include <stdarg.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include<functional>  //解决greater编译报错

using namespace std;

//*****类型定义*****
//二叉树节点
struct TreeNode {
	int val;
	int height = 0;
	TreeNode *parent = nullptr;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
	TreeNode() = default;
	explicit TreeNode(int x, TreeNode *parent = nullptr) :val(x), parent(parent) {}
};

//*****基础函数*****
template <typename T>
void printVector(vector<T> list)
{
	cout << "[";
	for (const auto &v : list )
	{
		if (&v != &list[0])
		{
			cout << ",";
		}
		cout << v;
	}
	cout << "]\n";
}

