# include <stdio.h>
#include <stdlib.h>
# define num 100
#define add 10
int main (){
    //malloc使用
    int *p=NULL;
    *p=malloc(num*sizeof(int));
    //realloc使用，用*q来申请，*p来操作，最后free（*q）
    int *q=(int *)realloc(p,add*sizeof(int));
    if(q!=NULL){
        p=q;
    }else {

    }
    return 0;
}
