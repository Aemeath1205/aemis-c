#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//void swap_pointer(double* pa, double* pb) {
//    double temp = *pa;
//    *pa = *pb;
//    *pb = temp;
//}
//
//int main() {
//    double a, b;
//    printf("请输入两个双精度数（空格分隔）：");
//    scanf("%lf %lf", &a, &b);
//    printf("\n======== 交换前 =========\n");
//    printf("a = %.2lf, b = %.2lf\n", a, b);
//    swap_pointer(&a, &b);
//    printf("\n======== 交换后 =========\n");
//    printf("a = %.2lf, b = %.2lf\n", a, b);
//    return 0;
//}


//#include <stdio.h>
//
//
//#define MAX = 10;
//
//
//void matrix_multiply(
//    double X[][MAX],
//    double Y[][MAX],
//    double Z[][MAX],
//    int m,
//    int p,
//    int n
//) {
//    
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            Z[i][j] = 0.0;
//        }
//    }
//
//    // 矩阵乘法核心公式：Z[i][j] = 累加k从0到p-1 X[i][k] * Y[k][j]
//    for (int i = 0; i < m; i++) {     // 遍历结果矩阵Z的行（对应X的行）
//        for (int k = 0; k < p; k++) { // 遍历公共维度p（X的列、Y的行）
//            for (int j = 0; j < n; j++) { // 遍历结果矩阵Z的列（对应Y的列）
//                Z[i][j] += X[i][k] * Y[k][j];
//            }
//        }
//    }
//}
//
//int main() {
//    int m, p, n;
//    double X[MAX][MAX], Y[MAX][MAX], Z[MAX][MAX];
//
//    // 1. 输入三个维度参数
//    printf("请输入矩阵维度m（X行数）、p（X列数/Y行数）、n（Y列数）：");
//    scanf("%d %d %d", &m, &p, &n);
//
//    // 维度合法性校验（保证不超过最大10×10）
//    if (m < 1 || p < 1 || n < 1 || m > MAX || p > MAX || n > MAX) {
//        printf("错误：维度必须为正整数，且最大不超过%d×%d\n", MAX, MAX);
//        return 1;
//    }
//
//    // 2. 输入第一个矩阵X（m行p列）
//    printf("\n请输入矩阵X（%d行%d列），逐行输入元素：\n", m, p);
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < p; j++) {
//            scanf("%lf", &X[i][j]);
//        }
//    }
//
//    // 3. 输入第二个矩阵Y（p行n列）
//    printf("\n请输入矩阵Y（%d行%d列），逐行输入元素：\n", p, n);
//    for (int i = 0; i < p; i++) {
//        for (int j = 0; j < n; j++) {
//            scanf("%lf", &Y[i][j]);
//        }
//    }
//
//    // 4. 调用题目要求的乘法函数
//    matrix_multiply(X, Y, Z, m, p, n);
//
//    // 5. 对齐输出结果矩阵Z
//    printf("\n矩阵乘积结果 Z = X × Y：\n");
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            // 固定占8个字符宽度，保留2位小数，保证输出整齐
//            printf("%8.2lf", Z[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}

//#include <stdio.h>
//
//// 严格按照题目要求保留const全局变量
//const int MAX = 10;
//
//void matrix_multiply(
//    double X[][10],
//    double Y[][10],
//    double Z[][10],
//    int m,
//    int p,
//    int n
//) {
//    int i, j, k;
//    for (i = 0; i < m; i++) {
//        for (j = 0; j < n; j++) {
//            Z[i][j] = 0.0;
//        }
//    }
//    for (i = 0; i < m; i++) {
//        for (k = 0; k < p; k++) {
//            for (j = 0; j < n; j++) {
//                Z[i][j] += X[i][k] * Y[k][j];
//            }
//        }
//    }
//}
//
//int main() {
//    int m, p, n, i, j;
//    double X[10][10], Y[10][10], Z[10][10];
//
//    printf("请输入矩阵维度m（X行数）、p（X列数/Y行数）、n（Y列数）：");
//    scanf("%d %d %d", &m, &p, &n);
//
//    if (m < 1 || p < 1 || n < 1 || m > 10 || p > 10 || n > 10) {
//        printf("错误：维度必须为正整数，且最大不超过10×10\n");
//        return 1;
//    }
//
//    printf("\n请输入矩阵X（%d行%d列），逐行输入元素：\n", m, p);
//    for (i = 0; i < m; i++) {
//        for (j = 0; j < p; j++) {
//            scanf("%lf", &X[i][j]);
//        }
//    }
//
//    printf("\n请输入矩阵Y（%d行%d列），逐行输入元素：\n", p, n);
//    for (i = 0; i < p; i++) {
//        for (j = 0; j < n; j++) {
//            scanf("%lf", &Y[i][j]);
//        }
//    }
//
//    matrix_multiply(X, Y, Z, m, p, n);
//
//    printf("\n矩阵乘积结果 Z = X × Y：\n");
//    for (i = 0; i < m; i++) {
//        for (j = 0; j < n; j++) {
//            printf("%8.2lf", Z[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}
//编写函数，求一元二次方程的实根
//编写函数 solve_quadratic，求一元二次方程：
//ax2 + bx + c = 0
//
//的实数根。编写函数判断方程根的情况，若有两个不相等实根，输出两个实根；若有两个相等实根，输出该实根；若无实根，输出“方程无实数根”。要求使用指针参数或引用参数返回根的值。
//提示：在主函数中输入 a、b、c；
//int solve_quadratic(double a, double b, double c, double* x1, double* x2);
//
//代码撰写：

//#include <stdio.h>
//#include <math.h>
//
//// 完全按照题目要求声明函数，使用指针参数返回根
//int solve_quadratic(double a, double b, double c, double* x1, double* x2) {
//    // 计算判别式 delta = b? - 4ac
//    double delta = b * b - 4 * a * c;
//
//    if (delta < 0) {
//        // 判别式小于0：无实根，返回0标记
//        return 0;
//    }
//    else if (fabs(delta) < 1e-9) {
//        // 判别式约等于0：两个相等实根，返回1标记
//        *x1 = -b / (2 * a);
//        return 1;
//    }
//    else {
//        // 判别式大于0：两个不等实根，返回2标记
//        double sqrt_delta = sqrt(delta);
//        *x1 = (-b + sqrt_delta) / (2 * a);
//        *x2 = (-b - sqrt_delta) / (2 * a);
//        return 2;
//    }
//}
//
//int main()
//{
//    double a, b, c, x1, x2;
//    printf("请输入一元二次方程的系数a、b、c：");
//    scanf("%lf %lf %lf", &a, &b, &c);
//
//    // 处理a=0的特殊情况（不是一元二次方程）
//    if (fabs(a) < 1e-9) {
//        printf("错误：a不能为0，这不是一元二次方程\n");
//        return 1;
//    }
//
//    int root_num = solve_quadratic(a, b, c, &x1, &x2);
//    switch (root_num) {
//    case 0:
//        printf("方程无实数根\n");
//        break;
//    case 1:
//        printf("方程有两个相等实根：%.2lf\n", x1);
//        break;
//    case 2:
//        printf("方程有两个不相等实根：x1 = %.2lf，x2 = %.2lf\n", x1, x2);
//        break;
//    default:
//        printf("未知错误\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//
//// 严格按照题目要求声明函数，使用指针参数接收数组
//void reverse_array(int* p, int n) {
//    int* start = p;       // 指针指向数组首元素
//    int* end = p + n - 1; // 指针指向数组末元素
//    int temp;
//
//    // 首尾指针逐步向中间逼近，交换对应元素，全程只用指针访问，不使用下标
//    while (start < end) {
//        temp = *start;   // 取出首指针指向的值
//        *start = *end;   // 将末指针值赋值给首指针
//        *end = temp;     // 将原首值赋值给末指针
//
//        start++; // 首指针后移
//        end--;   // 末指针前移
//    }
//}
//
//int main() {
//    int n, i;
//    printf("请输入数组长度：");
//    scanf("%d", &n);
//
//    if (n <= 0) {
//        printf("错误：数组长度必须为正整数\n");
//        return 1;
//    }
//
//    int arr[n]; // 定义变长数组（兼容C99及以上标准，大部分编译器支持）
//    printf("请输入数组的%d个元素：", n);
//    for (i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    // 输出逆序前数组
//    printf("\n逆序前数组：");
//    for (i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//
//    // 调用逆序函数
//    reverse_array(arr, n);
//
//    // 输出逆序后数组
//    printf("\n逆序后数组：");
//    for (i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//void reverse_array(int* p, int n) {
//    int* start = p;
//    int* end = p + n - 1;
//    int temp;
//    while (start < end) {
//        temp = *start;
//        *start = *end;
//        *end = temp;
//        start++;
//        end--;
//    }
//}
//
//int main() {
//    int n, i, * arr;
//    printf("请输入数组长度：");
//    scanf("%d", &n);
//
//    if (n <= 0) {
//        printf("错误：数组长度必须为正整数\n");
//        return 1;
//    }
//
//    // 动态分配数组，兼容所有C标准，解决不支持变长数组报错
//    arr = (int*)malloc(n * sizeof(int));
//    if (arr == NULL) {
//        printf("内存分配失败\n");
//        return 1;
//    }
//
//    printf("请输入数组的%d个元素：", n);
//    for (i = 0; i < n; i++) {
//        scanf("%d", arr + i);
//    }
//
//    printf("\n逆序前数组：");
//    for (i = 0; i < n; i++) {
//        printf("%d ", *(arr + i));
//    }
//
//    reverse_array(arr, n);
//
//    printf("\n逆序后数组：");
//    for (i = 0; i < n; i++) {
//        printf("%d ", *(arr + i));
//    }
//    printf("\n");
//
//    free(arr); // 释放动态分配的内存
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>

// 严格按照题目要求声明函数，全部使用一维指针，通过地址偏移访问元素
void matrix_multiply(const double* X, const double* Y, double* Z, int m, int p, int n) {
    // 初始化结果矩阵全部元素为0
    for (int i = 0; i < m * n; i++) {
        *(Z + i) = 0;
    }

    // 矩阵乘法核心：Z[i][j] = Σ(k=0到p-1) X[i][k] * Y[k][j]
    // 一维模拟二维的索引转换：i行j列 → 索引 = i*列数 + j
    for (int i = 0; i < m; i++) {          // X的行 / Z的行
        for (int k = 0; k < p; k++) {      // X的列 / Y的行
            double x_ik = *(X + i * p + k); // X[i][k]，通过地址偏移获取
            for (int j = 0; j < n; j++) {  // Y的列 / Z的列
                double y_kj = *(Y + k * n + j); // Y[k][j]，通过地址偏移获取
                *(Z + i * n + j) += x_ik * y_kj; // Z[i][j]累加结果
            }
        }
    }
}

int main() {
    int m, p, n;
    double* X, * Y, * Z;

    // 1. 输入矩阵规模
    printf("请输入三个正整数 m p n (X是m×p，Y是p×n，Z是m×n)：");
    scanf("%d %d %d", &m, &p, &n);

    if (m <= 0 || p <= 0 || n <= 0) {
        printf("错误：矩阵维度必须为正整数！\n");
        return 1;
    }

    // 2. 动态申请一维数组存储空间模拟二维矩阵
    X = (double*)malloc(m * p * sizeof(double));
    Y = (double*)malloc(p * n * sizeof(double));
    Z = (double*)malloc(m * n * sizeof(double));

    if (X == NULL || Y == NULL || Z == NULL) {
        printf("错误：内存分配失败！\n");
        // 提前退出前释放已分配内存，避免泄漏
        if (X != NULL) free(X);
        if (Y != NULL) free(Y);
        if (Z != NULL) free(Z);
        return 1;
    }

    // 3. 输入矩阵X的元素
    printf("\n请输入矩阵X（%d行%d列）的元素：\n", m, p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%lf", X + i * p + j);
        }
    }

    // 输入矩阵Y的元素
    printf("\n请输入矩阵Y（%d行%d列）的元素：\n", p, n);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", Y + i * n + j);
        }
    }

    // 4. 调用矩阵乘法函数
    matrix_multiply(X, Y, Z, m, p, n);

    // 5. 输出结果矩阵Z
    printf("\n矩阵乘积Z = X×Y 的结果（%d行%d列）：\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f\t", *(Z + i * n + j)); // 制表符分隔对齐
        }
        printf("\n");
    }

    // 6. 释放动态申请的内存
    free(X);
    free(Y);
    free(Z);

    return 0;
}