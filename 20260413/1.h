#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void menu (void);
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void display_board(char print[ROWS][COLS], int row, int col);
void set_mine(char mine[ROWS][COLS], int row, int col);
#define EASY_COUNT 10
#include <stdlib.h>
#include <time.h>
void found_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int GetMineCount(char mine[ROWS][COLS], int x, int y);
