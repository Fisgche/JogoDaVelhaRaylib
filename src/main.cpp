#include "raylib.h"
#include "domain/grid.h"
#include "domain/player.h"

using namespace tictactoe;

void DrawX(int row, int col, float cellSize, Color color, float thickness) {
    float x = col * cellSize;
    float y = row * cellSize;

    Vector2 topLeft     = { x + 20, y + 20 };
    Vector2 bottomRight = { x + cellSize - 20, y + cellSize - 20 };
    Vector2 topRight    = { x + cellSize - 20, y + 20 };
    Vector2 bottomLeft  = { x + 20, y + cellSize - 20 };

    DrawLineEx(topLeft, bottomRight, thickness, color);
    DrawLineEx(topRight, bottomLeft, thickness, color);
}

void DrawO(int row, int col, float cellSize, Color color) {
    int centerX = col * cellSize + cellSize / 2;
    int centerY = row * cellSize + cellSize / 2;
    float radius = (cellSize / 2) - 20;

    DrawCircleLines(centerX, centerY, radius, color);
}



int main(void)
{

    tictactoe::grid gameGrid;
    player player1(1); // Player 1 is X
    player player2(2); // Player 2 is O

    const int screenWidth = 800;
    const int screenHeight = 800;
    int winner = 0; // 0 for no winner, 1 for player 1, 2 for player 2
    int turnCount = 0; // To keep track of turns
    bool isGameOver = false; // To track if the game is over
    int currentPlayer = 1; // Start with player 1

    InitWindow(screenWidth, screenHeight, "Jogo da Velha");

    while (!WindowShouldClose())
    {
        

        Vector2 mousePosition = GetMousePosition();
        bool isMousePressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        // Check if the mouse is pressed and update the grid
        // Assuming each cell is 266x266 pixels, adjust as necessary

        if(isMousePressed)
        {
            if(player1.played == false)
            {
                currentPlayer = 1;
                player1.played = true;
                player2.played = false;
            }
            else
            {
                currentPlayer = 2;
                player1.played = false;
                player2.played = true;
            }

            int x = static_cast<int>(mousePosition.x / 266); // Assuming each cell is 266x266 pixels
            int y = static_cast<int>(mousePosition.y / 266);

            std::cout << "Player " << currentPlayer << " clicked at (" << x << ", " << y << ")" << std::endl;
            std::cout << "Mouse Position: (" << mousePosition.x << ", " << mousePosition.y << ")" << std::endl;
            if (gameGrid.score(currentPlayer, y,x)) // Note: gridArray is accessed as [row][col]
            {
                isGameOver = true;
                winner = currentPlayer;
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            }
            else if (++turnCount >= 9) // Check for draw
            {
                isGameOver = true;
                std::cout << "It's a draw!" << std::endl;
            }
            
            gameGrid.printGrid(); 
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Click to play!", 10, 10, 10, DARKGRAY);
            DrawText("Player 1: X", 10, 20, 10, DARKGRAY);
            DrawText("Player 2: O", 10, 30, 10, DARKGRAY);
            DrawText("Current Player: ", 10, 40, 10, DARKGRAY);
            if(currentPlayer == 1)
                DrawText("X", 100, 40, 10, DARKGRAY);
            else
                DrawText("O", 100, 40, 10, DARKGRAY);

            // Cor e espessura das linhas
            Color gridColor = BLACK;
            float lineThickness = 5.0f;
            

            // Tamanho de cada célula
            float cellSize = screenWidth / 3.0f;

            // Linhas verticais
            DrawRectangleRec((Rectangle){cellSize - lineThickness / 2, 0, lineThickness, screenHeight}, gridColor);
            DrawRectangleRec((Rectangle){2 * cellSize - lineThickness / 2, 0, lineThickness, screenHeight}, gridColor);

            // Linhas horizontais
            DrawRectangleRec((Rectangle){0, cellSize - lineThickness / 2, screenWidth, lineThickness}, gridColor);
            DrawRectangleRec((Rectangle){0, 2 * cellSize - lineThickness / 2, screenWidth, lineThickness}, gridColor);
            
            for(int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (gameGrid.gridArray[i][j] == 1) {
                        DrawX(i, j, cellSize, RED, 8);
                    } else if (gameGrid.gridArray[i][j] == 2) {
                        DrawO(i, j, cellSize, BLUE);
                    }
                }
            }
            

        EndDrawing();
    }

    CloseWindow();

    return 0;
}