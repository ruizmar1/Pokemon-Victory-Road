#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
using namespace std;

//a parameter constructor
GameObject:: GameObject(char in_code)
:display_code(in_code), id_num(1), state(0)
{
	//cout<<"GameObject constructed"<<endl;
}

//another parameter constructor
GameObject:: GameObject(Point2D in_loc, int in_id, char in_code)
:display_code(in_code), id_num(in_id), location(in_loc), state(0)
{
	//cout<<"GameObject constructed cool"<<endl;
}

//default constructor
GameObject::GameObject()
:location(0,0), id_num(0), display_code(0), state(0)
{

}

//destructor
GameObject:: ~GameObject()
{
	//cout<<"GameObject destructed"<<endl;
}

//Accessor function
Point2D GameObject:: GetLocation()
{
	//cout<<location<<endl;
	return location;
}

//Accessor function
int GameObject::GetId()
{
	return id_num;
}

//Accessor function
char GameObject::GetState()
{
	return state;
}

//Accessor function
void GameObject::ShowStatus()
{
	cout<<display_code<<id_num<<" at "<<location<<endl;
}

//Update Function
bool GameObject:: Update()
{
	return true;
}

//another virtual function
bool GameObject:: ShouldBeVisible()
{
	return true;
}

//added function to help View class
void GameObject:: DrawSelf(char* ptr)
{
	*ptr= display_code;
	*(ptr+1)='0'+id_num;
	return;
}
