#include <iostream>
#include "Edge.h"
using namespace std;

Edge::Edge()
{
	firstIndex = 0;
	secondIndex = 0;
	cost = 0;
}
Edge::Edge(int index1, int index2, double c)
{
	firstIndex = index1;
	secondIndex = index2;
	cost = c;
}
ostream& operator<<(ostream& strumien, const Edge& dane)
{
	strumien << "firstIndex: " << dane.firstIndex << "secondIndex: " << dane.secondIndex<<"cost: "<<dane.cost;
	return strumien;
}