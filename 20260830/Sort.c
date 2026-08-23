#include "Sort.h";

void InsertSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0) {
			if (arr[end] > tmp) {
				arr[end + 1] = arr[end];
				end--;
			}
			else {
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n) {
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (a[end] > tmp) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void swap(int* a, int* b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

void SelectSort(int* a, int n) {
	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		int maxi = begin;
		int mini = begin;
		for (int i = begin ; i <= end; i++) {
			if (a[i] < a[mini]) {
				mini = i;
			}
			if (a[i] > a[maxi]) {
				maxi = i;
			}
		}
		if (maxi == begin) {
			maxi = mini;
		}
		swap(&a[mini], &a[begin]);
		swap(&a[maxi], &a[end]);
		begin++;
		end--;
	}
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void QuickSort(int* a, int left, int right) {
	if (left >= right) {
		return;
	}
	int tmp = _QuickSort(a, left, right);
	QuickSort(a, left, tmp - 1);
	QuickSort(a, tmp + 1, right);
}


int _QuickSort(int* a, int left, int right) {
	//int begin = left;
	//int end = right;
	int keyi = left;
	left++;
	while (left <= right) {
		while (left <= right && a[right] > a[keyi]) {
			right--;
		}
		while (left <= right && a[left] < a[keyi]) {
			left++;
		}
		if (left <= right) {
			swap(&a[right--], &a[left++]);
		}
	}
	swap(&a[right], &a[keyi]);
	return right;
}

int _QuickSort2(int* a, int left, int right) {
	int hole = left;
	int key = a[hole];
	while (left < right) {
		while (left < right && a[right] >= key) {
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key) {
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

int _QuickSort3(int* a, int left, int right) {
	int key = left;
	int prev = left;
	int cur = prev++;
	while (cur <= right) {
		if (a[cur] < a[key] && ++prev != cur) {
			swap(&a[prev], &a[cur]);
		}
		cur++;
		//while (cur <= right && a[cur] > key) {
		//	cur++;
		//}
		//if (cur > right) {
		//	break;
		//}
		//prev++;
		//swap(&a[prev], &a[cur]);
	}
	swap(&a[key], &a[prev]);
	return prev;
}


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
		ps->a = (STDataType*)malloc(2 * sizeof(STDataType));
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
			STDataType* tmp = (STDataType*)realloc(ps->a, 2 * (ps->capacity) * sizeof(STDataType));
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
//////////////////////////
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
	return (ps->top == 0) ? true : false;
}

////////////////////////////

void QuickSortNonR(int* a, int left, int right) {
	ST st;
	STInit(&st);
	STPush(&st, left);
	STPush(&st, right);
	while (!STEmpty(&st)) {

		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		int key = begin;
		int prev = begin;
		int cur = prev++;
		while (cur <= end) {
			if (a[cur] < a[key] && ++prev != cur) {
				swap(&a[prev], &a[cur]);
			}
			cur++;
		}
		swap(&a[key], &a[prev]);
		if (prev - 1 > begin) {
			STPush(&st, begin);
			STPush(&st, prev-1);
		}
		if (prev + 1 < end) {
			STPush(&st, prev+1);
			STPush(&st, end);
		}
	}

	STDestroy(&st);
}

void _MergeSort(int* a, int left, int right, int* tmp) {
	if (left >= right) {
		return;
	}
	int mid = (left + right) / 2;
	//[left,mid],[mid+1,right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2]) {
			tmp[index++] = a[begin1++];
		}
		else {
			tmp[index++] = a[begin2++];
		}
	}
	if (begin1 > end1) {
		for (int i = begin2; i <= end2; i++) {
			tmp[index++] = a[begin2++];
		}
	}
	else {
		for (int i = begin1; i <= end1; i++) {
			tmp[index++] = a[begin1++];
		}
	}
	for (int i = left; i <= right; i++) {
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}

void CountSort(int* a, int n) {
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL) {
		perror("malloc fail");
		return;
	}
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++) {
		count[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++) {
		while (count[a[i] - min] != 0) {
			a[j++] = i + min;
		}
	}
}