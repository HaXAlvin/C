#include<stdio.h>
#include<string.h>
int add(int value, int value1)
{
    return value+value1;
}
//宣告add的副程式，將傳入的兩個數字相加
int sub(int value, int value1)
{
    return value-value1;
}
//宣告sub的副程式，將傳入的兩個數字相減
int multi(int value, int value1)
{
    return value*value1;
}
//宣告multi的副程式，將傳入的兩個數字相乘
int div(int value, int value1)
{
    return value/value1;
}
//宣告div的副程式，將傳入的兩個數字相除
int mod(int value, int value1)
{
    return value%value1;
}
//宣告mod的副程式，將傳入的兩個數字相取餘數
int main()
{
    int input,input1,input2; //宣告變數input和input1和input2
    int(*opt[])(int value,int value1)={add,sub,multi,div,mod};//宣告一個函數指標陣列
    while(1){
        printf("1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開:");
        scanf("%d", &input);
        if(input==1){
            printf("請輸入兩個數字:");
            scanf("%d %d", &input1, &input2);
            printf("%d + %d = %d\n", input1, input2, opt[0](input1,input2));
        }
        else if(input==2){
            printf("請輸入兩個數字:");
            scanf("%d %d", &input1, &input2);
            printf("%d - %d = %d\n", input1, input2, opt[1](input1,input2));
        }
        else if(input==3){
            printf("請輸入兩個數字:");
            scanf("%d %d", &input1, &input2);
            printf("%d * %d = %d\n", input1, input2, opt[2](input1,input2));
        }
        else if(input==4){
            printf("請輸入兩個數字:");
            scanf("%d %d", &input1, &input2);
            printf("%d / %d = %d\n", input1, input2, opt[3](input1,input2));
        }
        else if(input==5){
            printf("請輸入兩個數字:");
            scanf("%d %d", &input1, &input2);
            printf("%d %% %d = %d\n", input1, input2, opt[4](input1,input2));
        }
        else if(input==0){
            break;
        }
        else {
            printf("輸入錯誤 請重新輸入\n");
        }
        /* 使用WHHILE迴圈，
           接著輸入INPUT
           如果INPUT為1、2、3、4、5，則印出請輸入兩個數字:，接著輸入兩個數字，在印出兩數的加、減、乘、除、取餘數
           如果INPUT為0，則停止迴圈
           否則就會印出輸入錯誤 請重新輸入*/
    }
    return 0;
}
