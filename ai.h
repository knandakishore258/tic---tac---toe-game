#ifndef AI
#define AI
#include "board.h"
#include <random>
class ai{
    private:
        int moves[5][2];
        board &b;
        int moves_count;
    public:
        friend class player;
        ai(board& b1): b(b1) {}
        void make_move(){
            b.check_game_over();
            if(!b.game_over && b.board_empty()){
                std::random_device device;
                std::mt19937 gen(device());
                std::uniform_int_distribution<int> distr(0,2);
                int index_x = distr(gen);
                int index_y = distr(gen);
                while(!b.is_point_available(index_x, index_y)){
                    index_x = distr(gen);
                    index_y = distr(gen);
                }
                b.arr[index_x][index_y] = 0;
                b.print_board();
            }
            else{
                b.print_winner();
            }
        }
};
#endif