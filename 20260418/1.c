#define _CRT_SECURE_NO_WARNINGS
////求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
////
////例如：2 + 22 + 222 + 2222 + 22222
//int Sn = 0;
//
//
//
//int print(int n,int x)
//{
//	
//	if (x > 0)
//	{
//		int i = print(n, x - 1) * 10 + n;
//		
//		Sn += i;
//      return i;
//	}
//	return 0;
//	
//   
//}
//
//#include <stdio.h>
//int main()
//{
//	int n;
//	
//	scanf("%d", &n);
//	int x = 5;
//	print(n, 5);
//	printf("%d", Sn);
//	return 0;
//}





////写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
////
////例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
////
////输入：1729，输出：19
////
//#include <stdio.h>
//DigitSum(int n)
//{
//	
//	if (n == 0)
//		return n;
//	else
//	{
//		return n % 10 + DigitSum(n / 10);
//	}
//	
//}
//
//
//
//int main()
//{
//	int n;
//	
//	scanf("%d", &n);
//	printf("%d", DigitSum(n));
//	return;
//}

////编写一个函数实现n的k次方，使用递归实现。
//
//
//#include <stdio.h>
//int add(int n, int k)
//{
//	if (k == 0) return 1;
//	else return n * add(n,k - 1);
//}
//
//
//int main()
//{
//	int n;
//	int k;
//	scanf("%d", &n);
//	scanf("%d", &k);
//	printf("%d", add(n, k));
//
//	return 0;
//}

////递归和非递归分别实现求第n个斐波那契数
////
////例如：
////
////输入：5  输出：5
////
////输入：10， 输出：55
////
////输入：2， 输出：1
//
//#include <stdio.h>
//
//int add(int n)
//{
//	if (n == 1 || n == 2) return 1;
//	else
//		return add(n - 1) + add(n - 2);
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d", add(n));
//	return 0;
//}
#include <stdio.h>

int add(int n)
{
	if (n == 1 || n == 2) return 1;
	else
		return add(n - 1) + add(n - 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", add(n));
	return 0;
}