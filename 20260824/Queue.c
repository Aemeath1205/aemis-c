#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int QDataType;
//队列结点结构
typedef struct QueueNode{
	int val;
	struct QueueNode* next;
}QNode;

//队列结构
typedef struct Queue {
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//初始化队列
void QueueInit(Queue* pq) {
	assert(pq != NULL);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

//新建node并初始化
QNode* CreateNode(QDataType x) {
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL) {
		perror("malloc fail");
		exit(1);
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}

//销毁队列
void QueueDestroy(Queue* pq) {
	assert(pq != NULL);
	if (pq->phead == NULL) {
		return;
	}
	while (pq->phead != pq->ptail) {
		QNode* tmp = pq->phead->next;
		free(pq->phead);
		pq->phead = tmp;
	}
	free(pq->phead);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

// ⼊队列，队尾
void QueuePush(Queue* pq, QDataType x) {
	assert(pq != NULL);
	QNode* newnode = CreateNode(x);
	if (pq->phead == NULL) {
		pq->phead = newnode;
		pq->ptail = newnode;
		pq->size++;
		return;
	}
	else {
		pq->ptail->next = newnode;
		pq->ptail = newnode;
		pq->size++;
		return;
	}
}

// 出队列，队头
void QueuePop(Queue* pq) {
	assert(pq != NULL);
	if (pq->phead == NULL) {
		printf("QueuePop fail");
		exit(1);
	}
	else {
		QNode* tmp = pq->phead->next;
		free(pq->phead);
		pq->phead = tmp;
		pq->size--;
		if (pq->phead == NULL) {
			pq->ptail = NULL;
		}
	}
}

//取队头数据
QDataType QueueFront(Queue* pq) {
	assert(pq != NULL);
	if (pq->phead == NULL) {
		printf("QueueFront fail");
		exit(1);
	}
	else {
		return pq->phead->val;
	}
}

//取队尾数据
QDataType QueueBack(Queue* pq) {
	assert(pq != NULL);
	if (pq->phead == NULL) {
		printf("QueueBack fail");
		exit(1);
	}
	else {
		return pq->ptail->val;
	}
}

//队列判空
bool QueueEmpty(Queue* pq) {
	if (pq == NULL) {
		printf("pq==NULL illegal");
		exit(1);
	}
	if ( pq->size == 0) {
		return true;
	}
	return false;
}

//队列有效元素个数
int QueueSize(Queue* pq) {
	if (pq == NULL) {
		printf("pq==NULL illegal");
		exit(1);
	}
	return pq->size;
}


//用两个队列实现栈

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&(obj->q1));
	QueueInit(&(obj->q2));
	return obj;
}

void myStackPush(MyStack* obj, int x) {
	Queue* tmp = obj->q1.size == 0 ? &(obj->q1) : &(obj->q2);
	QueuePush(tmp, x);
	if (tmp == &(obj->q1)) {
		while (obj->q2.size != 0) {
			QueuePush(&(obj->q1), QueueFront(&(obj->q2)));
			QueuePop(&(obj->q2));
		}
	}
	else {
		while (obj->q1.size != 0) {
			QueuePush(&(obj->q2), QueueFront(&(obj->q1)));
			QueuePop(&(obj->q1));
		}
	}
}

int myStackPop(MyStack* obj) {
	Queue* tmp = obj->q1.size == 0 ? &(obj->q2) : &(obj->q1);
	int x = QueueFront(tmp);
	QueuePop(tmp);
	return x;
}

int myStackTop(MyStack* obj) {
	Queue* tmp = obj->q1.size == 0 ? &(obj->q2) : &(obj->q1);
	int x = QueueFront(tmp);
	return x;
}

bool myStackEmpty(MyStack* obj) {
	if (obj->q1.size == 0 && obj->q2.size == 0) {
		return true;
	}
	return false;
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&(obj->q1));
	QueueDestroy(&(obj->q2));
	free(obj);
}