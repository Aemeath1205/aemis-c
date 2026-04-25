#define _CRT_SECURE_NO_WARNINGS
//将课堂上所讲使用函数指针数组实现转移表的代码，自己实践后，并提交代码到答案窗口。
//#include <stdio.h>
//int add(int x, int y)
//{
//	return x + y;
//}
//
//int sub(int x, int y)
//{
//	return x - y;
//}
//
//int mul(int x, int y)
//{
//	return x * y;
//}
//
//int div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int x = 9;
//	int y = 3;
//	int input = 0;
//	int(*p[10])(int x, int y) = { 0, add,  sub , mul , div };
//	do
//	{
//		printf("请选择：");
//		printf("0:退出\n1,2,3,4");
//		scanf("%d", &input);
//		if (input <= 4 && input >= 1)
//		{
//			int r = (*p[input])(x, y);
//			printf("%d\n", r);
//		}
//		else if (input == 0)
//			break;
//		else
//		{
//			printf("重新输入");
//		}
//		
//	} while (input);
//
//	return 0;
//}


//练习使用库函数，qsort排序各种类型的数据
//void qsort(void* base, size_t num, size_t size,
//    int (*compar)(const void*, const void*));
//#include <stdio.h>
//#include <stdlib.h>
//int add(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}
//
//int main()
//{
//	int arr[] = { 1,9,2,3,4,5,6,7,8,9 };
//	size_t num = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, num, sizeof(arr[0]), add);
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//void qsort(void* base, size_t num, size_t size,
//	int (*compar)(const void*, const void*));
//#include <stdio.h>
//#include <stdlib.h>
//
//struct stu
//{
//	char name[20];
//	int age;
//};
//
//int stu_com_by_age(const void* p1, const void* p2)
//{
//	return ((struct stu*)p1)->age - ((struct stu*)p2)->age;
//}
//
//void test2()
//{
//	struct stu s[] = { {"zhangsan",20 },{"lisi",30},{"wangwu",15} };
//	size_t sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), stu_com_by_age);
//}
//
//int stu_com_by_name(const void* p1, const void* p2)
//{
//	return strcmp(((struct stu*)p1)->name, ((struct stu*)p2)->name);
//}
//
//void test3()
//{
//	struct stu s[] = { {"zhangsan",20 },{"lisi",30},{"wangwu",15} };
//	size_t sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), stu_com_by_name);
//
//}
//int main()
//{
//	test2();//年龄
//	test3();//名字
//
//	return 0;
//}


//模仿qsort的功能实现一个通用的冒泡排序

#include <stdio.h>
void compare(void*p1, void*p2)
{
	return *(int*)p1 - *(int*)p2;
}

void exchange(void *p1,void *p2,size_t width)
{
	for (int i = 0; i < width; i++)
	{
		char a = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = a;
	}
}

void bubble(void* arr, size_t sz, size_t width, int(*compare)(void*, void*))
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - j; j++)
		{
			if (compare((char*)arr + j * width, (char*)arr + (j + 1) * width) > 0)
			{
				exchange((char*)arr + j * width, (char*)arr + (j + 1) * width, width);
			}
		}
	}
}
int main()
{
	int arr[] = { 1,3,2,4,5,6,7,8,9 };
	size_t sz = sizeof(arr) / sizeof(arr[0]);
	bubble(arr, sz, sizeof(arr[0]), compare);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
