#include "raylib.h"
#include "domain/grid.h"
#include <iostream>

int main(void)
{

    tictactoe::grid gameGrid;
    gameGrid.printGrid();
    if(gameGrid.score( 1, 0, 0)){
        std::cout<<"Player 1 wins!"<<std::endl;
    }// Player 1 marks (0,0)
    std::cout<<"-----------------------------"<<std::endl;
    gameGrid.printGrid();

    if(gameGrid.score( 1, 0, 1)){
        std::cout<<"Player 1 wins!"<<std::endl;
    } 
    std::cout<<"-----------------------------"<<std::endl;
    gameGrid.printGrid();
    
    if(gameGrid.score( 1, 0, 2)){
        std::cout<<"Player 1 wins!"<<std::endl;
    } 
    std::cout<<"-----------------------------"<<std::endl;
    gameGrid.printGrid();


    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}