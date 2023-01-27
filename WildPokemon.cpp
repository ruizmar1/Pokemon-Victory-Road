#include "WildPokemon.h"
#include <iostream>
using namespace std;

//default constructor

WildPokemon::WildPokemon()
:attack(5), health(2), variant(false), in_combat(false)
{
    state=IN_ENVIRONMENT;
  //  cout<<"Deafult constructor created"<<endl;
}

WildPokemon::WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc)
:name(name), attack(attack), health(health), variant(variant), GameObject(in_loc, id, 'W')
{
    state=IN_ENVIRONMENT;
  //  cout<<"Constructor created"<<endl;
}

void WildPokemon::follow(Trainer* t)
{
    location= t->GetLocation();
    //trainer gets health
    t->AddHealthWildPokemon();
}

bool WildPokemon:: get_variant()
{
    return variant;
}

double WildPokemon:: get_attack()
{
    return attack;
}

double WildPokemon:: get_health()
{
    return health;
}

bool WildPokemon:: get_in_combat()
{
    return in_combat;
}


bool WildPokemon:: Update()
{
    switch(state)
    {
        case IN_ENVIRONMENT:
        {
            bool testing = isAlive();
            return false;
            break;
        }
        case DEAD:
        {
           return true;
            break;
        }
        case IN_TRAINER:
        {
            follow(current_trainer);
            return true;
            break;
        }
        default:
        {
            return false;
            break;
        }
    }
}

void WildPokemon:: ShowStatus()
{
    cout<<display_code<<id_num<<" at "<<location;
    if (state==DEAD)
        cout<<display_code<<id_num<<" is dead."<<endl;
    else    
        cout<<display_code<<id_num<<"is alive and well!"<<endl;
    if (state==IN_ENVIRONMENT)
        cout<<display_code<<id_num<<" is in environment"<<endl;
    else if (state==IN_TRAINER)
        cout<<display_code<<id_num<<" is following "<<current_trainer->GetName()<<endl;
    cout<<endl;
    return;
}

bool WildPokemon:: isAlive()
{
    if (health<=0)
    {
        state= DEAD;
        return false;
    }
    else
        return true;
}

bool WildPokemon::check_in_trainer(Trainer* t)
{   

    if (GetDistanceBetween(t->GetLocation(),location)==0)
    {
        cout<<"Momma I made it"<<endl;
         state= IN_TRAINER;
         current_trainer=t;
         follow(current_trainer);
         return true;
    }
 
        return false;
}

WildPokemon:: ~WildPokemon()
{
   // cout<<"WildPokemon desrtucted"<<endl;
}






