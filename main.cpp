#include <iostream>
#include "player.h"
#include "ai.h"
#include "board.h"

int main(){
    board b1;
    std::cout<<"enter the player ID: ";
    int ID;
    std::cin>>ID;
    players p1(ID, b1);
    ai a1(b1);
    while(!b1.game_over){
        int x,y;
        std::cout<< "enter the coordinates x and y: ";
        std::cin>>x>>y;
        if(x>=0 && x<3 && y>=0 && y <3){
            p1.make_move(x,y);
        }
        if(b1.game_over){
            return 0;
        }

        a1.make_move();        
    }
    std::cin.get();
}