#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


char empty_map[X][Y];
char full_map[X][Y];

void switch_of_menu() {
	int choice;
	char ch;
	scanf(" %d", &choice);
	switch (choice) {
	case 1:
		printf("欢迎!");
		set_map();
		printf("请选择是否管理员模式Y/N\n");
		scanf(" %c", &ch);
		if (ch == 'Y') {
			print_full_map();
			print_empty_map();
		}
		else {
			print_empty_map();
		}
		while (1) {
			gaming_look_for_boom();
		}
		break;
	case 2:
		printf("退出游戏");
		abort();
	}
}

void tmp_look_for_boom(int tmp_x,int tmp_y) {
	int tmp_count = 0;
	for (int tmp_i = tmp_x - 1; tmp_i < tmp_x + 2; tmp_i++)
	{
		for (int tmp_j = tmp_y - 1; tmp_j < tmp_y + 2; tmp_j++)
		{
			if (full_map[tmp_i][tmp_j] == '!')
			{
				tmp_count++;
			}
		}
	}
	empty_map[tmp_x][tmp_y] = tmp_count + 48;
	print_empty_map();
	//if (tmp_count != 0) {
	//	print_empty_map();
	//}
	//else 
	//{
	//	for (int tmp_i = tmp_x - 1; tmp_i < tmp_x + 2; tmp_i++)
	//	{
	//		for (int tmp_j = tmp_y - 1; tmp_j < tmp_y + 2; tmp_j++)
	//		{
	//			if (tmp_i == tmp_x && tmp_j == tmp_y) {
	//				continue;
	//			}
	//			tmp_look_for_boom(tmp_i, tmp_j);
	//		}
	//	}
	//}
}

void gaming_look_for_boom() {
	printf("请输入你想找的坐标,并用空格分开");
	int tmp_x;
	int tmp_y;
	scanf("%d %d", &tmp_x, &tmp_y);
	if (full_map[tmp_x][tmp_y] == '!') {
		printf("你被炸死了,游戏结束");
		print_full_map();
		abort();
	}
	else {
		tmp_look_for_boom(tmp_x, tmp_y);
	}
}

void menu() {
	printf("这是一个扫雷游戏的菜单，请选择\n");
	printf("1.开始游戏\n2.退出游戏\n");
}

void set_map() 
{
	
	for (int i = 0; i < Y-1; i++) 
	{
		for (int j = 0; j < X-1; j++) 
		{
			if (i == 0) 
			{
				empty_map[i][j] = 48 + j;
				full_map[i][j] = 48 + j;
				continue;
			}
			if (j == 0)
			{
				empty_map[i][j] = 48 + i;
				full_map[i][j] = 48 + i;
				continue;
			}
			empty_map[i][j] = '*';
			full_map[i][j] = '*';
		}
	}

	srand((unsigned int)time(NULL));
	int count = 10;
	while (count > 0)
	{
		int i = rand() % 9;
		int j = rand() % 9;
		full_map[i+1][j+1] = '!';
		count--;
	}
}

void print_full_map() 
{
	for (int i = 0; i < Y-1; i++)
	{
		for (int j = 0; j < X-1; j++)
		{
			printf("%c", full_map[i][j]);
		}
		printf("\n");
	}
}

void print_empty_map() {
	for (int i = 0; i < Y - 1; i++)
	{
		for (int j = 0; j < X - 1; j++)
		{
			printf("%c", empty_map[i][j]);
		}
		printf("\n");
	}
}