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
	
	//����
	path.pop_back();
}

void preOrder_3(TreeNode *root, int x, int exclude, vector<TreeNode*>& path, vector<vector<TreeNode*>>& res)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->val == exclude) //��֦����·������ǰ���ء�
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
	if (isSolution(state, x)) //����н�
	{   //��¼��
		recordSolution(state, res);
	}

	for (TreeNode* choice : choices)  //��������ѡ��·��
	{
		if (isValid(state, choice, exclude)) //������Чѡ��·��
		{
			makeChoice(state, choice);  //ѡ������·��
			vector<TreeNode*> nextchoices{choice->left, choice->right}; //��ȡ����·������·��
			backtrack_template(state, x, exclude, nextchoices, res);// ��������
			undoChoice(state, choice);  //��������·��
		}
	}
}







void testPreOrder_traversal_compact()
{
	TreeNode *root = vectorToTree(vector<int>{1, 7, 3, 4, 5, 6, 7});
	cout << "\n��ʼ��������" << endl;
	printTree(root);

	// ǰ�����
	//vector<TreeNode*> res;
	//preOrder_1(root, 7, res);
	//vector<TreeNode*> path;
	//vector<vector<TreeNode*>> paths;
	//preOrder_3(root, 7, 3, path, paths);

	// �����㷨
	vector<TreeNode *> state;
	vector<TreeNode *> choices = { root };
	vector<vector<TreeNode *>> res;
	//backtrack(state, choices, res);
	backtrack_template(state, 7, 3, choices, res);
	//cout << "\n�������ֵΪ 7 �Ľڵ�" << endl;
	//vector<int> vals;
	//for (TreeNode *node : res) {
	//	vals.push_back(node->val);
	//}
	cout << "\n������и��ڵ㵽�ڵ� 7 ��·��" << endl;
	for (vector<TreeNode *> &path : res) {
		vector<int> vals;
		for (TreeNode *node : path) {
			vals.push_back(node->val);
		}
		printVector(vals);
	}

	//printVector(vals);
}
