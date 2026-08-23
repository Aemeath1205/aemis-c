#include "Heap.h"

void HPInit(HP* php) {
	php->arr = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HPDestroy(HP* php) {
	assert(php != NULL);
	if (php->arr != NULL) {
		free(php->arr);
	}
	php->arr = NULL;
	php->size = 0;
	php->capacity = 0;
}

void CheckCapacity(HP* php) {
	assert(php != NULL);
	if (php->size == php->capacity) {
		int newcapacity = (php->capacity == 0) ? 10 : 2 * php->capacity;
		HPDataType* newarr = (HPDataType*)realloc(php->arr,newcapacity * sizeof(HPDataType));
		if (newarr == NULL) {
			perror("REALLOC FAIL");
			exit(1);
		}
		else {
			php->arr = newarr;
			php->capacity = newcapacity;
		}
	}
	return;
}
	

void HPPush(HP* php, HPDataType x) {
	CheckCapacity(php);
	int child = php->size;
	(php->arr)[child] = x;
	while (child > 0) {
		int father = (child - 1) / 2;
		if (php->arr[father] < php->arr[child]) {
			HPDataType tmp = php->arr[child];
			php->arr[child] = php->arr[father];
			php->arr[father] = tmp;
			child = father;
		}
		else {
			break;
		}
	}
	php->size++;
}

HPDataType HPTop(HP* php) {
	assert(php != NULL);
	//if (php->size == 0) {
	//	printf("HPTOP ILLEGAL");
	//	exit(1);
	//}
	assert(php->size > 0);
	return php->arr[0];
}

void HPPop(HP* php) {
	assert(php != NULL);
	if (php->size == 0) {
		return;
	}
	php->arr[0] = php->arr[php->size-1];
	php->size--;
	int father = 0;
	int left = 1;
	int right = 2;
	while ((2 * father + 2) < php->size) {
		if (php->arr[father] >= php->arr[left] && php->arr[father] >= php->arr[right]) {
			break;
		}

		if (php->arr[left] > php->arr[right]) {
			HPDataType tmp = php->arr[father];
			php->arr[father] = php->arr[left];
			php->arr[left] = tmp;
			father = left;
		}
		else {
			HPDataType tmp = php->arr[father];
			php->arr[father] = php->arr[right];
			php->arr[right] = tmp;
			father = right;
		}
		left = 2 * father + 1;
		right = 2 * father + 2;
	}
	if (left < php->size && php->arr[father] < php->arr[left]) {
		HPDataType tmp = php->arr[father];
		php->arr[father] = php->arr[left];
		php->arr[left] = tmp;
	}
}


bool HPEmpty(HP* php) {
	assert(php != NULL);
	if (php->size == 0) {
		return true;
	}
	return false;
}

int HPSize(HP* php) {
	assert(php != NULL);
	return php->size;
}