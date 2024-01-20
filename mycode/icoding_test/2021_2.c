#include <stdio.h>

int is_triangle(int a, int b, int c) {
    if (a + b > c && a + c > b && b + c > a) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int a, b, c;
    printf("请输入三边长度：");
    scanf("%d%d%d", &a, &b, &c);
    if (is_triangle(a, b, c)) {
        printf("可以构成三角形\n");
    } else {
        printf("不能构成三角形\n");
    }
    return 0;
}