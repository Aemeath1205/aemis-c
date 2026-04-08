#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	char arr[20][20];
//	int n;
//	scanf("%d", &n);
//	int a = 0;
//	int b = 0;
//	for (a = 0; a <= n; a++)
//	{
//		for (b = 0; b <= n; b++)
//		{
//			if (a == b)
//				arr[a][b] = '*';
//			else if (a + b == n)
//				arr[a][b] = '*';
//			else
//				arr[a][b] = ' ';
//		}
//	}
//	for (a = 0; a <= n; a++)
//	{
//		for (b = 0; b <= n; b++)
//		{
//			printf("%c", arr[a][b]);
//
//		}printf("\n");
//	}
//	return 0;
//
//}


//int main()
//{
//	char arr[20][20];
//	int a;
//	int b;
//	int n;
//	scanf("%d", &n);
//	for (a = 0; a <= n; a++)
//	{
//		for (b = 0; b <= n; b++)
//		{
//			if (a == 0 || a == n)
//				arr[a][b] = '*';
//			else if (b == 0 || b == n)
//				arr[a][b] = '*';
//			else
//				arr[a][b] = ' ';
//		}
//	}
//	for (a = 0; a <= n; a++)
//	{
//		for (b = 0; b <= n; b++)
//		{
//			printf("%c", arr[a][b]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int a;
//	int b;
//	int x;
//	int y;
//	scanf("%d%d", &x, &y);
//	int arr1[20][20];
//	int arr2[20][20];
//	/*int arr2[20][20];*/
//	for (a = 0; a <= x-1; a++)
//	{
//		for (b = 0; b <= y-1; b++)
//		{
//			scanf("%d", &arr1[a][b]);
//		}
//	}
//	for (a = 0; a <= x-1; a++)
//	{
//		for (b = 0; b <= y-1; b++)
//		{
//			arr2[b][a] = arr1[a][b];
//		}
//	}
//	for (b = 0; b <= y-1; b++)
//	{
//		for (a = 0;a <= x-1; a++)
//		{
//			printf("%d", arr2[b][a]);
//		}
//		printf("\n");
//	}
////
////	// 转置赋值
////	//for (a = 0; a < x; a++)
////	//{
////	//	for (b = 0; b < y; b++)
////	//	{
////	//		arr2[b][a] = arr1[a][b];
////	//	}
////	//}
////
////	//// 输出转置矩阵
////	//for (b = 0; b < y; b++)
////	//{
////	//	for (a = 0; a < x; a++)
////	//	{
////	//		printf("%d", arr2[b][a]);
////	//		if (a < x - 1) printf(" ");
////	//	}
////	//	printf("\n");
////	//}
//	return 0;
//}
//
////int main() {
////    int n, m;
////    scanf("%d %d", &n, &m);
////    int arr1[10][10], arr2[10][10];
////
////    // 输入原矩阵
////    for (int i = 0; i < n; i++)
////        for (int j = 0; j < m; j++)
////            scanf("%d", &arr1[i][j]);
////
////    // 转置：arr2[j][i] = arr1[i][j]
////    for (int i = 0; i < n; i++)
////        for (int j = 0; j < m; j++)
////            arr2[j][i] = arr1[i][j];
////
////    // 输出转置矩阵（m行，n列）
////    for (int i = 0; i < m; i++) {
////        for (int j = 0; j < n; j++) {
////            printf("%d", arr2[i][j]);
////            if (j < n - 1) printf(" ");
////        }
////        printf("\n");
////    }
////
////    return 0;
////}


//int main()
//{
//	int a;
//	int arr[10];
//	for (int a = 0; a < 10; a++)
//	{
//		scanf("%d", &arr[a]);
//	}
//	for (a = 9; a >= 0; a--)
//	{
//		printf("%d", arr[a]);
//	}
//	return 0;
//}

//int main()
//{
//	int a;
//	int b;
//	int i = 0;
//	int j = 0;
//	scanf("%d%d", &a, &b);
//	int arr1[20];
//	int arr2[20];
//	for (int i = 0; i < a; i++)
//		scanf("%d", &arr1[i]);
//	for (int i = 0; i < b; i++)
//		scanf("%d", &arr2[i]);
//	/*for (x = 0; x < a; x++)
//	{
//
//	test:
//		for (y = 0; y < b; y++)
//		{
//			if (arr1[x] < arr2[y])
//				printf("%d ", arr1[x]);
//			else
//			{
//				printf("%d ", arr2[y]);
//				goto test;
//			}
//		}
//
//	}*/
//	while (i < a && j < b)
//	{
//		if (arr1[i] <= arr2[j])
//		{
//			printf("%d ", arr1[i++]);
//		}
//		else 
//		{
//			printf("%d ", arr2[j++]);
//		}
//	}
//	// 输出剩余元素
//	while (i < a) printf("%d ", arr1[i++]);
//	while (j < b) printf("%d ", arr2[j++]);
//
//	return 0;
//}

//【一维数组】输入10个整数，求平均值

int arr