#include <stdio.h>
#include <stdlib.h>
int add(int a, int b){//兩數相加函式
    return a+b;//回傳兩數相加
}

int sub(int a, int b){//兩數相減函式
    return a-b;//回傳兩數相減
}

int multi(int a, int b){//兩數相乘函式
    return a*b;//回傳兩數相持乘
}

int divide(int a, int b){//兩數相除函式
    return a/b;//回傳兩數相除
}

int mod(int a, int b){//兩數取餘數函式
    return a%b;//回傳兩數取餘數
}

int main(){
    int cho;//功能選擇變數
    int n1, n2;//要計算的兩個數
    int (*opt[])(int, int)={add, sub, multi, divide, mod};//函式指標陣列
    printf("1.Add/2.Subtract/3.Multiply/4.Divide/5.Remainder/0.Leave：");//提示輸入
    scanf("%d", &cho);//使用者輸入選擇
    while(cho>=0&&cho<=5){
        if(cho==1){//選擇1(加法)
            printf("Enter 2 integers：");//提示輸入
            scanf("%d %d", &n1, &n2);//輸入兩個數字
            printf("%d + %d = %d\n", n1, n2, opt[cho-1](n1, n2));//印出結果
        }
        else if(cho==2){//選擇2(減法)
            printf("Enter 2 integers：");//提示輸入
            scanf("%d %d", &n1, &n2);//輸入兩個數字
            printf("%d - %d = %d\n", n1, n2, opt[cho-1](n1, n2));//印出結果
        }
        else if(cho==3){//選擇3(乘法)
            printf("Enter 2 integers：");//提示輸入
            scanf("%d %d", &n1, &n2);//輸入兩個數字
            printf("%d * %d = %d\n", n1, n2, opt[cho-1](n1, n2));//印出結果
        }
        else if(cho==4){//選擇4(除法)
            printf("Enter 2 integers：");//提示輸入
            scanf("%d %d", &n1, &n2);//輸入兩個數字
            printf("%d / %d = %d\n", n1, n2, opt[cho-1](n1, n2));//印出結果
        }
        else if(cho==5){//選擇5(取餘數)
            printf("Enter 2 integers：");//提示輸入
            scanf("%d %d", &n1, &n2);//輸入兩個數字
            printf("%d %% %d = %d\n", n1, n2, opt[cho-1](n1, n2));//印出結果
        }
        else if(cho==0)//選擇0(離開)
            return 0;
        printf("1.Add/2.Subtract/3.Multiply/4.Divide/5.Remainder/0.Leave：");//提示輸入
        scanf("%d", &cho);//使用者輸入選擇
    }
}
