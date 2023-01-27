#include <iostream>
#include "PokemonCenter.h"
using namespace std;

//Default Constructor
PokemonCenter::PokemonCenter()
:Building(), potion_capacity(100), num_potions_remaining(), pokedollar_cost_per_potion(5)
{
	num_potions_remaining=potion_capacity;
	display_code='C';
	state= POTIONS_AVAILABLE;
	//cout<<"PokemonCenter default constructed"<<endl;
}

//Paramter constructor
PokemonCenter:: PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc)
:Building('C', in_id, in_loc), pokedollar_cost_per_potion(potion_cost), potion_capacity(potion_cap), num_potions_remaining(potion_cap)
{
	//display_code='C';
	//id_num= in_id;
	//location=in_loc;
	state=POTIONS_AVAILABLE;
	//cout<<"PokemonCenter constructed cool"<<endl;
}

PokemonCenter::~PokemonCenter()
{
	//cout<<"center destructed"<<endl;
}

//public member functions

bool PokemonCenter::HasPotions()
{
	if (num_potions_remaining>0)
		return true;
	else
		return false;
}

unsigned int PokemonCenter::GetNumPotionsRemaining()
{
	return num_potions_remaining;
}

bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget)
{
	if( (potion*pokedollar_cost_per_potion)>budget)
		return true;
	else
		return false;
}

double PokemonCenter::GetPokeDollarCost(unsigned int potion)
{
	return (potion*pokedollar_cost_per_potion);
}

unsigned int PokemonCenter:: DistributePotion(unsigned int potion_needed)
{
	if (num_potions_remaining>=potion_needed)
	{
		num_potions_remaining=num_potions_remaining-potion_needed;
		return potion_needed;
	}
	else 
	{
		unsigned int dummyPotionsRemaining= num_potions_remaining;
		num_potions_remaining=0;
		return dummyPotionsRemaining;
	}
}

bool PokemonCenter:: Update()
{
	if (state==NO_POTIONS_AVAILABLE)
		return false;	
	else if (num_potions_remaining==0)
	{
		state=NO_POTIONS_AVAILABLE;
		display_code= 'c';
		cout<<"PokemonCenter "<<id_num<<" has ran out of potions"<<endl;

		return true;
	}
	else
		return false;
}

void PokemonCenter:: ShowStatus()
{
	cout<<"PokemonCenter Status: "<<endl;
	Building::ShowStatus();
	cout<<"PokeDollars per potion: "<<pokedollar_cost_per_potion<<endl<<"Has "<<num_potions_remaining<<" potion(s) remaining."<<endl<<endl;

}
