/*  109年度  資訊二丁
        第三週作業       */
#include<stdio.h>//標頭檔
#include<stdlib.h>
int add(int a, int b) //加法
{
    return a+b;//回傳值
}
int sub(int a, int b) //減法
{
    return a-b;
}
int multi(int a, int b) //乘法
{
    return a*b;
}
int divide(int a, int b) //除法
{
    return a/b;
}
int mod(int a, int b) //取餘數
{
    return a%b;
}
int main()
{
    int n=0,a=0,b=0;//宣告變數
    int (*opt[])(int,int)= {add,sub,multi,divide,mod};//儲存函式指標陣列

    while(1)
    {
        printf("請選擇(1.家法/2.減法/3.乘法/4.除法/5.取餘數/0.離開)：");//顯示文字
        scanf("%d",&n);

        if(n==1)//選擇加法
        {
            printf("請輸入兩個整數：");
            scanf("%d %d",&a,&b);
            printf("%d + %d = %d\n",a,b,opt[0](a,b));
        }
        if(n==2)//選擇減法
        {
            printf("請輸入兩個整數：");
            scanf("%d %d",&a,&b);
            printf("%d - %d = %d\n",a,b,opt[1](a,b));
        }
        if(n==3)//選擇乘法
        {
            printf("請輸入兩個整數：");
            scanf("%d %d",&a,&b);
            printf("%d * %d = %d\n",a,b,opt[2](a,b));
        }
        if(n==4)//選擇除法
        {
            printf("請輸入兩個整數：");
            scanf("%d %d",&a,&b);
            printf("%d / %d = %d\n",a,b,opt[3](a,b));
        }
        if(n==5)//選擇取餘數
        {
            printf("請輸入兩個整數：");
            scanf("%d %d",&a,&b);
            printf("%d %% %d = %d\n",a,b,opt[4](a,b));
        }
        if(n==0)//選擇離開
        {
            return 0;
        }

    }
}
