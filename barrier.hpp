#ifndef __BARRIER_H__
#define __BARRIER_H__

#include"ball.hpp"
#include"rsdl.hpp"

#include"map.hpp"
#include<vector>

using namespace std;
class water {
    public:
        water(int x1,int y1,int x2,int y2);
        void draw_water_area(Window * window);
        
        int get_x_left_up();
        int get_y_left_up();
        int get_x_right_down();
        int get_y_right_down();
        
    private:
        Point  left_up;
        Point  right_down;
        

};
class sharp_Wall {
    public:
        sharp_Wall(int x1,int y1,int x2,int y2);
        void draw_sharp_wall(Window * window);
        
        int get_x_left_up();
        int get_y_left_up();
        int get_x_right_down();
        int get_y_right_down();
        
    private:
        Point  left_up;
        Point  right_down;
        
};
class Wall{
    public:
        Wall(int x1,int y1,int x2,int y2);
        void draw_Wall(Window * window);
        int get_x_left_up();
        int get_y_left_up();
        int get_x_right_down();
        int get_y_right_down();
    private:
        Point  left_up;
        Point  right_down;

};

#endif