#include <iostream>
#include "Edge.h"

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