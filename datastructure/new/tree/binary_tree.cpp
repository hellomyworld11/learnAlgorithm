#include "binary_tree.h"


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
	/* ��ʼ�������� */
	// ���������һ��������ֱ�����ɶ������ĺ���
	//TreeNode *root = vectorToTree(vector<int>{1, 2, 3, 4, 5, 6, 7});
	//cout << endl << "��ʼ��������\n" << endl;
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


	cout << endl << "ǰ����� �ݹ� = ";
	preOrder(root1);
	
	cout << endl;
	cout << endl << "ǰ����� �ǵݹ� = ";
	vector<int> res = preOrderIterative(root1);
	printVector(res);
}
