#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main() {
//    int a, b, c, max;
//    printf("第一个整数: ");
//    scanf("%d", &a);
//    printf("第二个整数: ");
//    scanf("%d", &b);
//    printf("第三个整数: ");
//    scanf("%d", &c);
//
//    // 比较大小找出最大值
//    if (a >= b) {
//        if (a >= c) {
//            max = a;
//        }
//        else {
//            max = c;
//        }
//    }
//    else {
//        if (b >= c) {
//            max = b;
//        }
//        else {
//            max = c;
//        }
//    }
//
//    // 输出最大值
//    printf("最大值是: %d\n", max);
//
//    return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int kwh;
//    double total_fee;
//    // 输入用电量
//    printf("请输入用电量（度）: ");
//    scanf("%d", &kwh);
//
//    // 根据不同的用电量区间计算电费
//    if (kwh <= 100) {
//        total_fee = kwh * 0.5;
//    }
//    else if (kwh <= 200) {
//        total_fee = 100 * 0.5 + (kwh - 100) * 0.8;
//    }
//    else {
//        total_fee = 100 * 0.5 + 100 * 0.8 + (kwh - 200) * 1.2;
//    }
//
//    // 输出总电费
//    printf("总电费是: %.2f 元\n", total_fee);
//
//    return 0;
//}

#include <stdio.h>

int main() {
    double left, right, result;
    char operator;
    // 输入表达式
    printf("请输入表达式（格式：Left Operator Right）: ");
    scanf("%lf %c %lf", &left, &operator, &right);

    // 根据运算符进行计算
    switch (operator) {
    case '+':
        result = left + right;
        printf("计算结果是: %.2f\n", result);
        break;
    case '-':
        result = left - right;
        printf("计算结果是: %.2f\n", result);
        break;
    case '*':
        result = left * right;
        printf("计算结果是: %.2f\n", result);
        break;
    case '/':
        if (right == 0) {
            printf("Division by zero\n");
        }
        else {
            result = left / right;
            printf("计算结果是: %.2f\n", result);
        }
        break;
    default:
        printf("Invalid operator\n");
    }

    return 0;
}