#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//定义二叉链
typedef char BDDataType;
typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;//左 子节点
	struct BinaryTreeNode* right;//右 子节点
	BDDataType val;//当前节点值域
}BTNode;

void PreOrder(BTNode* root); //前序遍历 根 左 右
void InOrder(BTNode* root);  //中序遍历 左 根 右
void PostOrder(BTNode* root);//后序遍历 左 右 根

// ⼆叉树结点个数
int BinaryTreeSize(BTNode* root);

//⼆叉树叶⼦结点个数
int BinaryTreeLeafSize(BTNode* root); 

// ⼆叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode * root, int k);

//⼆叉树的深度/⾼度
int BinaryTreeDepth(BTNode * root);

// ⼆叉树查找值为x的结点
BTNode * BinaryTreeFind(BTNode * root, BDDataType x);

// ⼆叉树销毁
void BinaryTreeDestroy(BTNode** root);

//层序遍历
void LevelOrder(BTNode* root);



// queue.h

// ---------- 数据类型定义 ----------
typedef BTNode QDataType;

// ---------- 队列结点 ----------
typedef struct QueueNode {
    QDataType val;
    struct QueueNode* next;
} QNode;

// ---------- 队列结构 ----------
typedef struct Queue {
    QNode* phead;
    QNode* ptail;
    int size;
} Queue;

// ---------- 函数声明（只有原型） ----------

// 初始化队列
void QueueInit(Queue* pq);

// 入队（队尾插入）
void QueuePush(Queue* pq, QDataType x);

// 出队（队头删除）
void QueuePop(Queue* pq);

// 取队头元素
QDataType QueueFront(Queue* pq);

// 取队尾元素
QDataType QueueBack(Queue* pq);

// 判断队列是否为空
bool QueueEmpty(Queue* pq);

// 获取队列有效元素个数
int QueueSize(Queue* pq);

// 销毁队列（释放所有动态内存）
void QueueDestroy(Queue* pq);

bool BinaryTreeComplete(BTNode* root);