#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d ", arr[i]);
	}
}


//void main() {
//	int a[5] = { 1,2,3,4,5 };
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
//		printf("%d", *(a + i));
//	}
//}

//int my_strelen(char* start) {
//	char* tmp = start;
//	while (*tmp != '\0') {
//		tmp++;
//	}
//	return tmp - start;
//}
//
//void main() {
//	printf("%d", my_strelen("abcd"));
//}