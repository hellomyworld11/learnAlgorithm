#include "preorder_traversal_compact.h"

void preOrder_1(TreeNode *root, int x, vector<TreeNode*>& res)
{
	if (root  == nullptr)
	{
		return;
	}

	if (root->val == x)
	{
		res.push_back(root);
	}
	preOrder_1(root->left, x, res);
	preOrder_1(root->right, x, res);
}

void preOrder_2(TreeNode *root, int x, vector<TreeNode*>& path, vector<vector<TreeNode*>>& res)
{
	if (root == nullptr)
	{
		return;
	}

	path.push_back(root);
	if (root->val == x)
	{
		res.push_back(path);
	}
	preOrder_2(root->left, x, path, res);

	preOrder_2(root->right, x, path, res);
	
	//回退
	path.pop_back();
}

void preOrder_3(TreeNode *root, int x, int exclude, vector<TreeNode*>& path, vector<vector<TreeNode*>>& res)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->val == exclude) //剪枝，剪路径，提前返回。
	{
		return;
	}
	path.push_back(root);
	if (x == root->val)
	{
		res.push_back(path);
	}
	preOrder_3(root->left, x, exclude, path, res);

	preOrder_3(root->right, x, exclude, path, res);
	path.pop_back();
}

bool isSolution(vector<TreeNode*>& state, int x)
{
	return !state.empty() && state.back()->val == x;
}

void recordSolution(vector<TreeNode*>& state, vector<vector<TreeNode*>>& res)
{
	res.push_back(state);
}

bool isValid(vector<TreeNode*>& state, TreeNode* choice, int exclude)
{
	return choice != nullptr && choice->val != exclude;
}

void makeChoice(vector<TreeNode*>& state, TreeNode* choice)
{
	state.push_back(choice);
}

void undoChoice(vector<TreeNode*>& state, TreeNode* choice)
{
	state.pop_back();
}

void backtrack_template(vector<TreeNode*>& state, int x, int exclude, vector<TreeNode*>& choices, vector<vector<TreeNode*>>& res)
{
	if (isSolution(state, x)) //如果有解
	{   //记录解
		recordSolution(state, res);
	}

	for (TreeNode* choice : choices)  //遍历所有选择路径
	{
		if (isValid(state, choice, exclude)) //过滤无效选择路径
		{
			makeChoice(state, choice);  //选择这条路径
			vector<TreeNode*> nextchoices{choice->left, choice->right}; //获取这条路径的子路径
			backtrack_template(state, x, exclude, nextchoices, res);// 继续回溯
			undoChoice(state, choice);  //回退这条路径
		}
	}
}







void testPreOrder_traversal_compact()
{
	TreeNode *root = vectorToTree(vector<int>{1, 7, 3, 4, 5, 6, 7});
	cout << "\n初始化二叉树" << endl;
	printTree(root);

	// 前序遍历
	//vector<TreeNode*> res;
	//preOrder_1(root, 7, res);
	//vector<TreeNode*> path;
	//vector<vector<TreeNode*>> paths;
	//preOrder_3(root, 7, 3, path, paths);

	// 回溯算法
	vector<TreeNode *> state;
	vector<TreeNode *> choices = { root };
	vector<vector<TreeNode *>> res;
	//backtrack(state, choices, res);
	backtrack_template(state, 7, 3, choices, res);
	//cout << "\n输出所有值为 7 的节点" << endl;
	//vector<int> vals;
	//for (TreeNode *node : res) {
	//	vals.push_back(node->val);
	//}
	cout << "\n输出所有根节点到节点 7 的路径" << endl;
	for (vector<TreeNode *> &path : res) {
		vector<int> vals;
		for (TreeNode *node : path) {
			vals.push_back(node->val);
		}
		printVector(vals);
	}

	//printVector(vals);
}
