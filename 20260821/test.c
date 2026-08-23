#include "SeqList.h"

void main() {
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPushBack(&s1, 6);
	SLPushFront(&s1, 7);

	SLPushFront(&s1, 7);

	SLRemoveFront(&s1);
	SLRemoveBack(&s1);

	SLInsert(&s1, 1, 9);
	SLErase(&s1, 3);

	SLFind(&s1, 2);
	SLPrint(&s1);
}