#ifndef  LINKEDLIST_H
#define  LINKEDLIST_H

#include "common.h"
//定义链表的节点
typedef struct ListNode
{
    void* pData;
    struct  ListNode* pNextNode;
}ListNode;

//定义链表，也是定义链表的头节点
typedef struct
{
    ListNode* pFirstNode;
    int length;
    int dataSize;
}List;


ListNode* List_makeNode(List* pList, void* pData);
/*  函数功能：为pList指向的链表创建一个新的节点
    传入参数：链表的头节点pList,节点需储存的数据pData
    返回值：成功返回指向新节点的指针，失败返回NULL
*/

void List_freeNode(ListNode* pNode);
/*  函数功能：释放pNode指向的节点，同时释放节点上的数据
    传入参数：节点指针pNode
    无返回值
*/

List* ListConstruct(int sizeOFData);
/*  函数功能：在动态内存区创建一个空链表并初始化
    传入参数：链表节点的数据长度sizeofData
    返回值：成功返回链表指针，失败返回NULL；
*/

void ListClear(List* pList);
/*  函数功能：清空链表
    传入参数：链表指针pList
    无返回值
*/

void ListDestruct(List* pList);
/* 函数功能：析构链表
    传入参数：链表指针pList
    无返回值
*/

int ListGetLength(List* pList);
/*  函数功能：获得链表的长度
    传入参数：链表指针pList
    返回值：链表长度
*/

void* ListGetNode(ListNode* pNode);
/*  函数功能：获取节点的数据
    传入参数：节点指针pNode
    返回值：指向节点数据的指针
*/


Bool ListIsEmpty(List* pList);
/*  函数功能：判断链表是否为空
    传入参数：链表指针pList
    返回值：为空返回TRUE,非空返回FALSE
*/

Status ListInsertATFront(List* pList, void* pData);
/*  函数功能：在链表头部插入数据
    传入参数：链表指针pList，数据指针pData
    返回值：成功返回OK，失败返回ERROR
*/

Status ListAppendToEnd(List* pList, void* pData);
/*  函数功能：在尾部追加数据
    传入参数：链表指针pList，数据指针pData
    返回值：成功返回OK，失败返回ERROR
*/

Status ListInsertAfter(List* pList, ListNode* pNode, void* pData);
/*  函数功能：在某节点后插入数据
    传入参数：链表指针pList，节点指针pNode，数据指针pData
    返回值：成功插入返回OK；失败返回ERROR
*/


Status ListDeleteFirstNode(List* pList);
/*  函数功能：删除第一个节点
    传入参数：链表指针pList
    返回值：成功返回OK,失败返回ERROR
*/

Status ListDeleteLastNode(List* pList);
/*   函数功能：删除最后一个节点
     传入参数：链表指针pList
     返回值：成功返回OK，失败返回ERROR
*/

Status ListDeletNode(List* pList, ListNode* pNode);
/*  函数功能：删除指定节点
    传入参数:链表指针pList，节点指针pNode
    返回值：成功返回OK，失败返回ERROR
*/



#endif
