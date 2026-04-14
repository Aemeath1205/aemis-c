#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "1.h"
void game(void)
{
	char mine[ROWS][COLS];//存放雷的
	char show[ROWS][COLS];//展示+存放排查出的雷的；
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//display_board(mine, ROW, COL);
	display_board(show, ROW, COL);
	//放雷
	set_mine(mine,ROW,COL);
	display_board(mine, ROW, COL);
	//排雷
	found_mine(mine,show,ROW,COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:

			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	}while (input);
	return 0;
}