#include "game.hpp"
#include "rsdl.hpp"
#include"map.hpp"
#include"ball.hpp"
#include"barrier.hpp"

Game ::Game(Window * window,Ball * ball,Hole * h,vector<Wall>bws,vector<water*>game_Wareas,vector<sharp_Wall*>game_SHwalls,Grass * g,vector<Sand_area*>snd){
    win=window;
    b=ball;
    hole=h;
    Ws=bws;
    water_areas=game_Wareas;
    sharp_walls=game_SHwalls;
    grass=g;
    sand_areas=snd;
}

void Game::run() {
    int win_checker=0;
    int lose_checker=0;
    game_running = true;
    int checker;
    while(game_running) {
        process_events();
        checker=update_objects();
        if(checker==0){
            win_checker+=1;
            break;
        }
        else if (checker==-1){
            win_checker-=1;
            break;
        }
        draw_screen();
        delay(50);
    }
    if(win_checker>0){
        win->show_text("You Won :D", Point(100, 100),BLACK,"OpenSans.ttf",50);
        delay(500);
        win->update_screen();        
    }
    else if (win_checker<0){
        win->show_text("Game Over :(", Point(100, 100),BLACK,"OpenSans.ttf",50);
        delay(500);
        win->update_screen();  
    }
}
vector<int> Game:: calculate_d(){
    int x1=d_start.x;
    int y1=d_start.y;
    int x2=d_end.x;
    int y2=d_end.y;
    vector<int>d;
    d.push_back(x1-x2);
    d.push_back(y1-y2);
    return d;
}

void Game::process_events() {
    while(win->has_pending_event()) {
        Event event = win->poll_for_event();
        switch (event.get_type()) {
            case Event::QUIT:
                
                exit(0);
                break;
            case Event::LCLICK:
            
                d_start=get_current_mouse_position();
                break;
            case Event::LRELEASE:
                d_end=get_current_mouse_position();
                vector<int>d=calculate_d();
                b->calculate_movement(d);
                movement_num+=1;
                break;
        }
    }
}
void Game::draw_screen() {
    win->clear();
    grass->draw_grass(win);
    hole->draw_Hole(win);
    for(int j=0;j<water_areas.size();j++){
        water_areas[j]->draw_water_area(win);
    }
    for(int k=0;k<sharp_walls.size();k++){
        sharp_walls[k]->draw_sharp_wall(win);
    }
    for(int i=0;i<Ws.size();i++){
        Ws[i].draw_Wall(win);
    }
    for(int l=0;l<sand_areas.size();l++){
        sand_areas[l]->draw_sand(win);
    }
    b->draw_ball(win);
    win->show_text(to_string(movement_num), Point(600, 50),BLACK,"OpenSans.ttf",50);  
    win->update_screen();
}

int Game::update_objects() {
    int ball_update=b->update(win,hole,water_areas,sharp_walls,Ws,sand_areas);
    if(ball_update==0){
        return 0;
    }
    else if (ball_update==-1)
        return -1;
    else
        return 1;    
}