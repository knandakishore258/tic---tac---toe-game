#ifndef BOARD
#define BOARD
#include <iostream>
class board{
    private:
        int arr[3][3];
    public:
        bool game_over;
        bool user_wins;
        bool ai_wins;
        bool draw;
    public:
        board(): game_over(false), user_wins(false), ai_wins(false), draw(false){
            for(int i = 0;i<3;i++){
                for(int j = 0;j<3;j++){
                    arr[i][j] = -1;
                }
            }
        }
        void print_board(){
            std::cout << "-------------\n";
            for (int i = 0; i < 3; ++i) {
                std::cout << "|";
                for (int j = 0; j < 3; ++j) {
                    char symbol;
                    if (arr[i][j] == -1) symbol = ' ';
                    else if (arr[i][j] == 0) symbol = 'X';
                    else symbol = 'O';
                    std::cout << " " << symbol << " |";
                }
                std::cout << "\n-------------\n";
            }
        }
        
        bool board_empty(){
                    for(int i = 0;i<3;i++){
                        for(int j = 0;j<3;j++){
                            if(arr[i][j] == -1){
                                return true;
                            }
                        }
                    }
                    return false;
                }

        void check_game_over(){
            if((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != -1) || (arr[0][2] == arr[1][1] && arr[1][1]==arr[2][0] && arr[0][2] != -1)){
                if(arr[1][1] == 1){
                    user_wins = true;
                    game_over = true;
                    ai_wins = false;
                    draw = false;
                    return;
                }
                else{
                    if(arr[1][1]==0){
                        user_wins = false;
                        ai_wins = true;
                        draw = false;
                        game_over = true;
                        return;
                    }
                }
            }
            else{
                for(int i = 0;i<3;i++){
                        if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != -1){
                            if(arr[i][0] == 1){
                                game_over = true;
                                user_wins = true;
                                ai_wins = false;
                                draw = false;
                                return;
                            }
                            else{
                                game_over = true;
                                ai_wins = true;
                                user_wins = false;
                                draw = false;
                                return ;
                            }
                        }
                        else if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != -1){
                                {
                                    if(arr[0][i] == 1){
                                    game_over = true;
                                    user_wins = true;
                                    ai_wins = false;
                                    draw = false;
                                    return;
                                }
                                else{
                                    game_over = true;
                                    ai_wins = true;
                                    user_wins = false;
                                    draw = false;
                                    return;
                                }
                            }
                        }
                    } 
                } 
                if(board_empty() == false && user_wins == false && ai_wins == false){
                    game_over = true;
                    draw = true;
                }
            }  
        void print_winner(){
            if(user_wins == true){
                std::cout<<"user_wins"<<std::endl;
            }
            else if(ai_wins == true){
                std::cout<<"ai_wins"<<std::endl;
            }
            else if(draw == true){
                std::cout<<"draw"<<std::endl;
            }
        }
        friend class players;
        friend class ai;

        bool is_point_available(int x, int y){
            return arr[x][y] == -1;
        }
};
#endif