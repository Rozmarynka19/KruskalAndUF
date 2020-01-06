#pragma once
#include "Graph.h"
using namespace std;

class Edge {
	friend class Graph;
	friend ostream& operator<<(ostream& strumien, const Edge& dane);
	friend int Kruskal(Graph* graph, Graph* finalGraph);
	//friend int main();

	int firstIndex;
	int secondIndex;
	double cost;
public:
	Edge();
	Edge(const Edge& edge);
	Edge(int index1, int index2, double c);
	bool operator>(const Edge& arg);
};