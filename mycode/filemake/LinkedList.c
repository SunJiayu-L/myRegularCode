#include "common.h"
#include "LinkedList.h"

ListNode* List_makeNode(List* pList, void* pData) {
    ListNode* pNewNode;
    pNewNode = (ListNode*)malloc(sizeof(ListNode));//初始化一个节点指针，指向一个节点
    if (pNewNode == NULL) {                         //处理开辟失败的情况
        return NULL;
    }
    pNewNode->pData = malloc(pList->dataSize);//为节点数据开辟内存
    if (pNewNode->pData == NULL) {
        free(pNewNode);
        return NULL;
    }
    memcpy(pNewNode->pData, pData, pList->dataSize);//把pData的pList->dataSize个字节拷贝给pNewNode
    pNewNode->pNextNode = NULL;
    return pNewNode;
}

/*  函数功能：释放pNode指向的节点，同时释放节点上的数据
    传入参数：节点指针pNode
    无返回值
*/
void List_freeNode(ListNode* pNode) {
    if (pNode == NULL) {                        //如果节点指针指向空（没有需要释放的节点）
        return;
    }
    free(pNode->pData);                     //先释放节点数据
    free(pNode);                           //释放节点
    return;
}

/*  函数功能：在动态内存区创建一个空链表并初始化
    传入参数：链表节点的数据长度sizeofData
    返回值：成功返回链表指针，失败返回NULL；
*/
List* ListConstruct(int sizeOFData) {
    List* pList = (List*)malloc(sizeof(List));//定义一个链表（头节点）
    if (pList == NULL) {
        return NULL;
    }
    pList->pFirstNode = NULL;
    pList->length = 0;
    pList->dataSize = sizeOFData;
    return pList;
}

/*  函数功能：清空链表
    传入参数：链表指针pList
    无返回值
*/
void ListClear(List* pList) {
    ListNode* pCurrentNode, * pNextNode;      //定义两个辅助指针
    pCurrentNode = pList->pFirstNode;         //让pCurrentNode指向第一个节点
    while (pCurrentNode != NULL) {
        pNextNode = pCurrentNode->pNextNode;  //用pNextNode指向下一个需要释放的节点
        List_freeNode(pCurrentNode);        //释放pCurrentNode指向的节点
        pCurrentNode = pNextNode;             //让pCurrentNode指向下一个节点
    }
    pList->pFirstNode = NULL;
    pList->length = 0;
    return;
}

/* 函数功能：析构链表
    传入参数：链表指针pList
    无返回值
*/
void ListDestruct(List* pList) {
    ListClear(pList);
    free(pList);
    return;
}

/*  函数功能：获得链表的长度
    传入参数：链表指针pList
    返回值：链表长度
*/
int ListGetLength(List* pList) {
    return pList->length;
}

/*  函数功能：获取节点的数据
    传入参数：节点指针pNode
    返回值：指向节点数据的指针
*/
void* ListGetNode(ListNode* pNode) {
    return pNode->pData;
}

/*  函数功能：判断链表是否为空
    传入参数：链表指针pList
    返回值：为空返回TRUE,非空返回FALSE
*/
Bool ListIsEmpty(List* pList) {
    if (pList->length = 0) {
        return TRUE;
    }
    else {
        return FALUSE;
    }

}

/*  函数功能：在链表头部插入数据
    传入参数：链表指针pList，数据指针pData
    返回值：成功返回OK，失败返回ERROR
*/
Status ListInsertATFront(List* pList, void* pData) {
    ListNode* pNewNode;
    pNewNode = List_makeNode(pList, pData);    //创建一个节点指针
    if (pNewNode == NULL) {
        return ERROR;
    }
    pNewNode->pNextNode = pList->pFirstNode;  //让插入节点的pNextNode指向第一个节点
    pList->pFirstNode = pNewNode;             //让链表的pFirstNode指向pNewNode
    memcpy(pNewNode->pData, pData, pList->dataSize);
    pList->length++;
    return OK;
}

/*  函数功能：在尾部追加数据
    传入参数：链表指针pList，数据指针pData
    返回值：成功返回OK，失败返回ERROR
*/
Status ListAppendToEnd(List* pList, void* pData) {
    ListNode* pNewNode, * pTail;
    pNewNode = List_makeNode(pList, pData);
    if (pNewNode == NULL) {
        return ERROR;
    }
    if (pList->pFirstNode == NULL) {        //处理无节点的情况
        return ERROR;
    }
    else {                                   //检索尾部节点
        pTail = pList->pFirstNode;           //让尾部节点指针指向第一个节点
        while (pTail->pNextNode != NULL) {
            pTail = pTail->pNextNode;         //尾部节点下移移位
        }
        pTail->pNextNode = pNewNode;          //插入尾部节点
        memcpy(pNewNode->pData, pData, pList->dataSize);
    }
    pList->length++;
    return OK;
}

/*  函数功能：在某节点后插入数据
    传入参数：链表指针pList，节点指针pNode，数据指针pData
    返回值：成功插入返回OK；失败返回ERROR
*/
Status ListInsertAfter(List* pList, ListNode* pNode, void* pData) {
    ListNode* pNewNode;
    pNewNode = List_makeNode(pList, pData);
    if (pNewNode == NULL) {
        return ERROR;
    }
    pNewNode->pNextNode = pNode->pNextNode;
    pNode->pNextNode = pNewNode;
    memcpy(pNewNode->pData, pData, pList->dataSize);
    pList->length++;
    return OK;
}

/*  函数功能：删除第一个节点
    传入参数：链表指针pList
    返回值：成功返回OK,失败返回ERROR
*/
Status ListDeleteFirstNode(List* pList) {
    ListNode* pTemNode;
    if (pList->length == 0) {
        return ERROR;
    }
    pTemNode = pList->pFirstNode;
    pList->pFirstNode = pTemNode->pNextNode;
    List_freeNode(pTemNode);
    pTemNode = NULL;
    pList->length--;
    return OK;
}

/*   函数功能：删除最后一个节点
     传入参数：链表指针pList
     返回值：成功返回OK，失败返回ERROR
*/
Status ListDeleteLastNode(List* pList) {
    ListNode* pCurrentNode=NULL, * pNextNode;
    if (pList->length = 0) {
        return ERROR;
    }
    pNextNode = pList->pFirstNode;
    if (pNextNode->pNextNode = NULL) {       //只有一个节点
        return ListDeleteFirstNode(pList);
    }
    while (pNextNode != NULL) {
        pCurrentNode = pNextNode;
        pNextNode = pNextNode->pNextNode;
    }
    pCurrentNode->pNextNode = NULL;
    List_freeNode(pCurrentNode);
    pCurrentNode = NULL;
    pList->length--;
    return OK;
}

/*  函数功能：删除指定节点
    传入参数:链表指针pList，节点指针pNode
    返回值：成功返回OK，失败返回ERROR
*/
Status ListDeletNode(List* pList, ListNode* pNode) {
    ListNode* pTempNode;
    if (pNode == NULL) {        //如果节点已经删除
        return OK;
    }
    if (pList->length == 0) {   //如果无节点
        return ERROR;
    }
    pTempNode = pList->pFirstNode;
    if (pTempNode == pNode) {              //如果删除节点恰好为第一个节点
        pList->pFirstNode = pNode->pNextNode;
    }
    else {
        while (pTempNode != NULL && pTempNode->pNextNode != pNode) {
            pTempNode = pTempNode->pNextNode;
        }
        if (pTempNode == NULL) {       //如果没有删除的节点
            return ERROR;
        }
        pTempNode->pNextNode = pNode->pNextNode;
    }
    List_freeNode(pNode);
    pList->length--;
    return OK;
}

