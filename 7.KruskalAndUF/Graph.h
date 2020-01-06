#pragma once
#include "DynamicArray.h"
#include "Edge.h"
#include "Node.h"

class Graph
{
	friend class Node;
	friend class Edge;
	friend int Kruskal(Graph* graph, Graph* finalGraph);
	friend void DrawSummary(Graph* finalGraph, int& findCounter);

	static int graphNumber;
	Dynamic_Array<Node>* nodeArray;
	Dynamic_Array<Edge>* edgeArray;

	void prepareFiles(fstream& nodeFile, fstream& edgeFile);
public:
	Graph();	
	Graph(const Graph* graph);
	~Graph();	
	double CountSumOfCost();
	void Load(string filename);
	void DrawGraph();
};