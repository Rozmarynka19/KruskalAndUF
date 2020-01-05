#pragma once
#include "DynamicArray.h"
class UnionFind
{
	int* parentArray;
	int* rankArray;

public:
	UnionFind(int numberOfNodes);
	~UnionFind();
	void Union(int index1, int index2);
	int Find(int index);
};