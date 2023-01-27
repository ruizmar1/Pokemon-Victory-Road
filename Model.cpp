#include "Model.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//constructor
Model::Model()
:time(0)
{
	//pointers to objects, we will intialize 6 objects total.
	//complier doesn't like me making an array of game objects since game objects is an abstract claa. I took it out and worked around it
	/*trainer_ptrs= new Trainer[10];
	center_ptrs= new PokemonCenter[10];
	gym_ptrs= new PokemonGym[10];
	wildpokemon_ptrs= new WildPokemon[10];*/

	//linked list

	//initializing some objects to go in the linked lists
	Trainer* Ash= new Trainer("Ash", 1, 'T', 1, Point2D(5,1));
	Trainer* Mitsy= new Trainer("Mitsy", 2, 'T', 2, Point2D(10,1));
	PokemonCenter* C1= new PokemonCenter(1, 1.0, 100, Point2D(1, 8));
	PokemonCenter* C2= new PokemonCenter(2, 2.0, 200, Point2D(8,8));
	PokemonGym* G1= new PokemonGym(10, 1, 2.0, 3, 1, Point2D(0,0));
	PokemonGym* G2= new PokemonGym(20, 5, 7.5, 4, 2, Point2D(5,5));
	WildPokemon* W1= new WildPokemon("WildPokemon1", 5, 2, false, 1, Point2D(4,8));
	WildPokemon* W2= new WildPokemon("WildPokemon2", 5, 2, false, 2, Point2D(15,15));


	/*//storing Trainers in trainers_ptrs array
	trainer_ptrs[0]= *Ash;
	trainer_ptrs[1]= *Mitsy;
	//storing PokemonCenters in center_ptrs array
	center_ptrs[0]= *C1;
	center_ptrs[1]= *C2;
	//storing PokemonGyms in gym_ptrs array
	gym_ptrs[0]= *G1;
	gym_ptrs[1]= *G2;
	//storing WildPokemon in wildpokemon_ptrs array
	wildpokemon_ptrs[0]= *W1;
	wildpokemon_ptrs[1]= *W2;
*/


 //filling my linked lists
//game object linked list
	object_pointers.push_back(Ash);
	object_pointers.push_back(Mitsy);
	object_pointers.push_back(C1);
	object_pointers.push_back(C2);
	object_pointers.push_back(G1);
	object_pointers.push_back(G2);
	object_pointers.push_back(W1);
	object_pointers.push_back(W2);

//active pointers list
	active_pointers.push_back(Ash);
	active_pointers.push_back(Mitsy);
	active_pointers.push_back(C1);
	active_pointers.push_back(C2);
	active_pointers.push_back(G1);
	active_pointers.push_back(G2);
	active_pointers.push_back(W1);
	active_pointers.push_back(W2);

// trainers list
	trainer_pointers.push_back(Ash);
	trainer_pointers.push_back(Mitsy);

//Pokemon Center List
	center_pointers.push_back(C1);
	center_pointers.push_back(C2);

//Pokemon gym list
	gym_pointers.push_back(G1);
	gym_pointers.push_back(G2);

//Wildpokemon List
	wildpokemon_pointers.push_back(W1);
	wildpokemon_pointers.push_back(W2);

	//cout<<"Model default constructed"<<endl;
}

//destructor
Model::~Model()
{
	//cout<<"Model destruted"<<endl;
}


//Accessor functions

Trainer* Model:: GetTrainerPtr(int id)
{
	t1= trainer_pointers.begin();
	for ( int i= 0; i<(id-1); i++)
		t1++;
	return *t1;
	/*if ((id<=(trainer_pointers.size()))&&(id>0))
	{
		return (trainer_ptrs+(id-1));	
	}
	else
		return 0;*/	
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
	t2= center_pointers.begin();
	for ( int i= 0; i<(id-1); i++)
		t2++;
	return *t2;
	/*if ((id<center_pointers.size())&&(id>0))
	{
		return (center_ptrs+(id-1));	
	}
	else
		return 0;	*/
}

PokemonGym* Model:: GetPokemonGymPtr(int id)
{
	t3= gym_pointers.begin();
	for ( int i= 0; i<(id-1); i++)
		t3++;
	return *t3;
	/*if ((id<=gym_pointers.size())&&(id>0))
	{
		return (gym_ptrs+(id-1));	
	}
	else
		return 0;	*/
}

GameObject* Model:: GetGameObjectPtr(int id)
{
	t4= object_pointers.begin();
	for ( int i= 0; i<(id-1); i++)
		t4++;
	return *t4;
	/*if ((id<=wildpokemon_pointers.size())&&(id>0))
	{
		return (wildpokemon_ptrs+(id-1));	
	}
	else
		return 0;	*/
}

GameObject* Model:: GetActiveObjectPtr(int id)
{
	t6=active_pointers.begin();
	for ( int i= 0; i<(id-1); i++)
		t6++;
	return *t6;
}

WildPokemon* Model:: GetWildPokemonPtr(int id)
{
	t5= wildpokemon_pointers.begin();
	for ( int i= 0; i<(id-1); i++)
		t5++;
	return *t5;
	/*if ((id<=wildpokemon_pointers.size())&&(id>0))
	{
		return (wildpokemon_ptrs+(id-1));	
	}
	else
		return 0;	*/
}

int Model:: getTime()
{
	return time;
}

bool Model::Update()
{
	time++;
	bool maybe_true1;
	bool maybe_true2;
	bool maybe_true3;
	bool maybe_true4;
	bool maybe_true5;
	int maybe=0;
	//First going to run an update on all objects and see if I get a true
	/*for (int i1=0; i1<trainer_pointers.size(); i1++)
	{
		maybe_true1= (trainer_ptrs+i1)->Update();
		if (maybe_true1)
			maybe++;
	}
	for(int i2=0; i2<center_pointers.size(); i2++)
	{
		maybe_true2=(center_ptrs+i2)->Update();
		if (maybe_true2)
			maybe++;
	}
	for (int i3=0; i3<gym_pointers.size(); i3++)
	{
		maybe_true3= (gym_ptrs+i3)->Update();
		if (maybe_true3)
			maybe++;
	}
	for (int i4=0; i4<wildpokemon_pointers.size(); i4++)
	{
		maybe_true4= (wildpokemon_ptrs+i4)->Update();
		if (maybe_true4)
			maybe++;
	}*/

	t1= trainer_pointers.begin();
	t2= center_pointers.begin();
	t3= gym_pointers.begin();
	t4= object_pointers.begin();
	t5= wildpokemon_pointers.begin();
	t6= active_pointers.begin();
	for (t1= trainer_pointers.begin(); t1 != trainer_pointers.end(); ++t1)
	{
		maybe_true1=(*t1)->Update();
		if (maybe_true1)
			maybe++;
	}
	for (t2 = center_pointers.begin(); t2 != center_pointers.end(); ++t2)
	{
		maybe_true2 = (*t2)->Update();
		if (maybe_true2)
			maybe++;
	}
	for (t3 = gym_pointers.begin(); t3 != gym_pointers.end(); ++t3)
	{
		maybe_true3 = (*t3)->Update();
		if (maybe_true3)
			maybe++;
	}
	for (t5 = wildpokemon_pointers.begin(); t5 != wildpokemon_pointers.end(); ++t5)
	{
		maybe_true5 = (*t5)->Update();
		if (maybe_true5)
			maybe++;
	}


	//checking to see if there are no battles remaining in any gym
	int gym_wins=0;
	for (t3= gym_pointers.begin(); t3!=gym_pointers.end(); ++t3)
	{
		gym_wins+= (*t3)->GetNumBattlesRemaining();
	}
	if (gym_wins==0)
	{
		cout<<"GAME OVER: You Win! All batttles done!"<<endl;
		exit(0);
	}

	//checking to see if all trainers have fainted
	int trainers_fainted=0;
	bool fainted_maybe;
	for(t1= trainer_pointers.begin(); t1!=trainer_pointers.end(); ++t1)
	{
		if ((*t1)->HasFainted())
		{
			trainers_fainted++;
			cout<<(*t1)->GetName()<<" has been removed from active list"<<endl;
			//trainer_pointers.erase(t1);
		}
	}

	//checking to see if wildpokemon are dead
	int wildpokemon_fainted=0;
	bool dead_maybe1;
	for(t5= wildpokemon_pointers.begin(); t5!=wildpokemon_pointers.end(); ++t5)
	{
		dead_maybe1= (*t5)->isAlive();
		if (!dead_maybe1)
		{
			wildpokemon_fainted++;
			cout<<"W"<<(*t5)->GetId()<<" has been removed rom active list"<<endl;
			wildpokemon_pointers.erase(t5);
		}
	}

	if(trainers_fainted==trainer_pointers.size())
	{
		cout<<"GAME OVER: You lose! All of your Trainers' pokemon have fainted!"<<endl;
		exit(0);
	} 

	wildpokemonchecker();

	if (maybe)
		return true;
	else
		return false;
}

void Model:: Display(View& view)
{
	for (t1= trainer_pointers.begin(); t1 !=trainer_pointers.end(); ++t1)
	{
		if(!((*t1)->HasFainted()))
		{
			view.Plot(*t1);
		}
	}
	for (t2= center_pointers.begin(); t2 != center_pointers.end(); ++t2)
	{
		view.Plot(*t2);
	}
	for (t3= gym_pointers.begin(); t3 != gym_pointers.end(); ++t3)
	{
		view.Plot(*t3);
	}
	for (t5= wildpokemon_pointers.begin(); t5 != wildpokemon_pointers.end(); ++t5)
	{
		view.Plot(*t5);
	}
}

void Model::ShowStatus()
{
for (t1= trainer_pointers.begin(); t1 !=trainer_pointers.end(); ++t1)
	{
		(*t1)->ShowStatus();
	}
	for (t2= center_pointers.begin(); t2 != center_pointers.end(); ++t2)
	{
		(*t2)->ShowStatus();
	}
	for (t3= gym_pointers.begin(); t3 != gym_pointers.end(); ++t3)
	{
		(*t3)->ShowStatus();
	}
	for (t5= wildpokemon_pointers.begin(); t5 != wildpokemon_pointers.end(); ++t5)
	{
		(*t5)->ShowStatus();
	}
}	




void Model::centerAdd(PokemonCenter* c)
{
	center_pointers.push_back(c);
}

void Model::gymAdd(PokemonGym* g)
{
	gym_pointers.push_back(g);
}

void Model::trainerAdd(Trainer* t)
{
	trainer_pointers.push_back(t);
}

void Model::wildpokemonAdd(WildPokemon* w)
{
	wildpokemon_pointers.push_back(w);
}

void Model::wildpokemonchecker()
{
	//right now what we have are two linked lists, one of wild pokemon and one of trainers
	//we want to check which trainer is in which wild pokemon for each wild pokemon, which is a function of the wildpokemon. 
	t7= wildpokemon_pointers.begin();
	t8= trainer_pointers.begin();
	bool isInTrainer;
	//for (int i=0; i<wildpokemon_pointers.size(); i++)
	for (t7 = wildpokemon_pointers.begin(); t7 != wildpokemon_pointers.end(); ++t7)
	{
		//for(int j=0; j<trainer_pointers.size();j++)
        for (t8 = trainer_pointers.begin(); t8 != trainer_pointers.end(); ++t8)
		{
			isInTrainer= (*t7)->check_in_trainer(*t8);
		}
	}

}
















