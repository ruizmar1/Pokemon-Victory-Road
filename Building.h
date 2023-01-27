#ifndef BUILDING_H
#define BUILDING_H
#include "GameObject.h"

//Base class for all building objects in the game. Tracks total number of pokemon trainers that enter or leace a building
class Building: public GameObject
{
	private:
		unsigned int trainer_count;
	public:
		//constructors
		Building(); //default constructor
		Building(char in_code, int in_Id, Point2D in_loc); //parameter constuctor
		//public member functions
		unsigned int GetNumTrainer();	//returns number of trainers in building
		void AddOneTrainer();	//incrememnts trainer_count by one
		void RemoveOneTrainer();	//decrements trainer_count by one
		void ShowStatus();	//Prints variables
		bool ShouldBeVisible();	//returns true because buildings should always be visible
		//destructor
		~Building();
};

#endif

