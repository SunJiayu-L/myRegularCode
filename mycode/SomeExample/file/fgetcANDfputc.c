  //不能修改文件指针的值，光标自动下移移位
  //文件默认结尾为-1
#include <stdio.h>


int main() {

	FILE *fp = NULL;

	fp = fopen("D:/a.txt", "w");
    if(fp==NULL){   
        printf("fail");
        return -1;

    }
    char ch;
    ch=fgetc(fp);
    printf("%c ",ch);

    
    char temp='a';
    fputc(temp,fp);
    

	fclose(fp);


	return 0;
}