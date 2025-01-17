#include "GraphAdjList.h"

GraphAdjList::GraphAdjList(const vector<vector<Vertex*>>& edges)
{
	for (auto& edge : edges)
	{
		if (edge.size() != 2)
		{
			continue;
		}
		addVertex(edge[0]);
		addVertex(edge[1]);
		addEdge(edge[0], edge[1]);
	}
}

GraphAdjList::~GraphAdjList()
{
}

void GraphAdjList::addVertex(Vertex* vet)
{
	if (adjList_.count(vet))
		return;
	
	adjList_[vet] = vector<Vertex*>();
}

void GraphAdjList::removeVertex(Vertex* vet)
{
	if (!adjList_.count(vet))
		return;

	adjList_.erase(vet);
}

void GraphAdjList::removeVertex(vector<Vertex*>& vets, Vertex* vet)
{
	for (size_t i = 0; i < vets.size(); i++)
	{
		if (vets[i] == vet)
		{
			vets.erase(vets.begin() + i);
			break;
		}
	}
}

void GraphAdjList::addEdge(Vertex* vet1, Vertex* vet2)
{
	if (!adjList_.count(vet1) || !adjList_.count(vet2) || vet1 == vet2)
		throw invalid_argument("不存在顶点");

	adjList_[vet1].push_back(vet2);
	adjList_[vet2].push_back(vet1);
}

void GraphAdjList::removeEdge(Vertex* vet1, Vertex* vet2)
{
	if (!adjList_.count(vet1) || !adjList_.count(vet2) || vet1 == vet2)
		throw invalid_argument("不存在顶点");

	removeVertex(adjList_[vet1], vet2);
	removeVertex(adjList_[vet2], vet1);
}

int GraphAdjList::size()
{
	return adjList_.size();
}

void GraphAdjList::print()
{
	cout << "邻接表 =" << endl;
	for (auto &adj : adjList_) {
		const auto &key = adj.first;
		const auto &vec = adj.second;
		cout << key->val << ": ";
		vector<int> vals;
		for (int i = 0; i < vec.size(); i++)
		{
			vals.push_back(vec[i]->val);
		}
		printVector(vals);
	}
}

void GraphAdjList::test()
{
	/* 初始化无向图 */
	Vertex *v1 = new Vertex(1);
	Vertex *v2 = new Vertex(3);
	Vertex *v3 = new Vertex(2);
	Vertex *v4 = new Vertex(5);
	Vertex *v5 = new Vertex(4);

	vector<Vertex *> v = { v1, v2, v3, v4, v5 };
	vector<vector<Vertex *>> edges = { { v[0], v[1] },{ v[0], v[3] },{ v[1], v[2] },
	{ v[2], v[3] },{ v[2], v[4] },{ v[3], v[4] } };
	GraphAdjList graph(edges);
	cout << "\n初始化后，图为" << endl;
	graph.print();

	/* 添加边 */
	// 顶点 1, 2 即 v[0], v[2]
	graph.addEdge(v[0], v[2]);
	cout << "\n添加边 1-2 后，图为" << endl;
	graph.print();

	/* 删除边 */
	// 顶点 1, 3 即 v[0], v[1]
	graph.removeEdge(v[0], v[1]);
	cout << "\n删除边 1-3 后，图为" << endl;
	graph.print();

	/* 添加顶点 */
	Vertex *v6 = new Vertex(6);
	graph.addVertex(v6);
	cout << "\n添加顶点 6 后，图为" << endl;
	graph.print();

	/* 删除顶点 */
	// 顶点 3 即 v[1]
	graph.removeVertex(v[1]);
	cout << "\n删除顶点 3 后，图为" << endl;
	graph.print();

	// 释放内存
	for (Vertex *vet : v) {
		delete vet;
	}

}

void GraphAdjList::test_bfs()
{
	/* 初始化无向图 */
	vector<Vertex *> v;
	vector<int> vals = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int val : vals) {
		v.push_back(new Vertex(val));
	}

	vector<vector<Vertex *>> edges = { { v[0], v[1] },{ v[0], v[3] },{ v[1], v[2] },{ v[1], v[4] },
	{ v[2], v[5] },{ v[3], v[4] },{ v[3], v[6] },{ v[4], v[5] },
	{ v[4], v[7] },{ v[5], v[8] },{ v[6], v[7] },{ v[7], v[8] } };
	GraphAdjList graph(edges);
	cout << "\n初始化后，图为\\n";
	graph.print();

	/* 广度优先遍历 */
	vector<Vertex *> res = graph.graphBFS(v[0]);
	cout << "\n广度优先遍历（BFS）顶点序列为" << endl;
	vector<int> vals1;
	for (int i = 0; i < res.size(); i++)
	{
		vals1.push_back(res[i]->val);
	}
	printVector(vals1);

	// 释放内存
	for (Vertex *vet : v) {
		delete vet;
	}
}

void GraphAdjList::test_dfs()
{
	/* 初始化无向图 */
	vector<Vertex *> v;
	vector<int> vals = { 0, 1, 2, 3, 4, 5, 6 };
	for (int val : vals) {
		v.push_back(new Vertex(val));
	}
	vector<vector<Vertex *>> edges = { { v[0], v[1] },{ v[0], v[3] },{ v[1], v[2] },
	{ v[2], v[5] },{ v[4], v[5] },{ v[5], v[6] } };
	GraphAdjList graph(edges);
	cout << "\n初始化后，图为" << endl;
	graph.print();

	/* 深度优先遍历 */
	vector<Vertex *> res = graph.graphDFS(v[0]);
	cout << "\n深度优先遍历（DFS）顶点序列为" << endl;
	vector<int> vals1;
	for (int i = 0; i < res.size(); i++)
	{
		vals1.push_back(res[i]->val);
	}
	printVector(vals1);

	// 释放内存
	for (Vertex *vet : v) {
		delete vet;
	}
}

vector<GraphAdjList::Vertex*> GraphAdjList::graphBFS(Vertex* startVet)
{
	//节点放入队列，出队时获取节点的邻节点继续放入队列。
	vector<Vertex*> rets;
	unordered_set<Vertex*> visited; //已经被访问的节点

	queue<Vertex*> vetqueue;

	vetqueue.push(startVet);

	while (!vetqueue.empty())
	{
		Vertex* curVet = vetqueue.front();
		vetqueue.pop();

		if (!visited.count(curVet))
		{
			rets.push_back(curVet);
			visited.insert(curVet);

			for (auto& vet : adjList_[curVet])
			{
				vetqueue.push(vet);
			}
		}
	}

	return rets;
}

std::vector<GraphAdjList::Vertex *> GraphAdjList::graphDFS(Vertex* startVet)
{
	vector<Vertex*> res;
	unordered_set<Vertex*> visited;

	dfs(visited, res, startVet);

	return res;
}

void GraphAdjList::dfs(unordered_set<Vertex*>& visited, vector<Vertex*>& res, Vertex *vet)
{

	res.push_back(vet);
	visited.insert(vet);
	
	for (auto& vertex : adjList_[vet])
	{
		if (!visited.count(vertex))
		{
			dfs(visited, res, vertex);
		}
	}
}
