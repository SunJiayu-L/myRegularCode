#include <stdio.h>
#include <string.h>

void swapCase(char* str) {
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // 小写字母转大写字母
            str[i] = str[i] - 'a' + 'A';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            // 大写字母转小写字母
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

int main() {
    char str[100];
    printf("请输入字符串：");
    scanf("%s", str);
    
    printf("大小写字母互换后的结果为：");
    swapCase(str);
    printf("%s", str);
    
    return 0;
}
