#include "View.h"
#include <iostream>
using namespace std;

//constructor
View:: View()
:size(16), scale(2), origin(Point2D(0,0))
{
	//cout<<"View Default constructed"<<endl;
}

void View::Clear()
{
	//cout<<"did I do Clear?"<<endl;
	for (int j=0; j<size; j++)
	{
		for (int i=0; i<size; i++)
		{
			grid[i][j][0]= '.';
			grid[i][j][1]= ' ';
			//cout<<"cool cool"<<endl;
		}
	}

		//cout<<"did I do Clear?"<<endl;
	return;
}

void View::Plot(GameObject* ptr)
{
	int x;
	int y;
	char* array_ptr= new char[2];
	ptr->DrawSelf(array_ptr);
	if( GetSubscripts(x, y, ptr->GetLocation()))
	{
		if(grid[x][y][0]!='.')
		{
			grid[x][y][0]='*';
			grid[x][y][1]=' ';
		}
		else
		{
			grid[x][y][0]=*array_ptr;
			grid[x][y][1]=*(array_ptr+1);
		}
	}
	
	return;
	
}

void View::Draw()
{
    for (int j = size-1; j >= -1; j--)
    {
        for (int i = -1; i <= size-1; i++)
        {
            //grid axis
            if (i == -1 && j%2 == 0)
            {
                cout << j*2;
                if (j/5 == 0)
                {
                    cout << " ";
                }
            }
            else if (i == -1 && j%2 != 0)
            {
                cout << "  ";
            }
            else if (j == -1 && i%2 == 0)
            {
                cout << i*2;
                if (i/5 == 0)
                {
                    cout << " ";
                }
                cout << "  ";
            }
            //draw objects
            if (i >= 0 && j >=0)
            {
               cout << (grid[i][j][0]) << (grid[i][j][1]);//>> this is just printing out garabage for me and I can't figure out why
		//cout<<'.'<<' '; using this as a placeholder until I can figure out why it is not working
            }
        }
        cout << endl;
    }
	return;
}

bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
	int x_distance=int(location.x-origin.x);
	int y_distance=int(location.y-origin.y);
	out_x= (x_distance)/scale;
	out_y= (y_distance)/scale;
	if((x_distance>size) || (y_distance>size))
	{
		cout<<"An object is out of diplay"<<endl;
		return false;
	}
	else
		return true;
}

//destructor
View::~View()
{
	//cout<<"view destructed"<<endl;
}











