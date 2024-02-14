#include "LinkList.h"

Status LinkedList_Init(LinkList* L){
    L->next=NULL;
    L->data=0;
    return OK;
}

int ListEmpty(LinkList* L){
    if(L->data==0){
        return 0;
    }else{
        return L->data;
    }
}

//获取第i个节点的数字，首元节点为第1个
int  GetElem(LinkList* L,int i){
    LNode *temp=L;
    if(temp->data==0||i>temp->data){
        printf ("error");
        exit;
    }
    for(int j=0;j<i;j++){
        temp=temp->next;
    }
    return temp->data;
}

//获取数据为data的节点的地址（为第几个）
int LocateElem(LinkList* L,int data){
    LNode *temp=L;
    if(temp->data==0){
        printf ("error");
        exit;
    }
    temp=temp->next;
    int j=1;
    for( ;temp->data!=data;j++){
        temp=temp->next;
    }
    return j;
}

//在第i个后面插入节点node
Status ListInsert(LinkList* L,int x,int i){
    if(i<1||i>L->data){
        printf("ERROR");
        exit;
    }
    LNode *pre=L->next;
    for(int j=1;j<i;j++){
        pre=pre->next;
    }
    LNode* temp=(LNode*)malloc(sizeof(LNode));
    temp->data=x;
    temp->next=pre->next;
    pre->next=temp;
    L->data++;
    return OK;
}

Status ListDelete(LinkList* L,int i){
    LNode *temp=L;
    if(L->data==0){
        printf ("error");
        return ERROR;
    }
    if(i==1){
        free(L->next);
        L->data--;
        return OK;
    }
    temp=temp->next;
    for(int j=1;j<i-1;j++){
        temp=temp->next;
    }
    LNode *q=temp->next;
    temp->next=q->next;
    free(q);
    L->data--;
    return OK;
}

Status ListConstructATFront(LinkList* L,int data){
    LNode* temp=L;//存贮起始地址
    LNode *p=(LNode*)malloc(sizeof(LNode));
    if(p==NULL){
        return ERROR;
    }
    p->data=data;
    p->next=L->next;
    L->next=p;
    L=temp;//将L挪回表头
    L->data++;

}

Status ListConstructATAfter(LinkList* L,int data){
    LNode *temp=L;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    LNode *p=(LNode*)malloc(sizeof(LNode));
    if(p==NULL){
        return ERROR;
    }
    p->data=data;
    p->next=NULL;// "->"代表指针指向的结构体成员，并不是直接操作struct LNode，而是通过指针操作struct LNode
    temp->next=p;
    L->data++;
}

Status visit (int *a){
    printf("%d\n",*a);
    return OK;
}

Status ScanList (LinkList* L){
    LNode* temp=L;
    for (int i = 0; i < L->data; i++){
    temp=temp->next;
    visit(&temp->data);//在这一步判断时已经完成printf操作
    }
    return OK;
}
