#include <stdio.h>
void max_min(int a[], int n, int *max, int *min);
int main(){
    int arr[10]={0};
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    int max,min;
    int *pmax=&max;
    int *pmin=&min;
    max_min(arr,10,pmax, pmin);
    printf("%d\n",max);
    printf("%d",min);
    return 0;
}
void max_min(int a[], int n, int *max, int *min){
    *max=a[0];
    *min=a[0];
    for(int i=1;i<n;i++){
        if(*max<a[i]){
            *max=a[i];
        }
        if(*min>a[i]){
            *min=a[i];
        }
    }
}