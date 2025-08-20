#ifndef PLAYER_H 
#define PLAYER_H
#include <iostream>

namespace tictactoe
{
    class player
    {
        private:
            int type; // 1 for X, 2 for O
            void setType(int type);
        public:
            int getType();
            player(int type){
                setType(type);
            };
    };
}
#endif 