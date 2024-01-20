#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 5
#define ARRAT_SIZE      100
#define DEBUG 1

typedef enum {ERROR, OK} Status;

typedef enum {FALUSE, TRUE} Bool;

typedef struct {
	void *pBase;
	void *pTop;
	int elementSize;
	int stackSize;
} Stack;



Stack *Stack_Construct(int sizeOfElment);
/* 	函数功能：构造一个栈
	传入参数：sizeOFElement为栈的元素类型的长度
	返回值：如果构造成功返回指向栈的指针Stack*，如果失败返回NULL;
*/

void StackDestruct(Stack *pStack);
/* 	函数功能：销毁一个栈
	传入参数：栈指针pStack
	无返回值
*/

Bool Stack_IsEmpty(Stack *pStack);
/*	函数功能：判断栈是否空
	传入参数：栈指针pStack
	返回值：如果栈空返回TRUE；如果栈非空，返回FALUSE
*/

int Stack_Length(Stack *pStack);
/* 	函数功能：计算栈的长度
	传入参数：栈指针pStack
	返回值：返回栈顶指针与栈底指针的字节差
*/


Status Stack_Push (Stack *pStack, void *pElem);
/*	函数功能：将pElem指向的元素压入pStack指向的栈中
	传入参数：栈指针pStack；指向待入栈元素的指针pElem
	返回值：入栈成功返回OK;失败返回ERROR
*/

Status Stack_Pop(Stack *pStack, void *pElem);
/* 	函数功能：将pElem指向的元素从pStack指向的栈中弹出
	传入参数：栈指针pStack，指向待弹出的元素的指针pElem
	返回值：  出栈成功返回OK，出栈失败返回FALUSE
*/


Status StackGetTop(Stack *pStack, void *pElem);
/*	函数功能： 获取栈顶元素
	传入参数：栈指针pStack，指向栈顶元素的指针pElem
	返回值： 获取成功返回OK；获取失败返回FALUSE
*/

Status Stack_Traverse(Stack *pStack, Status(*visit) (void *));
/* 	函数功能：遍历pStack所指向的栈，对栈中每个元素指向visit操作
	传入参数：栈指针pStack，指向函数的指针visit，visit的参数是void*（为栈底指针），返回值为Status
	返回值：成功遍历，返回OK;失败返回ERROR;
*/

void TransPostNot(char *RecStr, char *MidStr);
/*	函数功能：中缀表达式转后缀表达式
	传入参数: 中缀表达式RecStr，用于接收的后缀表达式MidStr
	无返回值
*/

float Calculate(char *str);
/*	函数功能：计算后缀表达式
	传入参数：后缀表达式str
	返回值：double类型的计算结果
*/

int Get_Priority(char c) ;
/*	函数功能：比较操作符优先级
	传入参数：操作符c
	返回值：优先级大小
*/

Stack *Stack_Construct(int sizeOfElment) {
	Stack *pStack;
	pStack = (Stack *)malloc(sizeof(Stack));
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

void StackDestruct(Stack *pStack) {
	if (pStack == NULL) {
		return;
	}
	free(pStack->pBase);
	free(pStack);
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

Status Stack_Push (Stack *pStack, void *pElem) {
	int NewSize;
	void *pTemp = NULL;  //realloc使用，自定义一个新的指针申请内存
	if (Stack_Length(pStack) >= pStack->stackSize) {
		NewSize = pStack->stackSize + STACK_INCREMENT;
		pTemp = (void *)realloc(pStack->pBase, NewSize * sizeof(pStack->elementSize));

		if (pTemp == NULL) {
			return ERROR;
		} else { //成功申请内存后，要重新赋值，因为realloc可能导致栈不在原来的地方。
			pStack->pBase = pTemp;
			pStack->pTop = pStack->pBase + pStack->stackSize;
			pStack->stackSize = NewSize;
		}
	}
	memcpy(pStack->pTop, pElem, pStack->elementSize);
	char *pc = (char *)(pStack->pTop);
	pStack->pTop = pc + pStack->elementSize;
	return OK;
}

Status Stack_Pop(Stack *pStack, void *pElem) {
	char *pc;
	if (pStack->pTop == pStack->pBase) {
		return ERROR;
	} else {
		pc = (char *)(pStack->pTop);
		pStack->pTop = pc - pStack->elementSize; //pc用来辅助调整栈顶指针
		memcpy(pElem, pStack->pTop, pStack->elementSize); //把pStack->pTop的pStack->element给个字节内存拷贝给pElem，
		//此时pElem即指向存储的内容

		return OK;

	}
}

Status StackGetTop(Stack *pStack, void *pElem) {
	char *pc;
	if (pStack->pTop == pStack->pBase) {
		return ERROR;
	} else {
		pc = (char *)(pStack->pTop);
		pStack->pTop = pc - pStack->elementSize; //pc用来辅助调整栈顶指针
		memcpy(pElem, pStack->pTop, pStack->elementSize); //把pStack->pTop的pStack->element给个字节内存拷贝给pElem，
		//此时pElem即指向存储的内容
		pStack->pTop = pc;
		return OK;

	}
}

Status visit (void *pBase) {
	if (pBase != NULL) {
		printf("%p ", pBase);
		return OK;
	}
	return ERROR;
}

Status Stack_Traverse(Stack *pStack, Status (*visit) (void *)) {
	int i, n;
	if (pStack->pBase == NULL || pStack->pTop == pStack->pBase) {
		return ERROR;
	}
	void *p = pStack->pBase;
	while (p != pStack->pTop) {
		visit(p);
		p++;
	}
	return OK;
}

int Get_Priority(char c) {
    switch (c) {
		case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case 's':
		case 'c':
		case 't':
            return 4;
		case 'q':
			return 5;
        default:
            return -1;
    }
}



void TransPostNot(char *RecStr, char *MidStr) {
	//初始化字符栈
	Stack *pStack = Stack_Construct(sizeof(char));
	int i;
	int j = 0;
	for ( i = 0; i < (int)strlen(RecStr); i++) {
		if (RecStr[i] == '-') { //负数情况判断
			if (i == 0) {
				MidStr[j] = RecStr[i];
				j++;
				i++;
			} else if (RecStr[i - 1] == '(') {
				MidStr[j] = RecStr[i];
				j++;
				i++;
			}
		}
		//数字与小数点直接进入后缀表达式
		while (isdigit(RecStr[i]) || '.' == RecStr[i]) {
			MidStr[j] = RecStr[i];
			i++;
			j++;
			if (isdigit(RecStr[i]) == ERROR && '.' != RecStr[i]) {
				MidStr[j] = ' ';
				j++;
			}
		}

		char temp;
		//左括号直接入栈
		if (RecStr[i] == '(') {
			Stack_Push(pStack, &RecStr[i]);
		}
		//右括号入栈
		if (RecStr[i] == ')') {
			StackGetTop(pStack, &temp);
			while (temp != '(') {
				char temp1;
				Stack_Pop(pStack, &temp1);
				MidStr[j] = temp1;
				j++;
				MidStr[j] = ' ';
				j++;
				StackGetTop(pStack, &temp);
			}
			Stack_Pop(pStack, &temp);
		}


		if (RecStr[i] == '+' || RecStr[i] == '-') {
			StackGetTop(pStack, &temp);
			while (Stack_IsEmpty(pStack) == FALUSE && Get_Priority(RecStr[i])<=  Get_Priority(temp)) {
				char temp1;
				Stack_Pop(pStack, &temp1);
				MidStr[j] = temp1;
				j++;
				MidStr[j] = ' ';
				j++;
				StackGetTop(pStack, &temp);
			}
			Stack_Push(pStack, &RecStr[i]);
		}

		if (RecStr[i] == '*' || RecStr[i] == '/') {
			StackGetTop(pStack, &temp);
			while (Stack_IsEmpty(pStack) == FALUSE && Get_Priority(RecStr[i])<=  Get_Priority(temp)) {
				char temp1;
				Stack_Pop(pStack, &temp1);
				MidStr[j] = temp1;
				j++;
				MidStr[j] = ' ';
				j++;
				StackGetTop(pStack, &temp);
			}

			Stack_Push(pStack, &RecStr[i]);
		}
		if(RecStr[i] == 's'&&RecStr[i+1] == 'i'){
			StackGetTop(pStack, &temp);
			while (Stack_IsEmpty(pStack) == FALUSE && Get_Priority(RecStr[i])<=  Get_Priority(temp)) {
				char temp1;
				Stack_Pop(pStack, &temp1);
				MidStr[j] = temp1;
				j++;
				MidStr[j] = ' ';
				j++;
				StackGetTop(pStack, &temp);
			}
			Stack_Push(pStack, &RecStr[i]);
			i+=2;
		}
		if(RecStr[i] == 'c'){
			StackGetTop(pStack, &temp);
			while (Stack_IsEmpty(pStack) == FALUSE &&Get_Priority(RecStr[i])<=  Get_Priority(temp)) {
				char temp1;
				Stack_Pop(pStack, &temp1);
				MidStr[j] = temp1;
				j++;
				MidStr[j] = ' ';
				j++;
				StackGetTop(pStack, &temp);
			}
			Stack_Push(pStack, &RecStr[i]);
			i+=2;
		}
		if(RecStr[i] == 't'){
			StackGetTop(pStack, &temp);
			while (Stack_IsEmpty(pStack) == FALUSE&& Get_Priority(RecStr[i])<=  Get_Priority(temp)) {
				char temp1;
				Stack_Pop(pStack, &temp1);
				MidStr[j] = temp1;
				j++;
				MidStr[j] = ' ';
				j++;
				StackGetTop(pStack, &temp);
			}
			Stack_Push(pStack, &RecStr[i]);
			i+=2;
		}
		if(RecStr[i] == 's'&&RecStr[i+1] == 'q'){
			StackGetTop(pStack, &temp);
			while (Stack_IsEmpty(pStack) == FALUSE && Get_Priority(RecStr[i])<=  Get_Priority(temp)) {
				char temp1;
				Stack_Pop(pStack, &temp1);
				MidStr[j] = temp1;
				j++;
				MidStr[j] = ' ';
				j++;
				StackGetTop(pStack, &temp);
			}
			i++;
			Stack_Push(pStack, &RecStr[i]);
			i+=2;
		}
	}
	while (Stack_IsEmpty(pStack) == FALUSE) {
		char s;
		Stack_Pop(pStack, &s);
		if (s != '(') {
			MidStr[j] = s;
			j++;
			MidStr[j] = ' ';
			j++;
		}
	}
	MidStr[--j] = '\0';
	StackDestruct(pStack);
}

float Calculate(char *str) {
	int i = 0;
	int j = 0;
	char temp[ARRAT_SIZE];
	double temp1, temp2, temp3, result;/*temp1,temp分别为待计算数1，数2；
								    temp3为数1与数2的计算结果
									result为最终计算结果*/

	Stack *pNumStack = Stack_Construct(sizeof(double));
	while (str[i]) {
		switch (str[i]) {
			case '-':
				if ( isdigit(str[i + 1]) ) { //判断'-'是作为负数符号or运算符
					temp[j] = str[i];
					j++;
					i++;
					temp[j] = '\0';
					break;
				} else {
					Stack_Pop(pNumStack, &temp1);
					Stack_Pop(pNumStack, &temp2);
					temp3 = temp2 - temp1;
					Stack_Push(pNumStack, &temp3);
					i++;
					break;
				}
			case '+':
				Stack_Pop(pNumStack, &temp1);
				Stack_Pop(pNumStack, &temp2);
				temp3 = temp1 + temp2;
				Stack_Push(pNumStack, &temp3);
				i++;
				break;
			case '*':
				Stack_Pop(pNumStack, &temp1);
				Stack_Pop(pNumStack, &temp2);
				temp3 = temp1 * temp2;
				Stack_Push(pNumStack, &temp3);
				i++;
				break;
			case '/':
				Stack_Pop(pNumStack, &temp1);
				Stack_Pop(pNumStack, &temp2);
				if (temp2 == 0) {
					printf("ERROR：分母不能为0");//分母为0时：ERROR

				}
				temp3 = temp2 / temp1;
				Stack_Push(pNumStack, &temp3);
				i++;
				break;
			case ' ':
				i++;
				break;
			case 's':
				Stack_Pop(pNumStack, &temp1);
				temp3 = sin(temp1);
				Stack_Push(pNumStack, &temp3);
				i++;
				break;
			case 'c':
				Stack_Pop(pNumStack, &temp1);
				temp3 = cos(temp1);
				Stack_Push(pNumStack, &temp3);
				i++;
				break;
			case 't':
				Stack_Pop(pNumStack, &temp1);
				temp3 = tan(temp1);
				Stack_Push(pNumStack, &temp3);
				i++;
				break;
			case 'q':
				Stack_Pop(pNumStack, &temp1);
				temp3 = sqrt(temp1);
				Stack_Push(pNumStack, &temp3);
				i++;
				break;
		}

		while (isdigit(str[i]) || '.' == str[i]) {
			temp[j] = str[i];
			j++;
			i++;
			temp[j] = '\0';
			if ( str[i] == ' ' ) {
				result = atof(temp);  //此时分析出的就是完整的运算数
				Stack_Push(pNumStack, &result);
				i++;
				j = 0;
			}
		}
	}
	Stack_Pop(pNumStack, &result);
	StackDestruct(pNumStack);
	return result;
}

int main() {
	char RecStr[ARRAT_SIZE];//接收字符串
	char MidStr[ARRAT_SIZE];//中间量
	//模式选择
	printf("请选择模式\n");
	printf("1.普通计算\n");
	printf("2.批量计算\n");
	int opt=0;
	scanf("%d",&opt);
	if(opt==1){
		printf("输入所计算表达式\n");
		scanf("%s",RecStr);
		TransPostNot(RecStr, MidStr);
		double result = Calculate(MidStr);
		printf("%f ", result);
		#if DEBUG 	
		printf("后缀表达式为\n");
		printf("%s\n", MidStr);
		printf("计算结果为");
		printf("%f ", result);
		#endif
	} else if (opt==2){
		FILE* fp=fopen("D:/Mycode/input.txt","r");
		if(fp==NULL){
			printf("打开文件失败");
			return -1;
		}
		FILE* fp1=fopen("D:/Mycode/result.txt","w");
		if(fp1==NULL){
			printf("打开文件失败");
			return -1;
		}
		while (!feof(fp)){//判断文件是否结束
			fscanf(fp,"%s",RecStr);
			TransPostNot(RecStr, MidStr);
			double result = Calculate(MidStr);
			fprintf(fp1,"%s=%f\n",RecStr,result);
			#if DEBUG 
			printf("后缀表达式为");
			printf("%s\n", MidStr);
			printf("%f \n", result);
			#endif
		}
		fclose(fp);
		fclose(fp1);
	}
	return 0;
}


