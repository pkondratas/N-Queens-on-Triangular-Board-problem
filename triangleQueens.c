#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "triangleQueens.h"

bool condition = false;

//gets user input and checks whether it is correct(if not, asks to enter again)
void getInput(int *board_size, int *queen_count)
{
    bool correct_input = true;

    do
    {
        printf("Enter board size and amount of queens: ");
        int input = scanf("%d%d", board_size, queen_count);

        //checks whether input was a number
        if(input < 2 || getchar() != '\n')
        {
            printf("\n*Error: wrong input*\n");
            printf("*Note: input must be positive integer and queen count must be lower than size of the board*\n\n");
            while(getchar() != '\n') 
                ;
            correct_input = false;
        }
        //if input is a number, checks whether it is postive and queen count isn't higher than board size
        else if(input < 2 || *board_size < 1 || *queen_count < 1 || *board_size <= *queen_count)
        {
            printf("\n*Error: wrong input*\n");
            printf("*Note: input must be positive integer and queen count must be lower than size of the board*\n\n");
            correct_input = false;
        }
        else
        {
            correct_input = true;
        }
    } while(correct_input == false);
}

//creates the board and initializes its elements
Board createBoard(int board_size, int queen_count)
{
    Board new_board;

    new_board.queen_count = queen_count;
    new_board.solution_found = false;
    new_board.value = malloc(board_size * sizeof(char*));

    if(new_board.value == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        exit(-1);
    }
    else
    {   
        //creates board in descending order(triangle): first row is n, second is n-1, ..., last one is 1
        for(int i = 0; i < board_size; ++i)
        {
            new_board.value[i] = malloc((board_size - i) * sizeof(char));
            if(new_board.value[i] == NULL)
            {
                printf("Error: Memory allocation failed.\n");
                exit(-1);
            }

            //assigns every board element to value 'x'
            for(int j = 0; j < (board_size - i); ++j)
            {
                new_board.value[i][j] = 'x';
            }
        }
    }

    return new_board;
}
//function uses recursion and uses backtracking to find the first possible way to place N queens on M-ised triangular board(returns true if solution found, otherwise false)
bool solvePlacement(Board *board, int board_size, int placed_queens, int current_row)
{
    //if all queens are placed, returns true
    if((*board).queen_count == placed_queens)
    {
        return true;
    }
    
    for(int i = 0; i < board_size; ++i)
    {
        //checks whether it is possible to place queen there
        if(placementValidation(*board, i, current_row - 1))
        {
            (*board).value[current_row][i] = 'Q';
            placed_queens += 1;
            current_row += 1;
            if(solvePlacement(board, board_size - 1, placed_queens, current_row))
            {
                //recursion ends and solution is found
                return true;
            }   
            placed_queens -= 1;
            current_row -= 1;
            (*board).value[current_row][i] = 'x';
        }
    }

    return false;
}

//checks whether newly faced queen is not attacked by any other queen
bool placementValidation(Board board, int queen_placement, int current_row)
{
    int left_diagonal = queen_placement;  //left diagonal doesn't need to be changed
    int right_diagonal = queen_placement + 1;

    for(int i = current_row; i >= 0; --i)
    {
        if(board.value[i][left_diagonal] == 'Q' || board.value[i][right_diagonal] == 'Q')
        {
            return false;
        }
        right_diagonal += 1;
    }

    return true;
}

//displays the board on the screen
void printBoard(Board board, int board_size)
{   
    for(int i = (board_size - 1); i >= 0; --i)
    {
        for(int g = 0; g < i; ++g)
        {
            printf("  ");
        }
        for(int j = 0; j < board_size - i; ++j)
        {
            printf("%c   ", board.value[i][j]);
        }
        printf("\n");
    }
    
}

//memory deallocation
void freeBoard(Board *board, int board_size)
{
    for(int i = 0; i < board_size; ++i)
    {
        free((*board).value[i]);
    }
    free((*board).value);
}