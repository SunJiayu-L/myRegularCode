#include "LinkList.h"

int main(){
    LinkList L,*pL;
    pL=&L;   
    LinkedList_Init(pL);
    for(int i=0;i<MAX;i++){
    ListConstructATAfter(pL,i+10);
    } 
    //ListInsert(pL,10,5); 
    //ListDelete(pL,4);
    ScanList(pL); 
    int a=GetElem(pL,1);
    printf("%d",a);
    //int a= LocateElem(pL,10);
    //printf("%d",a);
    return 0;
}