#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int bin_search(int arr[], int left, int right, int key)
//{
//	int c = 0;
//	
//	while(left<=right)
//	{
//		int mid = (left + right) / 2;
//
//		if (arr[mid] < key)
//		{
//			left = mid+1;
//		}
//	    else if (arr[mid] > key)
//		{
//			right = mid-1;
//		}
//		else
//		{
//			c = mid;
//			break;
//		}
//	
//	}
//	if (c == 0)
//		return -1;
//	else
//		return c;
//}
//
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8};
//	int n;
//	scanf("%d", &n);
//	int x =bin_search(arr,0,7,n);
//	printf("%d", x);
//	return 0;
//}

//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//
//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
//void add(int x)
//{
//	int y = 0;
//	
//	for (y = 1; y <= x; y++) 
//	{
//		int a ;
//		for (a = 1;a <= y; a++)
//		{
//			int b = a * y;
//			printf("%d*%d = %d ",y,a,b);
//			
//		}
//		printf("\n");
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

//实现函数判断year是不是润年

//void add(int year)
//{
//	if (((year % 4 == 0) && year % 100 != 0 )|| year % 400 ==0)
//	{
//		printf("是闰年");
//	}
//	else
//	{
//		printf("不是闰年");
//	}
//}
//
//
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	add(year);
//	return 0;
//}

//实现一个函数is_prime，判断一个数是不是素数。
//
//利用上面实现的is_prime函数，打印100到200之间的素数。
void is_prime(int n)
{
	int x;
	int y = 0;
	for (x = 2; x < n; x++)
	{
		if (n % x == 0)
		{
			printf("不是素数");
			y = 0;
			break;
		}
		else
			y = 1;
	}
	if (y == 1)
		printf("是素数");
}


int main()
{
	int n = 0;
	scanf("%d", &n);
	is_prime(n);
	return 0;
}

//创建一个整形数组，完成对数组的操作
//
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。
//

