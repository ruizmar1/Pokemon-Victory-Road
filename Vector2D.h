#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>
using namespace std;

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
	//pubic member variables
	public:
	double x,y;
	
	//public member functions
	Vector2D(double in_x, double in_y);	//Parameter Constructor
	Vector2D();				//default constructor
	~Vector2D();				//destructor};

//Nonmeber overloaded operators
friend const Vector2D operator* (const Vector2D& vec1, double multi); //multiplication operator
friend const Vector2D operator/ (const Vector2D& vec1, double divi); //division operator
friend ostream& operator<< (ostream& left, const Vector2D& vector); //ostream operator
};

#endif

