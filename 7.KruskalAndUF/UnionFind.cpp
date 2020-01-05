#include "UnionFind.h"
#include <iostream>

UnionFind::UnionFind(int numberOfNodes)
{
	parentArray = new int[numberOfNodes];
	//rankArray = new int[numberOfNodes];

	for (int i = 0; i < numberOfNodes; i++)
	{
		parentArray[i] = i;
		//rankArray[i] = 0;
	}
}
UnionFind::~UnionFind()
{
	delete parentArray;
	//delete rankArray;
}