#include "UnionFind.h"
#include <iostream>

UnionFind::UnionFind(int numberOfNodes)
{
	unionCounter = findCounter = 0;
	parentArray = new int[numberOfNodes];
	rankArray = new int[numberOfNodes];

	for (int i = 0; i < numberOfNodes; i++)
	{
		parentArray[i] = i;
		rankArray[i] = 0;
	}
}
UnionFind::~UnionFind()
{
	delete parentArray;
	delete rankArray;
}
void UnionFind::Union(int index1, int index2)
{
	parentArray[index1] = index2;
	unionCounter++;
}
void UnionFind::UnionByRank(int index1, int index2)
{
	if (rankArray[index1] < rankArray[index2])
		parentArray[index1] = index2;
	else if (rankArray[index2] < rankArray[index1])
		parentArray[index2] = index1;
	else
	{
		parentArray[index1] = index2;
		rankArray[index2]++;
	}
	unionCounter++;
}
int UnionFind::Find(int index)
{
	findCounter++;
	if (index == parentArray[index]) return index;
	return Find(parentArray[index]);
}
int UnionFind::FindWithCompression(int index)
{
	findCounter++;
	if (index == parentArray[index]) return index;
	int parent = Find(parentArray[index]);
	if (parent != parentArray[index])
		parentArray[index] = parent;
	return parent;
}