#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include "Vector2D.h"
using namespace std;


//Paramter constructor
Vector2D:: Vector2D(double in_x, double in_y)
:x(in_x), y(in_y)
{
}

//Default constructor
Vector2D:: Vector2D()
:x(0.0), y(0.0)
{
}

//Destructor 
Vector2D:: ~Vector2D()
{
}

//Non-member overloaded operators
//multiplication operator
const Vector2D operator* (const Vector2D& vec1, double multi)
{
	double x_multiplication= vec1.x*multi;
	double y_multiplication= vec1.y*multi;
	Vector2D result(x_multiplication, y_multiplication);
	return result;
}

//division operator
const Vector2D operator/ (const Vector2D& vec1, double divi)
{
	if (divi==0)
	{
		Vector2D result(vec1.x, vec1.y);	
		return result;
	}
	else
	{
		double x_division= vec1.x/divi;
		double y_division= vec1.y/divi;
		Vector2D result(x_division, y_division);
		return result;
	}
}

//ostream operator 
ostream& operator<< (ostream& left, const Vector2D& vector)
{
	left<<"<"<<vector.x<<", "<<vector.y<<">"<<endl;
	return left;
}
