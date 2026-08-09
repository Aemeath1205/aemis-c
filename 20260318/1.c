#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	printf("hello,c++");
//	return 0;
//}

//int main()
//{
//	int age = 18;
//	double height = 180;
//	char grade = 'A';
//	printf("age=%d, height=%.1f, grade=%c\n", age, height, grade);
//	
//	
//	return 0;
//}
//int main()
//{
//    int num1, num2;
//    printf("请输入两个整数: ");
//    scanf("%d %d", &num1, &num2);
//
//    printf("输入的两个整型: %d 和 %d\n", num1, num2);
//    printf("和 = %d\n", num1 + num2);
//    printf("差 = %d\n", num1 - num2);
//    printf("积 = %d\n", num1 * num2);
//    if (num2 != 0) {
//        printf("商 = %.2f\n", (double)num1 / num2);
//        printf("余数 = %d\n", num1 % num2);
//    }
//    else {
//        printf("除数不能为 0，无法计算商和余数。\n");
//    }
//    return 0;
//}
//int main()
//{
//	/*int x;
//	int y;
//	scanf("%d %d", &x, &y);
//	printf()*/
//
//
//    int x, y;
//    printf("请输入两个整数 x 和 y: ");
//    scanf("%d %d", &x, &y);
//
//    printf("x > y: %d\n", x > y);
//    printf("x == y: %d\n", x == y);
//    printf("x != y: %d\n", x != y);
//    printf("(x > 0 && y > 0): %d\n", x > 0 && y > 0);
//    printf("(x > 0 || y > 0): %d\n", x > 0 || y > 0);
//    printf("!(x > y): %d\n", !(x > y));
//	return 0;
//}



int main()
{
	//int a;
	//int b;
	//int c;
	//scanf("%d %d %d", &a, &b, &c);
	//printf("a+b= %d/n", a + b);
	//
    int a, b, c;
    printf("三个整数 a、b、c: ");
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


