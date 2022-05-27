/*
 g++ ch13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ch13 `fltk-config --ldflags --use-images` -std=c++11
 */

#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>
#include <vector>
#include <stdio.h> 
#include <stdlib.h>     
#include <time.h> 

//--------------------------------------------------------------------

using namespace Graph_lib;

//--------------------------------------------------------------------


int main()
{           
    try {
        
//1. Make an 800-by-1000 Simple_window.
        Point t1{300,50};
        Simple_window win (t1,1000,800, "My window");

//--------------------------------------------------------------------

//2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that each square is 100 by 100).

        Lines grid;
        int x_size = 800;
        int y_size = 800;
        for (int i = 100; i <= x_size; i+=100)
            {
                grid.add(Point(i, 0), Point(i, y_size));
                grid.add(Point(0, i), Point(x_size, i));
            }
            win.attach(grid);
            win.wait_for_button();
            
//--------------------------------------------------------------------
int i = 7;
while ( i > -1)
{
Image pic {Point{i * 100, i * 100},"a.jpg"};
//pic.set_mask(Point{i*100,i*100},100,100);
win.attach(pic);
win.wait_for_button();
i = i - 1;
}


}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
    }
catch (...) {
	cerr << "exception\n";
	return 2;
    }
}


