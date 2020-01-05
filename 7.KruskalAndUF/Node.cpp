#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

Node::Node()
{
	this->x = 0;
	this->y = 0;
}
Node::Node(double x, double y)
{
	this->x = x;
	this->y = y;
}
ostream& operator<<(ostream& strumien, const Node& dane)
{
	strumien <<"x: "<< dane.x <<"y: "<<dane.y;
	return strumien;
}
//Node& Node::operator=(Node& arg)
//{
//	x = arg.x;
//	y = arg.y;
//	return *this;
//}