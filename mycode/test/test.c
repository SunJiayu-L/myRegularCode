#include <stdio.h> // 引入标准输入输出库
#include <stdlib.h>
#include <time.h>

int main() {
    char map[12][12];
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            map[i][j] = '.';
        }
  }

    srand((unsigned)time(NULL));
    map[1][1]='A';
    for(int x=1,y=1,num=1;num<26;){
        if (map[x + 1][y] == '.' || map[x - 1][y] == '.' || map[x][y + 1] == '.' ||map[x][y - 1] == '.') {
            int prevX = x, prevY = y; // 记下原位置
            int m = rand() % 4;
            switch (m) {
            case 0:
                x++;
                break;
            case 1:
                x--;
                break;
            case 2:
                y++;
                break;
            case 3:
                y--;
                break;
            }
        if (x > 0 && x < 11 && y > 0 && y < 11 && map[x][y] == '.'){
        map[x][y] = 'A' + num++;
        }else { // 如果移动后的位置不为空或跳出地图了，则返回刚刚的位置
        x = prevX;
        y = prevY;
      }
    } else{
      break;
    }
   }
     for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
             printf("%c", map[i][j]);
        }
        printf("\n");
  }
    return 0;
}