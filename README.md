# 2 lab. darbas, Paulius Kondratas 5 gr.

Užduotis: Rasti N valdovių išdėstymą M trikampėje lentoje, kad jos viena kitos nekirstų

# Galimos funkcijos

    Iš test.c failo:
    
    -  void validTest(int board_size, int queen_count);
        atlieka teisingus testus

    -  void invalidTest(int board_size, int queen_count);
        atlieka neteisingus testus

    Iš triangleQueens.c ir triangleQueens.h

    -  void getInput(int *board_size, int *queen_count);
        įvedamas lentos dydis ir valdovių skaičius ir patikrinama ar jie teisingi(jei ne, prašo įvesti iš naujo)

    -  Board createBoard(int board_size, int queen_count);
        sukuriama lenta ir inicializuojami jos elementai
        - grąžinama sukurta lenta

    -  bool solvePlacement(Board *board, int board_size, int placed_queens, int current_row);
        funkcija, kuri, naudodama "backtracking" algoritmą, randa ar ivestą valdovių skaičių galima sutalpinti
        pasirinkto dydžio lentoje taip, kad jos viena kitai negrasintų
        - true, jei išdėstymo būdas rastas
        - false, jei išdėstymo būdas nerastas


    -  bool placementValidation(Board board, int queen_placement, int current_row);
        tikrina, ar kordinatėse valdove nekerta anksčiau buvusių valdovių
        - true, jei vieta laisva
        - false, jei vieta negalima

    -  void printBoard(Board board, int board_size);
        į ekraną išvedamas lentos išdėstymas

    -  void freeBoard(Board *board, int board_size);
        atlaisvinama panaudota atmintis sukuriant lentą(Board)
