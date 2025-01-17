#pragma once

#include "../util.h"

//邻接表
class GraphAdjList
{
public:
	/* 顶点类 */
	struct Vertex {
		int val;
		Vertex(int x) : val(x) {
		}
	};

	GraphAdjList(const vector<vector<Vertex*>>& edges);

	~GraphAdjList();

	int size();

	void addEdge(Vertex* vet1, Vertex* vet2);

	void removeEdge(Vertex* vet1, Vertex* vet2);

	void addVertex(Vertex* vet);

	void removeVertex(Vertex* vet);

	void removeVertex(vector<Vertex*>& vets, Vertex * vet);

	void print();

	static void test();

	static void test_bfs();

	static void test_dfs();

	//广度优先遍历
	vector<Vertex *> graphBFS(Vertex* startVet);

	vector<Vertex *> graphDFS(Vertex* startVet);

	void dfs(unordered_set<Vertex*>& visited, vector<Vertex*>& res, Vertex *vet);

//	void graphDFS();

public:
	unordered_map<Vertex*, vector<Vertex*>> adjList_;
};

