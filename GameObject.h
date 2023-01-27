#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>
using namespace std;
#include "Point2D.h"
#include "Vector2D.h"
#

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
	//protected member variables
	protected:
	Point2D location;       //location of object
	int id_num;		//object's id
	char display_code; 	//How the object is represented in the View
	char state; 		//state of the object
	
	//public member functions
	public:
	GameObject(char in_code);				//parameter constructor
	GameObject(Point2D in_loc, int in_id, char in_code);	//parameter constructor
	GameObject();                                           //default constructor
	Point2D GetLocation();					//Accessor function
	int GetId();						//Accessor function
	char GetState();					//Accessor function
	virtual void ShowStatus();			       	//Virtual Accessor function
	virtual bool Update()=0;                                //pure virtual function
	virtual bool ShouldBeVisible();                      //another pure virtual function
	void DrawSelf(char * ptr);                              //puts display_code at character pointed to by ptr

	virtual ~GameObject();                                  //virtual destructor
	
};

#endif
