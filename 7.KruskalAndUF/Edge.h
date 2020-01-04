#pragma once
class Edge {
	int firstIndex;
	int secondIndex;
	double cost;
public:
	Edge();
	Edge(int index1, int index2, double c);
};