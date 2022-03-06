#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b); //加法
int sub(int a, int b); //減法
int multi(int a, int b); //乘法
int divide(int a, int b); //除法
int mod(int a, int b); //取餘數
int leave(int a, int b); //離開

int main() {
    int (*opt[6]) (int a, int b) = {leave, add, sub, multi, divide, mod};
    int actionCode, a, b, result;
    char instructionString[] = "請選擇（1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):";
    char *operators[] = {"lol", "+", "-", "*", "/", "%"};


    printf("%s", instructionString);

    while (scanf("%d", &actionCode)) {
        if (actionCode == 0) {
            printf("離開\n");
            break;
        }

        printf("請輸入2個整數:");
        scanf("%d %d", &a, &b);

        // result = (*opt[i]) (a, b);
        printf("%d %s %d = %d\n", a, operators[actionCode], b, (*opt[actionCode]) (a, b));
        printf("%s", instructionString);
    }

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int multi(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int mod(int a, int b){
    return a % b;
}

int leave(int a, int b) {
    return a = b;
}