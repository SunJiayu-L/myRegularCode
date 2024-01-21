#include  "Stack.h"

#define ARRAT_SIZE      100

int Get_Priority(char c);
/*	函数功能：比较操作符优先级
	传入参数：操作符c
	返回值：优先级大小
*/

void TransPostNot(char* RecStr, char* MidStr);
/*	函数功能：中缀表达式转后缀表达式
	传入参数: 中缀表达式RecStr，用于接收的后缀表达式MidStr
	无返回值
*/

float Calculate(char* str);
/*	函数功能：计算后缀表达式
	传入参数：后缀表达式str
	返回值：double类型的计算结果
*/

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



void TransPostNot(char* RecStr, char* MidStr) {
	//初始化字符栈
	Stack* pStack = Stack_Construct(sizeof(char));
	int i;
	int j = 0;
	for (i = 0; i < (int)strlen(RecStr); i++) {
		if (RecStr[i] == '-') { //负数情况判断
			if (i == 0) {
				MidStr[j] = RecStr[i];
				j++;
				i++;
			}
			else if (RecStr[i - 1] == '(') {
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
			while (Stack_IsEmpty(pStack) == FALUSE && Get_Priority(RecStr[i]) <= Get_Priority(temp)) {
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
			while (Stack_IsEmpty(pStack) == FALUSE && Get_Priority(RecStr[i]) <= Get_Priority(temp)) {
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
		if (RecStr[i] == 's' && RecStr[i + 1] == 'i') {
			StackGetTop(pStack, &temp);
			while (Stack_IsEmpty(pStack) == FALUSE && Get_Priority(RecStr[i]) <= Get_Priority(temp)) {
				char temp1;
				Stack_Pop(pStack, &temp1);
				MidStr[j] = temp1;
				j++;
				MidStr[j] = ' ';
				j++;
				StackGetTop(pStack, &temp);
			}
			Stack_Push(pStack, &RecStr[i]);
			i += 2;
		}
		if (RecStr[i] == 'c') {
			StackGetTop(pStack, &temp);
			while (Stack_IsEmpty(pStack) == FALUSE && Get_Priority(RecStr[i]) <= Get_Priority(temp)) {
				char temp1;
				Stack_Pop(pStack, &temp1);
				MidStr[j] = temp1;
				j++;
				MidStr[j] = ' ';
				j++;
				StackGetTop(pStack, &temp);
			}
			Stack_Push(pStack, &RecStr[i]);
			i += 2;
		}
		if (RecStr[i] == 't') {
			StackGetTop(pStack, &temp);
			while (Stack_IsEmpty(pStack) == FALUSE && Get_Priority(RecStr[i]) <= Get_Priority(temp)) {
				char temp1;
				Stack_Pop(pStack, &temp1);
				MidStr[j] = temp1;
				j++;
				MidStr[j] = ' ';
				j++;
				StackGetTop(pStack, &temp);
			}
			Stack_Push(pStack, &RecStr[i]);
			i += 2;
		}
		if (RecStr[i] == 's' && RecStr[i + 1] == 'q') {
			StackGetTop(pStack, &temp);
			while (Stack_IsEmpty(pStack) == FALUSE && Get_Priority(RecStr[i]) <= Get_Priority(temp)) {
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
			i += 2;
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

float Calculate(char* str) {
	int i = 0;
	int j = 0;
	char temp[ARRAT_SIZE];
	double temp1, temp2, temp3, result;/*temp1,temp分别为待计算数1，数2；
									temp3为数1与数2的计算结果
									result为最终计算结果*/

	Stack* pNumStack = Stack_Construct(sizeof(double));
	while (str[i]) {
		switch (str[i]) {
		case '-':
			if (isdigit(str[i + 1])) { //判断'-'是作为负数符号or运算符
				temp[j] = str[i];
				j++;
				i++;
				temp[j] = '\0';
				break;
			}
			else {
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
			if (str[i] == ' ') {
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
	int opt = 0;
	scanf("%d", &opt);
	if (opt == 1) {
		printf("输入所计算表达式\n");
		scanf("%s", RecStr);
		TransPostNot(RecStr, MidStr);
		double result = Calculate(MidStr);
		printf("%f ", result);
#if DEBUG 	
		printf("后缀表达式为\n");
		printf("%s\n", MidStr);
		printf("计算结果为");
		printf("%f ", result);
#endif
	}
	else if (opt == 2) {
		FILE* fp = fopen("D:/Mycode/input.txt", "r");
		if (fp == NULL) {
			printf("打开文件失败");
			return -1;
		}
		FILE* fp1 = fopen("D:/Mycode/result.txt", "w");
		if (fp1 == NULL) {
			printf("打开文件失败");
			return -1;
		}
		while (!feof(fp)) {//判断文件是否结束
			fscanf(fp, "%s", RecStr);
			TransPostNot(RecStr, MidStr);
			double result = Calculate(MidStr);
			fprintf(fp1, "%s=%f\n", RecStr, result);
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
