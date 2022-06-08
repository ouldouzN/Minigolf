#include"rsdl.hpp"
#include"map.hpp"
#include<vector>

using namespace std;

Grass:: Grass(Point p1,Point p2){
    left_up=p1;
    right_down=p2;
}
void Grass :: draw_grass(Window * window){
    Rectangle grass_rect(left_up,right_down);
    window->fill_rect(grass_rect,GREEN);
}
Sand_area:: Sand_area(Point p1,Point p2){
    left_up=p1;
    right_down=p2;
}
void Sand_area :: draw_sand(Window * window){
    Rectangle sand_rect(left_up,right_down);
    window->fill_rect(sand_rect,YELLOW);
}
int Sand_area ::get_x_left_up(){
    return left_up.x;
}
int Sand_area ::get_y_left_up(){
    return left_up.y;
}
int Sand_area ::get_x_right_down(){
    return right_down.x;
}
int Sand_area::get_y_right_down(){
    return right_down.y;
}
Hole ::Hole (Point P1,int R){
    hole_center=P1;
    raduis=R;
}
void Hole:: draw_Hole(Window* window){
    window->fill_circle(hole_center,raduis,BLACK);
}
Point Hole:: get_center(){
    return hole_center;
}