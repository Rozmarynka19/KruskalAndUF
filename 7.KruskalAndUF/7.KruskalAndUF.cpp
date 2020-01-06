// 7.KruskalAndUF.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include "Edge.h"
#include "Node.h"
#include "Graph.h"
#include "UnionFind.h"
#include "HeapSort.h"
#include "DynamicArray.h"
#include <string>
using namespace std;

clock_t KruskalStart, KruskalStop, SortStart, SortStop;

int Kruskal(Graph* graph, Graph* finalGraph)
{
	UnionFind* uf = new UnionFind(graph->nodeArray->currentSize);
	BinaryHeap<Edge>* binaryHeap = new BinaryHeap<Edge>(graph->edgeArray, false, false);

	SortStart = clock();
	binaryHeap->HeapSort();
	SortStop = clock();

	int i = 0, firstParent, secondParent;
	KruskalStart = clock();
	while (uf->unionCounter < graph->nodeArray->currentSize-1)
	{
		Edge currentEdge = graph->edgeArray->getData(i);

		//Find without compression
		firstParent = uf->Find(currentEdge.firstIndex);
		secondParent = uf->Find(currentEdge.secondIndex);

		////Find with compression
		//firstParent = uf->FindWithCompression(currentEdge.firstIndex);
		//secondParent = uf->FindWithCompression(currentEdge.secondIndex);

		if (firstParent != secondParent)
		{
			finalGraph->edgeArray->addElement(currentEdge);
			
			//Casual union
			uf->Union(firstParent, secondParent);

			//Union by rank
			//uf->UnionByRank(firstParent, secondParent);
			
		}

		i++;
	}
	KruskalStop = clock();
	int findCounter = uf->findCounter;

	delete uf, binaryHeap;

	return findCounter;
}

void DrawSummary(Graph* finalGraph, int &findCounter)
{
	cout.precision(numeric_limits<double>::max_digits10);
	cout << "============= SUMMARY =============" << endl;
	cout << "Number of edges in MST: " << finalGraph->edgeArray->currentSize << endl
		<< "Sum of edges' cost in MST: " << finalGraph->CountSumOfCost() << endl
		<< "Time of edges' sorting: " << (SortStop - SortStart) / (double)CLOCKS_PER_SEC << endl
		<< "Time of main Kruskal's loop: " << (KruskalStop - KruskalStart) / (double)CLOCKS_PER_SEC << endl
		<< "Number of Find's call: " << findCounter << endl
		<< "===================================" << endl;
}

int main()
{
	int findCounter;
	Graph *graph = new Graph();

	cout << "Loading graph." << endl;
	graph->Load("g1.txt");

	Graph* finalGraph = new Graph(graph);

	cout << "Kruskal starts" << endl;
	findCounter = Kruskal(graph, finalGraph);

	DrawSummary(finalGraph,findCounter);

	cout << "Drawing input graph." << endl;
	graph->DrawGraph();

	cout << "Drawing output graph." << endl;
	finalGraph->DrawGraph();

	delete graph, finalGraph;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
