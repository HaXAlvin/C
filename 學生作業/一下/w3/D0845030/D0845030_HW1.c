#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int a, int b){
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
    //設立變數
    int choice, a, b;
    int (*opt[])(int ,int) = {add, sub, multi, divide, mod};//將函式存成函式指標陣列opt
    printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開) : ");
    while(scanf("%d", &choice) && choice != 0){
        if(choice == 1){
            //加法
            printf("請輸入2個整數 : ");
            scanf("%d %d", &a, &b);
            printf("%d + %d = ", a, b);
            printf("%d\n", opt[0](a, b));//呼叫add
            printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開) : ");
        }
        if(choice == 2){
            //減法
            printf("請輸入2個整數 : ");
            scanf("%d %d", &a, &b);
            printf("%d - %d = ", a, b);
            printf("%d\n", opt[1](a, b));//呼叫sub
            printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開) : ");
        }
        if(choice == 3){
            //乘法
            printf("請輸入2個整數 : ");
            scanf("%d %d", &a, &b);
            printf("%d * %d = ", a, b);
            printf("%d\n", opt[2](a, b));//呼叫multi
            printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開) : ");
        }
        if(choice == 4){
            //除法
            printf("請輸入2個整數 : ");
            scanf("%d %d", &a, &b);
            printf("%d / %d = ", a, b);
            printf("%d\n", opt[3](a, b));//呼叫divide
            printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開) : ");
        }
        if(choice == 5){
            //取餘數
            printf("請輸入2個整數 : ");
            scanf("%d %d", &a, &b);
            printf("%d %% %d = ", a, b);
            printf("%d\n", opt[4](a, b));//呼叫mod
            printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開) : ");
        }
    }
    return 0;
}
