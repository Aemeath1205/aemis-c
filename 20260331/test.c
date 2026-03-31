#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//    int M = 0;
//    scanf("%d", &M);
//    int b = M % 5;
//    if (b == 0)
//        printf("%s\n", "YES");
//    else
//        printf("%s\n", "NO");
//    return 0;
//}

//代码1
#include <stdio.h>
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
//	printf("%d\n", i);
//	return 0;
//}

//写一个代码打印1 - 100之间所有3的倍数的数字
//int main()
//{
//	int i;
//	for (i = 1; i <= 100; i++)
//	{
//		int b = i % 3;
//		if (b==0)
//			printf("%d\n", i);
//	}
//	return 0;
//}

//写代码将三个整数数按从大到小输出。
//
//例如：
//
//输入：2 3 1
//
//输出：3 2 1

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b&& a>c)
	{
		if (b > c)
			printf("%d%d%d", a, b, c);
		else
			printf("%d%d%d", a, c, b);
	}
	//剩下的同上
	

	return 0;
}

