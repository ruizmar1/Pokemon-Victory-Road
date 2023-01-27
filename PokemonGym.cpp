#include <iostream>
#include "PokemonGym.h"
using namespace std;

//default constructor
PokemonGym::PokemonGym()
:Building(), max_number_of_battles(10), num_battles_remaining(), health_cost_per_battle(1), PokeDollar_cost_per_battle(1.0), experience_per_battle(2)
{
	display_code='G';
	state= NOT_DEFEATED;
	num_battles_remaining=max_number_of_battles;
	//cout<<"PokemonGym default constructed"<<endl;
}

//parameter constructor
PokemonGym:: PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc)
:Building('G', in_id, in_loc), max_number_of_battles(max_battle), health_cost_per_battle(health_loss), experience_per_battle(exp_per_battle), PokeDollar_cost_per_battle(PokeDollar_cost)
{
	num_battles_remaining=max_number_of_battles;
	//id_num=in_id;
	//location=in_loc;
	//cout<<"PokemonGym constructed cool"<<endl;
}


//destructor
PokemonGym::~PokemonGym()
{
	//cout<<"gym destruced"<<endl;
}


//Public member functions

double PokemonGym::GetPokeDollarCost(unsigned int battle_qty)
{
	return (PokeDollar_cost_per_battle*battle_qty);
}

unsigned int PokemonGym::GetHealthCost(unsigned int battle_qty)
{
	return (health_cost_per_battle*battle_qty);
}

unsigned int PokemonGym::GetNumBattlesRemaining()
{
	return num_battles_remaining;
}

bool PokemonGym:: IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health)
{
	if ((health>=(battle_qty*health_cost_per_battle))&&(budget>=(battle_qty*PokeDollar_cost_per_battle)))
		return true;
	else
		return false;
}

unsigned int PokemonGym::TrainPokemon(unsigned int battle_units)
{
	if (num_battles_remaining>=battle_units)
	{
		num_battles_remaining=num_battles_remaining-battle_units;
		return (battle_units*experience_per_battle);
	}
	else
	{
		return (num_battles_remaining*experience_per_battle);
	}
}

unsigned int PokemonGym:: GetExperiencePerBattle()
{
	return experience_per_battle;
}

bool PokemonGym::Update()
{
	if (state==DEFEATED)
		return false;	
	else if (num_battles_remaining==0)
	{
		state=DEFEATED;
		display_code= 'g';
		cout<<display_code<<id_num<<" has been beaten"<<endl;

		return true;
	}
	else
		return false;
}

bool PokemonGym::passed()
{
	if (num_battles_remaining)
		return true;
	else
		return false;
}

void PokemonGym::ShowStatus()
{
	//GameObject::ShowStatus();
	cout<<"PokemonGymStatus: "<<endl;
	Building::ShowStatus();
	cout<<"Max number of battles: "<<max_number_of_battles<<endl;
	cout<<"Health cost per battle: "<<health_cost_per_battle<<endl;
	cout<<"PokeDollar per battle: "<<PokeDollar_cost_per_battle<<endl;
	cout<<"Experience per battle: "<<experience_per_battle<<endl;
	cout<<num_battles_remaining<<" battle(s) are remaining for this PokemonGym"<<endl<<endl;
}
