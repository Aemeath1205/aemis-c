#define _CRT_SECURE_NO_WARNINGS
//写一个函数，可以逆序一个字符串的内容。
//#include <stdio.h>
//#include<string.h>
//void add(char arr[])
//{
//	
//	unsigned int x = strlen(arr);
//	for (unsigned int i = x-1; i >=0 ; i--)
//	{
//		printf("%c",*(arr + i));
//	}
//}
//
//int main()
//{
//	char arr[] = "hello java";
//	add(arr);
//	return 0;
//}

//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//
//#include <stdio.h>
//#include <string.h>
//void add(int x)
//{
//	char arr[] = "ABCD";
//	size_t y = strlen(arr);
//	int i = x;
//	for (i = x; i <= y-1; i++)
//	{
//		printf("%c ", *(arr + i));
//	}
//	for (int j = 0; j <= x - 1; j++)
//	{
//		printf("%c ", *(arr + j));
//	}
//}
//
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	add(x);
//	return 0;
//}

//模拟实现库函数strlen
//int add(char arr[])
//{
//	int count = 0;
//	char* x = arr;
//	while (*x!='\0')
//	{
//		x ++;
//		count++;
//	}
//	return count;
//}
//
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[] ="hello java";
//	int a = add(arr);
//	printf("%d\n", a);
//	printf("%zu", strlen(arr));
//	return 0;
//}

//输入一个整数数组，实现一个函数，
//
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//
//所有偶数位于数组的后半部分。
#include <stdio.h>
void add(int arr[])
{
	for (int i = 0; i < 5; i++)
	{
		if (*(arr + i) % 2 == 1)
			printf("%d ", *(arr + i));
	}
	for (int i = 0; i < 5; i++)
	{
		if (*(arr + i) % 2 == 0)
			printf("%d ", *(arr + i));
	}
}

int main()
{
	int arr[5];
	printf("输入5个数字：");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	add(arr);
	return 0;
}