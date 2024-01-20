#include <stdio.h>

#define CAPACITY  128

typedef struct {
    int len; // 线性表实际存储的元素个数
    int data[CAPACITY]; // 数组形式的存储空间
} list;


int del(list *L, int pos) {
    // TODO
    int temp=L->data[pos-1];
    for(int i=pos-1;i<L->len-1;i++){
    L->data[i]=L->data[i+1];
    }
    L->len--;
    return temp;

    // END OF TODO
}


int main() {
    // 定义线性表及其指针
    list l, *L = &l;

    // 输入线性表长度
    printf("len:");
    scanf("%d", &L->len);
    // 输入线性表元素
    for (int i = 0; i < L->len; ++i)
        scanf("%d", &L->data[i]);
    
    int pos;
    // 输入插入位置和插入值
    scanf("%d", &pos);

    // 删除操作
    printf("del=%d\n", del(L, pos));

    // 输出删除后的线性表
    for (int i = 0; i < L->len; ++i)
        printf("%d ", L->data[i]);
    printf("\n");

    return 0;
}