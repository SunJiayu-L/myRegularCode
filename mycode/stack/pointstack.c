# include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
typedef int StackElement;

typedef enum {ERROR, OK} Status;

typedef enum {FALUSE, TRUE} Bool;

typedef struct {
	StackElement *pBase;
	StackElement *pTop;
	int size;
} Stack;
Status Stack_Init(Stack *pStack);
void Stack_Free(Stack *pStack);
void Stack_Clear (Stack *pStack);
Bool Stack_IsEmpty(Stack *pStack);
int Stack_Length(Stack *pStack);
Status Stack_GetTop(Stack *pStack, StackElement *pElem);
Status Stack_Push (Stack *pStack, StackElement *pElem);
Status Stack_Pop(Stack *pStack, StackElement *pElem);
Status Stack_Traverse(Stack *pStack, Status (*visit)());



int main() {
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Stack stacks;
	Stack_Init(&stacks);
	for (int i = 0; i < 10; i++)
		Stack_Push (&stacks, &arr[i]);
	return 0;
}

Status Stack_Init(Stack *pStack) {
	pStack->pBase = (StackElement *)malloc(STACK_INIT_SIZE * sizeof(StackElement));
	if (pStack->pBase == NULL) {
		return ERROR;
	}
	pStack->pTop = pStack->pBase;
	pStack->size = STACK_INIT_SIZE;
	return OK;
}
void Stack_Free(Stack *pStack) {
	free(pStack->pBase);
	pStack->pBase = NULL;
	pStack->pTop = NULL;
	pStack->size = 0;
	return ;
}
void Stack_Clear (Stack *pStack) {
	pStack->pTop = pStack->pBase;
}
Bool Stack_IsEmpty(Stack *pStack) {
	if (pStack->pTop == pStack->pBase) {
		return TRUE;
	} else {
		return FALUSE;
	}
}
int Stack_Length(Stack *pStack) {
	return pStack->pTop - pStack->pBase;
}
Status Stack_GetTop(Stack *pStack, StackElement *pElem) {
	if (pStack->pTop == pStack->pBase) {
		return ERROR;
	}
	*pElem = *(pStack->pTop - 1);
	return OK;
}

Status Stack_Push (Stack *pStack, StackElement *pElem) {
	int newSize;
	StackElement *pTemp;//realloc使用，自定义一个新的指针申请内存
	if (Stack_Length(pStack) >= pStack->size) {
		newSize = pStack->size + STACK_INCREMENT;
		pTemp = (StackElement *)realloc(pStack->pBase, newSize * sizeof(StackElement));
		if (pTemp == NULL) {
			return ERROR;
		} else { //成功申请内存后，要重新赋值，因为realloc可能导致栈不在原来的地方。
			pStack->pBase = pTemp;
			pStack->pTop = pStack->pBase + pStack->size;
			pStack->size = newSize;
		}
	}
	*(pStack->pTop) = *pElem;
	pStack->pTop++;
	return OK;
}
Status Stack_Pop(Stack *pStack, StackElement *pElem) {
	if (pStack->pTop == pStack->pBase) {
		return ERROR;
	} else {
		pStack->pTop--;
		*pElem = *(pStack->pTop);
		return OK;
	}
}
Status Stack_Traverse(Stack *pStack, Status (*visit)()) {
	int i, n;
	n = Stack_Length(pStack);
	for (i = 0; i < n; i++) {
		if (visit(&(pStack->pBase[i])) == ERROR) {
			return ERROR;
		}
	}
	return OK;
}

