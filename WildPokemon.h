#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H
#include "Trainer.h"
#include "Point2D.h"
#include "Vector2D.h"
#include <iostream>
using namespace std;

class WildPokemon: public GameObject
{
    protected:
        double attack; //initial value is 5
        double health; //initial value is 2
        bool variant; //initial value is false. For extra credit you could actually make a derived class of WildPokemon
        bool in_combat; //returns true if the WildPokemon is following a trainer. DEfault is false
        string name; //name
        Trainer* current_trainer; //Holds the current trainer it is following;

    public:
        WildPokemon(); //default constructor
        WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc);// constructor
       void follow(Trainer* t); //follows trainer* t, should change the WildPokemon's current_trainer value and update trainer's information as needed
       bool get_variant();// Return variant
       double get_attack(); //return attack
       double get_health(); //return health
       bool get_in_combat(); //returns in_combat
       bool Update(); //state 'IN_ENVIRONMENT' default when we create WildPokemon and it returns false. 'DEAD' when WildPokemon health is zero or below. 'IN_TRAINER' when WildPokemon is following trainer
       void ShowStatus(); //outputs status
       bool isAlive(); //check the health of WildPokemon and return true if it is alive.
       bool check_in_trainer(Trainer* t);
       virtual ~WildPokemon(); //virtual destructor

};
enum WildPokemonStates
	{
		IN_ENVIRONMENT=0,
		DEAD=1,
		IN_TRAINER=2
	};

#endif