test.exe: test.c triangleQueens.h triangleQueens.o
	gcc -std=c99 -o test.exe test.c triangleQueens.o

triangleQueens.o: triangleQueens.c triangleQueens.h
	gcc -c -std=c99 triangleQueens.c