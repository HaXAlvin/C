#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int add(int a, int b){ //加法
    return a+b;
}
int sub(int a, int b){ //減法
    return a-b;
}
int multi(int a, int b){ //乘法
    return a*b;
}
int divide(int a, int b){ //除法
    return a/b;
}
int mod(int a, int b){ //取餘數
    return a%b;
}

int main(){
    int (*opt[])(int,int)={add,sub,multi,divide,mod};
    int WhatToDo;
    while(1){
        printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開)：");
        while(scanf("%d",&WhatToDo)){
            if(WhatToDo==0){
                return 0;
            }
            int num1,num2;
            printf("請輸入兩個整數：");
            scanf("%d %d",&num1,&num2);
            if(WhatToDo==1){
                printf("%d + %d = %d\n",num1,num2,opt[0](num1,num2));
            }
            if(WhatToDo==2){
                printf("%d - %d = %d\n",num1,num2,opt[1](num1,num2));
            }
            if(WhatToDo==3){
                printf("%d * %d = %d\n",num1,num2,opt[2](num1,num2));
            }
            if(WhatToDo==4){
                printf("%d / %d = %d\n",num1,num2,opt[3](num1,num2));
            }
            if(WhatToDo==5){
                printf("%d ％ %d = %d\n",num1,num2,opt[4](num1,num2));
            }
            break;
        }
    }
}
