#include<stdio.h>
#include<stdlib.h>
int add(int a,int b)
{
    return a+b;
}
int sub(int a,int b)
{
    return a-b;
}
int multi(int a,int b)
{
    return a*b;
}
int divide(int a,int b)
{
    return a/b;
}
int mod(int a,int b)
{
    return a%b;
}
int main()
{
    int n,a,b;
    float A;
    printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        if(n>0&&n<6)
        {
            printf("請輸入兩個整數:");
            scanf("%d %d",&a,&b);
            int opt[6]={0,add(a,b),sub(a,b),multi(a,b),divide(a,b),mod(a,b)};
            A = opt[n];
            if(n==1)
            {
                printf("%d + %d = %f\n",a,b,A);
            }
            else if(n==2)
            {
                printf("%d - %d = %f\n",a,b,A);
            }
            else if(n==3)
            {
                printf("%d * %d = %f\n",a,b,A);
            }
            else if(n==4)
            {
                printf("%d / %d = %f\n",a,b,A);
            }
            else if(n==5)
            {
                printf("%d %% %d = %f\n",a,b,A);
            }
            printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
        }
        else if((n>5)||(n<0))
        {
            printf("輸入錯誤\n");
            printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開):");
        }
        
    }
    return 0;
}
