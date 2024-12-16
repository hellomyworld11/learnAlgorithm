#pragma once

#include "util.h"

class GraphAdjList
{
public:
	/* ∂•µ„¿‡ */
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

	void print();

private:
	void removeVertex(vector<Vertex*> vets, Vertex* vet);
public:
	unordered_map<Vertex*, vector<Vertex*>> adjList_;
};

