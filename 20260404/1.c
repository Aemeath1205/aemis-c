#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,(3,4),5 };
//    printf("%d\n", sizeof(arr));
//    return 0;
//}

//猜数字游戏
#include <stdlib.h>
#include <time.h>

void game()
{
	int r = rand() % 100 + 1;
	int g;
	
	while (1)
	{
		printf("输入数字");
		scanf("%d", &g);
		if (g > r)
			printf("大了");
		else if (g < r)
			printf("小了");
		else
		{
			printf("对了");
			break;
		}

	}

}




int main()
{
	int i;
	int a;
	int b;
	srand((unsigned int)time(NULL));
	do 
	{
		printf("1.开始游戏");
		printf("0.退出游戏");
		scanf("%d", &a);
		switch (a)
		{
			case 1:
				game();
				break;
			case 0:
				break;
		}
	} while (a);
	return 0;
}