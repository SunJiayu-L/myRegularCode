#include <stdio.h>
int main(){
  int firstDay,firstMonth,firstYear;
  int secondDay,seconMonth,secondYear;
  scanf("%d/%d/%d",&firstMonth,&firstDay,&firstYear);
  scanf("%d/%d/%d",&seconMonth,&secondDay,&secondYear);
  if(firstYear>secondYear){
    printf("%d/%d/%d is earlier than %d/%d/%d",firstMonth,firstDay,firstYear,seconMonth,secondDay,secondYear);
  }
  if(firstYear<secondYear){
    printf("%d/%d/%d is earlier than %d/%d/%d",seconMonth,secondDay,secondYear,firstMonth,firstDay,firstYear);
  }
  if(firstYear==secondYear){
    if(firstMonth>seconMonth){
      printf("%d/%d/%d is earlier than %d/%d/%d",firstMonth,firstDay,firstYear,seconMonth,secondDay,secondYear);
    }
    if(firstMonth<seconMonth){
       printf("%d/%d/%d is earlier than %d/%d/%d",seconMonth,secondDay,secondYear,firstMonth,firstDay,firstYear);
    }
    if(firstMonth==seconMonth){
      if(firstDay>secondDay){
         printf("%d/%d/%d is earlier than %d/%d/%d",firstMonth,firstDay,firstYear,seconMonth,secondDay,secondYear);
      }
      if(firstDay<secondDay){
         printf("%d/%d/%d is earlier than %d/%d/%d",seconMonth,secondDay,secondYear,firstMonth,firstDay,firstYear);
      }
    }
  }
  return 0;
}