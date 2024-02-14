#ifndef LINKLIST_H
#define LINKLIST_H

#include "common.h"

#define MAX 5


//定义链表的结点，数据与节点指针
//linkList已经是指针了
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode,LinkList;

//This list includes headnode 

//创建链表时已经创建了headNode
Status LinkedList_Init(LinkList* L);

int ListEmpty(LinkList* L);

int  GetElem(LinkList* L,int i);

int LocateElem(LinkList* L,int data);

Status ListInsert(LinkList* L,int x,int i);

Status ListDelete(LinkList* L,int i);

Status ListConstructATFront(LinkList* L,int data);

Status ListConstructATAfter(LinkList* L,int data);

Status visit (int *a);

Status ScanList (LinkList* L);
#endif