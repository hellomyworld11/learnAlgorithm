#pragma once
#include <vector>
using namespace std;

class ArrayBinaryTree {
	
public:
	ArrayBinaryTree(vector<int> arr) {
		tree = arr;
	}
	int Size() { return tree.size(); }
	int Val(int i) 
	{
		if (i < 0 || i > tree.size())
		{
			return INT_MAX;
		}
		return tree[i];
	}
	int Left(int i)
	{
		return 2 * i + 1;
	}
	int Right(int i)
	{
		return 2 * i + 2;
	}
	int Parent(int i)
	{
		return (i - 1) / 2;
	}
	//层序
	vector<int> LevelOrder()
	{
		vector<int> res;
		for (int i = 0; i < Size(); i++)
		{
			if (Val(i) != INT_MAX)
			{
				res.push_back(Val(i));
			}
		}
		return res;
	}

	vector<int> PreOrder()
	{
		vector<int> res;
		dfs(0, "pre", res);
		return res;
	}
private:
	/* 深度优先遍历 */
	void dfs(int i, string order, vector<int> &res) {
		// 若为空位，则返回
		if (Val(i) == INT_MAX)
			return;
		// 前序遍历
		if (order == "pre")
			res.push_back(Val(i));
		dfs(Left(i), order, res);
		// 中序遍历
		if (order == "in")
			res.push_back(Val(i));
		dfs(Right(i), order, res);
		// 后序遍历
		if (order == "post")
			res.push_back(Val(i));
	}
	vector<int> tree;
};