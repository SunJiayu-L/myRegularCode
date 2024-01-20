#include <stdio.h>
#include <math.h>
int main(){
    double a=3,b=4,c=5,s;
    double area;
    s = (a + b + c) / 2.0;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("%f",area);
    return 0;
}