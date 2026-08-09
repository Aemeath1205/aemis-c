#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	printf("hello,c++");
//	return 0;
//}
int main()
{
    int a, b, c;
    printf("请输入三个整数 a、b、c: ");
    scanf("%d %d %d", &a, &b, &c);

    int sum = a + b + c;
    double average = (double)sum / 3;

    printf("和 = %d\n", sum);
    printf("平均值 = %.2f\n", average);
    printf("三个数是否全为正数：%d\n", a > 0 && b > 0 && c > 0);
    printf("是否至少有一个数大于 100：%d\n", a > 100 || b > 100 || c > 100);
    printf("a是否最大：%d\n", a >= b && a >= c);
    return 0;
}