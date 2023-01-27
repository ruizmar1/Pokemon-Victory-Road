#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include "Point2D.h"
using namespace std;


//Paramter constructor
Point2D:: Point2D(double in_x, double in_y)
:x(in_x), y(in_y)
{
}

//Default constructor
Point2D:: Point2D()
:x(0.0), y(0.0)
{
}

//Destructor 
Point2D:: ~Point2D()
{
}

//Non-member function
double GetDistanceBetween(Point2D p1, Point2D p2)
{
	return sqrt(pow((p1.x-p2.x),2)+ pow((p1.y-p2.y),2));
}

//Non-member overloaded operators
//addition operator
const Point2D operator+ (const Point2D& coord1, const Point2D& coord2)
{
	double x_addition= coord1.x+coord2.x;
	double y_addition= coord1.y+coord2.y;
	Point2D result(x_addition, y_addition);
	return result;
}

//subtraction operator
const Point2D operator- (const Point2D& coord1, const Point2D& coord2)
{
	double x_subtraction= coord1.x-coord2.x;
	double y_subtraction= coord1.y-coord2.y;
	Point2D result(x_subtraction, y_subtraction);
	return result;
}

//ostream operator 
ostream& operator<< (ostream& left, const Point2D& coordinate)
{
	left<<"("<<coordinate.x<<", "<<coordinate.y<<")"<<endl;
	return left;
}
