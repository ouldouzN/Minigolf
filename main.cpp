#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include"barrier.hpp"
#include"rsdl.hpp"
#include"ball.hpp"
#include"map.hpp"
#include"game.hpp"

using namespace std;

vector<string>getting_map(){
    vector<string>map_commands;
    std::ifstream file("map.txt");
    std::string str;
    while (std::getline(file, str)) {
        map_commands.push_back(str);
    }
    return map_commands;
}

vector<vector<string>> splitting_map(vector<string>map_commands){
    vector<vector<string>>spilitted_commands;
    for(int i=0;i<map_commands.size();i++){
        vector<string>temp_vec;
        std ::string temp;
        stringstream X(map_commands[i]);
        while (getline(X, temp, ' ')) {
            temp_vec.push_back(temp);
        }
        spilitted_commands.push_back(temp_vec);
    }
    return spilitted_commands;
}

void discovering_components(vector<vector<string>>splitted_commands){
    vector<Wall>game_walls;
    vector<water *>game_Wareas;
    vector<sharp_Wall*>game_SHwalls;
    vector<Sand_area *>sand_areas;
    Window * wnd;
    Grass *g;
    Ball * ball;
    Hole * h;
    string temp;
    
    for (int i=0;i<splitted_commands.size();i++){
        if(splitted_commands[i][0]=="window_size"){
            wnd=new Window(stoi(splitted_commands[i][1]),stoi(splitted_commands[i][2]),"RSDL Demo");
        }
        if(splitted_commands[i][0]=="grass_area"){
            Point P1;
            Point P2;
            P1.x=stoi(splitted_commands[i][1]);
            P1.y=stoi(splitted_commands[i][2]);
            P2.x=stoi(splitted_commands[i][3]);
            P2.y=stoi(splitted_commands[i][4]);
            g=new Grass(P1,P2);
        }
        if(splitted_commands[i][0]=="sand_area"){
            Point P1;
            Point P2;
            P1.x=stoi(splitted_commands[i][1]);
            P1.y=stoi(splitted_commands[i][2]);
            P2.x=stoi(splitted_commands[i][3]);
            P2.y=stoi(splitted_commands[i][4]);
            Sand_area * temp;
            temp=new Sand_area(P1,P2);
            sand_areas.push_back(temp);
        }
        if(splitted_commands[i][0]=="water_area"){
            Point P1;
            Point P2;
            water * temp;
            temp=new water(stoi(splitted_commands[i][1]),stoi(splitted_commands[i][2]),stoi(splitted_commands[i][3]),stoi(splitted_commands[i][4]));
            game_Wareas.push_back(temp);
        }
        if(splitted_commands[i][0]=="Wall"){
            Point P1;
            Point P2;
            int x1=stoi(splitted_commands[i][1]);
            int y1=stoi(splitted_commands[i][2]);
            int x2=stoi(splitted_commands[i][3]);
            int y2=stoi(splitted_commands[i][4]);
            game_walls.push_back(Wall(x1,y1,x2,y2));
        }
        if(splitted_commands[i][0]=="sharp_Wall"){
            Point P1;
            Point P2;
            sharp_Wall * temp;
            int x1=stoi(splitted_commands[i][1]);
            int y1=stoi(splitted_commands[i][2]);
            int x2=stoi(splitted_commands[i][3]);
            int y2=stoi(splitted_commands[i][4]);
            temp=new sharp_Wall(x1,y1,x2,y2);
            game_SHwalls.push_back(temp);
            
        }
        if(splitted_commands[i][0]=="Ball"){
            Point P1;
            P1.x=stoi(splitted_commands[i][1]);
            P1.y=stoi(splitted_commands[i][2]);
            ball=new Ball(P1,stoi(splitted_commands[i][3]));
        }       
        if(splitted_commands[i][0]=="Hole"){
            Point P1;
            P1.x=stoi(splitted_commands[i][1]);
            P1.y=stoi(splitted_commands[i][2]);
            h=new Hole(P1,stoi(splitted_commands[i][3]));
        }
        
    }
    Game my_game(wnd,ball,h,game_walls,game_Wareas,game_SHwalls,g,sand_areas);
    my_game.run();


} 
int main(){
    vector<string>map_commands=getting_map();
    vector<vector<string>>splitted_map=splitting_map(map_commands);
    discovering_components(splitted_map);
    return 0;
}