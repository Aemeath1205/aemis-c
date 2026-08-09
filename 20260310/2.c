#include <stdio.h>

int main() {
    int k = 3;
    // 后置自增运算符，先使用 k 的值，再对 k 进行自增
    printf("%d %d\n", k++, k);

    k = 3;
    // 前置自增运算符，先对 k 进行自增，再使用 k 的值
    printf("%d %d\n", ++k, k);

    k = 3;
    int a = k++ + 5;
    // 先使用 k 的当前值 3 参与运算得到 a = 3 + 5 = 8，然后 k 自增为 4
    printf("%d %d\n", a, k);

    k = 3;
    int b = ++k + 5;
    // 先将 k 自增为 4，然后使用 k 的新值参与运算得到 b = 4 + 5 = 9 
    printf("%d %d\n", b, k);

    return 0;
}