#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM 10
void Assign(float* pTable ,int n);//为平方跟赋值，pTable是指向平方根表的指针，n为平方根表的长度
void Print(float *pTable ,int n);//把平方根表打印在屏幕上，pTable是指向平方根表的指针，n为平方根表的长度
int main (){
    //定义一个指针叫pSqrtTable，用它来接收一块内存，注意一定要有申请失败的处理
    float *pSqrtTable;
    pSqrtTable=malloc(NUM*sizeof(float));
    if(pSqrtTable==NULL){
        printf("error");
        return 1;
    }
    //
    Assign(pSqrtTable,NUM);
    Print(pSqrtTable,NUM);
    //释放栈，同时把栈内指针置空
    free (pSqrtTable);
    pSqrtTable=NULL;
    //
    return 0;
}

void Assign(float* pTable ,int n){
    
    for (int i=0;i<10;i++){
        pTable[i]=sqrt((float)i);
    }
    return ;

}
void Print(float *pTable ,int n){
    for(int i=0;i<10;i++){
        printf("%d----%f\t",i ,pTable[i]);
    }
}
