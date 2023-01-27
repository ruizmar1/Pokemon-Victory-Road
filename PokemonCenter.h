#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H
#include "Building.h"

//this class has a location and a set amount of potions. It also has a display_code letter and an id number. Inherits from Building
class PokemonCenter: public Building
{

	private:
		unsigned int potion_capacity;	//max num of potions this PokemonCenter can hold
		unsigned int num_potions_remaining;	//amount of potions currently in this PokemonCenter 
		double pokedollar_cost_per_potion;	//per potion cost in PokemonCenter
	public:
		//constructors
		PokemonCenter();	//default constructor
		PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc);//parameter constructor
		//public member functions
		bool HasPotions();	//returns true if PokemonCenter has at least one potion, false otherwise
		unsigned int GetNumPotionsRemaining();	//Return number of potions remaining in this PokemonCenter
		bool CanAffordPotion(unsigned int potion, double budget);//Returns true if trainer can afford to purchae potion with budget
		double GetPokeDollarCost(unsigned int potion);//Returns pokedollar cost for specified number of potions
		unsigned int DistributePotion(unsigned int potion_needed);
		bool Update();
		void ShowStatus();
		//destructor
		~PokemonCenter();
};	
	enum PokemonCenterStates
	{
		POTIONS_AVAILABLE=0,
		NO_POTIONS_AVAILABLE=1
	};


#endif

