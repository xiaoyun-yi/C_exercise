
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  
#include <string.h>
#include <time.h>

#define ROW 7
#define COL 7

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 15

void initboard(char board[ROWS][COLS], int rows, int cols, char set);

void displayboard(char board[ROWS][COLS], char flag[ROWS][COLS], int rows, int cols);
void set(char board[ROWS][COLS], int row, int col);
void find(char mine[ROWS][COLS], char show[ROWS][COLS], char flag[ROWS][COLS], int row, int col);
