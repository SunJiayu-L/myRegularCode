#include <stdio.h>
int main(){
 int arr[9]={10,9,8,7,6,5,4,3,2};

int min=arr[0];
int n=0;
 for(int count=0;count<4;count++){
    for(int j=count;j<10;j++){//遍历数组找到最小值
        if(min>arr[j]){
            min=arr[j];
            n=j;
        }
    }
    //交换数组
    int temp;
    temp=arr[n];
    arr[n]=arr[count];
    arr[count]=temp;
    min=arr[count+1];
  
    }

//输出数组
 for(int i=0;i<10;i++){
    printf("%d\n",arr[i]);
}
 return 0;
}