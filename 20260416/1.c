#define _CRT_SECURE_NO_WARNINGS
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）。
//#include <stdio.h>
//int main()
//{
//	int price = 1; /*1瓶汽水1元*/
//	int x = 20;
//	int sum = 20;
//	int n=0;
//	int m=0;
//	do
//	{
//		
//		n = x / 2;
//		m = x % 2;
//		sum += n;
//		x = n + m;
//	} while (x!=1);
//	printf("%d", sum);
//}
//用C语言在屏幕上输出以下图案：

//#include <stdio.h>
//int main()
//{
//	char arr1[7][13] ;
//	int x;
//	int y;
//	int i;
//	for (x = 0; x < 7; x++)
//	{
//		for (y = 0; y < 13; y++)
//		{
//			arr1[x][y] = ' ';
//		}
//		printf("\n");
//	}
//
//	for (x = 0; x < 7; x++)
//	{
//		int c = 6 - x;
//		int d = 6 + x;
//		for (i = c; i <= d; i++)
//		{
//			arr1[x][i] = '*';
//		}
//		
//		
//	}
//	for (x = 0; x < 7; x++)
//	{
//		for (y = 0; y < 13; y++)
//		{
//			printf("%c", arr1[x][y]);
//		}
//		printf("\n");
//	}
//	
//	
//	char arr2[6][13];
//	for (x = 0; x < 6; x++)
//	{
//		for (y = 0; y < 13; y++)
//		{
//			arr2[x][y] = ' ';
//		}
//		printf("\n");
//	}
//	for (x = 0; x < 6; x++)
//	{
//		int c = x+1;
//		int d = 11 - x;
//		
//		for (i = c; i <= d; i++)
//		{
//			arr2[x][i] = '*';
//		}
//	}
//	for (x = 5; x >= 0; x--)
//	{
//		for (y = 0; y < 13; y++)
//		{
//			printf("%c", arr1[x][y]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//    // 整个菱形共12行，13列（6行上半+6行下半）
//    char diamond[12][13];
//    int x, y, i;
//
//    // 第一步：全部初始化为空格
//    for (x = 0; x < 12; x++) {
//        for (y = 0; y < 13; y++) {
//            diamond[x][y] = ' ';
//        }
//    }
//
//    // 第二步：填充上半部分（前6行，x=0~5，从上到下越来越宽）
//    for (x = 0; x < 6; x++)
//    {
//        int left = 6 - x;   
//        int right = 6 + x;  
//        for (i = left; i <= right; i++) {
//            diamond[x][i] = '*';
//        }
//    }
//
//    // 第三步：填充下半部分（后6行，x=6~11，从上到下越来越窄，正好是对的顺序）
//    for (x = 6; x < 12; x++)
//    {
//        // 
//        int left = x - 6;       
//        int right = 12 - (x - 6); 
//        right = 11 - (x - 6);  
//        for (i = left; i <= right; i++) {
//            diamond[x][i] = '*';
//        }
//    }
//
//    // 从头到尾正序打印
//    for (x = 0; x < 12; x++) {
//        for (y = 0; y < 13; y++) {
//            printf("%c", diamond[x][y]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}

//求出0～100000之间的所有“水仙花数”并输出。
//
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。

//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	
//	int x;
//	for (x = 0; x <= 100000; x++)
//	{
//		int a = x % 10;
//		int a1 = x / 10;
//		int b = x / 10% 10;
//		int b1 = x / 100;
//		int c = x /100% 10;
//		int c1 = x / 1000;
//		int d = x /1000% 10;
//		int d1 = x / 10000;
//		int e = x / 10000 %10;
//		int e1 = x / 100000;
//		int n= 0;
//		if (a1 == 0)
//			n = 1;
//		else if (b1 == 0)
//			n = 2;
//		else if (c1 == 0)
//			n = 3;
//		else if (d1 == 0)
//			n = 4;
//		else if (e1 == 0)
//			n = 5;
//		else if (x>=100000)
//			n = 6;
//		int y = pow(a, n) + pow(b, n) + pow(c, n) + pow(d, n) + pow(e, n);
//		if (x == y)
//			printf("%d ", x);
//		
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//    int x;
//    for (x = 0; x <= 100000; x++) // 修正：109000 → 100000
//    {
//        int a = x % 10;
//        int a1 = x / 10;
//        int b = (x / 10) % 10;     // 修正：提取十位数字
//        int b1 = x / 100;
//        int c = (x / 100) % 10;    // 修正：提取百位数字
//        int c1 = x / 1000;
//        int d = (x / 1000) % 10;   // 修正：提取千位数字
//        int d1 = x / 10000;
//        int e = (x / 10000) % 10;  // 修正：提取万位数字
//        int e1 = x / 100000;
//
//        int n = 0; // ? 关键修复：初始化n
//
//        if (a1 == 0)
//            n = 1;
//        else if (b1 == 0)  // 修正：用else if避免多个条件同时成立
//            n = 2;
//        else if (c1 == 0)
//            n = 3;
//        else if (d1 == 0)
//            n = 4;
//        else if (e1 == 0)
//            n = 5;
//        else if (x >= 100000) // 修正：六位数判断
//            n = 6;
//
//        // ? 修正：使用正确的各位数字（a, b, c, d, e），不是用取模后的中间变量
//        int y = pow(a, n) + pow(b, n) + pow(c, n) + pow(d, n) + pow(e, n);
//        if (x == y)
//            printf("%d ", x);
//    }
//    return 0;
//}
//



//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//
//例如：2 + 22 + 222 + 2222 + 22222
//

#include <stdio.h>
int main()
{
	int a;
	printf("请输入一个数字：");
	scanf("%d", &a);
	int Sn;
	Sn = a + (a + 10 * a) + (a + 10 * a + 100 * a) + (a + 10 * a + 100 * a + 1000 * a) + (a + 10 * a + 100 * a + 1000 * a + 10000 * a);
	printf("%d", Sn);
	return 0;
}
