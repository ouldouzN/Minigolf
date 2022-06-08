#ifndef __BALL_H__
#define __BALL_H__


#include"map.hpp"
#include"barrier.hpp"
#include"rsdl.hpp"

#include<iostream>
#include<vector>


using namespace std;

class water ;
class sharp_Wall;
class Wall;

class Ball{
public:
    Ball(Point P,int R);
    void draw_ball(Window * window);
    float calculate_d_size(vector<int>d);
    void calculate_new_values();
    vector<int> calculate_smaller_v();
    vector<int> calculate_bigger_v(float d_size);
    void calculate_movement(vector<int>dd);
    void calculate_end_point();
    void analyze_movement();
    int get_d();
    int get_last_possition_x();
    void set_location_x(int new_x);
    void set_location_y(int new_y);
    void set_v_x();
    void set_v_y();
    float get_center_x();
    float get_center_y();
    int clashig_water(vector<water *>water_area);
    int clashig_sharp_wall(vector<sharp_Wall *>shw);
    void clashing_right_wall(Point previous,Point new_point,Wall this_wall);
    void clashing_left_wall(Point previous,Point new_point,Wall this_wall);
    void clashing_up_wall(Point previous,Point new_point,Wall this_wall);
    void clashing_down_wall(Point previous,Point new_point,Wall this_wall);
    void clashing_walls(Point previos,Point new_point,vector<Wall>Ws);
    void loosing_check(vector<water *>water_area,vector<sharp_Wall* >shw,int &checker);
    void calculate_v();
    void calculate_a(vector<Sand_area*>snd);
    void calculate_sand_a();
    void calculate_normal_a();
    int update(Window * window,Hole * hole,vector<water* > water_area,vector<sharp_Wall * >shw,vector<Wall>Ws,vector<Sand_area*>sand_areas);
    int wining_check(Hole * hole);
private:
    Point  ball_center;
    int raduis;
    vector<float>a={0,0};
    vector<int>d={0,0};
    vector<int>v={0,0};
    vector<Point>ball_positions={Point(100,200)};
};

#endif