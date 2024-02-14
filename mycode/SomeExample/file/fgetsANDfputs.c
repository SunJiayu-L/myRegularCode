#include <stdio.h>
#include<string.h>
#define DEBUG 0

int main() {

	FILE *fp = NULL;
    #if DEBUG 
	fp = fopen("D:/a.txt", "r");
    if(fp==NULL){   
        printf("fail");
        return -1;

    }

   char buf[100] ;
    while (!feof(fp))//判断是否读取到文件结尾
    {
    memset(buf, 0, sizeof(buf));
    char *p = fgets(buf, sizeof(buf), fp);//从fp指向的文件中读取sizeof（buf）个值，保存到buf中，换行自动停止
    if (p != NULL) {
    printf("buf = %s", buf);
        } 
     }
     fclose(fp);
    #endif
   
    fp = fopen("D:/a.txt", "w");
    if(fp==NULL){   
        printf("fail");
        return -1;

    }
    char ch[]="hello world";
    fputs(ch,fp);
	fclose(fp);
	return 0;
}