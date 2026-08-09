#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void printbyzhen(int a) {
	if (a == 0) {
		return;
	}
	
	printbyzhen(a / 10);
	printf("%d", a % 10);
}
void main() {
	int a;
	scanf("%d", &a);
	printbyzhen(a);
}




void main1() {
	int a = 5;
	printf("%d", sqart(a));
}

int sqart(int a){
	if (a == 1) {
		return 1;
	}
	return a * sqart(a - 1);
}