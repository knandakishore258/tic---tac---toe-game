#ifndef PLAYER
#define PLAYER
#include "board.h"
class players{
    private:
        int ID;
        int moves[5][2];
        board &b;

        int moves_count;
    public: 
        players(int &Id, board &B) : moves_count(0),ID(Id),b(B){
            for (int i = 0; i < 5; ++i)
                for (int j = 0; j < 2; ++j)
                    moves[i][j] = 0;
            std::cout<<"you are player" <<  ID <<std::endl;
        }
        void make_move(int x, int y){
            b.check_game_over();
            if(b.game_over == false && b.is_point_available(x,y)){
                if(x >= 0 && y >= 0 && x < 3 && y <3){
                    b.arr[x][y] = 1;
                    moves[moves_count][0] = x;
                    moves[moves_count][1] = y;
                    moves_count += 1;
                }       
                b.print_board();
            }
            else{
                b.print_winner();
            }
        }
};
#endif