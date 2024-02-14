#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int main() {

	FILE *fp;
    FILE *fp1;

	fp = fopen("D:/a.txt", "r");
    fp1=fopen("D:/b.txt","w");
    if(fp==NULL){   
        printf("fail");
        return -1;

    }
    char *p=NULL;
    p=(char*)malloc(sizeof(char)*20);
    memset(p,0,20);
    fgets(p,20,fp);
    fputs(p,fp1);

	fclose(fp);
	return 0;
}