#ifndef GRID_H 
#define GRID_H
#include <iostream>

namespace tictactoe
{
    class grid
    {
        private:
            bool checkWin();
            void resetGrid();
        public:
            int gridArray[3][3];
            void printGrid();
            bool score(int player, int x, int y);
            grid(){
                resetGrid();
            }
    };
}


#endif 