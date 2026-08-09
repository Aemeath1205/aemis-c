#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main1() {
	char string1[] = "abcd";
	int num = sizeof(string1) / sizeof(string1[0]);
	printf("%d", num);//5
	return 0;
}

int main2() {
	char string1[] = { 'a','b','c','d' };
	int num = sizeof(string1) / sizeof(string1[0]);
	printf("%d", num);//4
	return 0;
}

int main3() {
	//int array[] = { 1,2,3,4,5,6,7,8,9,10 };
	//for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
	//	printf("%d", array[i]);
	//}

	//int array[2][3];
	//for (int i = 0; i < 2; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		scanf("%d", &array[i][j]);
	//	}
	//}
	//for (int i = 0; i < 2; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		printf("%d", array[i][j]);
	//	}
	//}

	//二分查找
	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//int tofind;
	//printf("输入一个你想找的数字");
	//scanf("%d", &tofind);
	//int left = 0;
	//int right = sizeof(arr) / sizeof(arr[0]) - 1;
	//int mid = (left + right) / 2;
	//while (left != right) {
	//	if (arr[mid] < tofind) {
	//		left = mid;
	//		int mid = (left + right) / 2;
	//		continue;
	//	}
	//	else if (arr[mid] > tofind) {
	//		right = mid;
	//		int mid = (left + right) / 2;
	//		continue;
	//	}
	//	else {
	//		printf("找到了孩子，下标是%d", mid);
	//		break;
	//	}
	//}
	//if (arr[mid] != tofind) {
	//	printf("nothing found by tofind num");
	//

}
//n的阶乘
//int func(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	return n * func(n - 1);
//}
//
//int main() {
//	printf("%d", func(3));
//	return 0;
//}
void print_everyone(int n) {
	if (n / 10 == 0) {
		printf("%d", n);
		return;
	}
	print_everyone(n / 10);
	printf("%d", n % 10);
}

int main() {
	print_everyone(1234);
	return 0;
}