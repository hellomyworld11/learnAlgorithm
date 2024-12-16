#pragma once
#include "../util.h"

//ÁÚ½Ó¾ØÕó ÎŞÏòÍ¼
class GraphAdjMat
{
public:

	~GraphAdjMat();

	GraphAdjMat(const vector<int> vertices, const vector<vector<int>>& edges);

	void addVertex(int val);

	void addEdge(int i, int j);

	void removeVertex(int index);

	void removeEdge(int i, int j);

	int size();

	void print();

	static void test();
private:
	vector<int> vertices_;
	vector<vector<int>> adjMat_;
};

