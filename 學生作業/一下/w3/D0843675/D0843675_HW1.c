#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int add(int a, int b){//加法
    return a+b;
}

int sub(int a, int b){//減法
    return a-b;
}

int multi(int a, int b){//乘法
    return a*b;
}

int divide(int a, int b){//除法
    return a/b;
}

int mob(int a, int b){//取餘數
    return a%b;
}

int main(){
    int a = 0;
    int b = 0;
    int option = 0;
    int (*opt[])(int,int) = {add,sub,multi,divide,mob};
    while(1){
        printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
        scanf("%d",&option);
        if(option==0)
            return 0;
        printf("請輸入2個整數:");
        scanf("%d %d",&a,&b);

        switch(option){
            case 1:
                printf("%d + %d = ",a,b);
                break;
            case 2:
                printf("%d - %d = ",a,b);
                break;
            case 3:
                printf("%d * %d = ",a,b);
                break;
            case 4:
                printf("%d / %d = ",a,b);
                break;
            case 5:
                printf("%d %% %d = ",a,b);
                break;
        }
        printf("%d\n",opt[option-1](a,b));
    }
}
