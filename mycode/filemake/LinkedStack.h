#ifndef LINKEDSTACK_H
#define	LINKEDSTACK_H

#include "common.h"
#include "LinkedList.h"

typedef List Stack;

 Stack* Stack_Construct(int sizeOFData);
/*	函数功能：构造一个栈
*	传入参数：栈元素类型长度sizeOFData
*	返回值：  栈指针
*/

 void StackDestruct(Stack* pStack);
/*	函数功能：析构栈
*	传入参数：栈指针pStack
*	无返回值
*/

 Bool Stack_IsEmpty(Stack* pStack);
/*	函数功能：判断是否栈空
*	传入参数：栈指针pStack
*	返回值：成功返回TRUE，失败返回FALUSE
*/


int Stack_Length(Stack* pStack);
/*	函数功能：获得栈的长度
*	传入参数：栈指针pStack
*	返回值：栈长度
*/

 Status Stack_Push(Stack* pStack, void* pElem);
/*	函数功能：入栈
*	传入参数：栈指针pStack，数据指针pElem
*	返回值：成功返回OK,失败返回ERROE
*/

 Status Stack_Pop(Stack* pStack, void* pElem);
/*	函数功能：出栈
*	传入参数：栈指针pStack，数据指针pElem
	返回值：成功返回OK,失败返回ERROR
*/

 Status StackGetTop(Stack* pStack, void* pElem);
/*	函数功能：获取栈顶指针
*	传入参数：栈指针篇Stack，数据指针pElem
*	返回值：成功返回OK,失败返回ERROR
*/

 Status visit(ListNode* pStack);
/*	函数功能：对栈中数据打印
*	传入参数：栈中元素的地址
*	返回值：成功返回OK,失败返回ERROR
*/

 Status Stack_Traverse(Stack* pStack, Status(*visit) (ListNode* ));
/*	函数功能：对栈进行遍历，执行visit操作
*	传入参数：栈指针，pStack，指向函数的指针visit，visit的参数是ListNode* （为栈底指针），返回值为Status
* 	返回值：成功返回OK,失败返回ERROR
*/


#endif 

