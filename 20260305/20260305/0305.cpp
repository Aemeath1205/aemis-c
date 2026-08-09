#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    // 个人信息
    char name[] = "孟";
    char student_id[] = "160925215";
    char interest[] = "钢琴";

    // 输出信息
    printf("姓名: %-15s\n", name);
    printf("学号: %-15s\n", student_id);
    printf("兴趣: %-15s\n", interest);


    return 0;
}