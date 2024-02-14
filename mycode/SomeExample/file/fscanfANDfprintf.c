#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1
int main(){
    #if DEBUG
    FILE* fp=NULL;
    fp=fopen("D:/a.txt","r");
    if(fp==NULL){
        return -1;
    }
    int a,b,c;
    fscanf(fp,"%d+%d=%d",&a,&b,&c);
    printf("%d ",a);
    printf("%d ",b);
    fclose(fp);
    #endif
    /*FILE* fp=NULL;
    fp=fopen("D:/a.txt","w");
    if(fp==NULL){
    return -1;
    }

    char arr[50];
    fprintf(fp,"%s",arr);*/
    return 0;
}