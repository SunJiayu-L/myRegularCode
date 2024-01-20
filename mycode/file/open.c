#include <stdio.h>

int main() {

	FILE *fp = NULL;
	fp = fopen("D:/a.txt", "r");
    if(fp==NULL){   
        printf("fail");
        return -1;

    }
	printf("%p ", fp);
	fclose(fp);
	return 0;
}