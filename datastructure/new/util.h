#pragma once


#include <stdarg.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include<functional>  //���greater���뱨��
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;

//*****���Ͷ���*****
//�������ڵ�
struct TreeNode {
	int val;
	int height = 0;
	TreeNode *parent = nullptr;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
	TreeNode() = default;
	explicit TreeNode(int x, TreeNode *parent = nullptr) :val(x), parent(parent) {}
};

//*****��������*****
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

//����������� 
inline void generateNums(int n, vector<int>& nums)
{
	unsigned int range = 100; 
	srand(time(0));

	for (int i = 0; i < n; i++)
	{
		nums.push_back(rand() % range);
	}
}
