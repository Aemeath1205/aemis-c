#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int type;

struct SListNode {
	type data;
	struct SListNode* next;//下一个节点
};
typedef struct SListNode SLTNode;

//链表的打印
void SLTPrint(SLTNode* phead);

//初始化
void iniNode(SLTNode* pNode, type x);

//尾插
void SLTPushBack(SLTNode** pphead, type x);
//尾删
void SLTPopBack(SLTNode** pphead);
//头插
void SLTPushFront(SLTNode** pphead, type x);
//头删
void SLTPopFront(SLTNode** pphead);

//查找指定位置数据
SLTNode* SLTFind(SLTNode* phead, type x);

//在指定位置之前插⼊数据
void SLTInsert(SLTNode** pphead, int pos,type x);

//删除pos结点
void SLTErase(SLTNode** pphead, SLTNode* pos);

//销毁链表
void SListDestroy(SLTNode** pphead);

