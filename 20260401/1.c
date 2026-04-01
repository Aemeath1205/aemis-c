#define _CRT_SECURE_NO_WARNINGS
//1. 两数比较与排序：输入两个整数，输出较大值、较小值，并按从小到大顺序输出这两个数。
//示例 / 得分点：输入8 3，输出max = 8, min = 3, 3 8
//要求：使用if else语句
#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	if (a > b)
//	{
//		printf("max=%d\n", a);
//		printf("min=%d\n", b);
//		printf("%d\n%d", a, b);
//	}
//	if (a < b)
//	{
//		printf("max=%d\n", b);
//		printf("min=%d\n", a);
//		printf("%d\n%d", a, b);
//	}
// 
//
//
//	return 0;
//}

//2. 简单计算器：输入两个整数和一个运算符，使用 switch 实现加、减、乘、除运算。
//示例 / 得分点1：输入18 * 6，输出108
//示例 / 得分点2：输入18 / 0，输出除数为0
//要求：使用swtich语句，能够处理非法运算符和除数为0的情况


//int main() {
//    int a, b, result;
//    char op;
//    printf("请输入表达式：");
//    scanf("%d%c%d", &a, &op, &b);
//
//    switch (op) {
//    case '+':
//        result = a + b;
//        printf("%d\n", result);
//        break;
//    case '-':
//        result = a - b;
//        printf("%d\n", result);
//        break;
//    case '*':
//        result = a * b;
//        printf("%d\n", result);
//        break;
//    case '/':
//        if (b == 0) {
//            printf("除数为0\n");
//        }
//        else {
//            printf("%d\n", a / b);
//        }
//        break;
//    default:
//        printf("非法运算符\n");
//    }
//    return 0;
//}

//s

//累加求和：使用 while 语句计算 1~n 的和并输出
//?示例 / 得分点：输入10，输出55
//?要求：使用while语句实现

//#include <stdio.h>
//int main()
//{
//    int n;
//    int sum = 0;
//    int i = 1;
//    printf("n=");
//    scanf("%d", &n);
//
//    while (i <= n) 
//    {
//        sum += i;
//        i++;
//    }
//
//    printf("%d\n", sum);
//    return 0;
//}

//合法字符输入：使用 do...while 编写程序，要求用户输入下列字符之一：y Y n N，若输入非法，则反复提示，直到输入合法为止。
//?示例 / 得分点：输入x，输出“please input the correct char”，并继续输入Y，输出“OK”
//?要求：使用 do...while语句

//#include <stdio.h>
//int main()
// {
//    char c;
//    do {
//        printf("请输入字符(y/Y/n/N)：");
//        scanf(" %c", &c);
//        if (!(c == 'y' || c == 'Y' || c == 'n' || c == 'N'))
//        {
//            printf("please input the correct char\n");
//        }
//    } 
//    while (!(c == 'y' || c == 'Y' || c == 'n' || c == 'N'));
//
//    printf("OK\n");
//    return 0;
//}

//使用 for 循环输出 1~120 中所有能被 4 整除但不能被 6 整除的整数，并统计个数。
//?要求：使用for循环语句，使用continue语句

//#include <stdio.h>
//int main() {
//    int count = 0;
//    printf("符合条件的数：\n");
//    for (int i = 1; i <= 120; i++) {
//        // 不满足条件直接跳过本次循环
//        if (i % 4 != 0 || i % 6 == 0) {
//            continue;
//        }
//        printf("%d ", i);
//        count++;
//    }
//    printf("\n符合条件的个数为：%d\n", count);
//    return 0;
//}

//输出100~999之间的所有水仙花数，所谓水仙花数，是指一个三位数，其各位数字立方和等于该数本身。
//?例如，153 = 1 ^ 3 + 5 ^ 3 + 3 ^ 3，153即为一个水仙花数


#include <stdio.h>
int main() 
{
    int bai = 0;
    int shi = 0;
    int ge = 0;

    printf("100~999之间的水仙花数：\n");
    for (int num = 100; num <= 999; num++) {
        bai = num / 100;       // 分解百位
        shi = num / 10 % 10;  // 分解十位
        ge = num % 10;        // 分解个位
        // 判断立方和是否等于自身
        if (bai * bai * bai + shi * shi * shi + ge * ge * ge == num) {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}