#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//// 保留你的全局变量定义
//int Sn = 0;
//
//// 保留你的递归函数结构，只做格式整理
//int print(int n, int x) 
//{
//    if (x > 0) 
//    {
//        int i = print(n, x - 1) * 10 + n;
//        Sn += i;
//        return i;  // 必须返回当前构造的项，供上层递归使用
//    }
//    return 0;  // 递归终止条件：x=0时返回0
//}
//
//int main() {
//    int n, c;
//    Sn = 0;  // 初始化全局变量，避免多次运行时累加旧值
//    // 修正1：你的原代码少写了%d中的%，格式符错误
//    scanf("%d", &n);
//    c = print(n, 5);
//    // 修正2：打印总和Sn，而不是返回值c（c只是最后一项）
//    printf("%d", Sn);
//    return 0;
//}