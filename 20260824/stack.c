#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef char STDataType;
typedef struct Stack {
	STDataType* a;
	int top;
	int capacity;
}ST;

// 初始化栈
void STInit(ST* ps) {
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

// 销毁栈
void STDestroy(ST* ps) {
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

//检测是否需要扩容并扩容
void CheckIfExpand(ST* ps) {
	if (ps->capacity == 0) {
		ps->a = (STDataType*)malloc(2*sizeof(STDataType));
		if (ps->a == NULL) {
			perror("malloc fail");
			exit(1);
		}
		ps->top = 0;
		ps->capacity = 2;
		return;
	}
	else {
		if (ps->top == ps->capacity) {
			STDataType* tmp = (STDataType*)realloc(ps->a, 2*(ps->capacity)*sizeof(STDataType));
			if (tmp == NULL) {
				perror("realloc fail");
				exit(1);
			}
			else {
				ps->a = tmp;
				ps->capacity *= 2;
				return;
			}
		}
		else {
			return;
		}
	}
}

// ⼊栈
void STPush(ST* ps, STDataType x) {
	CheckIfExpand(ps);
	(ps->a)[ps->top] = x;
	(ps->top)++;
}

//出栈
void STPop(ST* ps) {
	assert(ps != NULL);
	if (ps->top == 0) {
		printf("STPop fail");
		exit(1);
	}
	else {
		(ps->top)--;
	}
	return;
}

//取栈顶元素
STDataType STTop(ST* ps) {
	assert(ps != NULL);
	if (ps->top == 0) {
		printf("STTop fail");
		exit(1);
	}
	else {
		return (ps->a)[ps->top - 1];
	}
}

//获取栈中有效元素个数
int STSize(ST* ps) {
	assert(ps != NULL);
	return ps->top;
}

//栈是否为空
bool STEmpty(ST* ps) {
	assert(ps != NULL);
	return (ps->top == 0) ? true: false;
}

bool checkthefit(char s1, char s2) {
	//if ((s1 == '(') && (s2 == ']' || s2 == '}')) {
	//	return false;
	//}
	//if ((s1 == '[') && (s2 == ')' || s2 == '}')) {
	//	return false;
	//}
	//if ((s1 == '{') && (s2 == ']' || s2 == ')')) {
	//	return false;
	//}
	if (s1 == '(' && s2 == ')') {
		return true;
	}
	if (s1 == '{' && s2 == '}') {
		return true;
	}
	if (s1 == '[' && s2 == ']') {
		return true;
	}
	return false;
}

//OJ
bool isValid(char* s) {
	ST tmpstack;
	STInit(&tmpstack);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			STPush(&tmpstack, s[i]);
			continue;
		}
		else {
			if (STEmpty(&tmpstack) == true) {
				return false;
			}
			else {
				STDataType tmp = STTop(&tmpstack);
				if (checkthefit(tmp, s[i])==true) {
					STPop(&tmpstack);
				}
				else {
					return false;
				}
			}
		}
	}
	if (STEmpty(&tmpstack) == true) {
		STDestroy(&tmpstack);
		return true;
	}
	else {
		STDestroy(&tmpstack);
		return false;
	}
}

//用两个栈实现队列

typedef struct {
	ST in;
	ST out;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
	STInit(&(queue->in));
	STInit(&(queue->out));
	return queue;
}

void myQueuePush(MyQueue* obj, int x) {
	STPush(&(obj->in), x);
}

int myQueuePop(MyQueue* obj) {
	if (obj->out.top == 0) {
		while (obj->in.top != 0) {
			STPush(&(obj->out), STTop(&(obj->in)));
			STPop(&(obj->in));
		}
	}
	int x = STTop(&(obj->out));
	STPop(&(obj->out));
	return x;
}

int myQueuePeek(MyQueue* obj) {
	if (obj->out.top == 0) {
		while (obj->in.top != 0) {
			STPush(&(obj->out), STTop(&(obj->in)));
			STPop(&(obj->in));
		}
	}
	return STTop(&(obj->out));

}

bool myQueueEmpty(MyQueue* obj) {
	if (STEmpty(&(obj->in)) ==true && STEmpty(&(obj->out) == true)) {
		return true;
	}
	return false;
}

void myQueueFree(MyQueue* obj) {
	STDestroy(&(obj->in));
	STDestroy(&(obj->out));
	free(obj);
}