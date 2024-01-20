#include <stdio.h>
#define STACK_SIZE 10
typedef unsigned int Element;
typedef enum {ERROR, OK} Status;
typedef enum {FALUSE, TRUE} Bool;
 typedef struct  
 {
  Element arr[STACK_SIZE];
  int n;
 }SimpleStack;
 
 void InitStack(SimpleStack *pStack);
 Bool IsStackEmpty(SimpleStack *pStack);
 Status Push (SimpleStack *pStack,Element * pElem);
 Status Pop (SimpleStack *pStack,Element *pElem);

int main(){
    SimpleStack stack;
    InitStack(&stack);

    int number[10]={0};
    int receive[10]={0};
    int j=1;
    for (int i=0;i<10;i++){
    number[i]=j;
    j++;
     Push (&stack,&number[i]);
}
    for (int i = 0; i < 10; i++)
    {
         Pop(&stack,&receive[i]);
        printf("%d ",receive[i]);
    }
return 0;
}

 void InitStack(SimpleStack *pStack){
    pStack->n=0;
 }
  Bool IsStackEmpty(SimpleStack *pStack){
    if (pStack->n<=0){
        return ERROR ;
    }
  }

 Status Push (SimpleStack *pStack,Element * pElem){
    if(pStack->n>=STACK_SIZE){
        return ERROR;
    }
    pStack->arr[pStack->n]=*pElem;
    pStack->n++;
    return OK;
 }

 Status Pop (SimpleStack *pStack,Element *pElem){
     if (pStack->n<=0){
        return ERROR ;
    }
    pStack->n--;
    *pElem=pStack->arr[pStack->n];
    return OK;
 }
