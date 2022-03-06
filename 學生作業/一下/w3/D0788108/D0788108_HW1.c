#include <stdio.h>

int add (int a, int b){
    return a + b;
}
int sub(int a, int b){
    return a - b;
}
int multi(int a, int b){
    return a * b;
}
int divide(int a, int b){
    return a / b;
}
int mod(int a, int b){
    return a % b;
}
int main(){
    int n = 1;
    int (*opt[5])(int, int) = {add, sub, multi, divide, mod};
    int o[5] = {'+', '-', '*', '/', '%'};
    while (1){
        printf("請輸入(1. 加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開): ");
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("請輸入2個整數: ");
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d %c %d = %d\n", a, o[n-1], b, opt[n - 1](a, b));
    }

    return 0;
}
