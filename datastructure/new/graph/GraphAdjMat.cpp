#include "GraphAdjMat.h"



GraphAdjMat::GraphAdjMat(const vector<int> vertices, const vector<vector<int>>& edges)
{
	//��Ӷ���
	for (int val : vertices)
	{
		addVertex(val);
	}

	//��ӱ�
	for (const vector<int>& edge : edges)
	{
		addEdge(edge[0], edge[1]);
	}

}

void GraphAdjMat::addEdge(int i, int j)
{
	int n = size();
	if (i < 0 || i > n || j < 0 || j > n)
	{
		throw out_of_range("���㲻����");
	}
	adjMat_[i][j] = adjMat_[j][i] = 1;
}

GraphAdjMat::~GraphAdjMat()
{
}

void GraphAdjMat::addVertex(int val)
{
	int n = size();
	vertices_.push_back(val);
	//���һ��
	adjMat_.emplace_back(vector<int>(n, 0));
	//ÿһ�������
	for (vector<int>& row: adjMat_)
	{
		row.push_back(0);
	}
}

int GraphAdjMat::size()
{
	return vertices_.size();
}

void GraphAdjMat::test()
{
	/* ��ʼ������ͼ */
	// ��ע�⣬edges Ԫ�ش���������������Ӧ vertices Ԫ������
	vector<int> vertices = { 1, 3, 2, 5, 4 };
	vector<vector<int>> edges = { { 0, 1 },{ 0, 3 },{ 1, 2 },{ 2, 3 },{ 2, 4 },{ 3, 4 } };
	GraphAdjMat graph(vertices, edges);
	cout << "\n��ʼ����ͼΪ" << endl;
	graph.print();

	/* ��ӱ� */
	// ���� 1, 2 �������ֱ�Ϊ 0, 2
	graph.addEdge(0, 2);
	cout << "\n��ӱ� 1-2 ��ͼΪ" << endl;
	graph.print();

	/* ɾ���� */
	// ���� 1, 3 �������ֱ�Ϊ 0, 1
	graph.removeEdge(0, 1);
	cout << "\nɾ���� 1-3 ��ͼΪ" << endl;
	graph.print();

	/* ��Ӷ��� */
	graph.addVertex(6);
	cout << "\n��Ӷ��� 6 ��ͼΪ" << endl;
	graph.print();

	/* ɾ������ */
	// ���� 3 ������Ϊ 1
	graph.removeVertex(1);
	cout << "\nɾ������ 3 ��ͼΪ" << endl;
	graph.print();

}

void GraphAdjMat::removeVertex(int index)
{
	int n = size();
	//ɾ���ڼ���
	if (index < 0 || index > n)
	{
		throw out_of_range("���㲻����");
	}

	vertices_.erase(vertices_.begin() + index);

	for (vector<int>& row : adjMat_)
	{
		row.erase(row.begin() + index);
	}

}

void GraphAdjMat::removeEdge(int i, int j)
{
	int n = size();
	if (i < 0 || i > n || j < 0 || j > n)
	{
		throw out_of_range("���㲻����");
	}
	adjMat_[i][j] = adjMat_[j][i] = 0;
}

void GraphAdjMat::print()
{
	cout << "�����б� = ";
	printVector(vertices_);
	cout << "�ڽӾ��� =" << endl;

	for (vector<int> &list : adjMat_)
	{
		cout << "  ";
		printVector(list);
		cout << '\n';
	}	
}