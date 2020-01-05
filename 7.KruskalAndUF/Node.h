#pragma once
#include "Graph.h"
using namespace std;
class Node {
	friend class Graph;
	friend ostream& operator<<(ostream& strumien, const Node& dane);

	double x;
	double y;
public:
	Node();
	Node(double x, double y);
	//Node& operator=(Node& arg);
};