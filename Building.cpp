#include <iostream>
using namespace std;
#include "Building.h"


//default constructor
Building:: Building()
:GameObject(),trainer_count(0)
{
	display_code= 'B';	
	//cout<<"Building default constructed"<<endl;
}

//Paramter constructor
Building:: Building(char in_code, int in_id, Point2D in_loc)
:GameObject(in_loc,in_id,in_code), trainer_count(5)
{
	//cout<<"Building constructed"<<endl;
}

//Destructor
Building::~Building()
{
}

//public member functions

unsigned int Building::GetNumTrainer()
{
	return trainer_count;
}

void Building::AddOneTrainer()
{
	trainer_count++;	//incrementing trainer_count by one
	return;
}

void Building::RemoveOneTrainer()
{
	if (trainer_count>0)	
		trainer_count--;
	return;
}

void Building::ShowStatus()
{
	cout<<display_code<<id_num<< " located at "<<location;
	if (trainer_count==1)
	{
		cout<<trainer_count<<" trainer is in this building"<<endl;
	}
	else 
	{
		cout<<trainer_count<<" trainers are in this building"<<endl;
	}
	return;
}


bool Building::ShouldBeVisible()
{
	return true;
}
