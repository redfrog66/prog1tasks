//  g++ olimp.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o olimp `fltk-config --ldflags --use-images` -std=c++11

#include "Graph.h"
#include "Simple_window.h"

#include <iostream>

using namespace Graph_lib;

int main()
{
	try{
	//getting a window to display our circles
	
	Simple_window w {Point{100,100},700,600, "Olimp"};
	
//----------------------------------------------------------------

	//the five circles
	//first row - 3 circles
	Vector_ref<Circle> cr;
	int dist = 200;
	for (int i = 0; i < 3; i++)
		{
		cr.push_back(new Circle(Point{dist,200},100));
		cr[i].set_color(i);
		w.attach(cr[i]);
		dist = dist + 150;
		}
	
	//second row - 2 circles	
	Vector_ref<Circle> cr2;
	int dist2 = 275;
	for (int i = 0; i < 2; i++)
		{
		cr2.push_back(new Circle(Point{dist2,300},100));
		cr2[i].set_color(i);
		w.attach(cr2[i]);
		dist2 = dist2 + 150;
		}
	
	w.wait_for_button();
	

	}

catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
    }
catch (...) {
	cerr << "error\n";
	return 1;
	}


}
