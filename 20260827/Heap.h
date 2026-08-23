#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap {
	HPDataType* arr;
	int size;//有效数据个数
	int capacity;//实际空间大小
}HP;

//初始化
void HPInit(HP* php);

//销毁
void HPDestroy(HP* php);

//检查扩容
void CheckCapacity(HP* php);

//堆的插⼊
void HPPush(HP* php, HPDataType x);

//取堆顶的数据
HPDataType HPTop(HP* php);

// 删除堆顶的数据
void HPPop(HP* php);

// 判空
bool HPEmpty(HP* php);

//求size
int HPSize(HP* php);

