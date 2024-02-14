#include <stdio.h>
void Move (int m,char a,char b){
    printf("No.%d:  %c--> %c\n",m,a,b);//将编号为m的圆盘从a移动到b
}

void Hanoi(int k,char a,char b,char c){
    if(k==1){
        Move(k,a,c);
    }
    else{
        Hanoi(k-1,a,c,b);//将k-1个圆盘从a移到b，c做辅助
        Move(k,a,c);//将编号为k的圆盘从a移动到c
        Hanoi(k-1,b,a,c);//将k-1个园盘从b移动到c，a做辅助
    }

}

int main(){
    char a='a';
    char b='b';
    char c='c';
    Hanoi(3,a,b,c);
    return 0;
}