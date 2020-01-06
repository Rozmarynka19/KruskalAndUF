#pragma once
#include "Graph.h"
class UnionFind
{
	friend int Kruskal(Graph* graph, Graph* finalGraph);

	int* parentArray;
	int* rankArray;
	int unionCounter;
	int findCounter;

public:
	UnionFind(int numberOfNodes);
	~UnionFind();
	void Union(int index1, int index2);
	void UnionByRank(int index1, int index2);
	int Find(int index);
	int FindWithCompression(int index);
};