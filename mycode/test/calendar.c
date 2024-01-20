#include <stdio.h> 

int main() {
    int numOfDays,startOfData;
    scanf("%d %d",&numOfDays,&startOfData);
    printf("日  一  二  三  四  五  六\n");

    for(int i=1;i<startOfData;i++){
        printf("    ");
    }
    int control=startOfData;
    for(int j=1;j<numOfDays;j++){
        if(control==8){
            printf("\n");
            control=1;
        }
        if(j<10){
            printf("%d   ",j);
            control++;
        }
        if(j>=10){
            printf("%d  ",j);
            control++;
        }
    }

    return 0; // 函数返回0，表示程序正常结束
}