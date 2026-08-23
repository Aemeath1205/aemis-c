#include "Sort.h";

void main() {
	int arr[] = { 9,8,7,6,5 };
	SelectSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
}

void main2() {
	int arr[] = { 9,8,7,6,5 };
	ShellSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
}

void main1() {
	int arr[] = { 9,8,7,6,5 };
	InsertSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
}


