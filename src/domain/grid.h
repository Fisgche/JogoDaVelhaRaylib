#ifndef GRID_H 
#define GRID_H

namespace tictactoe
{
    class grid
    {
        private:
            int gridArray[3][3];
            bool checkWin();
            void resetGrid();
        public:
            void printGrid();
            bool score(int player, int x, int y);
            grid(){
                resetGrid();
            }
    };
}


#endif 