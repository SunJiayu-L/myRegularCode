#include <stdio.h>
#include <string.h>
int main(){

    char name[100];
    gets(name);
    char temp[100], first[50], last;
    int i = 0, j = 0; // 定义两个整数变量i和j，分别用于循环计数

  while (name[i] == ' ')
    i++;                              // 跳过空格
  if(name[i]!='\0') {                   // 当name[i]不为终止符时，进入循环
    while (name[i] != ' ') // 当name[i]不为空格时，继续读取字符
     first[j++] = name[i++]; // 将name[i]添加到temp数组的j位置，并使i，j加1
    while (name[i] == ' ')
      i++; // 跳过空格
    if (name[i]!=' ')
      last = name[i];
  }
  printf("%c,%s.",last,first);

    return 0;
}

 
