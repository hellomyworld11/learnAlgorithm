#include "GraphAdjMat.h"



GraphAdjMat::GraphAdjMat(const vector<int> vertices, const vector<vector<int>>& edges)
{
	//添加顶点
	for (int val : vertices)
	{
		addVertex(val);
	}

	//添加边
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
		throw out_of_range("顶点不存在");
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
	//添加一行
	adjMat_.emplace_back(vector<int>(n, 0));
	//每一行添加列
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
	/* 初始化无向图 */
	// 请注意，edges 元素代表顶点索引，即对应 vertices 元素索引
	vector<int> vertices = { 1, 3, 2, 5, 4 };
	vector<vector<int>> edges = { { 0, 1 },{ 0, 3 },{ 1, 2 },{ 2, 3 },{ 2, 4 },{ 3, 4 } };
	GraphAdjMat graph(vertices, edges);
	cout << "\n初始化后，图为" << endl;
	graph.print();

	/* 添加边 */
	// 顶点 1, 2 的索引分别为 0, 2
	graph.addEdge(0, 2);
	cout << "\n添加边 1-2 后，图为" << endl;
	graph.print();

	/* 删除边 */
	// 顶点 1, 3 的索引分别为 0, 1
	graph.removeEdge(0, 1);
	cout << "\n删除边 1-3 后，图为" << endl;
	graph.print();

	/* 添加顶点 */
	graph.addVertex(6);
	cout << "\n添加顶点 6 后，图为" << endl;
	graph.print();

	/* 删除顶点 */
	// 顶点 3 的索引为 1
	graph.removeVertex(1);
	cout << "\n删除顶点 3 后，图为" << endl;
	graph.print();

}

void GraphAdjMat::removeVertex(int index)
{
	int n = size();
	//删除第几行
	if (index < 0 || index > n)
	{
		throw out_of_range("顶点不存在");
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
		throw out_of_range("顶点不存在");
	}
	adjMat_[i][j] = adjMat_[j][i] = 0;
}

void GraphAdjMat::print()
{
	cout << "顶点列表 = ";
	printVector(vertices_);
	cout << "邻接矩阵 =" << endl;

	for (vector<int> &list : adjMat_)
	{
		cout << "  ";
		printVector(list);
		cout << '\n';
	}	
}