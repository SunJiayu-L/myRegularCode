#include <stdio.h>
int main (){
  int arr[10]={0};
  for(int i=0;i<10;i++){
    scanf("%d",&arr[i]);
  }

  for(int j=0;j<10-1;j++){//重复几次
        for(int i=0;i<10-1-j;i++){//单行排序
        
        if(arr[i]>arr[i+1]){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
  }
   for(int i=0;i<10;i++)
{
    printf("%d",arr[i]);
}



    return 0;
} 
