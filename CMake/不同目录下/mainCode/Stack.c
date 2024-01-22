#include "Stack.h"

Stack* Stack_Construct(int sizeOfElment) {
	Stack* pStack;
	pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL) {
		return NULL;
	}
	pStack->pBase = malloc(STACK_INIT_SIZE * sizeOfElment);
	if (pStack->pBase == NULL) {
		free(pStack);
		return NULL;
	}
	pStack->pTop = pStack->pBase;
	pStack->elementSize = sizeOfElment;
	pStack->stackSize = STACK_INIT_SIZE;
	return pStack;
}

void StackDestruct(Stack* pStack) {
	if (pStack == NULL) {
		return;
	}
	free(pStack->pBase);
	free(pStack);
	return;
}

Bool Stack_IsEmpty(Stack* pStack) {
	if (pStack->pTop == pStack->pBase) {
		return TRUE;
	}
	else {
		return FALUSE;
	}
}

int Stack_Length(Stack* pStack) {
	return (char*)(pStack->pTop )- (char*)(pStack->pBase);
}

Status Stack_Push(Stack* pStack, void* pElem) {
	int NewSize;
	void* pTemp = NULL;  //realloc使用，自定义一个新的指针申请内存
	if (Stack_Length(pStack) >= pStack->stackSize) {
		NewSize = pStack->stackSize + STACK_INCREMENT;
		pTemp = (void*)realloc(pStack->pBase, NewSize * sizeof(pStack->elementSize));

		if (pTemp == NULL) {
			return ERROR;
		}
		else { //成功申请内存后，要重新赋值，因为realloc可能导致栈不在原来的地方。
			pStack->pBase = pTemp;
			pStack->pTop = (char*)pStack->pBase + pStack->stackSize;
			pStack->stackSize = NewSize;
		}
	}
	memcpy(pStack->pTop, pElem, pStack->elementSize);
	char* pc = (char*)(pStack->pTop);
	pStack->pTop = pc + pStack->elementSize;
	return OK;
}

Status Stack_Pop(Stack* pStack, void* pElem) {
	char* pc;
	if (pStack->pTop == pStack->pBase) {
		return ERROR;
	}
	else {
		pc = (char*)(pStack->pTop);
		pStack->pTop = pc - pStack->elementSize; //pc用来辅助调整栈顶指针
		memcpy(pElem, pStack->pTop, pStack->elementSize); //把pStack->pTop的pStack->element给个字节内存拷贝给pElem，
		//此时pElem即指向存储的内容

		return OK;

	}
}

Status StackGetTop(Stack* pStack, void* pElem) {
	char* pc;
	if (pStack->pTop == pStack->pBase) {
		return ERROR;
	}
	else {
		pc = (char*)(pStack->pTop);
		pStack->pTop = pc - pStack->elementSize; //pc用来辅助调整栈顶指针
		memcpy(pElem, pStack->pTop, pStack->elementSize); //把pStack->pTop的pStack->element给个字节内存拷贝给pElem，
		//此时pElem即指向存储的内容
		pStack->pTop = pc;
		return OK;

	}
}

Status visit(void* pBase) {
	if (pBase != NULL) {
		printf("%p ", pBase);
		return OK;
	}
	return ERROR;
}

Status Stack_Traverse(Stack* pStack, Status(*visit) (void*)) {
	if (pStack->pBase == NULL || pStack->pTop == pStack->pBase) {
		return ERROR;
	}
	void* p = pStack->pBase;
	while (p != pStack->pTop) {
		visit(p);
		char* a = (char*)p;
		a++;
		p = a;
	}
	return OK;
}