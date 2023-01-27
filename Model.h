#ifndef MODEL_H
#define MODEL_H
#include "WildPokemon.h"
#include "View.h"
#include "GameObject.h"
#include "Trainer.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Point2D.h"
#include "Vector2D.h"
#include <iostream>
#include <iterator>
#include <list>
using namespace std;


//The model is a central component of the MVC pattern and stores all game objects in memory. Hence, it contains various arrays of pointers to the instances of the Game Object class. Also, it offers multiple methods to interact with the Controller and Vew components. 

class Model
{
	//private members
	private:
		int time;	//simulation time
		//set of arrays of pointers and a variable for the number in each array
		//int num_objects;
		Trainer* trainer_ptrs;
		//int num_trainers;
		PokemonCenter* center_ptrs;
		//int num_centers;
		PokemonGym* gym_ptrs;
		//int num_gyms;
		WildPokemon* wildpokemon_ptrs;
		//int num_wildpokemons;
		//linked lists to be used later
		list<GameObject*> object_pointers, active_pointers;
		list<Trainer*> trainer_pointers;
		list<PokemonCenter*> center_pointers;
		list<PokemonGym*> gym_pointers;
		list<WildPokemon*> wildpokemon_pointers;

	//iterators
		list<Trainer*>::iterator t1;
		list<PokemonCenter*>::iterator t2;
		list<PokemonGym*>::iterator t3;
		list<GameObject*>::iterator t4;
		list<WildPokemon*>::iterator t5;
		list<GameObject*>::iterator t6;
		list<WildPokemon*>::iterator t7; //check for wild pokemon
		list<Trainer*>::iterator t8; //check for wild pokemon
	

		/*Each pbject will have a pointer in the object_ptrs array and also in the appropriate other array*/
	
	//public members
	public:
		Model();	//defaut constructor
		~Model();	//destructor
		//public member functions
		Trainer* GetTrainerPtr(int id);
		PokemonCenter* GetPokemonCenterPtr(int id);
		PokemonGym* GetPokemonGymPtr(int id);
		WildPokemon* GetWildPokemonPtr(int id);
		GameObject* GetGameObjectPtr(int id);
		GameObject* GetActiveObjectPtr(int id);
		bool Update();
		void Display(View& view);
		void ShowStatus();
		int getTime();
		void centerAdd(PokemonCenter* c);
		void gymAdd(PokemonGym* g);
		void trainerAdd(Trainer* t);
		void wildpokemonAdd(WildPokemon* w);
		void wildpokemonchecker();


	
};


#endif
