#include <iostream>
#include <string>
#include <fstream>
#include "DynamicArray.h"
#include "Edge.h"
#include "Node.h"
#include "Graph.h"

Graph::Graph()
{
	nodeArray = new Dynamic_Array<Node>();
	edgeArray = new Dynamic_Array<Edge>();
}

void Graph::Load(string filename)
{
	ifstream plik;

	plik.open(filename);

	if (plik.good())
	{
		string line;
		int number, i1, i2;
		double x, y;

		plik >> line;
		cout << line << endl;
		number = atoi(line.c_str());

		for (int i = 0; i < number; i++)
		{
			plik >> line;
			x = atof(line.c_str());
			plik >> line;
			y = atof(line.c_str());

			cout << x << "\t" << y;
			getchar();
			nodeArray->addElement(*(new Node(x, y)));
		}
		//cout << nodeArray->currentSize << endl;

		plik >> line;
		cout << line << endl;
		number = atoi(line.c_str());

		for (int i = 0; i < number; i++)
		{
			plik >> line;
			i1 = atoi(line.c_str());
			plik >> line;
			i2 = atoi(line.c_str());
			plik >> line;
			x = atof(line.c_str());

			cout << i1 << "\t" << i2 << "\t" << x;
			getchar();
			edgeArray->addElement(*(new Edge(i1, i2, x)));
		}
		//cout << edgeArray->currentSize << endl;
		if (!plik.eof()) {
			cout << "I got sth else to read..." << endl;
			cout << line << endl;
		}


		cout << "\nGraph has been loaded." << endl;
	}
	else
	{
		try
		{
			throw logic_error("Reading file failed!");
		}
		catch (logic_error & error)
		{
			cout << "Logic error: " << error.what() << " Make sure that the file exists." << endl;
			terminate();
		}
	}
}