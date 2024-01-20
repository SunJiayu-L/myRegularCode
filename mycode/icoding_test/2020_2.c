#include <stdio.h>
double Multi (int a);
int main(){
    int temp;
    scanf("%d",&temp);
    double e=2;
    for(;temp!=1;temp--){
        e+=Multi(temp);
    }
    printf("%f",e);
    
    return 0;
}
double Multi (int a){
    double b=1;
    for(;a!=1;a--){
        b*=a;
    }

    return 1/b;
} 
