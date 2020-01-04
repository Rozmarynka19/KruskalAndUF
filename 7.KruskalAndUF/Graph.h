#pragma once
#include "DynamicArray.h"
#include "Edge.h"
#include "Node.h"

class Graph
{
	friend class Node;
	friend class Edge;

	Dynamic_Array<Node>* nodeArray;
	Dynamic_Array<Edge>* edgeArray;

public:
	Graph();	
	void Load(string filename);
};