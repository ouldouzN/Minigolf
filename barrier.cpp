#include"rsdl.hpp"
#include"barrier.hpp"
#include<vector>

using namespace std;

Wall :: Wall(int x1,int y1,int x2,int y2){
    left_up=Point(x1,y1);
    right_down=Point(x2,y2);

}
void Wall:: draw_Wall(Window * window){
    Rectangle grass_rect(left_up,right_down);
    window->fill_rect(grass_rect,BLACK);
}
int Wall ::get_x_left_up(){
    return left_up.x;
}
int Wall ::get_y_left_up(){
    return left_up.y;
}
int Wall ::get_x_right_down(){
    return right_down.x;
}
int Wall::get_y_right_down(){
    return right_down.y;
}
int water ::get_x_left_up(){
    return left_up.x;
}
int water ::get_y_left_up(){
    return left_up.y;
}
int water ::get_x_right_down(){
    return right_down.x;
}
int water ::get_y_right_down(){
    return right_down.y;
}
water :: water(int x1,int y1,int x2,int y2){
    left_up=Point(x1,y1);
    right_down=Point(x2,y2);

}

void water :: draw_water_area(Window* window){
    Rectangle grass_rect(left_up,right_down);
    window->fill_rect(grass_rect,CYAN);
}

sharp_Wall :: sharp_Wall(int x1,int y1,int x2,int y2){
    left_up=Point(x1,y1);
    right_down=Point(x2,y2);
}

void sharp_Wall :: draw_sharp_wall(Window* window){
    Rectangle grass_rect(left_up,right_down);
    window->fill_rect(grass_rect,RED);
}

int sharp_Wall ::get_x_left_up(){
    return left_up.x;
}
int sharp_Wall ::get_y_left_up(){
    return left_up.y;
}
int sharp_Wall ::get_x_right_down(){
    return right_down.x;
}
int sharp_Wall ::get_y_right_down(){
    return right_down.y;
}
