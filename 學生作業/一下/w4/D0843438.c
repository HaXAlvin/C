#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct _fraction//定義分數型態
{
    int numerator,denominator;
};
typedef struct _fraction fraction;

fraction contract(fraction a)//約分
{
    if(a.numerator%a.denominator==0)//整除
    {
        a.numerator=a.numerator/a.denominator;
        a.denominator=1;
    }
    else//約分
    {
        int i=2;
        while(i<=fabs(a.numerator)&&i<=fabs(a.denominator))
        {
            while(a.numerator%i==0&&a.denominator%i==0)
            {
                a.numerator=a.numerator/i;
                a.denominator=a.denominator/i;
            }
            i++;
        }
    }
    if(a.denominator<0)//分母化為正
    {
        a.numerator=-a.numerator;
        a.denominator=-a.denominator;
    }
    return a;
}
fraction add(fraction a,fraction b)//加法
{
    fraction c={a.numerator*b.denominator+b.numerator*a.denominator,a.denominator*b.denominator};
    return contract(c);
}
fraction sub(fraction a,fraction b)//減法
{
    fraction c={a.numerator*b.denominator-b.numerator*a.denominator,a.denominator*b.denominator};
    return contract(c);
}
fraction multi(fraction a,fraction b)//乘法
{
    fraction c={a.numerator*b.numerator,a.denominator*b.denominator};
    return contract(c);
}
fraction divide(fraction a,fraction b)//除法
{
    fraction c={a.numerator*b.denominator,a.denominator*b.numerator};
    return contract(c);
}
int main()//主程式
{
    int system,a,b,c,d;
    char sign[4]={'+','-','*','/'};
    fraction (*function[4])(fraction,fraction)={add,sub,multi,divide};
    while(1)//系統
    {
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
        scanf("%d",&system);
        if(system==0)//離開
        {
            return 0;
        }
        else if(system==1||system==2||system==3||system==4)//計算
        {
            printf("a/b %c c/d，請輸入a b c d:",sign[system-1]);
            scanf("%d %d %d %d",&a,&b,&c,&d);
            if(system==4&&c==0)//防呆(除數為0)
            {
                printf("除數不可為0\n\n");
            }
            else if(b==0||d==0)//防呆(分母為0)
            {
                printf("分母不可為0\n\n");
            }
            else
            {
                fraction input1={a,b};
                fraction input2={c,d};
                fraction output=function[system-1](input1,input2);
                printf("%d/%d %c %d/%d = ",a,b,sign[system-1],c,d);
                if(output.denominator==1)//整除
                {
                    printf("%d\n\n",output.numerator);
                }
                else//非整除
                {
                    printf("%d/%d\n\n",output.numerator,output.denominator);
                }
            }
        }
        else//防呆
        {
            printf("輸入錯誤\n\n");
        }
    }
}
