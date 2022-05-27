/*
g++ drill13_2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13_2 `fltk-config --ldflags --use-images` -std=c++11
*/

#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>
#include <vector> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//---------------------------------------------------------------------

using namespace Graph_lib;

//---------------------------------------------------------------------

struct occupied
{
	int ax; //x coordinates
	int ay; //y coordinates
};
//vector created to store the coordinates of the used objects
vector <occupied> Taken;

//fill Taken vector
void fill_Taken(int x, int y)
{
Taken.push_back(x,y);
}

//vector created to store the coordinates of the places where the moving picture has been
vector <occupied> beenThere;

//fill beenThere vector
void fill_beenThere (int x, int y)
{
beenThere.push_back(x,y);
}

//check if the generated coordinate is in Taken or beenThere
bool check(int x, int y)
{
int takencheck = 0;
for (int i = 0; i < Taken.size(); i++)
	if (Taken[i].ax = x & Taken[i].ay = y) takencheck = 1;
	else takencheck = 2;
	
int beentherecheck = 0;
for (int i = 0; i < beenThere.size(); i++)
	if (beenThere[i].ax = x & beenThere[i].ay = y) beentherecheck = 1;
	else beentherecheck = 2;
	
if (takencheck = 1 || beentherecheck = 1) return true;
	else return false;
}



