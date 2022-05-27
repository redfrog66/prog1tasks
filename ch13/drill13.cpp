/*
 g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images` -std=c++11
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
        win.wait_for_button();

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


//3. Make the eight squares on the diagonal starting from the top left corner red (use Rectangle).

        Vector_ref<Graph_lib::Rectangle> rectangles;
        for (int i = 0; i < 8; i++)
        {
            rectangles.push_back(new Graph_lib::Rectangle{Point{i * 100, i * 100}, 100, 100});
            rectangles[rectangles.size() - 1].set_fill_color(Color::red);
            win.attach(rectangles[rectangles.size() - 1]);
        }
        win.wait_for_button();
                
        

//--------------------------------------------------------------------

/*4. Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it 
on the grid (each image covering four squares). If you can’t find an image 
that is exactly 200 by 200, use set_mask() to pick a 200-by-200 section of 
a larger image. Don’t obscure the red squares. */

Image im1 {Point(300,100),"shrok.jpg"};
im1.set_mask(Point{300,100},200,200);
win.attach(im1);
//foursquare(3,0);

Image im2 {Point{0*100,6*100},"shrok.jpg"};
im2.set_mask(Point{0*100,6*100},200,200);
win.attach(im2);
//foursquare(0,6);

Image im3 {Point{6*100,0*100},"shrok.jpg"};
im3.set_mask(Point{6*100,0*100},200,200);
win.attach(im3);
//foursquare(6,0);

win.wait_for_button();

/* 5. Add a 100-by-100 image. Have it move around from square to square 
when you click the “Next” button. Just put wait_for_button() in a loop 
with some code that picks a new square for your image */

//we know that we have 30 places where the small image can jump
int i = 0;
while (i < 10)
    {
        //random number generator
        int x = rand() % 8;
        int y = rand() % 8;
       /* if (check(x,y) = true)
            {*/
            Image moving {Point{x*100,y*100},"definietlynotshrek.jpg"};
	    moving.set_mask(Point{x*100,y*100},100,100);
	    win.attach(moving);
         //   fillbeenThere(x,y);
            win.wait_for_button();
            i += 1;
       /*     }
            else i = i; */
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



