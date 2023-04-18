# N queens on M-sized triangular board problem

Task: to find N queen placement on M-sized triangular board so that they don't attack each other

# Galimos funkcijos

    From test.c file:
    
    -  void validTest(int board_size, int queen_count);
        completes correct tests

    -  void invalidTest(int board_size, int queen_count);
        completes incorrect tests

    Iš triangleQueens.c ir triangleQueens.h

    -  void getInput(int *board_size, int *queen_count);
        size of a board queen count is entered, both of them get validated(if not correct, user is asked to try again)

    -  Board createBoard(int board_size, int queen_count);
        creates the board and initializes it
        - returns the board 

    -  bool solvePlacement(Board *board, int board_size, int placed_queens, int current_row);
        function that by backtracking method finds whether it is possible to fit all the queens on the board in such way that they don't endanger each other
        - true, if the placement is found
        - false, if not found


    -  bool placementValidation(Board board, int queen_placement, int current_row);
        checks whether the queen in given coordinates endangers previously placed queens 
        - true, if placement is valid(doesn't endanger)
        - false, if not

    -  void printBoard(Board board, int board_size);
        prints the board to the console

    -  void freeBoard(Board *board, int board_size);
        frees the memory used(Board)
