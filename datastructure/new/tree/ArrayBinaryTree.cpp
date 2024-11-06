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
	// ��ʼ��������
	// ʹ�� INT_MAX �����λ nullptr
	vector<int> arr = { 1, 2, 3, 4, INT_MAX, 6, 7, 8, 9, INT_MAX, INT_MAX, 12, INT_MAX, INT_MAX, 15 };

	// �����ʾ�µĶ�������
	ArrayBinaryTree abt(arr);

	// ���ʽڵ�
	int i = 1;
	int l = abt.left(i), r = abt.right(i), p = abt.parent(i);
	cout << "\n��ǰ�ڵ������Ϊ " << i << "��ֵΪ " << abt.val(i) << "\n";
	cout << "�����ӽڵ������Ϊ " << l << "��ֵΪ " << (l != INT_MAX ? to_string(abt.val(l)) : "nullptr") << "\n";
	cout << "�����ӽڵ������Ϊ " << r << "��ֵΪ " << (r != INT_MAX ? to_string(abt.val(r)) : "nullptr") << "\n";
	cout << "�丸�ڵ������Ϊ " << p << "��ֵΪ " << (p != INT_MAX ? to_string(abt.val(p)) : "nullptr") << "\n";

	// ������
	vector<int> res = abt.levelOrder();
	cout << "\n�������Ϊ�� ";
	printVector(res);

	cout << "ǰ�����Ϊ�� ";
	abt.preOrder();
	
	cout << "�������Ϊ�� ";
	abt.inOrder();
	
	cout << "�������Ϊ�� ";
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
