#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//直接插入排序
void InsertSort(int* arr, int n);

//希尔排序
void ShellSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//hoare
int _QuickSort(int* a, int left, int right);

//挖坑法
int _QuickSort2(int* a, int left, int right);

//lomuto前后指针
int _QuickSort3(int* a, int left, int right);

//非递归快排
void QuickSortNonR(int* a, int left, int right);

//快速排序
void QuickSort(int* a, int left, int right);

//归并排序
void _MergeSort(int* a, int left, int right, int* tmp);

void MergeSort(int* a, int n);

//计数排序
void CountSort(int* a, int n);