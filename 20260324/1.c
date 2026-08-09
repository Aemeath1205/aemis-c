#define _CRT_SECURE_NO_WARNINGS

//课后题 1：编写求最大值函数
//题目：编写一个函数 int max2(int a, int b)，返回两个整数中的较大值。在main()中输入两个整数，调用该函数并输出较大值。
//要求：1.必须使用自定义函数 2. 自定义函数有返回值 3.主函数中完成输入和输出

#include <stdio.h>

//
//max2(int a, int b) {
//    if (a > b) {
//        return a;
//    }
//    else {
//        return b;
//    }
//}
//
//int main() {
//    int num1, num2;
//    // 提示用户输入两个整数
//    printf("请输入两个整数，用空格分隔：");
//    // 读取用户输入的两个整数
//    scanf("%d %d", &num1, &num2);
//    // 调用 max2 函数获取较大值
//    int max = max2(num1, num2);
//    // 输出较大值
//    printf("两个数中的较大值是：%d\n", max);
//    return 0;
//}


//课后题 2：用函数求数组元素之和
//题目：定义一个一维整型数组，存放5个整数。编写函数int sumArray(int a[], int n)，求数组前 n 个元素之和。在main()中输入5个整数，调用函数并输出结果。
//要求：1.使用数组作为函数参数；2.n由主函数传入；3.输出总和



//int sumArray(int a[], int n) {
//    int sum = 0;
//    for (int i = 0; i < n; i++) {
//        sum += a[i];
//    }
//    return sum;
//}
//
//int main() {
//    int arr[5];
//    // 提示用户输入 5 个整数
//    printf("请输入 5 个整数，用空格分隔：");
//    for (int i = 0; i < 5; i++) {
//        // 读取用户输入的整数存入数组
//        scanf("%d", &arr[i]);
//    }
//    // 调用 sumArray 函数计算数组元素之和
//    int result = sumArray(arr, 5);
//    // 输出数组元素之和
//    printf("数组元素的总和是：%d\n", result);
//    return 0;
//}



//课后题 3：求数组最大值和最小值
//题目：输入8个整数，存入一维数组。分别编写两个函数：int getMax(int a[], int n); int getMin(int a[], int n); 调用这两个函数，输出数组中的最大值和最小值。
//要求：不允许直接在main()中写完整求最大最小逻辑，必须通过函数完成

#include <stdio.h>

// 定义函数 getMax，用于求数组中的最大值
//int getMax(int a[], int n) {
//    int max = a[0];
//    for (int i = 1; i < n; i++) {
//        if (a[i] > max) {
//            max = a[i];
//        }
//    }
//    return max;
//}
//
//// 定义函数 getMin，用于求数组中的最小值
//int getMin(int a[], int n) {
//    int min = a[0];
//    for (int i = 1; i < n; i++) {
//        if (a[i] < min) {
//            min = a[i];
//        }
//    }
//    return min;
//}
//
//int main() {
//    int arr[8];
//    // 提示用户输入 8 个整数
//    printf("请输入 8 个整数，用空格分隔：");
//    for (int i = 0; i < 8; i++) {
//        // 读取用户输入的整数存入数组
//        scanf("%d", &arr[i]);
//    }
//    // 调用 getMax 函数获取最大值
//    int max = getMax(arr, 8);
//    // 调用 getMin 函数获取最小值
//    int min = getMin(arr, 8);
//    // 输出最大值和最小值
//    printf("数组中的最大值是：%d\n", max);
//    printf("数组中的最小值是：%d\n", min);
//    return 0;
//}



//
//课后题 4：二维数组求每行元素之和
//题目：定义一个3×4的二维整型数组，输入12个整数。编写程序输出每一行元素的和。
//要求：1.使用二维数组；2.使用循环嵌套；3.输出格式例如：
//第1行和：xx
//第2行和：xx
//第3行和：xx

//#include <stdio.h>
//
//#define ROWS 3
//#define COLS 4
//
//int main() {
//    int arr[ROWS][COLS];
//    // 提示用户输入 12 个整数
//    printf("请输入 12 个整数，按行依次输入，用空格分隔：\n");
//    for (int i = 0; i < ROWS; i++) {
//        for (int j = 0; j < COLS; j++) {
//            // 读取用户输入的整数存入二维数组
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    for (int i = 0; i < ROWS; i++) {
//        int rowSum = 0;
//        for (int j = 0; j < COLS; j++) {
//            // 计算每行元素的和
//            rowSum += arr[i][j];
//        }
//        // 输出每行元素的和
//        printf("第%d行和：%d\n", i + 1, rowSum);
//    }
//    return 0;
// 
// 
//}





//课后题 5：统计字符串长度
//题目：输入一个字符串（不含空格），存入字符数组。编写函数int myLen(char s[])，不调用strlen，自己统计字符串长度并输出。
//要求：1.使用字符数组；2.通过判断 '\0' 结束；3.不允许直接用库函数 strlen


#include <stdio.h>

// 定义函数 myLen，用于统计字符串的长度
int myLen(char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    char str[100];
    // 提示用户输入一个不含空格的字符串
    printf("请输入一个不含空格的字符串：");
    // 读取用户输入的字符串
    scanf("%s", str);
    // 调用 myLen 函数计算字符串长度
    int length = myLen(str);
    // 输出字符串长度
    printf("字符串的长度是：%d\n", length);
    return 0;
}