#include<stdio.h>
#include<string.h>
int add(int a, int b){
    return a+b;
} //加法
int sub(int a, int b){
    return a-b;
} //減法
int multi(int a, int b){
    return a*b;
} //乘法
int divide(int a, int b){
    return a/b;
} //除法
int mod(int a, int b){
    return a%b;
} //取餘數
int main(){
    int (*opt[])(int, int)={ add, sub, multi, divide, mod};
    while(1){

        int n;
        int x,y;
        printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開:");
        scanf("%d",&n);//選擇運算方式
        if (n==0){//如果輸入0則跳出
            break;
        }
        getchar();
        printf("請輸入兩個整數:");
        scanf("%d %d",&x,&y);
        printf("%d\n", opt[n-1](x,y));//進入所選副程式並印出結果


    }

}
