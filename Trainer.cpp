#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Trainer.h"
using namespace std;


//default constructor
Trainer::Trainer()
:GameObject(), speed(5)
{
	health=10;
	PokeDollars= 50;	
	experience=0;
	//cout<<"Trainer Default Constructed"<<endl;
}

//One paramter constructor
Trainer::Trainer(char in_code)
:GameObject(), speed(5)
{
	health=10;
	PokeDollars= 50;		
	experience=0;
	//cout<<"Trainer constructed"<<endl;
	state=STOPPED;
	display_code=in_code;
}

//another parameter constructor
Trainer::Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
:GameObject(in_loc, in_id, in_code), speed(in_speed), name(in_name)
{
	health=10; 	//I am just saying everyone starts with 10 health points. 
	PokeDollars= 50;	//everone starts off with 50 PokeDollars
	experience=0;
	//cout<<"Trainer construced cool"<<endl;
}

//destructor
Trainer::~Trainer()
{
	//cout<<"Trainer destructed"<<endl;
}

//public member functions:
void Trainer::StartMoving(Point2D dest)
{
	SetUpDestination(dest);
	if ((GetDistanceBetween(location, destination))==0)
		cout<<display_code<<id_num<<": I'm already there. See?"<<endl;
	else
	{
		cout<<display_code<<id_num<<": On my way."<<endl;
		if(state==AT_CENTER)//at center
		{
			current_center->RemoveOneTrainer();
		}
		if(state==IN_GYM)//at gym
		{
			current_gym->RemoveOneTrainer();
		}
		state=MOVING;

	}
	if (health==0)
	{
		cout<<display_code<<id_num<<": My pokemon have fainted. I may move but you cannot see me."<<endl;
		state=FAINTED;
	}
	return;

}

void Trainer::StartMovingToGym(PokemonGym* gym)
{
	SetUpDestination(gym->GetLocation());
	if (health==0)
	{
		cout<<display_code<<id_num<<": My Pokemon have fainted so I can't move to gym..."<<endl;
		state=FAINTED; 
	}
	else if (GetDistanceBetween(location, destination)==0)
	{
		cout<<display_code<<id_num<<": I am already at the PokemonGym!"<<endl;
	}
	else
	{
		cout<<display_code<<id_num<<": on my way to gym "<<(gym->GetId())<<"."<<endl;
		if(state==AT_CENTER)//at center
		{
			current_center->RemoveOneTrainer();
		}
		state= MOVING_TO_GYM;
		current_gym=gym;
	}
	return;
}

void Trainer::StartMovingToCenter(PokemonCenter* center)
{
	SetUpDestination(center->GetLocation());
	if (health==0)
	{
		cout<<display_code<<id_num<<": My pokemon have fainted so I should have gone to the center..."<<endl;
		state= FAINTED;
	}
	else if (GetDistanceBetween(location, destination)==0)
	{
		cout<<display_code<<id_num<<": I am already at the center!"<<endl;
	}
	else
	{
		cout<<display_code<<id_num<<": On my way to Center "<<(center->GetId())<<"."<<endl;
		if(state==IN_GYM)//at gym
		{
			current_gym->RemoveOneTrainer();
		}
		state= MOVING_TO_CENTER;
		current_center=center;
	}
	return;
}

void Trainer::StartBattling(unsigned int num_battles)
{
	if(health==0)
	{
		cout<<display_code<<id_num<<": My pokemon have fainted so no more battles for me..."<<endl;
	}

	else if (GetDistanceBetween(location, (current_gym->GetLocation()))!=0)
	{
		cout<<display_code<<id_num<<": I can only battle in a PokemonGym!"<<endl;
	}
	else if (PokeDollars-(current_gym->GetPokeDollarCost(num_battles))<0)
	{
		cout<<display_code<<id_num<<": Not enough money for battles."<<endl;
	}
	else if (!(current_gym->IsAbleToBattle(num_battles, PokeDollars, health)))
	{
		cout<<display_code<<id_num<<": I do not have enough health to battle!"<<endl;
	}
	else if ((current_gym->GetNumTrainer())==0)
	{
		cout<<display_code<<id_num<<": Cannot battle!! This PokemonGym has no more trainers to battle!"<<endl;
	}
	else if (state= IN_GYM)
	{
		state=BATTLING_IN_GYM; 
		cout<<display_code<<id_num<<": Started to battle at the PokemonGym "<<(current_gym->GetId())<<" with "<<num_battles<<" battles."<<endl;
		battles_to_buy=num_battles;
	}
	return;
}

void Trainer:: StartRecoveringHealth(unsigned int num_potions)
{
	if ((health-(current_center->GetPokeDollarCost(num_potions)))<0)
	{

		cout<<display_code<<id_num<<": Not enough money to recover health."<<endl;
	}
	else if((current_center->GetNumPotionsRemaining())==0)
	{
		cout<<display_code<<id_num<<": Cannot recover! No potion remaining in this PokemonCenter"<<endl;
	}
	else if(GetDistanceBetween(location, current_center->GetLocation()))

	{
		cout<<display_code<<id_num<<": I can only recover health at Pokemon Center!"<<endl;
	}
	else if(state== AT_CENTER)
	{
		int temp_potions= current_center->GetNumPotionsRemaining();
		state=RECOVERING_HEALTH;
		potions_to_buy=num_potions;
		PokeDollars= PokeDollars- (current_center->GetPokeDollarCost(num_potions));
		current_center->DistributePotion(num_potions);
		health= health + 5*(num_potions);
		cout<<display_code<<id_num<<": Bought "<<temp_potions-(current_center->GetNumPotionsRemaining())<<" potions at Pokemon center "<<(current_center->GetId())<<endl;
	}
	return;
}

void Trainer::Stop()
{
	state=STOPPED;
	cout<<display_code<<id_num<<": Stopping..."<<endl;
	return;
}


bool Trainer::HasFainted()
{
	if (health==0)
	{
		state=FAINTED;
		return true;
	}
	else
		return false;
}

string Trainer::GetName()
{
	return name;
}

bool Trainer::ShouldBeVisible()
{
	if (state==FAINTED)
		return false;
	else
		return true;
}


void Trainer::ShowStatus()
{
	switch(state)
	{
		case STOPPED:
			cout<<display_code<<id_num;
			cout<<" stopped"<<endl;

			break;
		case MOVING:
			cout<<display_code<<id_num;
			cout<<" moving at a speed of "<<speed<<" to destination "<<destination<<" each step of "<<delta<<endl;
			break;
		case MOVING_TO_GYM:
			cout<<display_code<<id_num;
			cout<<" heading to PokemonGym "<<(current_center->GetId())<<" at speed of "<<speed<<" at each step of "<<delta<<endl;
			break;
		case MOVING_TO_CENTER:
			cout<<display_code<<id_num;
			cout<<" heading to PokemonCenter "<<(current_center->GetId())<<" at a speed of "<<speed<<" at each steep of "<<delta<<endl;
			break;
		case IN_GYM:
			cout<<display_code<<id_num;
			cout<<" inside PokemonGym "<<(current_gym->GetId())<<endl;
			break;
		case AT_CENTER:
			cout<<display_code<<id_num;
			cout<<" inside Pokemon Center "<<(current_center->GetId())<<endl;
			break;
		case BATTLING_IN_GYM:
			cout<<display_code<<id_num;
			cout<<" battling in PokemonGym "<<(current_gym -> GetId())<<endl;
			break;
		case RECOVERING_HEALTH:	
			cout<<display_code<<id_num;
			cout<<" recovering health in PokemonCenter "<<(current_center->GetId())<<endl;
			break;
		case FAINTED:
			cout<<display_code<<id_num<<" ";
			cout<<name<<" is out of health and can't move"<<endl;
			break;
		default:
			cout<<"I have slayed"<<endl;
			break;
	}
	cout<<"Health: "<<health<<endl;
	cout<<"PokeDollars: "<<PokeDollars<<endl;
	cout<<"Experience: "<<experience<<endl<<endl;


	return;
}

bool Trainer::Update()
{
	switch(state)
	{
		case STOPPED:	
			return false;
			break;
		case MOVING:
		{
			bool Update=UpdateLocation();
			if(Update)
			{
				state=STOPPED;
				return true;
			}
			else
			{
				return false;
			}	
			break;
		}
		case MOVING_TO_GYM:
		{
			is_IN_GYM= UpdateLocation();
			if(is_IN_GYM)
			{
				state= IN_GYM;
				current_gym->AddOneTrainer();
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
		case MOVING_TO_CENTER:
		{
			is_at_center= UpdateLocation();
			if (is_at_center)
			{
				state= AT_CENTER;
				current_center->AddOneTrainer();
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
		case IN_GYM:
			return false;
			break;
		case AT_CENTER:
			return false;
			break;
		case BATTLING_IN_GYM:
		{
			unsigned int health_cost= current_gym->GetHealthCost(battles_to_buy);
			double PokeDollarCost= current_gym->GetPokeDollarCost(battles_to_buy);
			unsigned int experience_gained= current_gym-> TrainPokemon(battles_to_buy);
			health=health-health_cost;
			PokeDollars= PokeDollars-PokeDollarCost;
			experience= experience + experience_gained;
			cout<<"** "<<name<<" completed "<<battles_to_buy<<" battle(s)!**"<<endl;
			cout<<"** "<<name<<" gained "<<experience_gained<<" experience!**"<<endl;
			state= IN_GYM;
			return true;
			break;
		}
		case RECOVERING_HEALTH:
		{
			cout<<"**"<<name<<" recovered "<<5*(potions_to_buy)<<" health!!**"<<endl;
			cout<<"**"<<name<<" bought "<<potions_to_buy<<" potion(s)!**"<<endl;
			state= AT_CENTER;
			return true;
			break;
		}
		case FAINTED:
		{
			if (health==0)
				return true;
			else 
				return false;
			break;
		}
		default :
			return false;
			break;
		
	}
}

bool Trainer::UpdateLocation()
{
	double DIFFx=fabs(destination.x)-fabs(location.x);
	double DIFFy=fabs(destination.y)-fabs(location.y);
	if ((DIFFx<=(fabs(delta.x)))&&(DIFFy<=(fabs(delta.y))))
	{
		location=destination;
		cout<<"arrived"<<endl;
		return true;
	}

	else
	{
		Point2D deltaPT2D(delta.x, delta.y);
		location=location+deltaPT2D;
		cout<<"moved"<<endl;
		health--;
		PokeDollars+= GetRandomAmountOfPokeDollars();
		return false;
	}
}

void Trainer::SetUpDestination(Point2D dest)
{

	destination=dest; 
	Point2D dummyDelta=dest-location;
	Vector2D dummyVector(dummyDelta.x, dummyDelta.y);
	delta =dummyVector*(speed/GetDistanceBetween(dest, location));
	destination=dest; 

	return;
}


//Non-member (static) function
double GetRandomAmountOfPokeDollars()
{
	srand(time(NULL));
	return rand()%50+1;

}

void Trainer::AddHealthWildPokemon()
{
	health++;
}