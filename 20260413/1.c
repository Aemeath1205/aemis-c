#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "1.h"
//菜单
void menu (void)
{
	printf("************\n");
	printf("****1.play****\n");
	printf("****0.exit****\n");
	printf("************\n");
	printf("请输入");
}
//初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int a = 0;
	for (a = 0; a < rows; a++)
	{
		int b = 0;
		for (b = 0; b < cols; b++)
		{
			board[a][b] = set;
		}
	}
}
//打印棋盘
void display_board(char print[ROWS][COLS], int row, int col )
{
	int a = 0;
	printf("-----扫雷游戏-----\n");
	for (a = 0; a <= row; a++)
	{
		printf("%d", a);
	}
	printf("\n");
	for (a = 1; a <= row; a++)
	{
		int b = 0;
		printf("%d ", a);
		for (b = 1; b <= col; b++)
		{
			char c = print[a][b];
			printf("%c", c);
		}
		printf("\n");
	}
}
//放雷
void set_mine(char mine[ROWS][COLS], int row, int col)
{
	//生成10个随机的坐标，放雷
	int count = EASY_COUNT;
	while (count>0)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
//统计周围类书
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y -
		1] + mine[x + 1][y] +
		mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0');
}
//排雷

void found_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入要排查的坐标格");
		scanf("%d %d", &x, &y);
		if (x >= 1 && y >= 1 && x <= row && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你死了\n");
				display_board(mine, ROW, COL);
				break;
			}
			else
			{
				//该位置不是雷，就统计周围的雷数
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				display_board(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("字符非法，请重新输入");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("YOU WIN");
		display_board(mine, ROW, COL);
	}
}