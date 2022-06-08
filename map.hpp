#ifndef __MAP_H__
#define __MAP_H__

#include"rsdl.hpp"
#include<vector>

using namespace std;
class Grass{
    public:
        Grass(Point p1,Point p2);
        void draw_grass(Window * window);
    private:
        Point left_up;
        Point right_down;
};

class Hole{
    public:
        Hole(Point P,int r);
        Point get_center();
        void draw_Hole(Window * window);
    private:
        Point hole_center;
        int raduis;
};

class Sand_area{
    public:
        Sand_area(Point p1,Point p2);
        void draw_sand(Window * window);
        int get_x_left_up();
        int get_y_left_up();
        int get_x_right_down();
        int get_y_right_down();
    private:
        Point left_up;
        Point right_down;
    
};
#endif