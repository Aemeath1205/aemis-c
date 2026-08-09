#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {

	return 0;
}

int main3() {
	//计算1~100之间3的倍数的数字之和
	int sum = 0;
	int i = 1;
	for (i = 1; i <= 100; i++) {
		if (i % 3 == 0) {
			sum += i;
		}
	}
	printf("%d\n", sum);
	return 0;
}

int main2() {
	//输⼊：1234，输出：4 3 2 1
	//	输⼊：521，输出：1 2 5
	int a = 0;
	printf("输入一个数字以逆序打印:");
	scanf("%d", &a);
	while (a!=0) {
		printf("%d", a % 10);
		a /= 10;
	}
	return 0;
}

int main1() {
	//int a = 0;
	int b = 0;
	printf("输入一个数字：");
	scanf("%d", &b);
	if (b % 400 == 0 || (b % 4 == 0 && b % 100 != 0)) {
		printf("%d是一个闰年", b);
	}
	else {
		printf("%d不是一个闰年", b);
	}
	return 0;
}