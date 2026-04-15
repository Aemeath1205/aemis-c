#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <math.h>
//
//int main() {
//    // 1. 初始化随机数种子，保证每次运行生成不同随机序列
//    srand((unsigned int)time(NULL));
//
//    int arr[100];
//    // 2. 生成[0, 100]范围内的随机数并存入数组
//    for (int i = 0; i < 100; i++) {
//        // rand() % 101 即可得到0到100的整数
//        arr[i] = rand() % 101;
//    }
//
//    // 3. 计算均值
//    double sum = 0.0;
//    for (int i = 0; i < 100; i++) {
//        sum += arr[i];
//    }
//    double mean = sum / 100;
//
//    // 4. 计算标准偏差（样本标准差）
//    double variance_sum = 0.0;
//    for (int i = 0; i < 100; i++) {
//        variance_sum += (arr[i] - mean) * (arr[i] - mean);
//    }
//    // 除以n-1得到样本无偏估计，如果计算总体标准差可以改为除以100
//    double std_dev = sqrt(variance_sum / (100 - 1));
//
//    // 5. 输出结果
//    printf("生成的100个随机数:\n");
//    for (int i = 0; i < 100; i++) {
//        printf("%d ", arr[i]);
//        // 每10个数换行，方便查看
//        if ((i + 1) % 10 == 0) {
//            printf("\n");
//        }
//    }
//    printf("\n均值 = %.4f\n", mean);
//    printf("标准偏差 = %.4f\n", std_dev);
//
//    return 0;
//}

#/*include <stdio.h>
int main() {
    int arr[] = { 34, 91, 85, 59, 29, 93, 56, 12, 88, 72 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0], min_index = 0;

    for (int i = 1; i < len; i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }
    printf("最小数为: %d，其下标为: %d\n", min, min_index);
    return 0;
}*/

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define N 5
//int main() {
//    int X[N][N], Y[N][N], Z[N][N];
//    srand((unsigned int)time(NULL));
//
//    // 生成两个5阶随机矩阵，元素范围0~9
//    printf("矩阵X:\n");
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            X[i][j] = rand() % 10;
//            printf("%2d ", X[i][j]);
//        }
//        printf("\n");
//    }
//
//    printf("\n矩阵Y:\n");
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            Y[i][j] = rand() % 10;
//            printf("%2d ", Y[i][j]);
//        }
//        printf("\n");
//    }
//
//    // 矩阵乘法 Z = X * Y
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            Z[i][j] = 0;
//            for (int k = 0; k < N; k++) {
//                Z[i][j] += X[i][k] * Y[k][j];
//            }
//        }
//    }
//
//    printf("\n乘积矩阵Z = X * Y:\n");
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            printf("%4d ", Z[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//
//#include <stdio.h>
//int main() {
//    int arr[] = { 34, 91, 85, 59, 29, 93, 56, 12, 88, 72 };
//    int len = sizeof(arr) / sizeof(arr[0]);
//
//    printf("排序前数组: ");
//    for (int i = 0; i < len; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//
//    // 选择排序
//    for (int i = 0; i < len - 1; i++) {
//        int min_idx = i;
//        // 找剩余未排序元素中最小值下标
//        for (int j = i + 1; j < len; j++) {
//            if (arr[j] < arr[min_idx])
//                min_idx = j;
//        }
//        // 交换到当前位置
//        if (min_idx != i) {
//            int temp = arr[i];
//            arr[i] = arr[min_idx];
//            arr[min_idx] = temp;
//        }
//    }
//
//    printf("排序后数组: ");
//    for (int i = 0; i < len; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//    return 0;
//}

#include <stdio.h>
int main() {
    int arr[] = { 34, 91, 85, 59, 29, 93, 56, 12, 88, 72 };
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("排序前数组: ");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // 冒泡排序
    for (int i = 0; i < len - 1; i++) {
        // 每一轮确定一个最大元素到末尾，所以只需要比较到 len-i-1
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("排序后数组: ");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}