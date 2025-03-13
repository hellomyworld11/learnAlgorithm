#pragma once


#include <stdarg.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include<functional>  //解决greater编译报错
#include <unordered_map>
#include <unordered_set>
#include <time.h>

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

//生成随机数组 
inline void generateNums(int n, vector<int>& nums)
{
	

	//1.随机生成法
//	unsigned int range = 100;
// 	srand(time(0));
// 	for (int i = 0; i < n; i++)
// 	{
// 		nums.push_back(rand() % range);
// 	}

	//2. 乱序法
	for (int i = 0; i < n; i++)
	{
		nums.push_back(i);
	}
	std::random_shuffle(nums.begin(), nums.end());
}

inline int getBit(int num) {
	num = abs(num);
	int count = 0;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return count;
}

//获取一个数的第多少位 k[1,∞）
inline int getK(int num, int k)
{
	return (int)(num / pow(10, k - 1)) % 10;
}