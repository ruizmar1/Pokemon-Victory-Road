#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>
using namespace std;


#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
	//public member variables
	public:
	double x,y; 
	
	//Constructors
	Point2D(double in_x, double in_y); //Parameter Constructor
	Point2D();			//Defult Constructor
	
	~Point2D();			//Destructor
	
	


//non-member overloaded operators 
friend const Point2D operator+ (const Point2D& coord1, const Point2D& coord2); //addition operator
friend const Point2D operator- (const Point2D& coord1, const Point2D& coord2); //subtraction operator
friend ostream& operator<< (ostream& left, const Point2D& coordinate);//ostream operator
};

//non-member function
double GetDistanceBetween(Point2D p1, Point2D p2); 

//nonmeber overloaded operator
 #endif
