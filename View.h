#ifndef VIEW_H
#define VIEW_H

#include "Point2D.h"
#include "Vector2D.h"
#include "Trainer.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "GameObject.h"
#include "WildPokemon.h"
using namespace std;
#include <iostream>
const int view_maxsize=20;	//maximum size of grid array

class View
{
	//private members
	private:
		int size;	//current size of the grid to be displayed
		double scale;	//distance represented by each cell of the grid
		Point2D origin;	//the coordinates of the lower left-hand corner of the grid
		char grid[view_maxsize][view_maxsize][2];	//An aray to hold the charcters that make up the display grid
		bool GetSubscripts(int &out_x, int &out_y, Point2D location); //calculates column and row subscripts of  the grid array that correspond to the supplied location
		
	//public members
	public:
		View();
		void Clear();
		void Plot(GameObject * ptr); //plots the pointed-to object in the proper cell of the grid.
		void Draw(); //outputs the grid array
		~View();
};

#endif
