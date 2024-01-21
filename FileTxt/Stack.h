#ifndef STACK_H
#define STACK_H

#include "common.h"
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 5

typedef struct {
	void* pBase;
	void* pTop;
	int elementSize;
	int stackSize;
} Stack;

Stack* Stack_Construct(int sizeOfElment);
/* 	函数功能：构造一个栈
	传入参数：sizeOFElement为栈的元素类型的长度
	返回值：如果构造成功返回指向栈的指针Stack*，如果失败返回NULL;
*/

void StackDestruct(Stack* pStack);
/* 	函数功能：销毁一个栈
	传入参数：栈指针pStack
	无返回值
*/

Bool Stack_IsEmpty(Stack* pStack);
/*	函数功能：判断栈是否空
	传入参数：栈指针pStack
	返回值：如果栈空返回TRUE；如果栈非空，返回FALUSE
*/

int Stack_Length(Stack* pStack);
/* 	函数功能：计算栈的长度
	传入参数：栈指针pStack
	返回值：返回栈顶指针与栈底指针的字节差
*/


Status Stack_Push(Stack* pStack, void* pElem);
/*	函数功能：将pElem指向的元素压入pStack指向的栈中
	传入参数：栈指针pStack；指向待入栈元素的指针pElem
	返回值：入栈成功返回OK;失败返回ERROR
*/

Status Stack_Pop(Stack* pStack, void* pElem);
/* 	函数功能：将pElem指向的元素从pStack指向的栈中弹出
	传入参数：栈指针pStack，指向待弹出的元素的指针pElem
	返回值：  出栈成功返回OK，出栈失败返回FALUSE
*/


Status StackGetTop(Stack* pStack, void* pElem);
/*	函数功能： 获取栈顶元素
	传入参数：栈指针pStack，指向栈顶元素的指针pElem
	返回值： 获取成功返回OK；获取失败返回FALUSE
*/

Status Stack_Traverse(Stack* pStack, Status(*visit) (void*));
/* 	函数功能：遍历pStack所指向的栈，对栈中每个元素指向visit操作
	传入参数：栈指针pStack，指向函数的指针visit，visit的参数是void*（为栈底指针），返回值为Status
	返回值：成功遍历，返回OK;失败返回ERROR;
*/

#endif