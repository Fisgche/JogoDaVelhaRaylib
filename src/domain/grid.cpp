#include "grid.h"

using namespace tictactoe;

void grid::resetGrid()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gridArray[i][j] = 0;
        }
    }
}

bool grid::checkWin()
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((gridArray[i][0] != 0 && gridArray[i][0] == gridArray[i][1] && gridArray[i][1] == gridArray[i][2]) ||
            (gridArray[0][i] != 0 && gridArray[0][i] == gridArray[1][i] && gridArray[1][i] == gridArray[2][i]))
        {
            return true;
        }
    }

    // Check diagonals
    if ((gridArray[0][0] != 0 && gridArray[0][0] == gridArray[1][1] && gridArray[1][1] == gridArray[2][2]) ||
        (gridArray[0][2] != 0 && gridArray[0][2] == gridArray[1][1] && gridArray[1][1] == gridArray[2][0]))
    {
        return true;
    }

    return false;
}

bool grid::score(int player, int x, int y)
{
    if (gridArray[x][y] == 0)
    {
        gridArray[x][y] = player;
        return checkWin();
    }
    return false;
}

void grid::printGrid()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char mark;
            if (gridArray[i][j] == 1)
                mark = 'X';
            else if (gridArray[i][j] == 2)
                mark = 'O';
            else
                mark = '.';

            std::cout << mark << " ";
        }
        std::cout << std::endl;
    }
}