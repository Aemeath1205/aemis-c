#define _CRT_SECURE_NO_WARNINGS
//在一个整型数组中，只有一个数字出现一次，其他数组都是成对出现的，请找出那个只出现一次的数字。
//例如：
//数组中有：1 2 3 4 5 1 2 3 4，只有5出现一次，其他数字都出现2次，找出5

//#include <stdio.h>
//int main()
//{
//	int arr[9] = { 1,2,3,4,1,2,3,4,5 };
//	int x;
//	for (x = 0; x <= 8; x++)
//	{
//		int count = 0;
//		for (int y = 0; y <= 8; y++)
//		{
//			if (y!=x)
//			{
//				if (arr[x] == arr[y])
//					count++;
//			}
//		}
//		if (count == 0)
//			printf("%d ", arr[x]);
//	}
//	return 0;
//}


//不允许创建临时变量，交换两个整数的内容

//#include <stdio.h>
//int main()
//{
//	int a = 1;//001
//	int b = 2;//010
//	a = a ^ b;//011
//	b = a ^ b;//001
//	a = a ^ b;//010
//	printf("%d %d", a, b);
//	return 0;
//}

//写一个函数返回参数二进制中 1 的个数。
//
//比如： 15    0000 1111    4 个 1

#include <stdio.h>
int main()
{
	int num = 0;
	scanf("%d", &num);
	int count = 0;
	while (num)
	{
		count++;
		num = num & (num - 1);//0001101（1
                            //0001100  （2
                            //0001011
                            //0001000    （3
                            //0000111
	}
	printf("%d",count);
	return 0;
}



//#include <stdio.h>
//
//void print_odd_even_bits(int num) {
//    // 打印奇数位（从右向左数，第1、3、...、31位）
//    printf("奇数位二进制序列：");
//    for (int i = 30; i >= 0; i -= 2) {
//        // 将num右移i位，再和1按位与，提取当前位的值
//        printf("%d ", (num >> i) & 1);
//    }
//    printf("\n");
//
//    // 打印偶数位（从右向左数，第2、4、...、32位）
//    printf("偶数位二进制序列：");
//    for (int i = 31; i >= 1; i -= 2) {
//        printf("%d ", (num >> i) & 1);
//    }
//    printf("\n");
//}
//
//int main() {
//    int num;
//    printf("请输入一个整数：");
//    scanf("%d", &num);
//    print_odd_even_bits(num);
//    return 0;
//}
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
//#include <stdio.h>
//void add(int a)
//{
//	//打印奇数位
//	printf("奇数位");
//	for (int n = 31; n >= 1; n -= 2)
//	{
//		printf("%d ", (a >> n) & 1);
//	}
//	printf("/n");
//	//打印偶数位
//	printf("偶数位");
//	for (int n = 30; n >= 2; n -= 2)
//	{
//		printf("%d ", (a >> n) & 1);
//	}
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	add(a);
//	return 0;
//}

//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//
//输入例子 :
//
//1999 2299
//
//输出例子 : 7
#include <stdio.h>
int main()
{
	int m;
	int n;
	scanf("%d %d", &m, &n);
	int count = 0;
	while (m!=0&&n!=0)
	{
		if ((m >> 31) != (n >> 31))
		   count++;
		m =(m << 1);
		n =(n << 1);
	}
	printf("%d", count);
	return 0;
}

