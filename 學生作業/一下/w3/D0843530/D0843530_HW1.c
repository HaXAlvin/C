#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){//加法
    return a + b;
}
int sub(int a, int b){//減法
    return a - b;
}
int multi(int a, int b){//乘法
    return a * b;
}
int divide(int a, int b){//除法
    return a / b;
}
int mod(int a, int b){ //取餘數
    return a % b;
}


int main(){
    int chose,a,b;
    char op[] = {"+-*/%"};//符號表
    int (*opt[])(int ,int) = {add,sub,multi,divide,mod};
    while(1){
        puts("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開)：");
        scanf("%d",&chose);
        if(!chose){
            printf("exit\n");
            break;
        }
        else if(chose>5 || chose<0){
            printf("error\n");
            continue;
        }
        printf("請輸入兩個整數：");
        scanf("%d %d",&a,&b);
        printf("%d %c %d = %d\n",a,op[chose - 1],b,opt[chose - 1](a , b));
    }


}
