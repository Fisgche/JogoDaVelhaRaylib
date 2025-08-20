#include "raylib.h"
#include "domain/grid.h"
#include "domain/player.h"

using namespace tictactoe;
int main(void)
{

    tictactoe::grid gameGrid;
    gameGrid.printGrid();
    player player1(1); // Player 1 is X
    player player2(2); // Player 2 is O
    std::cout << "Player 1 type: " << player1.getType() << std::endl;
    std::cout << "Player 2 type: " << player2.getType() << std::endl;
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