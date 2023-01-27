#ifndef POKEMONGYM_H
#define POKEMONGYM_H
#include "Building.h"

//PokemonGym has a location and amount of battles. You can battle with your trainer in a PokemonGym and earn experience. It also has a display_code and id number that are used to help identigy the object in the output. PokemonGym Objects should inherit from Building
class PokemonGym: public Building
{

	private:
		unsigned int num_battles_remaining;
		unsigned int max_number_of_battles;
		unsigned int health_cost_per_battle;
		double PokeDollar_cost_per_battle;
		unsigned int experience_per_battle;
	public:
		//constructors
		PokemonGym();	//default constructor
		PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc);
		//public member functions
		double GetPokeDollarCost(unsigned int battle_qty); //returns cost of battling
		unsigned int GetHealthCost(unsigned int battle_qty);//returns amount of health points required to battle
		unsigned int GetNumBattlesRemaining(); //returns number of battles remaining in pokemon gym
		bool IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health);////returns true if able to battle
		unsigned int TrainPokemon(unsigned int battle_units);//subtract from num battles remaining, returns experience
		unsigned int GetExperiencePerBattle();//returns experience gained from each battle
		bool Update();
		bool passed();//returns true if battle remaining is zero
		void ShowStatus();
		//destructor
		~PokemonGym();
};
	enum PokemonGymStates
	{
		NOT_DEFEATED=0,
		DEFEATED=1
	};

#endif

