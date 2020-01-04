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
		while (!plik.eof())
		{
			string line;

			plik >> line;
			cout << line << endl;
			getchar();

			//getline(plik, ma);
			//getline(plik, mo);
			//getline(plik, linia);
			//rok = atoi(linia.c_str()); //konwersja stringa na int
			//getline(plik, linia);
			//poj = stof(linia); //konwersja stringa na float
			//getline(plik, linia);
			//rez = linia.compare("1") ? true : false;//konwersja stringa na bool
			//getline(plik, linia);
			//c = stof(linia);//konwersja stringa na float

			//baza_motocykli.push_back(Motocykl(ma, mo, rok, poj, rez, c));
		}

		cout << "\nGraf zostal wczytany." << endl;
	}
	else
	{
		try
		{
			throw logic_error("Plik nie zostal odczytany!");
		}
		catch (logic_error & error)
		{
			cout << "Logic error: " << error.what() << " Upewnij sie, ze podales dobra sciezke dostepu do pliku." << endl;
			terminate();
		}
	}
}