#include "Tree.h"

void PreOrder(BTNode* root) {
	if (root == NULL) {
		printf("N ");
		return;
	}
	//count++;
	printf("%d ", root->val);
	//if (root->left == NULL && root->right == NULL) {
	//	leave++;
	//}
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root) {
	if (root == NULL) {
		printf("N ");
		return;
	}
	//count++;
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}

void PostOrder(BTNode* root) {
	if (root == NULL) {
		printf("N ");
		return;
	}
	//count++;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}

int BinaryTreeSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}


int BinaryTreeDepth(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	int leftDepth = BinaryTreeDepth(root->left);   
	int rightDepth = BinaryTreeDepth(root->right); 
	return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

BTNode* BinaryTreeFind(BTNode* root, BDDataType x) {
	if (root == NULL) {
		return NULL;
	}
	if (root->val == x) {
		return root;
	}
	BTNode* tmpleft = BinaryTreeFind(root->left, x);
	BTNode* tmpright = BinaryTreeFind(root->right, x);
	if (tmpleft == NULL && tmpright == NULL) {
		return NULL;
	}
	return tmpleft == NULL ? tmpright : tmpleft;
}


//BTNode* BinaryTreeFind(BTNode* root, BDDataType x) {
//	if (root == NULL) return NULL;
//	if (root->val == x) return root;
//
//	BTNode* leftResult = BinaryTreeFind(root->left, x);
//	if (leftResult != NULL) return leftResult;  // 短路：左边找到就直接返回
//
//	return BinaryTreeFind(root->right, x);       // 左边没找到，再去右边找
//}

void BinaryTreeDestroy(BTNode** root){
	if (root == NULL) {
		return;
	}
	if (*root == NULL) {
		return;
	}
	BinaryTreeDestroy((&(*root)->left));
	BinaryTreeDestroy((&(*root)->right));
	free(*root);
	*root = NULL;
}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <assert.h>


// ---------- 1. 初始化 ----------
void QueueInit(Queue* pq) {
	assert(pq != NULL);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

// ---------- 2. 创建新结点 ----------
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

// ---------- 3. 入队（队尾插入） ----------
void QueuePush(Queue* pq, QDataType x) {
	assert(pq != NULL);
	QNode* newnode = CreateNode(x);
	if (pq->phead == NULL) {
		pq->phead = newnode;
		pq->ptail = newnode;
	}
	else {
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}

// ---------- 4. 出队（队头删除） ----------
void QueuePop(Queue* pq) {
	assert(pq != NULL);
	assert(pq->phead != NULL);
	QNode* tmp = pq->phead->next;
	free(pq->phead);
	pq->phead = tmp;
	if (pq->phead == NULL) {
		pq->ptail = NULL;
	}
	pq->size--;
}

// ---------- 5. 取队头元素 ----------
QDataType QueueFront(Queue* pq) {
	assert(pq != NULL);
	assert(pq->phead != NULL);
	return pq->phead->val;
}

// ---------- 6. 取队尾元素（你之前写过） ----------
QDataType QueueBack(Queue* pq) {
	assert(pq != NULL);
	assert(pq->ptail != NULL);
	return pq->ptail->val;
}

// ---------- 7. 判空 ----------
bool QueueEmpty(Queue* pq) {
	if (pq == NULL) {
		printf("QueueEmpty: pq is NULL!\n");
		exit(1);
	}
	return pq->size == 0;
}

// ---------- 8. 获取元素个数 ----------
int QueueSize(Queue* pq) {
	if (pq == NULL) {
		printf("QueueSize: pq is NULL!\n");
		exit(1);
	}
	return pq->size;
}

// ---------- 9. 销毁队列 ----------
void QueueDestroy(Queue* pq) {
	assert(pq != NULL);
	QNode* cur = pq->phead;
	while (cur != NULL) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}


void LevelOrder(BTNode* root) {
	if (root == NULL) return;
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, *root);
	while (QueueEmpty(&q1) != true) {
		BTNode tmp = QueueFront(&q1);
		QueuePop(&q1);
		printf("%d ", tmp.val);
		if (tmp.left != NULL) {
			QueuePush(&q1,*(tmp.left));
		}
		if (tmp.right != NULL) {
			QueuePush(&q1, *(tmp.right));
		}
	}
	QueueDestroy(&q1);
}

bool BinaryTreeComplete(BTNode* root) {
	if (root == NULL) return;
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, *root);
	while (q1.size != 0) {
		BTNode tmp = QueueFront(&q1);
		QueuePop(&q1);
		if (&tmp == NULL) {

		}
	}
}



 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 //struct TreeNode* count = NULL;
 bool isUnivalTree(struct TreeNode* root) {
	 if (root == NULL) {
		 return true;
	 }
	 if (root->left && root->left->val != root->val) {
		 return false;
	 }
	 if (root->right && root->right->val != root->val) {
		 return false;
	 }
	 return isUnivalTree(root->left) && isUnivalTree(root->right);
 }

 bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	 if (p == NULL) {
		 if (q != NULL)  return false;
		 else return true;
	 }
	 else {
		 if (q == NULL) return false;
	 }
	 if (p->val != q->val) { return false; }
	 return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
 }

 bool check(struct TreeNode* p1, struct TreeNode* p2) {
	 if (p1 == NULL) {
		 if (p2 == NULL) return true;
		 else return false;
	 }
	 else {
		 if (p2 == NULL) return false;
	 }
	 if (p1->val != p2->val) return false;
	  
	 return check(p1->left, p2->right) && check(p1->right, p2->left);
 }

 bool isSymmetric(struct TreeNode* root) {
	 return check(root->left, root->right);
 }

 struct TreeNode* lookfor(struct TreeNode* root, int x) {
	 if (root == NULL) {
		 return NULL;
	 }
	 if (root->val == x) {
		 return root;
	 }
	 struct TreeNode* tmp1 = lookfor(root->left, x);
	 struct TreeNode* tmp2 = lookfor(root->right, x);
	 return tmp1 == NULL ? tmp2 : tmp1;
 }

 
 bool check2(struct TreeNode* p1, struct TreeNode* p2) {
	 if (p1 == NULL) {
		 if (p2 == NULL) return true;
		 else return false;
	 }
	 else {
		 if (p2 == NULL) return false;
	 }
	 if (p1->val != p2->val) return false;

	 return check2(p1->left, p2->left) && check2(p1->right, p2->right);
 }

 bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
	 if (subRoot == NULL) {
		 return false;
	 }
	 struct TreeNode* tmp = lookfor(root, subRoot->val);
	 if (tmp == NULL) {
		 return false;
	 }
	 if (check2(tmp, subRoot) == false) {
		 bool tmp1 = isSubtree(root->left, subRoot);
		 bool tmp2 = isSubtree(root->right, subRoot);
		 if (tmp1 == false && tmp2 == false) {
			 return false;
		 }
		 return true;
	 }
 }


#include<stdio.h>
 typedef struct TreeNode
 {
	 char val;
	 struct TreeNode* left;
	 struct TreeNode* right;
 }TreeNode;

 TreeNode* maketree(char* arr, int* count)
 {
	 if (arr[*count] == '#' || arr[*count] == '\0')
	 {
		 return NULL;
	 }
	 TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	 newnode->val = arr[(*count)++];

	 newnode->left = maketree(arr, count);
	 (*count)++;
	 newnode->right = maketree(arr, count);
	 return newnode;
 }

 void Inorder(TreeNode* root)
 {
	 if (root == NULL)
	 {
		 return;
	 }
	 Inorder(root->left);
	 printf("%c ", root->val);
	 Inorder(root->right);
 }

 int main()
 {
	 char arr[101];
	 scanf("%s", arr);
	 int count = 0;
	 TreeNode* tree = maketree(arr, &count);
	 Inorder(tree);
	 return 0;
 }