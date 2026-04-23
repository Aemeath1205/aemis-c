#define _CRT_SECURE_NO_WARNINGS
//写一个函数打印arr数组的内容，不使用数组下标，使用指针。
//
//arr是一个整形一维数组。
//#include <stdio.h>
//void add(int arr[])
//{
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d", *(arr + i));
//	}
//}
//
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	add(arr);
//	return 0;
//}
//实现一个对整形数组的冒泡排序

//#include <stdio.h>
//void add(int arr[],int sz)
//{
//	for (int i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for ( j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				
//				int a = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = a;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[5] = { 1,3,4,2,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	add(arr,sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
//#include <stdio.h>
//#include<string.h>
//int add(char arr1[], char arr2[],size_t y)
//{
//	int n = 0;
//	int count = 1;
//		while (count==1)
//		{
//			count = 0;
//			n++;
//			/*for (int j = 1; j <= y - 1; j++)
//			{*/
//				char a = arr1[0];
//				arr1[0] = arr1[1];
//				arr1[1] = arr1[2];
//				arr1[2] = arr1[3];
//				arr1[3] = arr1[4];
//				arr1[4] = a;
//			/*}*/
//
//			for (int z = 0; z < y; z++)
//			{
//				if (arr1[z] != arr2[z])
//
//				count = 1;
//			}
//		}
//		return n;
//}
//int main()
//{
//	char arr1[] = "AABCD";
//	char arr2[] = "BCDAA";
//	/*int i;
//	scanf("%d", &i);*/
//	size_t y = strlen(arr1);
//	int n = add(arr1, arr2,y);
//	printf("%d", n);
//	return;
//}


//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);




//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
//例如：
//有数组的元素是：1，2，3，4，5，1，2，3，4，6
//只有5和6只出现1次，要找出5和6.
//
//#include <stdio.h>
//void add(int arr[],int sz)
//{
//	
//	for (int i = 0; i < sz; i++)
//	{
//		int count= 0;
//		for (int j = 0; j < sz; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				count++;
//			}
//			
//		}
//		if (count == 1)
//				printf("%d",arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[] = {1,2,3,4,5,1,2,3,4,6};
//	unsigned int sz = sizeof(arr) / sizeof(arr[0]);
//	add(arr,sz);
//	return 0;
//}

//多组输入，一行有两个整数，分别表示年份和月份，用空格分隔。
//输出描述：
//针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天。

#include <stdio.h>
int add(int year, int month)
{
	//先判断是不是闰年
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		switch (month)
		{
		case 1:
			return 31;
			break;
		case

		}
	}
	else
	{

	}
}

int main()
{
	int year;
	int month;
	scanf("%d %d", &year, &month);
	int day = add(year, month);
	printf("%d", day);
	return 0;
}