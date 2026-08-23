#include "SList.h"

//链表的打印
void SLTPrint(SLTNode* phead) {
	SLTNode* tmp = phead;
	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}

//初始化
void iniNode(SLTNode* pNode, type x) {
	pNode->data = x;
	pNode->next = NULL;
}

//尾插
void SLTPushBack(SLTNode** pphead, type x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) {
		perror("malloc when push back");
		return;  // 内存分配失败
	}
	iniNode(newnode, x);
	if (*pphead == NULL) {
		*pphead = newnode;
		return;
	}
	SLTNode* tmphead = *pphead;
	while (tmphead->next != NULL) {
		tmphead = tmphead->next;
	}
	tmphead->next = newnode;
}

//尾删
void SLTPopBack(SLTNode** pphead) {
	SLTNode* tmphead = *pphead;
	if (tmphead == NULL) {
		printf("尾删不合法");
		exit(1);
	}
	if (tmphead->next == NULL) {
		free(*pphead);
		*pphead = NULL;//这里只能用*pphead
		return;
	}
	while (tmphead->next->next != NULL) {
		tmphead = tmphead->next;
	}
	free(tmphead->next);
	tmphead->next = NULL;
	return;
}

//头插
void SLTPushFront(SLTNode** pphead, type x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) {
		perror("malloc when push front");
		return;  // 内存分配失败
	}
	iniNode(newnode, x);
	if (*pphead == NULL) {
		*pphead = newnode;
		return;
	}
	newnode->next = *pphead;
	*pphead = newnode;
}

//头删
void SLTPopFront(SLTNode** pphead) {
	if (*pphead = NULL) {
		printf("头删不合法");
		exit(1);
	}
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
		return;
	}
	SLTNode* tmphead = *pphead;
	*pphead = tmphead->next;
	free(tmphead);
	return;
}

//查找指定位置数据
SLTNode* SLTFind(SLTNode* phead, type x) {
	SLTNode* tmphead = phead;
	while (tmphead != NULL) {
		if (tmphead->data == x) {
			return tmphead;
		}
		tmphead = tmphead->next;
	}
	printf("没有找到你想要的数据");
	return NULL;
}

//在指定位置之前插⼊数据
void SLTInsert(SLTNode** pphead, int pos, type x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) {
		perror("malloc when push front");
		return;  // 内存分配失败
	}

	iniNode(newnode, x);
	int count = 0;
	SLTNode* tmphead = *pphead;
	
	if (pos == 0) {
		if (*pphead == NULL) {
			*pphead = newnode;
			return;
		}
		else {
			newnode->next = tmphead;
			*pphead = newnode;
			return;
		}
	}

	if (*pphead == NULL) {
		printf("指定位置插入数据非法");
		exit(1);
	}
	
	while (tmphead->next != NULL) {
		count++;
		tmphead = tmphead->next;
	}

	if (pos == count+1) {
		tmphead->next = newnode;
		return;
	}
	if (pos > count+1) {
		printf("指定位置插入数据非法");
		exit(1);
	}

	tmphead = *pphead;
	while (pos > 1) {
		pos--;
		tmphead = tmphead->next;
	}
	newnode->next = tmphead->next;
	tmphead->next = newnode;
}

//删除pos结点
void SLTErase(SLTNode** pphead, SLTNode* pos) {
	if (pos == NULL) {
		printf("删除pos结点非法");
		exit(1);
	}
	SLTNode* tmphead = *pphead;
	if (tmphead == NULL) {
		printf("删除pos结点非法");
		exit(1);
	}

	if (tmphead == pos) {
		*pphead = tmphead->next;
		free(pos);
		return;
	}
	
	while (tmphead != NULL) {
		if (tmphead->next == pos) {
			tmphead->next = tmphead->next->next;
			free(pos);
			return;
		}
		tmphead = tmphead->next;
	}
	printf("删除pos结点非法");
	exit(1);
}

//销毁链表
void SListDestroy(SLTNode** pphead) {
	if (*pphead == NULL) {
		printf("销毁链表非法");
		exit(1);
	}
	SLTNode* tmphead = *pphead;
	SLTNode* tmphead2 = *pphead;
	while (tmphead != NULL) {
		tmphead = tmphead->next;
		free(tmphead2);
		tmphead2 = tmphead;
	}
	*pphead = NULL;
}


