#include<stdio.h>
#include<stdlib.h>

int add(int a, int b)//加法
{
    return a+b;
}



int sub(int a, int b)//減法
{
    return a-b;
}
int multi(int a, int b)//乘法
{
    return a*b;
}
int divide(int a, int b)//除法
{
    return a/b;
}
int mod(int a, int b)//取餘數
{
    return  a%b;
}
int main()
{
    int input;//輸入要做哪個運算
    int num1,num2;//輸入哪兩個數運算
    int (*opt[5])(int,int) = {add,sub,multi,divide,mod}; //函式陣列
    while (1){
        printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
        scanf("%d",&input);
        if (input==0)//判斷是否離開
            break;
        printf("請輸入2個整數:");
        scanf("%d %d",&num1,&num2);
        switch (input)
        {
            case 1://加法
                printf("%d + %d = %d\n",num1,num2,opt[0](num1,num2));
                break;
            case 2://減法
                printf("%d - %d = %d\n",num1,num2,opt[1](num1,num2));
                break;
            case 3://乘法
                printf("%d * %d = %d\n",num1,num2,opt[2](num1,num2));
                break;
            case 4://除法
                printf("%d / %d = %d\n",num1,num2,opt[3](num1,num2));
                break;
            case 5://取餘數
                printf("%d %% %d = %d\n",num1,num2,opt[4](num1,num2));
                break;
        }
    }
}
