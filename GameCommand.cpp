#include "Model.h"
#include "GameCommand.h"
#include "View.h"
//#include "Input_Handling.h" For whatever reaason my IDE does not like this
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
//char in_code;

//game commands
void DoMoveCommand(Model& model, int trainer_id, Point2D p1)
{
	Trainer* test_trainer= model.GetTrainerPtr(trainer_id);
	WildPokemon* WildPokemon1= model.GetWildPokemonPtr(1);
	WildPokemon* WildPokemon2= model.GetWildPokemonPtr(2);
	if(test_trainer==0)
	{
		cout<<"Error: Please enter a valid command!"<<endl;
	}
	else
	{
		cout<<"*************************************************************************"<<endl;
		cout<<"Moving "<<(test_trainer->GetName())<<" to "<<p1;
		cout<<"*************************************************************************"<<endl;
		test_trainer->StartMoving(p1);
	}
}

void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id)
{	
	Trainer* test_trainer= model.GetTrainerPtr(trainer_id);
	if(test_trainer==0)
	{
		cout<<"Error: Please enter a valid command!"<<endl;
	}
	else
	{
		cout<<"*************************************************************************"<<endl;
		cout<<"Moving "<<(test_trainer->GetName())<<" to pokemon center "<<center_id<<endl;
		cout<<"*************************************************************************"<<endl;
		test_trainer->StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
	}
}

void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id)
{
	Trainer* test_trainer= model.GetTrainerPtr(trainer_id);
	if(test_trainer==0)
	{
		cout<<"Error: Please enter a valid command!"<<endl;
	}
	else
	{
		cout<<"*************************************************************************"<<endl;
		cout<<"Moving "<<(test_trainer->GetName())<<" to gym "<<gym_id<<endl;
		cout<<"*************************************************************************"<<endl;
		test_trainer->StartMovingToGym(model.GetPokemonGymPtr(gym_id));
	}
}

void DoStopCommand(Model& model, int trainer_id)
{
	Trainer* test_trainer= model.GetTrainerPtr(trainer_id);
	if(test_trainer==0)
	{
		cout<<"Error: Please enter a valid command!"<<endl;
	}
	else
	{
		cout<<"*************************************************************************"<<endl;
		cout<<"Stopping "<<(test_trainer->GetName())<<endl;
		cout<<"*************************************************************************"<<endl;
		test_trainer->Stop();
	}
}

void DoBattleCommand(Model& model, int trainer_id, unsigned int battles)
{
	Trainer* test_trainer= model.GetTrainerPtr(trainer_id);
	if(test_trainer==0)
	{
		cout<<"Error: Please enter a valid command!"<<endl;
	}
	else
	{
		cout<<"*************************************************************************"<<endl;
		cout<<(test_trainer->GetName())<<" is is starting to battle"<<endl;
		cout<<"*************************************************************************"<<endl;
		test_trainer->StartBattling(battles);
	}
}

void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed)
{
	Trainer* test_trainer= model.GetTrainerPtr(trainer_id);
	if(test_trainer==0)
	{
		cout<<"Error: Please enter a valid command!"<<endl;
	}
	else
	{
		cout<<"*************************************************************************"<<endl;
		cout<<"Recovering "<<(test_trainer->GetName())<<"'s Pokemon's health"<<endl;
		cout<<"*************************************************************************"<<endl;
		test_trainer->StartRecoveringHealth(potions_needed);
	}
}

void DoAdvanceCommand(Model& model, View & view)
{
	cout<<"*************************************************************************"<<endl;
	cout<<"Advancing one tick."<<endl;
	cout<<"*************************************************************************"<<endl;
	bool unsure= model.Update();
	model.ShowStatus();
	view.Clear();
	model.Display(view);
	view.Draw();
	return;
}

void DoRunCommand(Model& model, View& view)
{
	cout<<"*************************************************************************"<<endl;
	cout<<"Advancing to next event."<<endl;
	cout<<"*************************************************************************"<<endl;
	
	for (int i=0; i<5; i++)
	{
		bool LetsSee= model.Update();
		if (LetsSee)
			break;
	}
	model.ShowStatus();
	view.Clear();
	model.Display(view);
	view.Draw();
	return;
}

void NewCommand(char obj_type,int obj_id, int x_coord, int y_coord, Model& model)
{
	switch (obj_type)
	{
	case 'c':
	{	srand(time(NULL));
	    double newPotionCost=rand()%10+1;
		int newPotionCapacity= rand()%200+1;
		PokemonCenter* newC = new PokemonCenter(obj_id, newPotionCost, newPotionCapacity, Point2D(x_coord, y_coord));
		model.centerAdd(newC);
		return;
		break;
	}
	case 'g':
	{
		srand(time(NULL));
	    int newMaxBattle=rand()%30+1;
		int newHealthLost=rand()%5+1;
		double newPokeDollarCost= rand()%10+1;
		double newExperienceGain= rand()%10+1;
		PokemonGym* newG = new PokemonGym(newMaxBattle, newHealthLost, newPokeDollarCost, newExperienceGain, obj_id, Point2D(x_coord,y_coord));
		model.gymAdd(newG);
		return;
		break;
	}
	{
	case 't':
	{
		string newName;
		cout<<"Please enter new Trainer name: ";
		cin>>newName;
		srand(time(NULL));
	    int newSpeed=rand()%5+1;
		//would be cool if each new trainer got varied speeds, will work on that too
		Trainer* newT = new Trainer(newName, obj_id, obj_type, newSpeed, Point2D(x_coord, y_coord));
		model.trainerAdd(newT);
		return;
		break;
	}
	case 'w':
	{
		string newName;
		cout<<"Please enter name of new WildPokemon: ";
		cin>>newName;
		srand(time(NULL));
	    int newHealth=rand()%10+1;
		WildPokemon* newW = new WildPokemon(newName, 2, newHealth, false, obj_id, Point2D(x_coord, y_coord));
		model.wildpokemonAdd(newW);
		return;
		break;
	}
	default:
	{
		cout << "Invalid command" << endl;
		return;
		break;
	}

	}

	}
}

	void UserInput()
	{
		Model model;
		View view;
		//cout<<"HI"<<endl;
		int trainer_id;
		char obj_type;
		int obj_id;
		int gym_id;
		char in_code;
		int new_x_coord;
		int new_y_coord;
		//char in_code;
		view.Clear();
		model.Display(view);
		view.Draw();
		do
		{
			cout<<endl;
			cout << "Please enter a command code: ";
			cin >> in_code;
			try {
				//bool is1_in_trainer1;
				//bool is1_in_trainer2;
				//bool is2_in_trainer1;
				//bool is2_in_trainer2;

				switch (in_code)
				{
				case 'm':
				{
					cout << "Please enter trainer ID: ";
					cin >> trainer_id;
					Point2D p2;
					cout << "Please enter x value of location: ";
					cin >> p2.x;
					cout << "Please enter y value of location: ";
					cin >> p2.y;
					cout<<endl;
					DoMoveCommand(model, trainer_id, p2);
					break;
				}
				case 'c':
				{
					cout << "Please enter trainer ID: ";
					cin >> trainer_id;
					int center_id;
					cout << "Please enter Pokemon Center ID: ";
					cin >> center_id;
					cout<<endl;
					DoMoveToCenterCommand(model, trainer_id, center_id);
					break;
				}
				case 'g':
				{
					cout << "Please enter trainer ID: ";
					cin >> trainer_id;
					cout << "Please enter Pokemon Gym ID: ";
					cin >> gym_id;
					cout<<endl;
					DoMoveToGymCommand(model, trainer_id, gym_id);
					break;
				}
				case 's':
				{
					cout << "Please enter trainer ID: ";
					cin >> trainer_id;
					cout<<endl;
					DoStopCommand(model, trainer_id);
					break;
				}
				case 'p':
				{
					cout << "Please enter trainer ID: ";
					cin >> trainer_id;					
					unsigned int potions_needed;
					cout << "Please enter potions needed: ";
					cin >> potions_needed;
					cout<<endl;
					DoRecoverInCenterCommand(model, trainer_id, potions_needed);
					break;
				}
				case 'b':
				{
					cout << "Please enter trainer ID: ";
					cin >> trainer_id;
					unsigned int battles;
					cout << "Please enter number of battles: ";
					cin >> battles;
					cout<<endl;
					DoBattleCommand(model, trainer_id, battles);
					break;
				}
				case 'n':
				{
					cout << "Please enter type of object you wish to create: ";
					cin >> obj_type;
					while (true)
					{
						if (obj_type=='t')
							break;
						if (obj_type == 'g')
							break;
						if (obj_type == 'c')
							break;
						if (obj_type == 'w')
							break;
						cout<<"Invalid object. Please enter a valid object: ";
						cin>>obj_type;
					}
					cout << "Please enter the object's ID number (cannot be already in use): ";
					cin >> obj_id;
					cout << "Please enter x coordinate for new object: ";
					cin >> new_x_coord;
					cout << "Please enter y coordinate for the new object: ";
					cin >> new_y_coord;
					while (obj_id > 9)
					{
						cout << "Object ID must be bewteen 0 and 9 inclusive. Please re-enter an ID: ";
						cin >> obj_id;
					}
					cout<<endl;
					NewCommand(obj_type, obj_id, new_x_coord, new_y_coord, model);

				}
				case 'a':
				{
					//is1_in_trainer1= (model.GetWildPokemonPtr(1))->check_in_trainer(model.GetTrainerPtr(1));
					//is1_in_trainer2= (model.GetWildPokemonPtr(1))->check_in_trainer(model.GetTrainerPtr(2));
					//is2_in_trainer1= (model.GetWildPokemonPtr(2))->check_in_trainer(model.GetTrainerPtr(1));
					//is2_in_trainer2= (model.GetWildPokemonPtr(2))->check_in_trainer(model.GetTrainerPtr(2));
					//check for all wildpokemon
					//int n=1;
					//int m=1;
					/*while(model.GetWildPokemonPtr(n)!=NULL)
					{
						while(model.GetTrainerPtr(m)!=NULL)
						{
							model.GetWildPokemonPtr(n)->check_in_trainer(model.GetTrainerPtr(m));
							m++;
						}
						n++;
					
					}*/
					//this right now is creating an infinite loop
					//I think the issue is that I am treating this like an array when in reality this is a linked list
					//Maybe this check needs to go in the model class. 
					DoAdvanceCommand(model, view);
					break;
				}
				case 'r':
				{
					int n=1;
					int m=1;
					/*
					while(model.GetWildPokemonPtr(n)!=NULL)
					{
						while(model.GetTrainerPtr(m)!=NULL)
						{
							model.GetWildPokemonPtr(n)->check_in_trainer(model.GetTrainerPtr(m));
							m++;
						}
						n++;
					}
					*/
					DoRunCommand(model, view);
					break;
				}
				case 'q':
				{	exit(0);
				break; }
				default:
				{
					throw in_code;
					break;
				}
				}

			}
			catch (int in_code)
			{
				cout << "Invalid game command" << endl;
				exit(0);

			}
		} while (true);
	return;
}
