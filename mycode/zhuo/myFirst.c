#include<stdio.h>
#include<stdlib.h>

#define MAX_INT 4294967295

int  LoopLeftShiftandCheck(unsigned int num) {
    for (int rotate_imm = 1; rotate_imm < 16; rotate_imm++) {
        int n=rotate_imm * 2;                                       //n为左移的位数
        unsigned int shifted_num = (num << n) | (num >> (32 - n));  //shifted_num是num循环左移的结果
                                            //num << n 是把num循环左移n位，num >> n 是把num左端的n位移动到shifted_num低n位
        if (shifted_num <= 0xFF) {
            return 1; // 可以表示
        } 
    }
    return 0; // 不可以表示
}


//m小于num n大于num
int SearchForMandN (unsigned int num,unsigned int *pm,unsigned int *pn){
    // 找 m < num
    for (unsigned int  m = num - 1; m >= 0; m--) {
        if ( LoopLeftShiftandCheck(m) &&  LoopLeftShiftandCheck(num - m)) {
            *pm= m;
            break;
        }
    }

    // 找 n > num
    for (unsigned int  n = num + 1; n <MAX_INT; n++) {
        if (LoopLeftShiftandCheck(n) && LoopLeftShiftandCheck(n-num)) {
            *pn = n;
            break;
        }
    }
    if (*pm != -1 && *pn != -1) {
        return 1; // 找到
    } else {
        return 0; // 没找到
    }
}


int main(){
    unsigned int num;
    scanf("%u",&num);
    if (LoopLeftShiftandCheck(num)) {
        printf("-1\n");
    } else {
        unsigned int lower_m = -1, upper_n = -1;
        if (SearchForMandN(num, &lower_m, &upper_n)) {
            printf("%u,%u,%u\n", num, lower_m, upper_n);
        } else {
            printf("-2\n");
        }
    }

    return 0;
}

