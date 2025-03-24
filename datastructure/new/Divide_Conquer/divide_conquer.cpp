#include "divide_conquer.h"


//基于分治法 的二分法
//O(logn)

int dfs(vector<int>& nums, int target, int i, int j)
{
	if (i > j)
	{
		return -1;
	}
	int mid = (i + j) / 2;
	if (nums[mid] < target)
	{
		return dfs(nums, target, mid + 1, j);
	}
	else if (nums[mid] > target)
	{
		return dfs(nums, target, i, mid - 1);
	}
	else {
		return mid;
	}
}

void dfs(int n, vector<int>& src, vector<int>& buf, vector<int>& tar)
{
	//1.移动n-1个盘子放buf
	//2.把最底下的盘子放入tar
	//3.转换为 buf的n-1个盘子移到 tar的子问题
	//4.完成所有移动
	//时间复杂度 O（2的n次）控件O（n）
	if (n == 1)
	{
		move(src, tar);
		return;
	}
	dfs(n-1, src, tar, buf);
	move(src, tar);
	dfs(n-1, buf, src, tar);
}

void move(vector<int>& src, vector<int>& tar)
{
	int pan = src.back();
	src.pop_back();
	tar.push_back(pan);
}

int binarySearch(vector<int>& nums, int target)
{
	int n = nums.size();
	//cout << target << " 位置： " << dfs(nums, target, 0, n-1);
	return dfs(nums, target, 0, n-1);
}

void test_divide_conquer()
{
	vector<int> nums = { 1, 3, 6, 8, 12, 15, 23, 26, 31, 35 };
	printVector(nums);
	// 二分查找（双闭区间）
	
	for (auto num : nums)
	{
		int index = binarySearch(nums, num);
		cout << "目标元素 " << num <<" 的索引 = " << index << endl;
	}
	
}

void test_hanota()
{
	// 列表尾部是柱子顶部
	vector<int> A = { 5, 4, 3, 2, 1 };
	vector<int> B = {};
	vector<int> C = {};

	cout << "初始状态下：\n";
	cout << "A =";
	printVector(A);
	cout << "B =";
	printVector(B);
	cout << "C =";
	printVector(C);

	hanota(A, B, C);

	cout << "圆盘移动完成后：\n";
	cout << "A =";
	printVector(A);
	cout << "B =";
	printVector(B);
	cout << "C =";
	printVector(C);
}

TreeNode* dfs(vector<int>& preOrder, unordered_map<int, int>& inOrderMap, int root, int l, int r)
{
	if (r < l) //注意这里r==l是 叶节点的情况。
	{
		return nullptr;
	}
	int rootval = preOrder[root];
	int rootOrder = inOrderMap[rootval];
	TreeNode *node = new TreeNode(rootval);
	node->left = dfs(preOrder, inOrderMap, root + 1, l, rootOrder - 1);
	node->right = dfs(preOrder, inOrderMap, root + 1 + (rootOrder - l), rootOrder + 1, r);
	return node;
}

TreeNode * buildTree(vector<int>& preOrder, vector<int>& inOrder)
{
	//算法： 1. 前序遍历得到树的根节点和两个子树根节点。
	//	   2.  根节点在中序遍历里可以确定此根节点的左子树区间和右子树区间
	//	   3.  子树根节点 继续此流程
	//		4. 当子树区间<0，退出构建。最终得到整个树
	// 时间复杂度O(n) 控件O（n）

	//构建 节点的中序索引
	unordered_map<int, int > inOrderMap;
	for (int i = 0; i < inOrder.size(); i++)
	{
		inOrderMap[inOrder[i]] = i;
	}

	//前序遍历，  索引表   根节点在前序的索引   此根节点为代表的树的区间。
	TreeNode *tree = dfs(preOrder, inOrderMap, 0, 0, inOrder.size() - 1);
	return tree;
}

void hanota(vector<int>& A, vector<int>& B, vector<int>& C)
{
	//从A n个圆盘 移到C
	int n = A.size();
	dfs(n, A, B, C);
}

void test_buildtree()
{
	vector<int> preorder = { 3, 9, 2, 1, 7 };
	vector<int> inorder = { 9, 3, 1, 2, 7 };
	cout << "前序遍历 = ";
	printVector(preorder);
	cout << "中序遍历 = ";
	printVector(inorder);

	TreeNode *root = buildTree(preorder, inorder);
	cout << "构建的二叉树为：\n";
	printTree(root);
}
