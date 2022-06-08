#ifndef _GAME_HPP
#define _GAME_HPP
#include<vector>
#include"rsdl.hpp"
#include"ball.hpp"
#include"map.hpp"
#include"barrier.hpp"

using namespace std;


class Game {
public:
    Game(Window * window,Ball * ball,Hole * h,vector<Wall>bws,vector<water*>game_Wareas,vector<sharp_Wall*>game_SHwalls,Grass * g,vector<Sand_area*>snd);
    void run();
    vector<int> calculate_d();
private:
    int movement_num=0;
    void process_events();
    void draw_screen();
    int update_objects();
    Point d_start;
    Point d_end;
    bool game_running;
    Window* win;
    Ball * b;
    Hole * hole;
    vector<Wall>Ws;
    vector<water *>water_areas;
    vector<sharp_Wall *>sharp_walls;
    vector<Sand_area *>sand_areas;
    Grass * grass;
};

#endif
