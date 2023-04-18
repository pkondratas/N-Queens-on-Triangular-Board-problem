
//2023-03-21
//Paulius Kondratas PS1
//Program that solves N queens on M-ised triangular board problem.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "triangleQueens.h"

//function to test valid tests
void validTest(int board_size, int queen_count)
{
    Board test = createBoard(board_size, queen_count);
    test.queen_count = queen_count;
    assert(solvePlacement(&test, board_size, 0, 0));
    freeBoard(&test, board_size);
}

//function to test invalid tests
void invalidTest(int board_size, int queen_count)
{
    Board test = createBoard(board_size, queen_count);
    test.queen_count = queen_count;
    assert(!solvePlacement(&test, board_size, 0, 0));
    freeBoard(&test, board_size);
}

int main()
{   
    validTest(4, 3);
    validTest(6, 4);
    validTest(20, 12);
    invalidTest(6, 5);
    invalidTest(9, 9);
    invalidTest(10, 15);

    printf("\n*All tests passed*\n\n");

    Board board;
    int board_size;
    int queen_count;
    
    getInput(&board_size, &queen_count);
    board = createBoard(board_size, queen_count);

    if(solvePlacement(&board, board_size, 0, 0))
    {
        printf("\nValid placement of %d queens on %d-sized triangular board:\n\n", queen_count, board_size);
        printBoard(board, board_size);
    }
    else
    {
        printf("\nNo valid placement found\n");
    }
    freeBoard(&board, board_size);

    system("pause");
    return 0;
}