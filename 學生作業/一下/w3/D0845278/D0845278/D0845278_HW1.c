#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int add(int a, int b); //加法
int sub(int a, int b); //減法
int multi(int a, int b); //乘法
int divide(int a, int b); //除法
int mod(int a, int b); //取餘數
int main() {
    int n;
    int a,b;
    printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
    while(scanf("%d",&n)!=EOF) {
        int (*opt[])(int,int)= {add,sub,multi,divide,mod};//函數指標陣列
        if(n<0||n>5) {//防呆
            printf("輸入錯誤!\n");
            continue;
        } else {
            if (n==0){
                printf("\n程式結束!\n");
                return 0;
            }
            printf("\n請輸入2個整數:");
            scanf("%d %d",&a,&b);
        }
        if (n==1) {
            printf("\n%d + %d = %d\n",a,b,opt[0](a,b));
        } else if (n==2) {
            printf("\n%d - %d = %d\n",a,b,opt[1](a,b));
        } else if (n==3) {
            printf("\n%d * %d = %d\n",a,b,opt[2](a,b));
        } else if (n==4) {
            printf("\n%d / %d = %d\n",a,b,opt[3](a,b));
        } else if (n==5) {
            printf("\n%d %% %d = %d\n",a,b,opt[4](a,b));
        }
        printf("\n請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
    }
}
int add(int a,int b) {
    return a + b;
}
int sub(int a,int b) {
    return a - b;
}
int multi(int a,int b) {
    return a * b;
}
int divide(int a,int b) {
    return a / b;
}
int mod(int a,int b) {
    return a % b;
}
