#include "ArrayBinaryTree.h"



ArrayBinaryTree::ArrayBinaryTree(vector<int> input)
{
	tree_.assign(input.begin(), input.end());
}


ArrayBinaryTree::~ArrayBinaryTree()
{
}

std::vector<int> ArrayBinaryTree::levelOrder()
{
	return tree_;
}

void ArrayBinaryTree::preOrder(int rootindex)
{
	if (rootindex >= tree_.size() || tree_[rootindex] == INT_MAX) return;

	cout << val(rootindex) << " ";

	preOrder(left(rootindex));
	preOrder(right(rootindex));
}

void ArrayBinaryTree::inOrder(int rootindex)
{
	if (rootindex >= tree_.size() || tree_[rootindex] == INT_MAX) return;

	inOrder(left(rootindex));
	cout << tree_[rootindex] << " ";
	inOrder(right(rootindex));
}

void ArrayBinaryTree::postOrder(int rootindex)
{
	if (rootindex >= tree_.size() || tree_[rootindex] == INT_MAX) return;

	postOrder(left(rootindex));
	postOrder(right(rootindex));
	cout << tree_[rootindex] << " ";
}

void ArrayBinaryTree::test()
{
	// 初始化二叉树
	// 使用 INT_MAX 代表空位 nullptr
	vector<int> arr = { 1, 2, 3, 4, INT_MAX, 6, 7, 8, 9, INT_MAX, INT_MAX, 12, INT_MAX, INT_MAX, 15 };

	// 数组表示下的二叉树类
	ArrayBinaryTree abt(arr);

	// 访问节点
	int i = 1;
	int l = abt.left(i), r = abt.right(i), p = abt.parent(i);
	cout << "\n当前节点的索引为 " << i << "，值为 " << abt.val(i) << "\n";
	cout << "其左子节点的索引为 " << l << "，值为 " << (l != INT_MAX ? to_string(abt.val(l)) : "nullptr") << "\n";
	cout << "其右子节点的索引为 " << r << "，值为 " << (r != INT_MAX ? to_string(abt.val(r)) : "nullptr") << "\n";
	cout << "其父节点的索引为 " << p << "，值为 " << (p != INT_MAX ? to_string(abt.val(p)) : "nullptr") << "\n";

	// 遍历树
	vector<int> res = abt.levelOrder();
	cout << "\n层序遍历为： ";
	printVector(res);

	cout << "前序遍历为： ";
	abt.preOrder();
	
	cout << "中序遍历为： ";
	abt.inOrder();
	
	cout << "后序遍历为： ";
	abt.postOrder();
}

int ArrayBinaryTree::left(int i)
{
	return 2 * i + 1;
}

int ArrayBinaryTree::right(int i)
{
	return 2 * i + 2;
}

int ArrayBinaryTree::parent(int i)
{
	return (i - 1) / 2;
}

int ArrayBinaryTree::val(int i)
{
	if (i < 0  || i > size())
	{
		return INT_MAX;
	}
	return tree_[i];
}

int ArrayBinaryTree::size()
{
	return tree_.size();
}
