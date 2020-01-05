#pragma once
#include "DynamicArray.h"
#include "Edge.h"
#include "Node.h"

class Graph
{
	friend class Node;
	friend class Edge;
	friend void Kruskal(Graph& graph);

	Dynamic_Array<Node>* nodeArray;
	Dynamic_Array<Edge>* edgeArray;

	void prepareFiles(fstream& nodeFile, fstream& edgeFile);
public:
	Graph();	
	~Graph();	
	void Load(string filename);
	void DrawGraph();
};