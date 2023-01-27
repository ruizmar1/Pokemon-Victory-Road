#ifndef TRAINER_H
#define TRAINER_H
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "GameObject.h"



//this class inherits from GameObject. It will represent objects that move around and can be commanded to do things. It is responsible for the data and functions for moving around, recovering health and battling in pokemonGyms

class Trainer: public GameObject
{
	
	//public members 
	public:
		Trainer();//Default Constructor
		Trainer(char in_code);	//parameter constructor
		Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);//Another Parameter constructor
		void StartMoving(Point2D dest);//Tells trainer to start moving
		void StartMovingToGym(PokemonGym* gym);//Tells trainer to start moving to PokemonGym
		void StartMovingToCenter(PokemonCenter* center);//Tells trainer to start moving to PokemonCenter
		void StartBattling(unsigned int num_battles);//Tells trainer to start battlings (num_battles) in a PokemonGym
		void StartRecoveringHealth(unsigned int num_potions);//tells trainer to start recovering at PokemonCenter
		void Stop(); //Tells trainer to stop doing whatever it is that it is doing
		bool HasFainted();//Returns true if health is zero
		string GetName();
		bool ShouldBeVisible(); //Returns true if trainer has NOT fainted
		void ShowStatus();
		bool Update();
		void AddHealthWildPokemon(); //When traveling with a wild pokemon, trainer's health increases because wild Pokemon are so cute
	    ~Trainer();//virtual Destructor

	//protected members
	protected:
		bool UpdateLocation();//Updates Object's location while it moves
		void SetUpDestination(Point2D dest);//sets up the object to start moving to dest


	//private members
	private:
		double speed;		//speed this object travels
		bool is_at_center;	//True if Trainer is at Pokemon center
		bool is_IN_GYM;		//True if trainer is in Pokemon Gym
		bool is_at_WildPokemon;
		unsigned int health;	//amt of health trainer's pokemon has
		unsigned int experience;//amt of experience points this trainer has
		double PokeDollars;	//total amt of PokeDollars trainer holds
		unsigned int battles_to_buy;//stores num of battles to buy when in a PokemonGym
		unsigned int potions_to_buy;//stores num of potions to buy when in a PokemonCenter
		string name;		//name of this trainer
		PokemonCenter* current_center = new PokemonCenter(1, 1.0, 100, Point2D(1, 8));	//Pointer to current PokemonCenter
		PokemonGym* current_gym = new PokemonGym(10, 1, 2.0, 3, 1, Point2D(0,0));//pointer to current PokemonGym
		Point2D destination;	//This object's current destination coordinates in the real plane
		Vector2D delta;		//Contains the x and y amounts that the object will move on each time unit


		

};

enum TrainerStates
	{
		STOPPED=0,
		MOVING=1,
		FAINTED=2, 
		AT_CENTER=3,
		IN_GYM= 4,
		MOVING_TO_CENTER=5,
		MOVING_TO_GYM=6,
		BATTLING_IN_GYM=7,
		RECOVERING_HEALTH=8
	};

//non-member functions (static)
	static double GetRandomAmountOfPokeDollars();


#endif

