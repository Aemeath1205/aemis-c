#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//			sum += i;
//	}
//	printf("%d\n", sum);
//	printf("%d\n", i);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}

//在屏幕上输出9 * 9乘法口诀表

//#include <stdio.h>
//int main()
//{
//	int x = 0;
//	int y = 0;
//	for ( x = 1; x <= 9; x++ )
//	{
//		for (y = 1; y <= x; y++)
//		{
//			int n = x * y;
//			printf("%d * %d = %d\n ", x, y, n);
//
//		}
//	}
//	return 0;
//}

//求10 个整数中最大值


//int main()
//{
//	int i = 0;
//	int arr[10];
//	for (i = 0;i <= 9; i++)
//	{
//		scanf("%d", &arr[i]);
//	}	
//	int max = arr[0];
//	
//	for (i = 1; i <= 9; i++)
//		{
//		if (arr[i] >= max)
//			max = arr[i];
//		else
//			continue;
//		}
//	
//	printf("%d", max);
//	return 0;
//}

//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值，打印出结果

//int main()
//{
//	double x = 1;
//	int y = 1;
//	double sum = 0;
//	for ( y = 1 ; y <= 100 ; y++ )
//	{
//		double a = x / y;
//		sum += a;
//	}
//	printf("%lf", sum);
//	return 0;
//}

//
//编写程序数一下 1到 100 的所有整数中出现多少个数字9
//#include <stdio.h>
//int main()
//{
//	int sum = 0;
//	int a = 0;
//	
//	for (a = 1; a <= 100; a++)
//	{
//		int x = a % 10;//个位
//		int z = a / 10;
//		int y = z % 10;//十位
//		if (a > 0 && a < 10)
//		{
//			if (x == 9)
//				sum += 1;
//		}
//		else 
//		{
//			
//			if (x == 9)
//				sum += 1;
//			if (y == 9)
//				sum += 1;
//		}
//		
//		
//	}
//	printf("%d", sum);
//			
//	return 0;
//}


//写一个代码：打印100~200之间的素数
//#include <stdio.h>
//int main()
//{
//	int a = 0 ;
//	int b = 0;
//	for ( a = 100; a <= 200 ; a++ )
//	{
//		for (b = 2; b < a; b++)
//		{
//			if (a % b == 0)
//				break;
//		}
//		if (b == a)
//			printf("%d ", a);
//	}
//	return 0;
//}

//打印1000年到2000年之间的闰年
//#include <stdio.h>
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year += 1)
//	{
//		if (year % 100 == 0)
//		{
//			if (year % 400 == 0)
//				printf("%d ", year);
//		}
//		else
//			{
//				if (year % 4 == 0 && year % 100 != 0)
//					printf("%d ", year);
//			}
//		
//		
//	}
//	return 0;
//}


//给定两个数，求这两个数的最大公约数
//
//例如：
//
//输入：20 40
//
//输出：20

#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	scanf("%d%d", &a, &b);
	if (a > b)
		c = b;
	else
		c = a;
	for (d = c; d > 0 ; d--)
	{
		if (a % d == 0 && b % d == 0)
		{
			break;
		}
		
	}
	printf("%d ", d);
	return 0;
}