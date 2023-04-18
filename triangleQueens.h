#ifndef TRIANGLEQUEENS_H
#define TRIANGLEQUEENS_H

#include <stdbool.h>

typedef struct Board
{
    bool solution_found;
    int queen_count;
    char **value;
}Board;

void getInput(int *board_size, int *queen_count);
Board createBoard(int board_size, int queen_count);
bool solvePlacement(Board *board, int board_size, int placed_queens, int current_row);
bool placementValidation(Board board, int queen_placement, int current_row);
void printBoard(Board board, int board_size);
void freeBoard(Board *board, int board_size);

#endif