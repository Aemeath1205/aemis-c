#include "SeqList.h"

//初始化
//注意是传值还是传址
//如果直接用SL接收，相当于是把原结构体拷贝了一份给形参
void SLInit(SL* s) {
	(*s).arr = NULL;
	(*s).used_size = 0;
	(*s).real_size = 0;
}

//尾插
//malloc  申请固定大小的空间
//calloc  malloc+初始化
//realloc 增加空间
void SLPushBack(SL* s, SLDataType x) {
	if (s->used_size < s->real_size) {
		s->arr[s->used_size] = x;
		s->used_size++;
	}
	else if (s->used_size == s->real_size ) {
		int newsize = ((s->real_size == 0) ? 1 : 2 * (s->real_size));
		SLDataType *tmp= (SLDataType*) realloc(s->arr, newsize * sizeof(SLDataType));
		if (tmp == NULL) {
			perror("realloc fail");
			exit(1);
		}
		s->arr = tmp;
		s->arr[s->used_size] = x;
		s->used_size++;
		if (s->real_size == 0) {
			s->real_size = 1;
			return;
		}
		s->real_size *= 2;
	}
}

void SLRemoveBack(SL* s) {
	if (s->arr == NULL || s->used_size == 0) {
		printf("没有数据可以删除");
		exit(1);//return;
	}
	else {
		//s->arr[s->used_size - 1] = 0;
		s->used_size -= 1;
	}
}

void SL_Expand(SL* s) {
	int newsize = ((s->real_size == 0) ? 1 : 2 * (s->real_size));
	SLDataType* tmp = (SLDataType*)realloc(s->arr, newsize * sizeof(SLDataType));
	if (tmp == NULL) {
		perror("realloc fail");
		exit(1);
	}
	s->arr = tmp;
	s->used_size++;
	if (s->real_size == 0) {
		s->real_size = 1;
		return;
	}
	s->real_size *= 2;
}


void SLPushFront(SL* s, SLDataType x) {
	if (s->used_size == s->real_size) {
		//扩容
		SL_Expand(s);
	}
	//int tmp = s->used_size;
	for (int i = s->used_size; i > 0; i--) {
		s->arr[i] = s->arr[i - 1];
	}
	s->used_size++;
	s->arr[0] = x;
}

void SLRemoveFront(SL* s) {
	if (s->arr == NULL || s->used_size == 0) {
		printf("没有数据可以删除");
		exit(1);//return;
	}
	else {
		int i = 0;
		for ( i = 0; i < s->used_size-1; i++) {
			s->arr[i] = s->arr[i + 1];
		}
		s->arr[i] = 0;
		s->used_size -= 1;
	}
}

//指定位置之前插⼊
void SLInsert(SL* s, int pos, SLDataType x) {
	if (pos >= s->used_size || pos < 0) {
		printf("THE POS IS ILLEGAL");
		return;
	}
	else {
		if (s->used_size == s->real_size) {
			SL_Expand(s);
		}
		else {
			for (int i = s->used_size; i > pos; i--) {
				s->arr[i] = s->arr[i - 1];
			}
			s->arr[pos] = x;
		}
		s->used_size++;
	}
}

//指定位置删除数据
void SLErase(SL* s, int pos) {
	if (pos >= s->used_size || pos<0) {
		printf("THE POS IS ILLEGAL");
		return;
	}
	else {
		int i = 0;
		for (i = pos; i < s->used_size-1; i++) {
			s->arr[i] = s->arr[i + 1];
		}
		s->arr[i] = 0;
		s->used_size--;
	}
}

int SLFind(SL* s, SLDataType x) {
	if (s->arr == NULL) {
		printf("The x is illegal");
		exit(1);
	}
	else {
		for (int i = 0; i < s->used_size; i++) {
			if (s->arr[i] == x) {
				printf("找到了");
				return i;
			}
		}
		printf("没找到");
		return 0;
	}
}

void SLPrint(SL* s) {
	if (s->arr == NULL) {
		printf("The s is null");
		exit(1);
	}
	else {
		for (int i = 0; i < s->used_size; i++) {
			printf("%d ", s->arr[i]);
		}
	}
	return;
}