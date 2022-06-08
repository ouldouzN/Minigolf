#include"rsdl.hpp"
#include<iostream>
#include <typeinfo>
#define MaX_INIT_SPEED 25
#define THROW_RADUIS 80
#define delay_duration 1
#define MIO 1
#include"ball.hpp"
#include"map.hpp"
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

Ball :: Ball(Point P,int R){
    ball_center=P;
    raduis=R;
}
void Ball::draw_ball(Window * window){
    window->fill_circle(ball_center,10,WHITE);
}

float Ball :: calculate_d_size(vector<int>d){
    return sqrt(d[0]*d[0]+d[1]*d[1]);
}
vector<int> Ball:: calculate_smaller_v(){
    vector<int>V;
    V.push_back(d[0]*MaX_INIT_SPEED/THROW_RADUIS);
    V.push_back(d[1]*MaX_INIT_SPEED/THROW_RADUIS);
    return V;
}
vector<int> Ball:: calculate_bigger_v(float d_size){
    vector<int>V;
    V.push_back(d[0]*MaX_INIT_SPEED/d_size);
    V.push_back(d[1]*MaX_INIT_SPEED/d_size);
    return V;
}
void Ball:: calculate_end_point(){
    int vec_size=ball_positions.size();
    Point starting=ball_positions[vec_size-1];
    int new_x=starting.x+v[0]*delay_duration;
    int new_y=starting.y+v[1]*delay_duration;
    Point ending;
    ending.x=new_x;
    ending.y=new_y;
    ball_positions.push_back(ending);
}
void Ball :: calculate_movement(vector<int>dd){
    d=dd;
    float d_size=calculate_d_size(dd);
    if(d_size <= THROW_RADUIS){
        v=calculate_smaller_v();
    }    
    else{
        v=calculate_bigger_v(d_size);
    }
}
int Ball:: get_last_possition_x(){
    int num=ball_positions.size();
    return ball_positions[num-1].x;
}
void Ball::set_location_x(int new_x){
    ball_center.x=new_x;
}
void Ball::set_location_y(int new_y){
    ball_center.y=new_y;
}
void Ball::set_v_x(){
    v[0]=v[0]*(-1);
}
void Ball::set_v_y(){
    v[1]=v[1]*(-1);
}
float Ball::get_center_x(){
    return ball_center.x;
}
float Ball::get_center_y(){
    return ball_center.y;
}
int Ball:: wining_check(Hole * hole){
    Point hole_center=hole->get_center();
    if(ball_center.x>=hole_center.x-10 && ball_center.x<=hole_center.x+10 && 
    ball_center.y>=hole_center.y-10 && ball_center.y<=hole_center.y+10){
        return 0;
    }
    return 1;
        
}
int Ball:: clashig_water(vector<water *> water_area){
    for(int i=0;i<water_area.size();i++){
        if(water_area[i]->get_x_left_up()<= ball_center.x && water_area[i]->get_x_right_down()>=ball_center.x &&
        water_area[i]->get_y_left_up()<=ball_center.y && water_area[i]->get_y_right_down() >= ball_center.y){
            return 1;
        }
    }
    
}
int Ball:: clashig_sharp_wall(vector<sharp_Wall *>shw){
    for(int i=0;i<shw.size();i++){
        if(shw[i]->get_x_left_up()<= ball_center.x && shw[i]->get_x_right_down()>=ball_center.x &&
        shw[i]->get_y_left_up()<=ball_center.y && shw[i]->get_y_right_down() >= ball_center.y){
            return 1;
        }
    }
    
}
void Ball :: loosing_check(vector<water *> water_area,vector<sharp_Wall *>shw,int &checker){
    int water_clash=clashig_water(water_area);
    int sharp_wall_clash=clashig_sharp_wall(shw);
    if (water_clash==1 || sharp_wall_clash==1)
        checker=-1;

}
void Ball :: clashing_right_wall(Point previous,Point new_point,Wall this_wall){
    int do_sth;
    if( previous.y>this_wall.get_y_right_down() && new_point.y>this_wall.get_y_right_down())
        do_sth=0;
    else if(previous.y<this_wall.get_y_left_up() && new_point.y<this_wall.get_y_left_up())
        do_sth=0;
    else {
        if (new_point.x+raduis>this_wall.get_x_left_up()){
            ball_center.x=2*this_wall.get_x_left_up()-new_point.x;
            v[0]=(-1)*v[0];
        }
    }
}
void Ball :: clashing_left_wall(Point previous,Point new_point,Wall this_wall){
    int do_sth;
    if( previous.y>this_wall.get_y_right_down() && new_point.y>this_wall.get_y_right_down())
        do_sth=0;
    else if(previous.y<this_wall.get_y_left_up() && new_point.y<this_wall.get_y_left_up())
        do_sth=0;
    else {
        if (new_point.x-raduis<this_wall.get_x_right_down()){
            ball_center.x=2*this_wall.get_x_right_down()-new_point.x;
            v[0]=(-1)*v[0];
        }
    }
}
void Ball :: clashing_up_wall(Point previous,Point new_point,Wall this_wall){
    int do_sth=0;
    if( previous.x>this_wall.get_x_right_down() && new_point.x>this_wall.get_x_right_down())
        do_sth=0;
    else if(previous.x<this_wall.get_x_left_up() && new_point.x<this_wall.get_x_left_up())
        do_sth=0;
    else {
        if (new_point.y+raduis>this_wall.get_y_right_down()){
            ball_center.y=2*this_wall.get_y_right_down()-new_point.y;
            v[1]=(-1)*v[1];
        }
    }
}
void Ball :: clashing_down_wall(Point previous,Point new_point,Wall this_wall){
    int do_sth;
    if( previous.x>this_wall.get_x_right_down() && new_point.x>this_wall.get_x_right_down())
        do_sth=0;
    else if(previous.x<this_wall.get_x_left_up() && new_point.x<this_wall.get_x_left_up())
        do_sth=0;
    else {
        if (new_point.y-raduis<this_wall.get_y_left_up()){
            ball_center.y=2*this_wall.get_y_left_up()-new_point.y;
            v[1]=(-1)*v[1];
        }
    }
}


void Ball::clashing_walls(Point previos,Point new_point,vector<Wall>Ws){
    for(int i=0;i<Ws.size();i++){
        if(previos.x<Ws[i].get_x_left_up()){
            clashing_right_wall(previos,new_point,Ws[i]);
        }
        if(previos.x>Ws[i].get_x_right_down())
            clashing_left_wall(previos,new_point,Ws[i]);
        if(previos.y<Ws[i].get_y_right_down())
            clashing_up_wall(previos,new_point,Ws[i]);
        if(previos.y > Ws[i].get_y_left_up())
            clashing_down_wall(previos,new_point,Ws[i]);
    }
}
void Ball :: calculate_normal_a(){
    a[0]=(v[0]/sqrt(v[0]*v[0]+v[1]*v[1]))*MIO;
    a[1]=(v[1]/sqrt(v[0]*v[0]+v[1]*v[1]))*MIO;
}
void Ball :: calculate_sand_a(){
    a[0]=(v[0]/sqrt(v[0]*v[0]+v[1]*v[1]))*MIO*4;
    a[1]=(v[1]/sqrt(v[0]*v[0]+v[1]*v[1]))*MIO*4;
}

void Ball :: calculate_v(){
    if(v[0]!=0 && ((v[0]-a[0])*v[0])>0)
        v[0]=v[0]-a[0];
    else
        v[0]=0;
    
    if(v[1]!=0 && ((v[1]-a[1])*v[1])>0)
        v[1]=v[1]-a[1];
    else
        v[1]=0;
    
}
void Ball::calculate_a(vector<Sand_area*>snd){
    int checker=0;
    for(int i=0;i<snd.size();i++){
        if(snd[i]->get_x_left_up()<= ball_center.x && snd[i]->get_x_right_down()>=ball_center.x &&
        snd[i]->get_y_left_up()<=ball_center.y && snd[i]->get_y_right_down() >= ball_center.y){
            checker=1;
        }
    }
    if(checker==1)
        calculate_sand_a();
    else
        calculate_normal_a();

    
}
int Ball :: update(Window * window,Hole * hole,vector<water * >water_area,vector<sharp_Wall *>shw,vector<Wall>Ws,vector<Sand_area*>snd){   
    int checker=1;
    Point prev_position=ball_center;
    int new_x=ball_center.x+v[0];
    int new_y=ball_center.y+v[1];
    ball_center=Point(new_x,new_y);
    checker=wining_check(hole);
    loosing_check(water_area,shw,checker);
    clashing_walls(prev_position,ball_center,Ws);
    window->fill_circle(ball_center,10,WHITE);
    window->update_screen();
    calculate_a(snd);
    calculate_v();
    return checker;
}
