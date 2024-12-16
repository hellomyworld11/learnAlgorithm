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
		//printVector(vetsToVals(vec));
	}
}