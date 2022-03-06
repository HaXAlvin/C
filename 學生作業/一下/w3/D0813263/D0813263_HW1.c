#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int a, int b){//加
    return a + b;
}
int sub(int a, int b){//減
    return a - b;
}
int multi(int a, int b){//乘
    return a * b;
}
int divide(int a, int b){//除
    return a / b;
}
int mod(int a, int b){//取餘數
    return a % b;
}

int main(){
    int a,b,n;
    int (*opt[])(int,int) = {add,sub,multi,divide,mod};//使用opt[n]呼叫副程式
    while (n != 0){
        printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
        scanf("%d",&n);
        if (n == 0) return 0;
        printf("請輸入2個整數:");
        scanf("%d %d",&a,&b);
        switch (n){
            case 1:
                printf("%d + %d = %d\n",a,b,opt[0](a,b));
                break;
            case 2:
                printf("%d - %d = %d\n",a,b,opt[1](a,b));
                break;
            case 3:
                printf("%d * %d = %d\n",a,b,opt[2](a,b));
                break;
            case 4:
                printf("%d / %d = %d\n",a,b,opt[3](a,b));
                break;
            case 5:
                printf("%d %% %d = %d\n",a,b,opt[4](a,b));
                break;
        }
    }
}
