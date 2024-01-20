
#include "LinkedStack.h"

typedef List Stack;

static Stack* Stack_Construct(int sizeOFData) {
    List* pList=(List* )malloc(sizeof(List));//定义一个链表（头节点）
    if(pList==NULL){
        return NULL;
    }
    pList->pFirstNode=NULL;
    pList->length=0;
    pList->dataSize=sizeOFData;
    return pList;
}

static void StackDestruct(Stack* pStack) {
	if (pStack == NULL) {
		return;
	}
	ListClear(pStack);
	free(pStack);
	return;
}

static Bool Stack_IsEmpty(Stack* pStack) {
	if (pStack->length = 0) {
		return TRUE;
	}
	else {
		return FALUSE;
	}
}


static int Stack_Length(Stack* pStack) {
	return pStack->length;
}

static Status Stack_Push(Stack* pStack, void* pElem) {
	ListNode* pNewNode, * pTail;
	pNewNode = List_makeNode(pStack, pElem);
	if (pNewNode == NULL) {
		return ERROR;
	}
	if (pStack->pFirstNode == NULL) {        //处理无节点的情况
		return ERROR;
	}
	else {                                   //检索尾部节点
		pTail = pStack->pFirstNode;           //让尾部节点指针指向第一个节点
		while (pTail->pNextNode != NULL) {
			pTail = pTail->pNextNode;         //尾部节点下移移位
		}
		pTail->pNextNode = pNewNode;          //插入尾部节点
		memcpy(pNewNode->pData, pElem, pStack->dataSize);
	}
	pStack->length++;
	return OK;
}

static Status Stack_Pop(Stack* pStack, void* pElem) {
	ListNode* pCurrentNode = NULL, * pNextNode;
	if (pStack->length = 0) {
		return ERROR;
	}
	pNextNode = pStack->pFirstNode;
	if (pNextNode->pNextNode = NULL) {       //只有头节点
		return ERROR;
	}
	while (pNextNode != NULL) {				
		pCurrentNode = pNextNode;
		pNextNode = pNextNode->pNextNode;
	}
	pElem=ListGetNode(pCurrentNode);
	pCurrentNode->pNextNode = NULL;
	List_freeNode(pCurrentNode);
	pCurrentNode = NULL;
	pStack->length--;
	return OK;
}

static Status StackGetTop(Stack* pStack, void* pElem) {
	ListNode* pCurrentNode = NULL, * pNextNode;
	if (pStack->length = 0) {
		return ERROR;
	}
	pNextNode = pStack->pFirstNode;
	if (pNextNode->pNextNode = NULL) {       //只有头节点
		return ERROR;
	}
	while (pNextNode != NULL) {
		pCurrentNode = pNextNode;
		pNextNode = pNextNode->pNextNode;
	}
	pElem = ListGetNode(pCurrentNode);
	pCurrentNode->pNextNode = NULL;
	pCurrentNode = NULL;
	return OK;

}

static Status visit(ListNode* pStack) {
	if (pStack != NULL) {
		char* a =(char*) pStack->pData;
		printf("%s ", a);
		return OK;
	}
	return ERROR;
}

static Status Stack_Traverse(Stack* pStack, Status(*visit) (ListNode*)) {
	if (pStack->length==0) {
		return ERROR;
	}
	ListNode* pCurrent = pStack->pFirstNode;
	while (pCurrent->pNextNode != NULL) {
		if (visit(pCurrent) == ERROR) {
			return ERROR;
		}
		char* a = (char*)pCurrent;
		a++;
		pCurrent = (ListNode * )a;
	}
	return OK;
}