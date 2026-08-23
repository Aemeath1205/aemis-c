#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int LTDataType;
typedef struct ListNode {
	struct ListNode* next; //指针保存下⼀个结点的地址
	struct ListNode* prev; //指针保存前⼀个结点的地址
	LTDataType data;
}LTNode;

LTNode* CreateNewNode_and_Ini(LTDataType data) {
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL) {
		perror("malloc when create fail");
		exit(1);
	}
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->data = data;
	return newnode;
}


void LTDestroy(LTNode** pphead) {
	if (pphead == NULL || *pphead == NULL) {
		printf("LTDestory illegal");
		return;
	}
	LTNode* tmpfast = *pphead;
	LTNode* tmpslow = *pphead;
	while (tmpfast != NULL) {
		tmpfast = tmpfast->next;
		free(tmpslow);
		tmpslow = tmpfast;
	}
	*pphead = NULL;
	return;
}

void LTPrint(LTNode* phead) {
	if (phead == NULL) {
		printf("LTPrint illegal");
		return;
	}
	LTNode* tmphead = phead;
	while (tmphead != NULL) {
		printf("%d ", tmphead->data);
		tmphead = tmphead->next;
	}
	return;
}

bool LTEmpty(LTNode* phead) {
	if (phead == NULL) {
		return false;
	}
	return true;
}

void LTPushBack(LTNode** phead, LTDataType x) {
	LTNode* newnode = CreateNewNode_and_Ini(x);
	if (phead == NULL) {
		printf("LTPushBack illegal");
		exit(1);
	}
	if (*phead == NULL) {
		*phead = newnode;
		return;
	}
	else {
		LTNode* tmphead = *phead;
		while (tmphead->next != NULL) {
			tmphead = tmphead->next;
		}
		tmphead->next = newnode;
		newnode->prev = tmphead;
	}
	return;
}

void LTPopBack(LTNode** pphead) {
	if (pphead == NULL) {
		printf("LTPopBack illegal");
		exit(1);
	}
	if (*pphead == NULL) {
		return;
	}
	else {
		LTNode* tmphead = *pphead;
		if (tmphead->next ==NULL) {
			free(tmphead);
			*pphead = NULL;
			return;
		}
		while (tmphead->next->next != NULL) {
			tmphead = tmphead->next;
		}
		free(tmphead->next);
		tmphead->next = NULL;
	}
}

void LTPushFront(LTNode** pphead, LTDataType x) {
	LTNode* newnode = CreateNewNode_and_Ini(x);
	if (pphead == NULL) {
		printf("LTPushFront illegal");
		return;
	}
	if (*pphead == NULL) {
		*pphead = newnode;
		return;
	}
	newnode->next = *pphead;
	(*pphead)->prev = newnode;
	*pphead = newnode;
}

void LTPopFront(LTNode** phead) {
	if (phead == NULL) {
		printf("LTPopFront illegal");
		exit(1);
	}
	if (*phead == NULL) {
		return;
	}
	if ((*phead)->next == NULL) {
		free(*phead);
		*phead = NULL;
		return;
	}
	else {
		*phead = (*phead)->next;
		free((*phead)->prev);
		(*phead)->prev = NULL;
	}
}

//在pos位置之后插⼊数据
void LTInsert(LTNode* pos, LTDataType x) {
	if (pos == NULL) {
		printf("LTInsert illegal");
		exit(1);
	}
	LTNode* newnode = CreateNewNode_and_Ini(x);
	if (pos->next == NULL) {
		pos->next = newnode;
		newnode->prev = pos;
	}
	else {
		newnode->next = pos->next;
		newnode->prev = pos;
		newnode->next->prev = newnode;
		pos->next = newnode;
	}
	return;
}

void LTErase(LTNode* pos) {
	if (pos == NULL) {
		printf("LTErase illegal");
		exit(1);
	}
	if (pos->next == NULL) {
		pos->prev->next = NULL;
		free(pos);
		return;
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

LTNode* LTFind(LTNode* phead, LTDataType x) {
	while (phead != NULL) {
		if (phead->data == x) {
			return phead;
		}
		else {
			phead = phead->next;
		}
	}
	return NULL;
}

