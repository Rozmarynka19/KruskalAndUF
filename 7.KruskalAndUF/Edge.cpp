#include <iostream>
#include "Edge.h"

Edge::Edge(int index1, int index2, double c)
{
	firstIndex = index1;
	secondIndex = index2;
	cost = c;
}