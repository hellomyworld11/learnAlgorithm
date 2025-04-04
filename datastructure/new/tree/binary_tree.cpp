#include "binary_tree.h"


TreeNode * vectorToTree(vector<int> nums)
{
	return vectorToTreeDFS(nums, 0);
}

TreeNode* vectorToTreeDFS(vector<int>& nums, int index)
{
	if (index < 0 || index >= nums.size() || nums[index] == INT_MAX)
	{
		return nullptr;
	}
	TreeNode *node = new TreeNode(nums[index]);
	node->left = vectorToTreeDFS(nums, 2 * index + 1);
	node->right = vectorToTreeDFS(nums, 2 * index + 2);
	return node;
}

std::vector<int> TreeToVector(TreeNode* tree)
{
	vector<int> res;
	TreeToVectorDFS(tree, 0, res);
	return res;
}

void TreeToVectorDFS(TreeNode* tree, int index, vector<int>& res)
{
	if (nullptr ==  tree || index < 0)
	{
		return;
	}

	while (index >= res.size())
	{
		res.push_back(INT_MAX);
	}
	res[index] = tree->val;
	TreeToVectorDFS(tree->left, 2 * index + 1, res);
	TreeToVectorDFS(tree->right, 2 * index + 2, res);
}

void freeTree(TreeNode *root)
{
	if (root == nullptr)
		return;
	freeTree(root->left);
	freeTree(root->right);
	delete root;
}

vector<int> levelOrder(TreeNode *root)
{
	vector<int> vec;
	queue<TreeNode*> queue;
	queue.push(root);

	while (!queue.empty())
	{
		TreeNode *node = queue.front();
		queue.pop();
		vec.push_back(node->val);
		if (node->left != nullptr)
			queue.push(node->left);
		if (node->right != nullptr)
			queue.push(node->right);
	}
	return vec;
}

void preOrder(TreeNode *root)
{
	if (root == nullptr) return;

	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

std::vector<int> preOrderIterative(TreeNode *root)
{
	vector<int> res;
	stack<TreeNode*> stack;
	TreeNode *cur = root;
	while (cur || !stack.empty())
	{
		if (cur)
		{
			res.push_back(cur->val);
			stack.push(cur);
			cur = cur->left;
		}
		else {
			cur = stack.top();
			stack.pop();
			cur = cur->right;
		}
	}
	return res;
}

void inOrder(TreeNode *root)
{
	if (root == nullptr) return;

	inOrder(root->left);
	cout << root->val << endl;
	inOrder(root->right);
}

void postOrder(TreeNode *root)
{
	if (root == nullptr) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << endl;
}

void test1()
{
	/* 初始化二叉树 */
	// 这里借助了一个从数组直接生成二叉树的函数
	//TreeNode *root = vectorToTree(vector<int>{1, 2, 3, 4, 5, 6, 7});
	//cout << endl << "初始化二叉树\n" << endl;
	TreeNode *root1 = new TreeNode(1);
	TreeNode *root2 = new TreeNode(2);
	TreeNode *root3 = new TreeNode(3);
	TreeNode *root4 = new TreeNode(4);
	TreeNode *root5 = new TreeNode(5);
	TreeNode *root6 = new TreeNode(6);
	TreeNode *root7 = new TreeNode(7);
	root1->left = root2;
	root1->right = root3;
	root2->left = root4;
	root2->right = root5;
	root3->left = root6;
	root3->right = root7;


	cout << endl << "前序遍历 递归 = ";
	preOrder(root1);
	
	cout << endl;
	cout << endl << "前序遍历 非递归 = ";
	vector<int> res = preOrderIterative(root1);
	printVector(res);
}


/* Print a binary tree */
void printTree(TreeNode *root, Trunk *prev, bool isRight) {
	if (root == nullptr) {
		return;
	}

	string prev_str = "    ";
	Trunk trunk(prev, prev_str);

	printTree(root->right, &trunk, true);

	if (!prev) {
		trunk.str = "———";
	}
	else if (isRight) {
		trunk.str = "/———";
		prev_str = "   |";
	}
	else {
		trunk.str = "\\———";
		prev->str = prev_str;
	}

	showTrunks(&trunk);
	cout << " " << root->val << endl;

	if (prev) {
		prev->str = prev_str;
	}
	trunk.str = "   |";

	printTree(root->left, &trunk, false);
}

/* The interface of the tree printer */
void printTree(TreeNode *root) {
	printTree(root, nullptr, false);
}

void showTrunks(Trunk *p) {
	if (p == nullptr) {
		return;
	}

	showTrunks(p->prev);
	cout << p->str;
}