#pragma once
#include <stdio.h>
#include <stdlib.h>

//动态顺序表的定义

typedef int SLDataType;

struct SeqList {
	SLDataType* arr;
	int used_size;
	int real_size;
};

typedef struct SeqList SL;

//初始化
void SLInit(SL* s);

//尾插
void SLPushBack(SL* s, SLDataType x);

//尾删
void SLRemoveBack(SL* s);

//头插
void SLPushFront(SL* s, SLDataType x);

//头删
void SLRemoveFront(SL* s);

//指定位置之前插?
void SLInsert(SL* s, int pos, SLDataType x);

//指定位置删除数据
void SLErase(SL* s, int pos);

int SLFind(SL* s, SLDataType x);

void SLPrint(SL* s);